#ifndef MECANUM_H
#define MECANUM_H

/* Mecanum chassis parameters. */
typedef struct {
    float lx;           /* Half track width (m) */
    float ly;           /* Half wheelbase (m) */
    float wheel_radius; /* Wheel radius (m) */
    float max_rpm;      /* Motor maximum speed (RPM) */
} MecanumConfig;

/* Four-wheel speed output in RPM. Positive values rotate forward. */
typedef struct {
    float fl; /* Front-left wheel */
    float fr; /* Front-right wheel */
    float rl; /* Rear-left wheel */
    float rr; /* Rear-right wheel */
} WheelSpeeds;

/**
 * O-layout mecanum inverse kinematics.
 *
 * @param vx robot-frame x velocity (m/s, forward positive)
 * @param vy robot-frame y velocity (m/s, left positive)
 * @param omega z angular velocity (rad/s, counterclockwise positive)
 * @param cfg chassis parameters
 * @param out wheel speeds clamped to +/- max_rpm
 */
void mecanum_inverse(float vx, float vy, float omega,
                     const MecanumConfig *cfg, WheelSpeeds *out);

#endif /* MECANUM_H */
