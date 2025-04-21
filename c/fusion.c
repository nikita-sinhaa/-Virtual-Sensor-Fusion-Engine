
#include "fusion.h"
#include <math.h>

void complementary_filter(SensorData data, Orientation* orientation) {
    float dt = 0.01;

    float acc_pitch = atan2(data.ay, sqrt(data.ax * data.ax + data.az * data.az)) * 180 / 3.14159;
    float acc_roll = atan2(-data.ax, data.az) * 180 / 3.14159;

    float acc_magnitude = sqrt(data.ax * data.ax + data.ay * data.ay + data.az * data.az);
    float acc_error = fabs(1.0 - acc_magnitude);  // Ideal = 1g
    float alpha = (acc_error < 0.05) ? 0.98 : 0.90;  // Trust accel less if error is high

    orientation->pitch = alpha * (orientation->pitch + data.gx * dt) + (1 - alpha) * acc_pitch;
    orientation->roll = alpha * (orientation->roll + data.gy * dt) + (1 - alpha) * acc_roll;
    orientation->yaw += data.gz * dt;
}
