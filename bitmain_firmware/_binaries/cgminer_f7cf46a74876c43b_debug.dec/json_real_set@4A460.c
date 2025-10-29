int __fastcall json_real_set(json_t *json, double value)
{
  double v3; // d0

  if ( !json || json->type != JSON_REAL || fabs(v3) > 1.79769313e308 )
    return -1;
  *(double *)&json[1] = v3;
  return 0;
}
