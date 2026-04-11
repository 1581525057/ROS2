#include "mecanum.h"

static float clamp(float v, float min, float max) {
    if (v < min) {
        return min;
    }
    if (v > max) {
        return max;
    }
    return v;
}

void mecanum_inverse(float vx, float vy, float omega,
                     const MecanumConfig *cfg, WheelSpeeds *out) {
    float k = cfg->lx + cfg->ly;
    float v_fl = vx - vy - k * omega;
    float v_fr = vx + vy + k * omega;
    float v_rl = vx + vy - k * omega;
    float v_rr = vx - vy + k * omega;

    float to_rpm = 60.0f / (2.0f * 3.14159265f * cfg->wheel_radius);
    float max_rpm = cfg->max_rpm;

    out->fl = clamp(v_fl * to_rpm, -max_rpm, max_rpm);
    out->fr = clamp(v_fr * to_rpm, -max_rpm, max_rpm);
    out->rl = clamp(v_rl * to_rpm, -max_rpm, max_rpm);
    out->rr = clamp(v_rr * to_rpm, -max_rpm, max_rpm);
}
