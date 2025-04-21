
#include <stdio.h>

void log_metrics(FILE* f, int t, const char* task, double exec_time, double deadline, const char* status) {
    fprintf(f, "%d,%s,%.2f,%.2f,%s\n", t, task, exec_time, deadline, status);
}
