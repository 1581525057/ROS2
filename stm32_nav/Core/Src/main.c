/*
 * STM32 mecanum navigation main loop framework.
 *
 * Usage:
 * 1. Complete CubeMX initialization in STM32CubeIDE for UART, TIM, and PWM.
 * 2. Paste generated HAL initialization code into USER CODE regions.
 * 3. Replace set_motor_rpm() with real PWM output logic.
 * 4. Tune PID parameters and chassis dimensions for the platform.
 */

#include "mecanum.h"
#include "navigation.h"
#include "protocol.h"

#include <stdint.h>
#include <string.h>

/* ===== User configuration BEGIN ===== */
#define MECANUM_LX 0.15f
#define MECANUM_LY 0.15f
#define WHEEL_RADIUS 0.076f
#define MAX_RPM 300.0f

#define CONTROL_DT 0.005f
/* ===== User configuration END ===== */

/* USER CODE BEGIN HAL Handles */
/* extern UART_HandleTypeDef huart1; */
/* extern TIM_HandleTypeDef htim2; */
/* USER CODE END HAL Handles */

static NavContext g_nav;
static WheelSpeeds g_wheels;
static char g_rx_buf[128];
static uint8_t g_rx_byte;
static uint8_t g_rx_idx;
static uint8_t g_ctrl_flag;

static float g_cur_x;
static float g_cur_y;
static float g_cur_yaw;

static void set_motor_rpm(const WheelSpeeds *ws) {
    /* TODO: Convert ws->fl/fr/rl/rr RPM into TIM CCR values for motor PWM. */
    (void)ws;
}

void HAL_TIM_PeriodElapsedCallback(void *htim) {
    /* USER CODE BEGIN TIM Callback */
    /* if (htim->Instance == TIM2) { g_ctrl_flag = 1; } */
    /* USER CODE END TIM Callback */
    (void)htim;
    g_ctrl_flag = 1;
}

void HAL_UART_RxCpltCallback(void *huart) {
    (void)huart;

    char c = (char)g_rx_byte;
    if (c == '\n') {
        g_rx_buf[g_rx_idx] = '\0';
        g_rx_idx = 0;

        NavFrame frame;
        if (protocol_parse_nav(g_rx_buf, &frame)) {
            if (g_nav.state == NAV_IDLE) {
                nav_set_target(&g_nav,
                               frame.target_x,
                               frame.target_y,
                               frame.target_yaw);
            }
            g_cur_x = frame.current_x;
            g_cur_y = frame.current_y;
            g_cur_yaw = frame.current_yaw;
        }
    } else if (c != '\r') {
        if (g_rx_idx < sizeof(g_rx_buf) - 1U) {
            g_rx_buf[g_rx_idx++] = c;
        }
    }

    /* USER CODE BEGIN UART RX Restart */
    /* USER: uncomment with actual HAL handle */
    /* HAL_UART_Receive_IT(&huart1, &g_rx_byte, 1); */
    /* USER CODE END UART RX Restart */
}

int main(void) {
    /* USER CODE BEGIN Init */
    /* HAL_Init(); */
    /* SystemClock_Config(); */
    /* MX_GPIO_Init(); */
    /* MX_USART1_UART_Init(); */
    /* MX_TIM2_Init(); */
    /* USER CODE END Init */

    MecanumConfig mcfg = {
        .lx = MECANUM_LX,
        .ly = MECANUM_LY,
        .wheel_radius = WHEEL_RADIUS,
        .max_rpm = MAX_RPM,
    };
    nav_init(&g_nav, &mcfg);

    /* protocol_send(&huart1, "$READY\r\n"); */

    /* USER CODE BEGIN UART RX Start */
    /* USER: uncomment with actual HAL handle */
    /* HAL_UART_Receive_IT(&huart1, &g_rx_byte, 1); */
    /* USER CODE END UART RX Start */

    /* HAL_TIM_Base_Start_IT(&htim2); */

    while (1) {
        if (g_ctrl_flag) {
            g_ctrl_flag = 0;

            NavState s = nav_update(&g_nav,
                                    g_cur_x,
                                    g_cur_y,
                                    g_cur_yaw,
                                    CONTROL_DT,
                                    &g_wheels);
            set_motor_rpm(&g_wheels);

            if (s == NAV_DONE) {
                /* USER CODE BEGIN Done Response */
                /* USER: uncomment with actual HAL handle */
                /* protocol_send(&huart1, "$DONE\r\n"); */
                /* USER CODE END Done Response */
                nav_reset(&g_nav, &g_wheels);
            }
        }
    }
}
