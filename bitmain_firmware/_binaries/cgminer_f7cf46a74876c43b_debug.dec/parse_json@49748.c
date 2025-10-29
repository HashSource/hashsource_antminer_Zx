// Alternative name is 'parse_json.constprop.6'
json_t *__fastcall parse_json(lex_t *lex, size_t flags, json_error_t *error)
{
  json_t *v6; // r6
  size_t refcount; // r3
  size_t v9; // r3
  json_t *v10; // r0

  lex_scan(lex, error);
  v6 = (json_t *)(flags & 4);
  if ( (flags & 4) == 0 && (lex->token & 0xFFFFFFDF) != 0x5B )
  {
    error_set(error, lex, "'[' or '{' expected");
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
      error_set(error, lex, "end of file expected");
      refcount = v6->refcount;
      if ( refcount != -1 )
      {
        v9 = refcount - 1;
        v6->refcount = v9;
        if ( !v9 )
        {
          v10 = v6;
          v6 = 0;
          json_delete(v10);
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
