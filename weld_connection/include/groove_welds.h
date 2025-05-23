#ifndef GROOVE_WELDS
#define GROOVE_WELDS

#ifdef __cplusplus
extern "C"
{
#endif

double calc_area_base_metal_groove(double h, double lw, int k_lw);
double calc_area_weld_metal_groove(double h, double lw, int k_lw);

#ifdef __cplusplus
}
#endif

#endif // GROOVE_WELDS