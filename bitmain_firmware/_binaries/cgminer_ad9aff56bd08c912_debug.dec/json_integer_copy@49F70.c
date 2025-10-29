json_t *__fastcall json_integer_copy(const json_t *integer)
{
  json_t v1; // r4
  json_t *result; // r0

  if ( integer && integer->type == JSON_INTEGER )
    v1 = integer[1];
  else
    v1 = 0;
  result = (json_t *)jsonp_malloc(0x10u);
  if ( result )
  {
    result[1] = v1;
    *result = (json_t)0x100000003LL;
  }
  return result;
}
