json_t *__fastcall json_loadb(const char *buffer, size_t buflen, size_t flags, json_error_t *error)
{
  const char *v6; // r1
  int (*v9)(void *); // r3
  json_t *v10; // r4
  const char *v12; // r2
  buffer_data_t stream_data; // [sp+4h] [bp-4Ch] BYREF
  lex_t lex; // [sp+10h] [bp-40h] BYREF

  LOWORD(v6) = -19376;
  HIWORD(v6) = (unsigned int)"of file expected" >> 16;
  jsonp_error_init(error, v6);
  if ( buffer )
  {
    LOWORD(v9) = -29831;
    v10 = 0;
    HIWORD(v9) = (unsigned int)&loc_48B48 >> 16;
    stream_data.data = buffer;
    stream_data.len = buflen;
    lex.stream.get = v9;
    stream_data.pos = 0;
    lex.stream.buffer[0] = 0;
    lex.stream.buffer_pos = 0;
    lex.stream.state = 0;
    lex.stream.column = 0;
    lex.stream.position = 0;
    lex.stream.data = &stream_data;
    lex.stream.line = 1;
    if ( !strbuffer_init(&lex.saved_text) )
    {
      lex.token = -1;
      v10 = parse_json(&lex, flags, error);
      lex_close(&lex);
    }
  }
  else
  {
    LOWORD(v12) = -19392;
    HIWORD(v12) = (unsigned int)"{' expected" >> 16;
    error_set(error, 0, v12);
    return 0;
  }
  return v10;
}
