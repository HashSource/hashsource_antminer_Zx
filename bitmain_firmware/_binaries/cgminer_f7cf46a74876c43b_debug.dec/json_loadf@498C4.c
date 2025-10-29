json_t *__fastcall json_loadf(FILE *input, size_t flags, json_error_t *error)
{
  const char *v6; // r1
  json_t *v7; // r4
  lex_t lex; // [sp+0h] [bp-40h] BYREF

  if ( (FILE *)stdin == input )
    v6 = "<stdin>";
  else
    v6 = "<stream>";
  jsonp_error_init(error, v6);
  if ( input )
  {
    v7 = 0;
    lex.stream.data = input;
    lex.stream.get = (get_func)fgetc;
    lex.stream.buffer[0] = 0;
    lex.stream.buffer_pos = 0;
    lex.stream.state = 0;
    lex.stream.column = 0;
    lex.stream.position = 0;
    lex.stream.line = 1;
    if ( !strbuffer_init(&lex.saved_text) )
    {
      lex.token = -1;
      v7 = parse_json(&lex, flags, error);
      lex_close(&lex);
    }
  }
  else
  {
    error_set(error, 0, "wrong arguments");
    return 0;
  }
  return v7;
}
