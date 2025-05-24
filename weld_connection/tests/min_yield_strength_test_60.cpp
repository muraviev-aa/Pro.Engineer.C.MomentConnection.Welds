#include <gtest/gtest.h>
#include "../include/min_yield_strength_60.h"
#include "../include/stress.h"

// Тестируем функцию designed_strength_60
TEST(FlangeDesignedStrengthTest, AccuracyHundredths)
{
    // Двутавр 70Ш8
    ASSERT_NEAR(designed_strength_60(315, 64, 317), 3834432, 0.01);
}

// Тестируем функцию designed_shear_60
TEST(WallDesignedShearTest, AccuracyHundredths)
{
    double r_s = stress_shear_metal(300);
    // Двутавр 70Ш8
    ASSERT_NEAR(designed_shear_60(r_s, 38, 64, 780), 2586614.4, 0.01);
}