#include <gtest/gtest.h>
#include "../include/groove_welds.h"

// Тестируем функцию calculated_area_base_metal
TEST(GrooveWeldsCalculatedAreaBaseMetalTest, AccuracyHundredths)
{
    // с выводными планками (k_lw = 1)
    ASSERT_NEAR(calculated_area_base_metal(6.7, 115, 1), 2003.3, 0.01);
    // без выводных планок (k_lw = 0)
    ASSERT_NEAR(calculated_area_base_metal(5.3, 155, 0), 1998.1, 0.01);
}

TEST(GrooveWeldsCalculatedAreaBaseMetalTest, WithOutputPlanks) {
    // с выводными планками (k_lw = 1)
    EXPECT_DOUBLE_EQ(calculated_area_base_metal(10.0, 20.0, 1), 2.6 * 10.0 * 20.0);
    EXPECT_DOUBLE_EQ(calculated_area_base_metal(5.0, 15.0, 1), 2.6 * 5.0 * 15.0);
}

TEST(GrooveWeldsCalculatedAreaBaseMetalTest, WithoutOutputPlanks) {
    // без выводных планок (k_lw = 0)
    EXPECT_DOUBLE_EQ(calculated_area_base_metal(10.0, 20.0, 0), 2.6 * 10.0 * (20.0 - 10));
    EXPECT_DOUBLE_EQ(calculated_area_base_metal(5.0, 15.0, 0), 2.6 * 5.0 * (15.0 - 10));
}

TEST(GrooveWeldsCalculatedAreaBaseMetalTest, EdgeCases) {
    // крайние случаи
    EXPECT_DOUBLE_EQ(calculated_area_base_metal(0.0, 20.0, 1), 0.0); // h = 0
    EXPECT_DOUBLE_EQ(calculated_area_base_metal(10.0, 10.0, 1), 2.6 * 10.0 * 10.0); // lw = h
    EXPECT_DOUBLE_EQ(calculated_area_base_metal(10.0, 10.0, 0), 2.6 * 10.0 * (10.0 - 10)); // lw = h
}

// Тестируем функцию calculated_area_weld_metal
TEST(GrooveWeldsCalculatedAreaWeldMetalTest, AccuracyHundredths)
{
    ASSERT_NEAR(calculated_area_weld_metal(6.7, 115, 1), 2157.4, 0.01);
    ASSERT_NEAR(calculated_area_weld_metal(5.3, 155, 0), 2151.8, 0.01);
}