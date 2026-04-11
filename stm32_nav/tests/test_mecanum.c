#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "mecanum.h"

static MecanumConfig cfg = {
    .lx = 0.15f,
    .ly = 0.15f,
    .wheel_radius = 0.076f,
    .max_rpm = 300.0f,
};

static void test_pure_forward(void) {
    WheelSpeeds ws;

    mecanum_inverse(0.5f, 0.0f, 0.0f, &cfg, &ws);

    assert(fabs(ws.fl - ws.fr) < 1e-3f);
    assert(fabs(ws.fl - ws.rl) < 1e-3f);
    assert(fabs(ws.fl - ws.rr) < 1e-3f);
    assert(ws.fl > 0.0f);
    printf("[PASS] test_pure_forward\n");
}

static void test_pure_strafe(void) {
    WheelSpeeds ws;

    mecanum_inverse(0.0f, 0.5f, 0.0f, &cfg, &ws);

    assert(ws.fl < 0.0f);
    assert(ws.fr > 0.0f);
    assert(ws.rl > 0.0f);
    assert(ws.rr < 0.0f);
    printf("[PASS] test_pure_strafe\n");
}

static void test_clamp(void) {
    WheelSpeeds ws;

    mecanum_inverse(100.0f, 0.0f, 0.0f, &cfg, &ws);

    assert(fabs(ws.fl) <= cfg.max_rpm + 1e-3f);
    assert(fabs(ws.fr) <= cfg.max_rpm + 1e-3f);
    assert(fabs(ws.rl) <= cfg.max_rpm + 1e-3f);
    assert(fabs(ws.rr) <= cfg.max_rpm + 1e-3f);
    printf("[PASS] test_clamp\n");
}

int main(void) {
    test_pure_forward();
    test_pure_strafe();
    test_clamp();
    printf("All mecanum tests passed.\n");
    return 0;
}
