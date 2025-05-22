#ifndef GROOVE_WELDS //уникальный макрос защиты
#define GROOVE_WELDS

#ifdef __cplusplus
extern "C"
{
#endif

double calculated_area_base_metal(double h, double lw, int k_lw);
double calculated_area_weld_metal(double h, double lw, int k_lw);

#ifdef __cplusplus
}
#endif

#endif // GROOVE_WELDS