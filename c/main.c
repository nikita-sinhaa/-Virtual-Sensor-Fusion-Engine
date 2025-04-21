
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "fusion.h"

double get_time_ms();
int check_deadline(double exec_time, double deadline_ms);
void log_metrics(FILE* f, int t, const char* task, double exec_time, double deadline, const char* status);

#define SAMPLES 1000
#define FUSION_DEADLINE 10.0

float accel[SAMPLES][3], gyro[SAMPLES][3], mag[SAMPLES][3];
Orientation orientation = {0};

void load_data(const char* file, float arr[SAMPLES][3]) {
    FILE* f = fopen(file, "r");
    for (int i = 0; i < SAMPLES; i++)
        fscanf(f, "%f,%f,%f\n", &arr[i][0], &arr[i][1], &arr[i][2]);
    fclose(f);
}

int main() {
    load_data("../data/accel_data.csv", accel);
    load_data("../data/gyro_data.csv", gyro);
    load_data("../data/mag_data.csv", mag);

    FILE* fout = fopen("../output/orientation_log.csv", "w");
    FILE* flog = fopen("../output/metrics_log.csv", "w");
    fprintf(fout, "Time,Pitch,Roll,Yaw\n");
    fprintf(flog, "Time(ms),Task,Exec_Time(ms),Deadline(ms),Status\n");

    for (int i = 0; i < SAMPLES; i++) {
        double start = get_time_ms();

        SensorData data = {
            accel[i][0], accel[i][1], accel[i][2],
            gyro[i][0], gyro[i][1], gyro[i][2],
            mag[i][0], mag[i][1], mag[i][2]
        };
        complementary_filter(data, &orientation);

        double end = get_time_ms();
        double exec_time = end - start;

        fprintf(fout, "%d,%.2f,%.2f,%.2f\n", i, orientation.pitch, orientation.roll, orientation.yaw);

        const char* status = check_deadline(exec_time, FUSION_DEADLINE) ? "Met" : "Missed";
        log_metrics(flog, i, "Fusion", exec_time, FUSION_DEADLINE, status);
    }

    fclose(fout);
    fclose(flog);
    printf("Enhanced orientation and metrics logs saved.\n");
    return 0;
}
