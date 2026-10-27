/**
 * @file sensor.h
 * @brief Перевірка температури датчика.
 */
#ifndef SENSOR_H
#define SENSOR_H

#define TEMP_WARN_C 70
#define TEMP_CRITICAL_C 85

/** Рівень температури датчика. */
typedef enum {
    TEMP_OK,
    TEMP_WARN,
    TEMP_CRITICAL,
} TempLevel;

/**
 * @brief Визначає рівень температури датчика.
 *
 * @param[in] temp_c Температура в градусах Цельсія.
 *
 * @return TEMP_OK, TEMP_WARN або TEMP_CRITICAL.
 */
TempLevel sensor_check_temp(int temp_c);

#endif /* SENSOR_H */
