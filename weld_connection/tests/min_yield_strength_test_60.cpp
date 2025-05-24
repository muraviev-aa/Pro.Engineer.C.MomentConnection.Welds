#include <gtest/gtest.h>
#include "../include/min_yield_strength_60.h"

// Тестируем функцию designed_strength_60
TEST(FlangeDesignedStrengthTest, AccuracyHundredths)
{
    ASSERT_NEAR(designed_strength_60(315, 64, 317), 3834432, 0.01);
}