// Alternative name is 'parse_json.constprop.6'
json_t *__fastcall parse_json(lex_t *lex, size_t flags, json_error_t *error)
{
  json_t *v6; // r6
  const char *v8; // r2
  size_t refcount; // r3
  size_t v10; // r3
  const char *v11; // r2
  json_t *v12; // r0

  lex_scan(lex, error);
  v6 = (json_t *)(flags & 4);
  if ( (flags & 4) == 0 && (lex->token & 0xFFFFFFDF) != 0x5B )
  {
    LOWORD(v11) = -19448;
    HIWORD(v11) = (unsigned int)"lid token" >> 16;
    error_set(error, lex, v11);
    return v6;
  }
  v6 = parse_value(lex, flags, error);
  if ( !v6 )
    return 0;
  if ( (flags & 2) == 0 )
  {
    lex_scan(lex, error);
    if ( lex->token )
    {
      LOWORD(v8) = -19428;
      HIWORD(v8) = (unsigned int)"ed token" >> 16;
      error_set(error, lex, v8);
      refcount = v6->refcount;
      if ( refcount != -1 )
      {
        v10 = refcount - 1;
        v6->refcount = v10;
        if ( !v10 )
        {
          v12 = v6;
          v6 = 0;
          json_delete(v12);
          return v6;
        }
      }
      return 0;
    }
  }
  if ( error )
    error->position = lex->stream.position;
  return v6;
}
