#include <gtest/gtest.h>
#include "../include/fillet_welds.h"

// Тестируем функцию calc_area_base_metal_fillet
TEST(FilletWeldsCalculatedAreaBaseMetalTest, AccuracyHundredths)
{
    ASSERT_NEAR(calc_area_base_metal_fillet(0.9, 6, 100), 486.0, 0.01);
    ASSERT_NEAR(calc_area_base_metal_fillet(0.8, 10, 50), 320.0, 0.01);
}

TEST(FilletWeldsCalculatedAreaBaseMetalTest, BasicCases) {
    EXPECT_DOUBLE_EQ(calc_area_base_metal_fillet(1.0, 10, 20), 1.0 * 10 * (20 - 10));
    EXPECT_DOUBLE_EQ(calc_area_base_metal_fillet(0.9, 6, 30), 0.9 * 6 * (30 - 10));
}

TEST(FilletWeldsCalculatedAreaBaseMetalTest, EdgeCases)
{
    EXPECT_DOUBLE_EQ(calc_area_base_metal_fillet(1.0, 10, 10), 0.0); // lw = 10
    EXPECT_DOUBLE_EQ(calc_area_base_metal_fillet(0.0, 10, 20), 0.0); // beta_f = 0
    EXPECT_DOUBLE_EQ(calc_area_base_metal_fillet(1.5, 0, 20), 0.0); // kf = 0
}

// Тестируем функцию calc_area_weld_metal_fillet
TEST(FilletWeldsCalculatedAreaWeldMetalTest, AccuracyHundredths)
{
    ASSERT_NEAR(calc_area_weld_metal_fillet(1.05, 8, 70), 504.0, 0.01);
    ASSERT_NEAR(calc_area_weld_metal_fillet(1.0, 6, 55), 270.0, 0.01);
}

TEST(FilletWeldsCalculatedAreaWeldMetalTest, BasicCases) {
    EXPECT_DOUBLE_EQ(calc_area_weld_metal_fillet(1.0, 10, 20), 1.0 * 10 * (20 - 10));
    EXPECT_DOUBLE_EQ(calc_area_weld_metal_fillet(0.9, 6, 30), 0.9 * 6 * (30 - 10));
}

TEST(FilletWeldsCalculatedAreaWeldMetalTest, EdgeCases)
{
    EXPECT_DOUBLE_EQ(calc_area_weld_metal_fillet(1.0, 10, 10), 0.0); // lw = 10
    EXPECT_DOUBLE_EQ(calc_area_weld_metal_fillet(0.0, 10, 20), 0.0); // beta_z = 0
    EXPECT_DOUBLE_EQ(calc_area_weld_metal_fillet(1.5, 0, 20), 0.0); // kf = 0
}