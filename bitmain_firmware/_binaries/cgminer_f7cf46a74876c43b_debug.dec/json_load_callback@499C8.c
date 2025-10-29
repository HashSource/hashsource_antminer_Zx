json_t *__fastcall json_load_callback(json_load_callback_t callback, void *arg, size_t flags, json_error_t *error)
{
  lex_t lex; // [sp+0h] [bp-454h] BYREF
  callback_data_t stream_data; // [sp+40h] [bp-414h] BYREF

  memset(&stream_data, 0, sizeof(stream_data));
  stream_data.arg = arg;
  stream_data.callback = callback;
  jsonp_error_init(error, "<callback>");
  if ( callback )
  {
    callback = 0;
    lex.stream.get = callback_get;
    lex.stream.line = 1;
    lex.stream.data = &stream_data;
    lex.stream.buffer[0] = 0;
    lex.stream.buffer_pos = 0;
    lex.stream.state = 0;
    lex.stream.column = 0;
    lex.stream.position = 0;
    if ( !strbuffer_init(&lex.saved_text) )
    {
      lex.token = -1;
      callback = (json_load_callback_t)parse_json(&lex, flags, error);
      lex_close(&lex);
    }
  }
  else
  {
    error_set(error, 0, "wrong arguments");
  }
  return (json_t *)callback;
}
