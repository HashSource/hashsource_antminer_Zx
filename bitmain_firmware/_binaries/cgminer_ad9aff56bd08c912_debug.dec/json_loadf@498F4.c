json_t *__fastcall json_loadf(FILE *input, size_t flags, json_error_t *error)
{
  const char *v3; // r4
  const char *v4; // r3
  const char *v8; // r1
  json_t *v9; // r4
  const char *v11; // r2
  lex_t lex; // [sp+0h] [bp-40h] BYREF

  LOWORD(v3) = -19364;
  LOWORD(v4) = -19356;
  if ( (FILE *)stdin == input )
  {
    HIWORD(v3) = (unsigned int)"cted" >> 16;
    v8 = v3;
  }
  else
  {
    HIWORD(v4) = (unsigned int)"<string>" >> 16;
    v8 = v4;
  }
  jsonp_error_init(error, v8);
  if ( input )
  {
    v9 = 0;
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
      v9 = parse_json(&lex, flags, error);
      lex_close(&lex);
    }
  }
  else
  {
    LOWORD(v11) = -19392;
    HIWORD(v11) = (unsigned int)"{' expected" >> 16;
    error_set(error, 0, v11);
    return 0;
  }
  return v9;
}
