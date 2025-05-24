#include "stress.h"

/**
  * @brief Вычисляет Rwz - расчетное сопротивление по металлу границы сплавления.
  * @param r_un [int] Временное сопротивление стали Run (Н/мм^2).
  * @retval [double] Rwz (Н/мм^2)
  */
double stress_weld_metal(int r_un)
{
    return 0.45 * r_un;
}

/**
  * @brief Вычисляет Rs - расчетное сопротивление стали сдвигу.
  * @param r_y [int] Расчетное сопротивление стали (Н/мм^2).
  * @retval [double] Rs (Н/мм^2)
  */
double stress_shear_metal(int r_y)
{
    return 0.58 * r_y;
}