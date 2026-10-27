/**
 * @file stats.h
 * @brief Статистичні функції для масивів цілих чисел.
 */
#ifndef STATS_H
#define STATS_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Сума додатних елементів масиву.
 *
 * @param[in] values Масив чисел; NULL дає результат 0.
 * @param[in] count  Кількість елементів у масиві.
 *
 * @return Сума додатних елементів.
 */
int64_t sum_positive(const int *values, size_t count);

#endif /* STATS_H */
