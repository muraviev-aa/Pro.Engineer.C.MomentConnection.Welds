#include "groove_welds.h"

/**
  * @brief Вычисляет площадь св. шва по металлу шва.
  * @param h [double] Глубина разделки кромок (миллиметры).
  * @param lw [double] Длина св. шва (миллиметры).
  * @param k_lw [int] Флаг для определения расчетной длины св. шва
  * (k_lw = 1, используются выводные планки; k_lw = 0, выводные планки не используются).
  * @retval [double] Площадь сварного шва в квадратных миллиметрах.
  */
double calculated_area_base_metal(double h, double lw, int k_lw)
{
    return (k_lw == 1) ? (2.6 * h * lw) : (2.6 * h * (lw - 10));
}

/**
  * @brief Вычисляет площадь св. шва по границе сплавления шва.
  * @param h [double] Глубина разделки кромок (миллиметры).
  * @param lw [double] Длина св. шва (миллиметры).
  * @param k_lw [int] Флаг для определения расчетной длины св. шва
  * (k_lw = 1, используются выводные планки; k_lw = 0, выводные планки не используются).
  * @retval [double] Площадь сварного шва в квадратных миллиметрах.
  */
double calculated_area_weld_metal(double h, double lw, int k_lw)
{
    return (k_lw == 1) ? (2.8 * h * lw) : (2.8 * h * (lw - 10));
}