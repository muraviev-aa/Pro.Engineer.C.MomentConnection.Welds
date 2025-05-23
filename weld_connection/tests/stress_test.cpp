#include <gtest/gtest.h>
#include "../include/stress.h"

// тестируем функцию stress_weld_metal
TEST(StressTest, WeldMetal) {
    // C345 Run = 480 Н/мм^2 (толщина до 10 мм)
    EXPECT_DOUBLE_EQ(stress_weld_metal(480), 0.45 * 480);
    // C255 Run = 380 Н/мм^2 (толщина до 10 мм)
    EXPECT_DOUBLE_EQ(stress_weld_metal(380), 0.45 * 380);
}