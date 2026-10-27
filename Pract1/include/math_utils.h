/**
 * @file math_utils.h
 * @brief Допоміжні математичні функції.
 */
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

/**
 * @brief Обмежує значення діапазоном [min, max].
 *
 * @param[in] value Вхідне значення.
 * @param[in] min   Нижня межа.
 * @param[in] max   Верхня межа.
 *
 * @return Значення, обмежене межами min і max.
 */
int clamp(int value, int min, int max);

#endif /* MATH_UTILS_H */
