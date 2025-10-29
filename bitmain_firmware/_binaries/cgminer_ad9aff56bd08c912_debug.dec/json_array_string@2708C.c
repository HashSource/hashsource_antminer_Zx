char *__fastcall json_array_string(json_t *val, unsigned int entry)
{
  char *result; // r0

  result = _json_array_string(val, entry);
  if ( result )
    return j___strdup(result);
  return result;
}
