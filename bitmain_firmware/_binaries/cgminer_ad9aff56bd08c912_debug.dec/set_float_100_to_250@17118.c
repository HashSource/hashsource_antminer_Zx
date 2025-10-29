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
      LOWORD(result) = -2944;
      HIWORD(result) = (unsigned int)" be HH:MM" >> 16;
    }
  }
  return result;
}
