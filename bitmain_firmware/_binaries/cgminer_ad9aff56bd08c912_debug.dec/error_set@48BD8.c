void error_set(json_error_t *error, const lex_t *lex, const char *a3, ...)
{
  const char *v5; // r0
  __int64 v6; // kr00_8
  size_t position; // r9
  char *v8; // r3
  const char *v9; // r4
  const char *v10; // r2
  const char *v11; // r2
  char msg_text[160]; // [sp+1Ch] [bp-168h] BYREF
  char msg_with_context[192]; // [sp+BCh] [bp-C8h] BYREF
  va_list va; // [sp+180h] [bp-4h] BYREF

  va_start(va, a3);
  if ( error )
  {
    vsnprintf(msg_text, 0xA0u, a3, va);
    msg_text[159] = 0;
    if ( lex )
    {
      v5 = strbuffer_value(&lex->saved_text);
      v6 = *(_QWORD *)&lex->stream.line;
      position = lex->stream.position;
      if ( v5 && *v5 )
      {
        if ( lex->saved_text.length <= 0x14 )
        {
          LOWORD(v11) = -20032;
          HIWORD(v11) = (unsigned int)"unget_unsave" >> 16;
          snprintf(msg_with_context, 0xA0u, v11, msg_text, v5);
          v8 = msg_with_context;
          msg_with_context[159] = 0;
          goto LABEL_8;
        }
      }
      else if ( lex->stream.state != -2 )
      {
        LOWORD(v10) = -20016;
        HIWORD(v10) = (unsigned int)"lex_scan_string" >> 16;
        snprintf(msg_with_context, 0xA0u, v10, msg_text);
        v8 = msg_with_context;
        msg_with_context[159] = 0;
        goto LABEL_8;
      }
      v8 = msg_text;
    }
    else
    {
      v8 = msg_text;
      position = 0;
      v6 = -1;
    }
LABEL_8:
    LOWORD(v9) = 20752;
    HIWORD(v9) = (unsigned int)"mcast join failed (%s)%s" >> 16;
    jsonp_error_set(error, v6, SHIDWORD(v6), position, v9, v8);
  }
}
