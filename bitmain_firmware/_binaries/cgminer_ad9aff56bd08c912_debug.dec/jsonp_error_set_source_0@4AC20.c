// Alternative name is 'jsonp_error_set_source.part.0'
void __fastcall jsonp_error_set_source_0(json_error_t *error, const char *source)
{
  size_t v4; // r0
  _DWORD *v5; // r3

  v4 = strlen(source);
  if ( v4 <= 0x4F )
  {
    sub_12058(error->source, source, v4 + 1);
  }
  else
  {
    LOWORD(v5) = -20908;
    HIWORD(v5) = (unsigned int)"statusServiceThread send http timeout, try again..." >> 16;
    *(_DWORD *)error->source = *v5;
    j_strcpy(&error->source[3], &source[v4 - 76]);
  }
}
