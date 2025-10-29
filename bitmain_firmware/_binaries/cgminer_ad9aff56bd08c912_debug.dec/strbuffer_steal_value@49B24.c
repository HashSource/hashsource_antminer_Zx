char *__fastcall strbuffer_steal_value(strbuffer_t *strbuff)
{
  char *result; // r0

  result = strbuff->value;
  strbuff->value = 0;
  return result;
}
