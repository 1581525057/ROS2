#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "mecanum.h"

typedef enum {
    NAV_IDLE = 0,
    NAV_NAVIGATING,
    NAV_DONE,
} NavState;

typedef struct {
    float kp;             /* 比例增益：根据当前误差产生控制输出 */
    float ki;             /* 积分增益：消除稳态误差 */
    float kd;             /* 微分增益：抑制误差变化过快 */
    float integral;       /* 积分累计值 */
    float prev_error;     /* 上一次误差，用于计算微分项 */
    float integral_limit; /* 积分限幅，防止积分饱和 */
    float output_limit;   /* 输出限幅，对应最大速度或角速度 */
} PIDController;

typedef struct {
    NavState state;  /* 当前导航状态：IDLE、NAVIGATING 或 DONE */
    float target_x;  /* 目标 x 坐标，世界坐标系，单位 m */
    float target_y;  /* 目标 y 坐标，世界坐标系，单位 m */
    float target_yaw; /* 目标偏航角，世界坐标系，单位 rad */

    PIDController pid_x;   /* 本体 x 方向速度 PID */
    PIDController pid_y;   /* 本体 y 方向速度 PID */
    PIDController pid_yaw; /* 偏航角速度 PID */

    MecanumConfig mecanum; /* 麦克纳姆底盘几何参数与最大转速 */

    float pos_threshold; /* 到达判定位置误差阈值，单位 m，默认 0.03 */
    float yaw_threshold; /* 到达判定角度误差阈值，单位 rad，默认 0.052 */
} NavContext;

void nav_init(NavContext *ctx, const MecanumConfig *mcfg);

void nav_set_target(NavContext *ctx, float tx, float ty, float tyaw);

NavState nav_update(NavContext *ctx,
                    float cx, float cy, float cyaw,
                    float dt, WheelSpeeds *out);

void nav_reset(NavContext *ctx, WheelSpeeds *out);

#endif /* NAVIGATION_H */
