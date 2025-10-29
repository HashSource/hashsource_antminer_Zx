void __fastcall strbuffer_clear(strbuffer_t *strbuff)
{
  char *value; // r2

  value = strbuff->value;
  strbuff->length = 0;
  *value = 0;
}
