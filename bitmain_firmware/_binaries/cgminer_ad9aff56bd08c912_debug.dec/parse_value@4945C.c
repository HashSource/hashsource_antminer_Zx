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
  const char *v18; // r2
  const char *v19; // r2
  int v20; // r3
  int appended; // r0
  size_t refcount; // r3
  bool v23; // zf
  size_t v24; // r3
  int v25; // r3
  json_t *v26; // r0
  size_t v27; // r3
  size_t v28; // r3
  json_t *v29; // r0
  char v30; // r1
  double v31; // r0
  const char *v32; // r2
  const char *v33; // r2
  size_t v34; // r3
  const char *v35; // r2
  const char *v36; // r2
  const char *v37; // r2
  const char *v38; // r2
  double value; // [sp+0h] [bp-Ch] BYREF

  v3 = lex;
  token = lex->token;
  lex = (lex_t *)257;
  v6 = v5;
  if ( token == 257 )
  {
    if ( (v30 & 8) == 0 )
      return json_integer(v3->value.integer);
    LODWORD(v31) = jsonp_strtod(&v3->saved_text, &value);
    if ( !LODWORD(v31) )
      return json_real(v31);
    LOWORD(v32) = -19604;
    HIWORD(v32) = (unsigned int)"ger" >> 16;
    error_set(error, v3, v32);
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
        v20 = v3->token;
        if ( v20 == 93 )
          return v8;
        if ( v20 )
        {
          while ( 1 )
          {
            v26 = parse_value(v3, v6, error);
            v13 = v26;
            if ( !v26 )
              break;
            if ( v26->refcount != -1 )
              ++v26->refcount;
            appended = json_array_append_new(v8, v26);
            refcount = v13->refcount;
            if ( appended )
            {
              if ( refcount != -1 )
              {
LABEL_62:
                v34 = refcount - 1;
                v13->refcount = v34;
                if ( !v34 )
                  json_delete(v13);
              }
              goto LABEL_51;
            }
            v23 = refcount == -1;
            v24 = refcount - 1;
            if ( !v23 )
            {
              v13->refcount = v24;
              if ( !v24 )
                json_delete(v13);
            }
            lex_scan(v3, error);
            v25 = v3->token;
            if ( v25 != 44 )
            {
              if ( v25 == 93 )
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
          LOWORD(v33) = -19464;
          HIWORD(v33) = (unsigned int)"expected" >> 16;
          error_set(error, v3, v33);
        }
        goto LABEL_51;
      }
    }
    else if ( token <= 91 )
    {
      if ( token != -1 )
        goto LABEL_37;
      LOWORD(v18) = -19500;
      HIWORD(v18) = (unsigned int)"e object key" >> 16;
      error_set(error, v3, v18);
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
          LOWORD(v35) = -19580;
          HIWORD(v35) = (unsigned int)"lex->saved_text.length" >> 16;
          error_set(error, v3, v35);
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
              LOWORD(v38) = -19556;
              HIWORD(v38) = (unsigned int)"real number overflow" >> 16;
              error_set(error, v3, v38);
              goto LABEL_51;
            }
            lex_scan(v3, error);
            if ( v3->token != 58 )
            {
              jsonp_free(string);
              LOWORD(v36) = -19532;
              HIWORD(v36) = (unsigned int)"string or '}' expected" >> 16;
              error_set(error, v3, v36);
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
          LOWORD(v37) = -19516;
          HIWORD(v37) = (unsigned int)"pected" >> 16;
          error_set(error, v3, v37);
LABEL_51:
          v27 = v8->refcount;
          if ( v27 != -1 )
          {
            v28 = v27 - 1;
            v8->refcount = v28;
            if ( !v28 )
            {
              v29 = v8;
              v8 = 0;
              json_delete(v29);
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
  LOWORD(v19) = -19484;
  HIWORD(v19) = (unsigned int)"':' expected" >> 16;
  error_set(error, v3, v19);
  return 0;
}
