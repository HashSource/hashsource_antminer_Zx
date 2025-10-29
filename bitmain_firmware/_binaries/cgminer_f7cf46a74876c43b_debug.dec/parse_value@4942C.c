// local variable allocation has failed, the output may be wrong!
json_t *__fastcall parse_value(lex_t *lex, size_t flags, json_error_t *error)
{
  lex_t *v3; // r4
  int token; // r3
  size_t v5; // r1
  size_t v6; // r9
  json_t *v8; // r6
  int v10; // r3
  char *string; // r8
  json_t *v12; // r0
  json_t *v13; // r7
  size_t v14; // r3
  size_t v15; // r3
  size_t v16; // r3
  int v17; // r3
  int v18; // r3
  int appended; // r0
  size_t refcount; // r3
  bool v21; // zf
  size_t v22; // r3
  int v23; // r3
  json_t *v24; // r0
  size_t v25; // r3
  size_t v26; // r3
  json_t *v27; // r0
  char v28; // r1
  double v29; // r0
  size_t v30; // r3
  double value; // [sp+0h] [bp-Ch] BYREF

  v3 = lex;
  token = lex->token;
  lex = (lex_t *)257;
  v6 = v5;
  if ( token == 257 )
  {
    if ( (v28 & 8) == 0 )
      return json_integer(v3->value.integer);
    LODWORD(v29) = jsonp_strtod(&v3->saved_text, &value);
    if ( !LODWORD(v29) )
      return json_real(v29);
    error_set(error, v3, "real number overflow");
    return 0;
  }
  if ( token < 258 )
  {
    if ( token == 91 )
    {
      v8 = json_array();
      if ( v8 )
      {
        lex_scan(v3, error);
        v18 = v3->token;
        if ( v18 == 93 )
          return v8;
        if ( v18 )
        {
          while ( 1 )
          {
            v24 = parse_value(v3, v6, error);
            v13 = v24;
            if ( !v24 )
              break;
            if ( v24->refcount != -1 )
              ++v24->refcount;
            appended = json_array_append_new(v8, v24);
            refcount = v13->refcount;
            if ( appended )
            {
              if ( refcount != -1 )
              {
LABEL_62:
                v30 = refcount - 1;
                v13->refcount = v30;
                if ( !v30 )
                  json_delete(v13);
              }
              goto LABEL_51;
            }
            v21 = refcount == -1;
            v22 = refcount - 1;
            if ( !v21 )
            {
              v13->refcount = v22;
              if ( !v22 )
                json_delete(v13);
            }
            lex_scan(v3, error);
            v23 = v3->token;
            if ( v23 != 44 )
            {
              if ( v23 == 93 )
                return v8;
              goto LABEL_60;
            }
            lex_scan(v3, error);
            if ( !v3->token )
              goto LABEL_60;
          }
        }
        else
        {
LABEL_60:
          error_set(error, v3, "']' expected");
        }
        goto LABEL_51;
      }
    }
    else if ( token <= 91 )
    {
      if ( token != -1 )
        goto LABEL_37;
      error_set(error, v3, "invalid token");
    }
    else
    {
      if ( token != 123 )
      {
        if ( token == 256 )
          return json_string_nocheck(v3->value.string);
        goto LABEL_37;
      }
      v8 = (json_t *)json_object();
      if ( v8 )
      {
        lex_scan(v3, error);
        v10 = v3->token;
        if ( v10 == 125 )
          return v8;
        if ( v10 != 256 )
        {
LABEL_64:
          error_set(error, v3, "string or '}' expected");
          goto LABEL_51;
        }
        string = v3->value.string;
        v3->value.string = 0;
        if ( string )
        {
          while ( 1 )
          {
            if ( (v6 & 1) != 0 && json_object_get(v8, string) )
            {
              jsonp_free(string);
              error_set(error, v3, "duplicate object key");
              goto LABEL_51;
            }
            lex_scan(v3, error);
            if ( v3->token != 58 )
            {
              jsonp_free(string);
              error_set(error, v3, "':' expected");
              goto LABEL_51;
            }
            lex_scan(v3, error);
            v12 = parse_value(v3, v6, error);
            v13 = v12;
            if ( !v12 )
            {
              jsonp_free(string);
              goto LABEL_51;
            }
            v14 = v12->refcount;
            if ( v14 != -1 )
              v12->refcount = v14 + 1;
            if ( json_object_set_new_nocheck(v8, string, v12) )
            {
              jsonp_free(string);
              refcount = v13->refcount;
              if ( refcount != -1 )
                goto LABEL_62;
              goto LABEL_51;
            }
            v15 = v13->refcount;
            if ( v15 != -1 )
            {
              v16 = v15 - 1;
              v13->refcount = v16;
              if ( !v16 )
                json_delete(v13);
            }
            jsonp_free(string);
            lex_scan(v3, error);
            v17 = v3->token;
            if ( v17 != 44 )
              break;
            lex_scan(v3, error);
            if ( v3->token != 256 )
              goto LABEL_64;
            string = v3->value.string;
            v3->value.string = 0;
            if ( !string )
              return 0;
          }
          if ( v17 == 125 )
            return v8;
          error_set(error, v3, "'}' expected");
LABEL_51:
          v25 = v8->refcount;
          if ( v25 != -1 )
          {
            v26 = v25 - 1;
            v8->refcount = v26;
            if ( !v26 )
            {
              v27 = v8;
              v8 = 0;
              json_delete(v27);
              return v8;
            }
          }
        }
      }
    }
    return 0;
  }
  if ( token == 259 )
    return json_true();
  if ( token <= 258 )
    return json_real(*(double *)&lex);
  if ( token == 260 )
    return json_false();
  if ( token == 261 )
    return json_null();
LABEL_37:
  error_set(error, v3, "unexpected token");
  return 0;
}
