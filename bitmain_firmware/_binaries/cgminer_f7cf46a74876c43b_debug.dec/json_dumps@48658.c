char *__fastcall json_dumps(const json_t *json, size_t flags)
{
  char *v4; // r4
  const char *v6; // r0
  strbuffer_t strbuff; // [sp+4h] [bp-Ch] BYREF

  v4 = 0;
  if ( !strbuffer_init(&strbuff) )
  {
    v4 = 0;
    if ( !json_dump_callback(json, dump_to_strbuffer, &strbuff, flags) )
    {
      v6 = strbuffer_value(&strbuff);
      v4 = jsonp_strdup(v6);
    }
    strbuffer_close(&strbuff);
  }
  return v4;
}
