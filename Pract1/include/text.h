/**
 * @file text.h
 * @brief Безпечна робота з рядками.
 */
#ifndef TEXT_H
#define TEXT_H

#include <stddef.h>

/**
 * @brief Копіює рядок у буфер фіксованого розміру.
 *
 * @param[out] dst  Буфер призначення.
 * @param[in]  src  Рядок-джерело, не NULL.
 * @param[in]  size Розмір dst у байтах.
 *
 * @retval  0 Рядок скопійовано повністю.
 * @retval -1 Рядок обрізано або аргументи некоректні.
 */
int text_copy(char *dst, const char *src, size_t size);

#endif /* TEXT_H */
