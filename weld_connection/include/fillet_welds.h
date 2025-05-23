#ifndef FILLET_WELDS
#define FILLET_WELDS

#ifdef __cplusplus
extern "C"
{
#endif

double calc_area_base_metal_fillet(double beta_f , int kf, int lw);
double calc_area_weld_metal_fillet(double beta_z , int kf, int lw);

#ifdef __cplusplus
}
#endif

#endif // FILLET_WELDS