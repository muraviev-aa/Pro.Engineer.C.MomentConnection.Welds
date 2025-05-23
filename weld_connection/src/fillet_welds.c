#include "fillet_welds.h"

/**
  * @brief Вычисляет площадь углового св. шва по металлу шва.
  * @param beta_f [double] Коэффициент перехода от катета углового шва к расчетному сечению
  * по металлу шва (б/р).
  * @param kf [int] Катет св. шва (мм).
  * @param lw [double] Длина св. шва (мм).
  * @retval [double] Площадь сварного шва (мм^2).
  */
double calc_area_base_metal_fillet(double beta_f , int kf, int lw)
{
    return beta_f * kf * (lw - 10);
}

/**
  * @brief Вычисляет площадь углового св. шва по металлу границы сплавления шва.
  * @param beta_z [double] Коэффициент перехода от катета углового шва к расчетному сечению
  * по металлу границы сплавления (б/р).
  * @param kf [int] Катет св. шва (мм).
  * @param lw [double] Длина св. шва (мм).
  * @retval [double] Площадь сварного шва (мм^2).
  */
double calc_area_weld_metal_fillet(double beta_z , int kf, int lw)
{
    return beta_z * kf * (lw - 10);
}