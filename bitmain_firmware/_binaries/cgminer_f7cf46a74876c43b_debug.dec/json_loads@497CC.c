json_t *__fastcall json_loads(const char *string, size_t flags, json_error_t *error)
{
  json_t *v6; // r4
  string_data_t stream_data; // [sp+0h] [bp-4Ch] BYREF
  lex_t lex; // [sp+8h] [bp-44h] BYREF

  jsonp_error_init(error, "<string>");
  if ( string )
  {
    v6 = 0;
    stream_data.data = string;
    lex.stream.get = string_get;
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
      v6 = parse_json(&lex, flags, error);
      lex_close(&lex);
    }
  }
  else
  {
    error_set(error, 0, "wrong arguments");
    return 0;
  }
  return v6;
}
