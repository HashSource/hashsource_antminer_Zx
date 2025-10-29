int __fastcall strbuffer_init(strbuffer_t *strbuff)
{
  char *v2; // r0

  strbuff->length = 0;
  strbuff->size = 16;
  v2 = (char *)jsonp_malloc(0x10u);
  strbuff->value = v2;
  if ( !v2 )
    return -1;
  *v2 = 0;
  return 0;
}
