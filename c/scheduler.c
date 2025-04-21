
#include <windows.h>
#include <stdio.h>
#include "fusion.h"

double get_time_ms() {
    LARGE_INTEGER freq, now;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&now);
    return (double)(now.QuadPart) * 1000.0 / freq.QuadPart;
}

int check_deadline(double exec_time, double deadline_ms) {
    return exec_time <= deadline_ms;
}
