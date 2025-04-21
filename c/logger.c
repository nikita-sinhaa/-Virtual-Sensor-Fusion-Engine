
#include <stdio.h>
#include "fusion.h"

void log_orientation(FILE* log, int t, Orientation o) {
    fprintf(log, "%d,%.2f,%.2f,%.2f\n", t, o.pitch, o.roll, o.yaw);
}
