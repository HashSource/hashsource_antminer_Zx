// local variable allocation has failed, the output may be wrong!
double __fastcall json_number_value(const json_t *json)
{
  double result; // r0

  if ( json && json->type == JSON_INTEGER )
    *(double *)&json = (double)(__int64)json[1];
  LODWORD(result) = json;
  return result;
}
