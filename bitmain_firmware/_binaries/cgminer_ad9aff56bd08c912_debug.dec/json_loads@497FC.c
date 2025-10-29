json_t *__fastcall json_loads(const char *string, size_t flags, json_error_t *error)
{
  const char *v5; // r1
  int (*v7)(void *); // r3
  json_t *v8; // r4
  const char *v10; // r2
  string_data_t stream_data; // [sp+0h] [bp-4Ch] BYREF
  lex_t lex; // [sp+8h] [bp-44h] BYREF

  LOWORD(v5) = -19404;
  HIWORD(v5) = (unsigned int)"" >> 16;
  jsonp_error_init(error, v5);
  if ( string )
  {
    LOWORD(v7) = -29855;
    v8 = 0;
    HIWORD(v7) = (unsigned int)hashtable_iter_value >> 16;
    stream_data.data = string;
    lex.stream.get = v7;
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
      v8 = parse_json(&lex, flags, error);
      lex_close(&lex);
    }
  }
  else
  {
    LOWORD(v10) = -19392;
    HIWORD(v10) = (unsigned int)"{' expected" >> 16;
    error_set(error, 0, v10);
    return 0;
  }
  return v8;
}
