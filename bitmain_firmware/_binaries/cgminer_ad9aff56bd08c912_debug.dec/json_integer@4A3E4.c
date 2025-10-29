json_t *__fastcall json_integer(json_int_t value)
{
  json_t *result; // r0

  result = (json_t *)jsonp_malloc(0x10u);
  if ( result )
  {
    result[1] = (json_t)value;
    *result = (json_t)0x100000003LL;
  }
  return result;
}
