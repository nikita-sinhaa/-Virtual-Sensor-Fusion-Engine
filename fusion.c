
#include "fusion.h"
#include <math.h>

void complementary_filter(SensorData data, Orientation* orientation) {
    float alpha = 0.98;
    float dt = 0.01;  // 100 Hz

    float acc_pitch = atan2(data.ay, sqrt(data.ax * data.ax + data.az * data.az)) * 180 / 3.14159;
    float acc_roll = atan2(-data.ax, data.az) * 180 / 3.14159;

    orientation->pitch = alpha * (orientation->pitch + data.gx * dt) + (1 - alpha) * acc_pitch;
    orientation->roll = alpha * (orientation->roll + data.gy * dt) + (1 - alpha) * acc_roll;
    orientation->yaw += data.gz * dt;
}
