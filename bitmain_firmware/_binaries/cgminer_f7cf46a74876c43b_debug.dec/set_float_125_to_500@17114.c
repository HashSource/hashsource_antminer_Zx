char *__fastcall set_float_125_to_500(const char *arg, float *i)
{
  char *result; // r0

  result = opt_set_floatval(arg, i);
  if ( !result )
  {
    if ( *i >= 125.0 )
    {
      if ( *i > 500.0 )
        return "Value out of range";
    }
    else
    {
      return "Value out of range";
    }
  }
  return result;
}
