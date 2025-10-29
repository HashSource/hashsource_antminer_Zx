void __fastcall strbuffer_close(strbuffer_t *strbuff)
{
  char *value; // r0

  value = strbuff->value;
  if ( value )
    jsonp_free(value);
  strbuff->length = 0;
  strbuff->size = 0;
  strbuff->value = 0;
}
