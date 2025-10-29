int __fastcall dump_string(const char *str, json_dump_callback_t dump, void *data, size_t flags)
{
  const char *v7; // r11
  const char *v9; // r5
  bool v10; // zf
  int v11; // r1
  char *v12; // r0
  size_t v13; // r1
  int v14; // r3
  unsigned int v15; // r2
  int32_t codepoint; // [sp+Ch] [bp-18h] BYREF
  char seq[20]; // [sp+10h] [bp-14h] BYREF

  if ( ((int (__fastcall *)(char *, int))dump)("\"", 1) )
    return -1;
  v7 = str;
  while ( *v7 )
  {
    v9 = utf8_iterate(v7, &codepoint);
    if ( !v9 )
      return -1;
    v10 = codepoint == 34;
    if ( codepoint != 34 )
      v10 = codepoint == 92;
    v11 = v10;
    if ( codepoint <= 31 )
      v11 |= 1u;
    if ( v11 || ((codepoint == 47) & (flags >> 10)) != 0 || ((codepoint > 127) & (flags >> 6)) != 0 )
    {
      if ( v7 != str && dump(str, v7 - str, data) )
        return -1;
      if ( v7 == v9 )
        return dump("\"", 1, data);
      if ( codepoint == 12 )
      {
        v13 = 2;
        v12 = "\\f";
        goto LABEL_26;
      }
      if ( codepoint <= 12 )
      {
        switch ( codepoint )
        {
          case 9:
            v12 = "\\t";
            v13 = 2;
            goto LABEL_26;
          case 10:
            v12 = "\\n";
            v13 = 2;
            goto LABEL_26;
          case 8:
            v12 = "\\b";
            v13 = 2;
            goto LABEL_26;
        }
        goto LABEL_31;
      }
      if ( codepoint == 34 )
      {
        v12 = "\\\"";
        v13 = 2;
        goto LABEL_26;
      }
      if ( codepoint > 34 )
      {
        if ( codepoint == 47 )
        {
          v12 = "\\/";
          v13 = 2;
          goto LABEL_26;
        }
        if ( codepoint == 92 )
        {
          v12 = "\\\\";
          v13 = 2;
          goto LABEL_26;
        }
LABEL_31:
        if ( codepoint < 0x10000 )
          goto LABEL_32;
        v14 = (codepoint - 0x10000) & 0x3FF | 0xDC00;
        v15 = ((unsigned int)(codepoint - 0x10000) >> 10) & 0x3FF | 0xD800;
        codepoint -= 0x10000;
        sprintf(seq, "\\u%04x\\u%04x", v15, v14);
        v12 = seq;
        v13 = 12;
        goto LABEL_26;
      }
      if ( codepoint != 13 )
      {
LABEL_32:
        sprintf(seq, "\\u%04x", codepoint);
        v12 = seq;
        v13 = 6;
        goto LABEL_26;
      }
      v12 = "\\r";
      v13 = 2;
LABEL_26:
      if ( dump(v12, v13, data) )
        return -1;
      str = v9;
      v7 = v9;
    }
    else
    {
      v7 = v9;
    }
  }
  if ( v7 == str || !dump(str, v7 - str, data) )
    return dump("\"", 1, data);
  return -1;
}
