double __fastcall json_real_value(const json_t *json)
{
  double result; // r0

  LODWORD(result) = json;
  return result;
}
