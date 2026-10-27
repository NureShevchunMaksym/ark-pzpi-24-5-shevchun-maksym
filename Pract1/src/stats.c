#include "stats.h"

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
