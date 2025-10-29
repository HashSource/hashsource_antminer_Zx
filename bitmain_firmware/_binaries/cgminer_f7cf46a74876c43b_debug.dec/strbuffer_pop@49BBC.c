char __fastcall strbuffer_pop(strbuffer_t *strbuff)
{
  size_t length; // r3
  char *value; // r2
  size_t v3; // r3
  char result; // r0

  length = strbuff->length;
  if ( !length )
    return 0;
  value = strbuff->value;
  v3 = length - 1;
  strbuff->length = v3;
  result = value[v3];
  value[v3] = 0;
  return result;
}
