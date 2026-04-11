#include <assert.h>
#include <stdio.h>

#include "navigation.h"

static MecanumConfig mcfg = {
    .lx = 0.15f,
    .ly = 0.15f,
    .wheel_radius = 0.076f,
    .max_rpm = 300.0f,
};

static void test_init_state(void) {
    NavContext ctx;

    nav_init(&ctx, &mcfg);

    assert(ctx.state == NAV_IDLE);
    printf("[PASS] test_init_state\n");
}

static void test_set_target(void) {
    NavContext ctx;

    nav_init(&ctx, &mcfg);
    nav_set_target(&ctx, 1.0f, 0.0f, 0.0f);

    assert(ctx.state == NAV_NAVIGATING);
    printf("[PASS] test_set_target\n");
}

static void test_already_at_target(void) {
    NavContext ctx;
    WheelSpeeds ws;

    nav_init(&ctx, &mcfg);
    nav_set_target(&ctx, 0.0f, 0.0f, 0.0f);
    NavState s = nav_update(&ctx, 0.0f, 0.0f, 0.0f, 0.005f, &ws);

    assert(s == NAV_DONE);
    assert(ws.fl == 0.0f && ws.fr == 0.0f);
    printf("[PASS] test_already_at_target\n");
}

static void test_nonzero_output_when_far(void) {
    NavContext ctx;
    WheelSpeeds ws;

    nav_init(&ctx, &mcfg);
    nav_set_target(&ctx, 2.0f, 0.0f, 0.0f);
    NavState s = nav_update(&ctx, 0.0f, 0.0f, 0.0f, 0.005f, &ws);

    assert(s == NAV_NAVIGATING);
    assert(ws.fl != 0.0f || ws.fr != 0.0f);
    printf("[PASS] test_nonzero_output_when_far\n");
}

static void test_reset(void) {
    NavContext ctx;
    WheelSpeeds ws;

    nav_init(&ctx, &mcfg);
    nav_set_target(&ctx, 1.0f, 0.0f, 0.0f);
    nav_reset(&ctx, &ws);

    assert(ctx.state == NAV_IDLE);
    assert(ws.fl == 0.0f);
    printf("[PASS] test_reset\n");
}

int main(void) {
    test_init_state();
    test_set_target();
    test_already_at_target();
    test_nonzero_output_when_far();
    test_reset();
    printf("All navigation tests passed.\n");
    return 0;
}
