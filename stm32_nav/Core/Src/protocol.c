#include "protocol.h"

#include <stdio.h>
#include <string.h>

#ifdef USE_HAL_DRIVER
#include "usart.h"
#endif

int protocol_parse_nav(const char *line, NavFrame *out) {
    if (line == NULL || out == NULL) {
        return 0;
    }

    int matched = sscanf(line,
                         "$NAV,%f,%f,%f,%f,%f,%f",
                         &out->target_x,
                         &out->target_y,
                         &out->target_yaw,
                         &out->current_x,
                         &out->current_y,
                         &out->current_yaw);

    return (matched == 6) ? 1 : 0;
}

void protocol_send(void *huart, const char *msg) {
#ifdef USE_HAL_DRIVER
    UART_HandleTypeDef *h = (UART_HandleTypeDef *)huart;
    HAL_UART_Transmit(h, (uint8_t *)msg, strlen(msg), 100);
#else
    (void)huart;
    (void)msg;
#endif
}
