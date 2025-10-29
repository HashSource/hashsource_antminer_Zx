json_t *__fastcall json_loadb(const char *buffer, size_t buflen, size_t flags, json_error_t *error)
{
  json_t *v8; // r4
  buffer_data_t stream_data; // [sp+4h] [bp-4Ch] BYREF
  lex_t lex; // [sp+10h] [bp-40h] BYREF

  jsonp_error_init(error, "<buffer>");
  if ( buffer )
  {
    v8 = 0;
    stream_data.data = buffer;
    stream_data.len = buflen;
    lex.stream.get = buffer_get;
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
    error_set(error, 0, "wrong arguments");
    return 0;
  }
  return v8;
}
