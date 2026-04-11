#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "protocol.h"

static void test_valid_frame(void) {
    NavFrame f;
    int ok = protocol_parse_nav("$NAV,1.500,2.300,1.571,0.100,0.200,0.050", &f);

    assert(ok == 1);
    assert(fabs(f.target_x - 1.500f) < 1e-4f);
    assert(fabs(f.target_y - 2.300f) < 1e-4f);
    assert(fabs(f.target_yaw - 1.571f) < 1e-4f);
    assert(fabs(f.current_x - 0.100f) < 1e-4f);
    assert(fabs(f.current_y - 0.200f) < 1e-4f);
    assert(fabs(f.current_yaw - 0.050f) < 1e-4f);
    printf("[PASS] test_valid_frame\n");
}

static void test_invalid_frame(void) {
    NavFrame f;
    int ok = protocol_parse_nav("$GARBAGE,1,2", &f);

    assert(ok == 0);
    printf("[PASS] test_invalid_frame\n");
}

static void test_null_input(void) {
    int ok = protocol_parse_nav(NULL, NULL);

    assert(ok == 0);
    printf("[PASS] test_null_input\n");
}

int main(void) {
    test_valid_frame();
    test_invalid_frame();
    test_null_input();
    printf("All protocol tests passed.\n");
    return 0;
}
