#include <string.h>

#include "text.h"

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
