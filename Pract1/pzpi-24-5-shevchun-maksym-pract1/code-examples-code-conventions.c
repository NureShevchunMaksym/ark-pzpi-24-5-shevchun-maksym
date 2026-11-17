/**
 * @file code-examples-code-conventions.c
 * @brief Приклади коду до практичної роботи №1 (конвенції коду мовою C).
 *
 * Збірка та запуск тестів:
 *   gcc -std=c99 -Wall -Wextra code-examples-code-conventions.c -o pract1
 *   ./pract1
 */
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* ======================================================================
 * Приклад 1. Код ДО рефакторинґу: незрозумілі імена, «магічні числа»,
 * відсутні дужки та форматування.
 * ====================================================================== */

int chk(int t) { return t > 85 ? 2 : t > 70; }

int f(int*a,int n){int s=0,i;
for(i=0;i<n;i++)if(a[i]>0)s+=a[i];return s;}

/* ======================================================================
 * Приклад 2. Допоміжні математичні функції (math_utils).
 * ====================================================================== */

/**
 * @brief Обмежує значення діапазоном [min, max].
 *
 * @param[in] value Вхідне значення.
 * @param[in] min   Нижня межа.
 * @param[in] max   Верхня межа.
 *
 * @return Значення, обмежене межами min і max.
 */
int clamp(int value, int min, int max)
{
    if (value < min) {
        return min;
    }
    if (value > max) {
        return max;
    }
    return value;
}

/* ======================================================================
 * Приклад 3. Перевірка температури датчика (sensor) —
 * рефакторинґ функції chk(): іменовані константи та перелік.
 * ====================================================================== */

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

/* ======================================================================
 * Приклад 4. Статистичні функції (stats) —
 * рефакторинґ функції f(): зрозумілі імена, size_t, int64_t, перевірка NULL.
 * ====================================================================== */

/**
 * @brief Сума додатних елементів масиву.
 *
 * @param[in] values Масив чисел; NULL дає результат 0.
 * @param[in] count  Кількість елементів у масиві.
 *
 * @return Сума додатних елементів.
 */
int64_t sum_positive(const int *values, size_t count)
{
    int64_t total = 0;

    if (values == NULL) {
        return 0;
    }
    for (size_t i = 0; i < count; i++) {
        if (values[i] > 0) {
            total += values[i];
        }
    }
    return total;
}

/* ======================================================================
 * Приклад 5. Безпечна робота з рядками (text).
 * ====================================================================== */

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
int text_copy(char *dst, const char *src, size_t size)
{
    size_t len;

    if (dst == NULL || src == NULL || size == 0) {
        return -1;
    }

    len = strlen(src);

    /* strncpy не додає '\0', якщо src довший
       за буфер, тому завершуємо рядок вручну */
    strncpy(dst, src, size - 1);
    dst[size - 1] = '\0';

    return (len < size) ? 0 : -1;
}

/* ======================================================================
 * Приклад 6. Модульні тести за схемою Arrange-Act-Assert.
 * У проєкті використовувався фреймворк Unity; тут — мінімальний
 * аналог TEST_ASSERT_EQUAL_INT, щоб приклад був у одному файлі.
 * ====================================================================== */

static int tests_failed = 0;

#define TEST_ASSERT_EQUAL_INT(expected, actual)                          \
    do {                                                                 \
        int exp_ = (expected);                                           \
        int act_ = (actual);                                             \
        if (exp_ != act_) {                                              \
            printf("%s:%d: FAIL: expected %d, got %d\n",                 \
                   __FILE__, __LINE__, exp_, act_);                      \
            tests_failed++;                                              \
        }                                                                \
    } while (0)

#define RUN_TEST(test)                 \
    do {                               \
        printf("RUN  %s\n", #test);    \
        test();                        \
    } while (0)

void test_clamp_limits_value_to_max(void)
{
    int value = 150;                    /* Arrange */
    int result = clamp(value, 0, 100);  /* Act */
    TEST_ASSERT_EQUAL_INT(100, result); /* Assert */
}

void test_clamp_keeps_value_inside_range(void)
{
    int value = 42;
    int result = clamp(value, 0, 100);
    TEST_ASSERT_EQUAL_INT(42, result);
}

int main(void)
{
    RUN_TEST(test_clamp_limits_value_to_max);
    RUN_TEST(test_clamp_keeps_value_inside_range);

    printf(tests_failed == 0 ? "OK\n" : "FAILED\n");
    return tests_failed == 0 ? 0 : 1;
}
