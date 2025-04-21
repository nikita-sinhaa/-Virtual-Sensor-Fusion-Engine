
#ifndef FUSION_H
#define FUSION_H

typedef struct {
    float ax, ay, az;
    float gx, gy, gz;
    float mx, my, mz;
} SensorData;

typedef struct {
    float pitch;
    float roll;
    float yaw;
} Orientation;

void complementary_filter(SensorData data, Orientation* orientation);

#endif
