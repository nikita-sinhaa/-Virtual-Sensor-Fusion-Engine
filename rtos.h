
#ifndef RTOS_H
#define RTOS_H

void task_accel_reader();
void task_gyro_reader();
void task_mag_reader();
void task_fusion_estimator();
void task_logger();

void run_scheduler();

#endif
