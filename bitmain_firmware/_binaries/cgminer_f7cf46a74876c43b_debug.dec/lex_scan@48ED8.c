int __fastcall lex_scan(lex_t *lex, json_error_t *error)
{
  strbuffer_t *p_saved_text; // r7
  unsigned int state; // r4
  bool v6; // cc
  int v7; // r3
  int v8; // r4
  bool v9; // zf
  _BOOL4 v10; // r2
  bool v11; // cc
  char i; // r1
  size_t v13; // r3
  size_t v14; // r2
  int v16; // r0
  const char *v17; // r4
  int v18; // r0
  bool v19; // zf
  int part_3; // r1
  json_int_t v21; // r2
  json_error_t *v22; // r1
  lex_t *v23; // r0
  unsigned int v24; // r4
  int v25; // r0
  bool v26; // zf
  unsigned int v27; // r3
  const char *v28; // r4
  int *v29; // r7
  json_int_t v30; // r0
  char *v31; // r4
  const char *j; // r7
  int v33; // r3
  unsigned int v34; // r3
  const char *v35; // r2
  int v36; // r8
  unsigned int v37; // r3
  unsigned int v38; // r4
  bool v39; // cc
  int save; // r0
  _DWORD *v41; // r1
  int32_t v42; // r0
  const char *v43; // r11
  int32_t v44; // r3
  int32_t v45; // r0
  const char *v46; // r2
  int32_t v47; // [sp+8h] [bp-1Ch]
  int v48; // [sp+Ch] [bp-18h]
  char buffer[4]; // [sp+14h] [bp-10h] BYREF
  json_int_t out; // [sp+18h] [bp-Ch] BYREF

  p_saved_text = &lex->saved_text;
  strbuffer_clear(&lex->saved_text);
  if ( lex->token == 256 )
  {
    jsonp_free(lex->value.string);
    lex->value.string = 0;
  }
  do
  {
    state = lex->stream.state;
    if ( !state )
      state = stream_get_part_3(lex, error);
    v6 = state > 0x20;
    if ( state != 32 )
      v6 = state - 9 > 1;
    v7 = !v6;
  }
  while ( !v6 || state == 13 );
  if ( state == -1 )
  {
    lex->token = v7;
    return v7;
  }
  if ( state == -2 )
    goto LABEL_31;
  strbuffer_append_byte(p_saved_text, state);
  if ( (((state & 0xFFFFFFDF) - 91) & 0xFFFFFFFD) == 0 )
    goto LABEL_34;
  v9 = state == 44;
  if ( state != 44 )
    v9 = state == 58;
  v10 = v9;
  if ( v9 )
    goto LABEL_34;
  if ( state != 34 )
  {
    v11 = state > 0x2D;
    if ( state != 45 )
      v11 = state - 48 > 9;
    if ( !v11 )
    {
      lex->token = -1;
      if ( state == 45 )
      {
        save = lex_get_save(lex, error);
        v41 = (_DWORD *)save;
        if ( save != 48 )
        {
          if ( (unsigned int)(save - 48) > 9 )
          {
LABEL_110:
            lex_unget_unsave(lex, v41);
            return lex->token;
          }
          goto LABEL_42;
        }
      }
      else if ( state != 48 )
      {
        do
LABEL_42:
          v18 = lex_get_save(lex, error);
        while ( (unsigned int)(v18 - 48) <= 9 );
        goto LABEL_43;
      }
      v18 = lex_get_save(lex, error);
      if ( (unsigned int)(v18 - 48) <= 9 )
      {
LABEL_112:
        v41 = (_DWORD *)v18;
        goto LABEL_110;
      }
LABEL_43:
      v19 = v18 == 46;
      if ( v18 != 46 )
        v19 = v18 == 69;
      if ( v19 )
      {
        if ( v18 == 46 )
        {
          part_3 = lex->stream.state;
          if ( !part_3 )
            part_3 = stream_get_part_3(lex, error);
          if ( (unsigned int)(part_3 - 48) > 9 )
          {
            stream_unget(lex, part_3);
            return lex->token;
          }
          strbuffer_append_byte(p_saved_text, part_3);
          do
            v18 = lex_get_save(lex, error);
          while ( (unsigned int)(v18 - 48) <= 9 );
        }
        if ( (v18 & 0xFFFFFFDF) != 0x45 )
          goto LABEL_54;
      }
      else if ( v18 != 101 )
      {
        lex_unget_unsave(lex, (_DWORD *)v18);
        v28 = strbuffer_value(p_saved_text);
        v29 = _errno_location();
        *v29 = 0;
        v30 = strtoll(v28, (char **)&out, 10);
        if ( *v29 == 34 )
        {
          if ( v30 >= 0 )
            LOWORD(v46) = -19712;
          else
            LOWORD(v46) = -19740;
          HIWORD(v46) = 5;
          error_set(error, lex, v46, HIDWORD(v30));
          return lex->token;
        }
        else
        {
          if ( (const char *)out != &v28[lex->saved_text.length] )
            _assert_fail("end == saved_text + lex->saved_text.length", "load.c", 0x206u, "lex_scan_number");
          v8 = 257;
          lex->value.integer = v30;
          lex->token = 257;
        }
        return v8;
      }
      v18 = lex_get_save(lex, error);
      if ( ((v18 - 43) & 0xFFFFFFFD) == 0 )
        v18 = lex_get_save(lex, error);
      if ( (unsigned int)(v18 - 48) <= 9 )
      {
        do
          v18 = lex_get_save(lex, error);
        while ( (unsigned int)(v18 - 48) <= 9 );
LABEL_54:
        lex_unget_unsave(lex, (_DWORD *)v18);
        if ( jsonp_strtod(p_saved_text, (double *)&out) )
        {
          error_set(error, lex, "real number overflow");
          return lex->token;
        }
        else
        {
          v21 = out;
          v8 = 258;
          lex->token = 258;
          lex->value.integer = v21;
        }
        return v8;
      }
      goto LABEL_112;
    }
    if ( (state & 0xFFFFFFDF) - 65 > 0x19 )
    {
      for ( i = lex->stream.buffer[lex->stream.buffer_pos]; i; i = lex->stream.buffer[v13] )
      {
        strbuffer_append_byte(p_saved_text, i);
        v13 = lex->stream.buffer_pos + 1;
        v14 = lex->stream.position + 1;
        lex->stream.buffer_pos = v13;
        lex->stream.position = v14;
      }
      goto LABEL_31;
    }
    do
      v16 = lex_get_save(lex, error);
    while ( (v16 & 0xFFFFFFDF) - 65 <= 0x19 );
    lex_unget_unsave(lex, (_DWORD *)v16);
    v17 = strbuffer_value(p_saved_text);
    if ( !strcmp(v17, "true") )
    {
      v8 = 259;
      lex->token = 259;
      return v8;
    }
    if ( strcmp(v17, "false") )
    {
      if ( !strcmp(v17, "null") )
      {
        v8 = 261;
        lex->token = 261;
        return v8;
      }
LABEL_31:
      v8 = -1;
      lex->token = -1;
      return v8;
    }
    state = 260;
LABEL_34:
    lex->token = state;
    return state;
  }
  lex->token = -1;
  lex->value.string = (char *)v10;
LABEL_57:
  v22 = error;
  v23 = lex;
  while ( 1 )
  {
    v24 = lex_get_save(v23, v22);
LABEL_59:
    if ( v24 == 34 )
    {
      v31 = (char *)jsonp_malloc(lex->saved_text.length + 1);
      lex->value.string = v31;
      if ( !v31 )
        goto LABEL_72;
      for ( j = strbuffer_value(p_saved_text) + 1; ; j += 2 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            v33 = *(unsigned __int8 *)j;
            if ( v33 == 34 )
            {
              *v31 = 0;
              v8 = 256;
              lex->token = 256;
              return v8;
            }
            if ( v33 == 92 )
              break;
            *v31 = v33;
            ++j;
            ++v31;
          }
          v34 = *((unsigned __int8 *)j + 1);
          if ( v34 != 117 )
            break;
          v42 = decode_unicode_escape(j + 1);
          v43 = j + 6;
          v44 = v42;
          v48 = v42 - 55296;
          if ( (unsigned int)(v42 - 55296) >= 0x400 )
          {
            if ( (unsigned int)(v42 - 56320) < 0x400 )
              goto LABEL_143;
            if ( !v42 )
            {
              error_set(error, lex, "\\u0000 is not allowed", 0);
              goto LABEL_72;
            }
          }
          else
          {
            if ( j[6] != 92 || j[7] != 117 )
            {
LABEL_143:
              error_set(error, lex, "invalid Unicode '\\u%04X'", v42);
              goto LABEL_72;
            }
            v47 = v42;
            v45 = decode_unicode_escape(j + 7);
            v43 = j + 12;
            if ( (unsigned int)(v45 - 56320) >= 0x400 )
            {
              error_set(error, lex, "invalid Unicode '\\u%04X\\u%04X'", v47, v45);
              goto LABEL_72;
            }
            v44 = v45 - 56320 + (v48 << 10) + 0x10000;
          }
          if ( utf8_encode(v44, buffer, (int *)&out) )
            _assert_fail((const char *)&word_53210, "load.c", 0x1AEu, "lex_scan_string");
          j = v43;
          memcpy(v31, buffer, out);
          v31 += out;
        }
        if ( v34 == 98 )
        {
          *v31 = 8;
        }
        else
        {
          if ( v34 <= 0x62 )
          {
            if ( v34 != 47 && v34 != 92 && v34 != 34 )
LABEL_121:
              _assert_fail((const char *)&word_53210, "load.c", 0x1BCu, "lex_scan_string");
            goto LABEL_116;
          }
          if ( v34 == 110 )
          {
            *v31 = 10;
          }
          else
          {
            if ( v34 <= 0x6E )
            {
              if ( v34 != 102 )
                goto LABEL_121;
              LOBYTE(v34) = 12;
LABEL_116:
              *v31 = v34;
              goto LABEL_96;
            }
            if ( v34 == 114 )
            {
              *v31 = 13;
            }
            else
            {
              if ( v34 != 116 )
                goto LABEL_121;
              *v31 = 9;
            }
          }
        }
LABEL_96:
        ++v31;
      }
    }
    if ( v24 == -2 )
      goto LABEL_72;
    if ( v24 == -1 )
    {
      error_set(error, lex, "premature end of input", 0);
      goto LABEL_72;
    }
    if ( v24 <= 0x1F )
      break;
    v22 = error;
    v23 = lex;
    if ( v24 == 92 )
    {
      v25 = lex_get_save(lex, error);
      if ( v25 == 117 )
      {
        v36 = 4;
        v24 = lex_get_save(lex, error);
        while ( 1 )
        {
          v37 = v24 & 0xFFFFFFDF;
          v38 = v24 - 48;
          v27 = v37 - 65;
          v39 = v27 > 5;
          if ( v27 > 5 )
            v39 = v38 > 9;
          if ( v39 )
            break;
          --v36;
          v24 = lex_get_save(lex, error);
          if ( !v36 )
            goto LABEL_59;
        }
LABEL_71:
        error_set(error, lex, "invalid escape", v27);
        goto LABEL_72;
      }
      v26 = v25 == 92;
      if ( v25 != 92 )
        v26 = (v25 & 0xFFFFFFBF) == 34;
      if ( !v26 && v25 != 47 && (v25 & 0xFFFFFFF7) != 0x66 )
      {
        v27 = (v25 - 114) & 0xFFFFFFFD;
        if ( v27 )
          goto LABEL_71;
      }
      goto LABEL_57;
    }
  }
  lex_unget_unsave(lex, (_DWORD *)v24);
  if ( v24 == 10 )
    LOWORD(v35) = -19884;
  else
    LOWORD(v35) = -19864;
  HIWORD(v35) = 5;
  error_set(error, lex, v35, v24);
LABEL_72:
  jsonp_free(lex->value.string);
  return lex->token;
}
