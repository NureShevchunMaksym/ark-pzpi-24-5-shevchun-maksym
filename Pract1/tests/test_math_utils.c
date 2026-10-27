#include "math_utils.h"
#include "unity.h"

void setUp(void) {}
void tearDown(void) {}

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
    UNITY_BEGIN();
    RUN_TEST(test_clamp_limits_value_to_max);
    RUN_TEST(test_clamp_keeps_value_inside_range);
    return UNITY_END();
}
