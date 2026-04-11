#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "mecanum.h"

typedef enum {
    NAV_IDLE = 0,
    NAV_NAVIGATING,
    NAV_DONE,
} NavState;

typedef struct {
    float kp;
    float ki;
    float kd;
    float integral;
    float prev_error;
    float integral_limit;
    float output_limit;
} PIDController;

typedef struct {
    NavState state;
    float target_x;
    float target_y;
    float target_yaw;

    PIDController pid_x;
    PIDController pid_y;
    PIDController pid_yaw;

    MecanumConfig mecanum;

    float pos_threshold;
    float yaw_threshold;
} NavContext;

void nav_init(NavContext *ctx, const MecanumConfig *mcfg);

void nav_set_target(NavContext *ctx, float tx, float ty, float tyaw);

NavState nav_update(NavContext *ctx,
                    float cx, float cy, float cyaw,
                    float dt, WheelSpeeds *out);

void nav_reset(NavContext *ctx, WheelSpeeds *out);

#endif /* NAVIGATION_H */
