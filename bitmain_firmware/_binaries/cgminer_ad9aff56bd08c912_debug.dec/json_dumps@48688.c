char *__fastcall json_dumps(const json_t *json, size_t flags)
{
  char *v4; // r4
  json_dump_callback_t v5; // r1
  const char *v7; // r0
  strbuffer_t strbuff; // [sp+4h] [bp-Ch] BYREF

  v4 = 0;
  if ( !strbuffer_init(&strbuff) )
  {
    LOWORD(v5) = 32705;
    v4 = 0;
    HIWORD(v5) = (unsigned int)&loc_47F90 >> 16;
    if ( !json_dump_callback(json, v5, &strbuff, flags) )
    {
      v7 = strbuffer_value(&strbuff);
      v4 = jsonp_strdup(v7);
    }
    strbuffer_close(&strbuff);
  }
  return v4;
}
