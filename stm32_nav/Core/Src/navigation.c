#include "navigation.h"

#include <math.h>
#include <string.h>

#define NAV_PI 3.14159265f

static float pid_update(PIDController *pid, float error, float dt) {
    pid->integral += error * dt;
    if (pid->integral > pid->integral_limit) {
        pid->integral = pid->integral_limit;
    }
    if (pid->integral < -pid->integral_limit) {
        pid->integral = -pid->integral_limit;
    }

    float derivative = (error - pid->prev_error) / dt;
    pid->prev_error = error;

    float output = pid->kp * error + pid->ki * pid->integral + pid->kd * derivative;
    if (output > pid->output_limit) {
        output = pid->output_limit;
    }
    if (output < -pid->output_limit) {
        output = -pid->output_limit;
    }
    return output;
}

static void pid_reset(PIDController *pid) {
    pid->integral = 0.0f;
    pid->prev_error = 0.0f;
}

static float normalize_angle(float a) {
    while (a > NAV_PI) {
        a -= 2.0f * NAV_PI;
    }
    while (a < -NAV_PI) {
        a += 2.0f * NAV_PI;
    }
    return a;
}

void nav_init(NavContext *ctx, const MecanumConfig *mcfg) {
    memset(ctx, 0, sizeof(NavContext));
    ctx->mecanum = *mcfg;
    ctx->state = NAV_IDLE;

    ctx->pid_x.kp = 1.2f;
    ctx->pid_x.ki = 0.0f;
    ctx->pid_x.kd = 0.05f;
    ctx->pid_x.integral_limit = 1.0f;
    ctx->pid_x.output_limit = 0.5f;

    ctx->pid_y.kp = 1.2f;
    ctx->pid_y.ki = 0.0f;
    ctx->pid_y.kd = 0.05f;
    ctx->pid_y.integral_limit = 1.0f;
    ctx->pid_y.output_limit = 0.5f;

    ctx->pid_yaw.kp = 1.5f;
    ctx->pid_yaw.ki = 0.0f;
    ctx->pid_yaw.kd = 0.08f;
    ctx->pid_yaw.integral_limit = 1.0f;
    ctx->pid_yaw.output_limit = 1.5f;

    ctx->pos_threshold = 0.03f;
    ctx->yaw_threshold = 0.052f;
}

void nav_set_target(NavContext *ctx, float tx, float ty, float tyaw) {
    ctx->target_x = tx;
    ctx->target_y = ty;
    ctx->target_yaw = tyaw;
    pid_reset(&ctx->pid_x);
    pid_reset(&ctx->pid_y);
    pid_reset(&ctx->pid_yaw);
    ctx->state = NAV_NAVIGATING;
}

NavState nav_update(NavContext *ctx,
                    float cx, float cy, float cyaw,
                    float dt, WheelSpeeds *out) {
    if (ctx->state != NAV_NAVIGATING) {
        out->fl = 0.0f;
        out->fr = 0.0f;
        out->rl = 0.0f;
        out->rr = 0.0f;
        return ctx->state;
    }

    float ex_world = ctx->target_x - cx;
    float ey_world = ctx->target_y - cy;
    float eyaw = normalize_angle(ctx->target_yaw - cyaw);

    float cos_yaw = cosf(cyaw);
    float sin_yaw = sinf(cyaw);
    float ex_body = cos_yaw * ex_world + sin_yaw * ey_world;
    float ey_body = -sin_yaw * ex_world + cos_yaw * ey_world;

    float pos_err = sqrtf(ex_world * ex_world + ey_world * ey_world);
    if (pos_err < ctx->pos_threshold && fabsf(eyaw) < ctx->yaw_threshold) {
        out->fl = 0.0f;
        out->fr = 0.0f;
        out->rl = 0.0f;
        out->rr = 0.0f;
        ctx->state = NAV_DONE;
        return NAV_DONE;
    }

    float vx = pid_update(&ctx->pid_x, ex_body, dt);
    float vy = pid_update(&ctx->pid_y, ey_body, dt);
    float omega = pid_update(&ctx->pid_yaw, eyaw, dt);

    mecanum_inverse(vx, vy, omega, &ctx->mecanum, out);
    return NAV_NAVIGATING;
}

void nav_reset(NavContext *ctx, WheelSpeeds *out) {
    ctx->state = NAV_IDLE;
    pid_reset(&ctx->pid_x);
    pid_reset(&ctx->pid_y);
    pid_reset(&ctx->pid_yaw);
    out->fl = 0.0f;
    out->fr = 0.0f;
    out->rl = 0.0f;
    out->rr = 0.0f;
}
