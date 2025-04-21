
#include <stdio.h>
#include <stdlib.h>
#include "fusion.h"

#define SAMPLES 1000

float accel[SAMPLES][3], gyro[SAMPLES][3], mag[SAMPLES][3];
Orientation orientation = {0};

void load_data(const char* file, float arr[SAMPLES][3]) {
    FILE* f = fopen(file, "r");
    for (int i = 0; i < SAMPLES; i++) {
        fscanf(f, "%f,%f,%f\n", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
    fclose(f);
}

int main() {
    load_data("../data/accel_data.csv", accel);
    load_data("../data/gyro_data.csv", gyro);
    load_data("../data/mag_data.csv", mag);

    FILE* fout = fopen("../output/orientation_log.csv", "w");
    fprintf(fout, "Time,Pitch,Roll,Yaw\n");

    for (int i = 0; i < SAMPLES; i++) {
        SensorData data = {
            accel[i][0], accel[i][1], accel[i][2],
            gyro[i][0], gyro[i][1], gyro[i][2],
            mag[i][0], mag[i][1], mag[i][2]
        };
        complementary_filter(data, &orientation);
        fprintf(fout, "%d,%.2f,%.2f,%.2f\n", i, orientation.pitch, orientation.roll, orientation.yaw);
    }

    fclose(fout);
    printf("Orientation log saved to orientation_log.csv\n");
    return 0;
}
