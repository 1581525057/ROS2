#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdint.h>

/* Parsed navigation frame. */
typedef struct {
    float target_x;    /* Target x (m) */
    float target_y;    /* Target y (m) */
    float target_yaw;  /* Target yaw (rad) */
    float current_x;   /* Current x (m) */
    float current_y;   /* Current y (m) */
    float current_yaw; /* Current yaw (rad) */
} NavFrame;

/**
 * Parse one UART line after stripping CRLF.
 *
 * Example input:
 * "$NAV,1.5,2.3,1.571,0.1,0.2,0.05"
 *
 * @param line input string
 * @param out parsed frame destination
 * @return 1 on success, 0 on failure
 */
int protocol_parse_nav(const char *line, NavFrame *out);

/**
 * Send a fixed response frame through HAL UART.
 *
 * @param huart HAL UART handle pointer
 * @param msg response string, for example "$DONE\r\n"
 */
void protocol_send(void *huart, const char *msg);

#endif /* PROTOCOL_H */
