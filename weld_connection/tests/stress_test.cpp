#include <gtest/gtest.h>
#include "../include/stress.h"

// тестируем функцию stress_weld_metal
TEST(StressTest, WeldMetal) {
    // C345 Run = 480 Н/мм^2 (толщина до 10 мм)
    EXPECT_DOUBLE_EQ(stress_weld_metal(480), 0.45 * 480);
    // C255 Run = 380 Н/мм^2 (толщина до 10 мм)
    EXPECT_DOUBLE_EQ(stress_weld_metal(380), 0.45 * 380);
}

// тестируем функцию stress_shear_metal
TEST(StressTest, ShearMetal) {
    // C345 Ry = 340 Н/мм^2 (толщина до 10 мм)
    EXPECT_DOUBLE_EQ(stress_shear_metal(340), 0.58 * 340);
    // C255 Run = 250 Н/мм^2 (толщина до 10 мм)
    EXPECT_DOUBLE_EQ(stress_shear_metal(250), 0.58 * 250);
}