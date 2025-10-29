char *__fastcall set_float_100_to_250(const char *arg, float *i)
{
  char *result; // r0

  result = opt_set_floatval(arg, i);
  if ( !result )
  {
    if ( *i >= 100.0 )
    {
      if ( *i > 250.0 )
        return "Value out of range";
    }
    else
    {
      return "Value out of range";
    }
  }
  return result;
}
