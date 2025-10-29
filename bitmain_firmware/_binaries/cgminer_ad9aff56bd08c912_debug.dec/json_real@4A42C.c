json_t *__fastcall json_real(double value)
{
  double v1; // d0
  json_t *result; // r0

  if ( fabs(v1) > 1.79769313e308 )
    return 0;
  result = (json_t *)jsonp_malloc(0x10u);
  if ( result )
  {
    *(double *)&result[1] = v1;
    *result = (json_t)0x100000004LL;
  }
  return result;
}
