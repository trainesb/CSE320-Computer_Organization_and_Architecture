/*******************************************************************************
  Project05
  Ben Traines
  06/04/2018
*******************************************************************************/


#include "proj05.support.c"



int main()
{
  float inf=get_infinity();
  float nan=get_nan();
  float max_norm = get_max_normal();
  float min_norm = get_min_normal();
  float max_denorm = get_max_denormal();
  float min_denorm = get_min_denormal();
  
  union sp_object A, B, C, D, E, F;
  A.frep = inf;
  B.frep = nan;
  C.frep = max_norm;
  D.frep = min_norm;
  E.frep = max_denorm;
  F.frep =  min_denorm;
  
  printf("inf: %.02f\n", A.frep);
  printf("nan: %.04f\n", B.frep);
  printf("max_norm: %.08f\n", C.frep);
  printf("min_norm: %.09f\n", D.frep);
  printf("max_denorm: %.10f\n", E.frep);
  printf("min_denorm: %.12f\n", F.frep);




  
  float negative = -10, pos = 10;
  int neg=is_negative(negative);
  printf("is negative: %d\n", neg);
  neg=is_negative(pos);
  printf("is negative: %d\n", neg);
  
  float infin = get_infinity(), no_infin = 13.0;
  int is_inf=is_infinity(infin);
  printf("is Infinity: %d\n", is_inf);
  is_inf=is_infinity(no_infin);
  printf("is Infinity: %d\n", is_inf);
  
  float yes_nan = get_nan(), no_nan = 13.0;
  int is_n = is_nan(yes_nan);
  printf("is NaN: %d\n", is_n);
  is_n = is_nan(no_nan);
  printf("is NaN: %d\n", is_n);
  
  float z = 0.0, not_z = 1;
  int zero = is_zero(z);
  printf("is Zero: %d\n", zero);
  zero = is_zero(not_z);
  printf("is Zero: %d\n", zero);
  
  union sp_object denum;
  denum.irep = 0x007fffff;
  int denorm = is_denormal(denum.frep);
  printf("is Denormal: %d\n", denorm);
  float notdenum = 1;
  denorm = is_denormal(notdenum);
  printf("is Denormal: %d\n", denorm);
  
  float c = 12, abss = -12;
  float negated = negate(c);
  printf("negated: %f\n", negated);
  float abs = absolute(abss);
  printf("Absolute: %f\n", abs);

}

