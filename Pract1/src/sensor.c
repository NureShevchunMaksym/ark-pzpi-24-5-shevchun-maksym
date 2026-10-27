#include "sensor.h"

TempLevel sensor_check_temp(int temp_c)
{
    if (temp_c > TEMP_CRITICAL_C) {
        return TEMP_CRITICAL;
    }
    if (temp_c > TEMP_WARN_C) {
        return TEMP_WARN;
    }
    return TEMP_OK;
}
