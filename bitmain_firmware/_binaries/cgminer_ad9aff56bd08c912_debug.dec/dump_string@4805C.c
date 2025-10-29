int __fastcall dump_string(const char *str, json_dump_callback_t dump, void *data, size_t flags)
{
  int v5; // r0
  char *v8; // r8
  const char *v9; // r10
  const char *v10; // r9
  const char *v11; // r11
  const char *v13; // r5
  bool v14; // zf
  int v15; // r1
  size_t v16; // r1
  char *v17; // r0
  int v18; // r3
  unsigned int v19; // r2
  const char *v20; // r0
  int32_t codepoint; // [sp+Ch] [bp-18h] BYREF
  char seq[20]; // [sp+10h] [bp-14h] BYREF

  LOWORD(v5) = -2120;
  HIWORD(v5) = (unsigned int)",\n\"round-robin\" : true" >> 16;
  if ( ((int (__fastcall *)(int, int))dump)(v5, 1) )
    return -1;
  LOWORD(v8) = -20328;
  LOWORD(v9) = -20300;
  LOWORD(v10) = -20308;
  v11 = str;
  while ( *v11 )
  {
    v13 = utf8_iterate(v11, &codepoint);
    if ( !v13 )
      return -1;
    v14 = codepoint == 34;
    if ( codepoint != 34 )
      v14 = codepoint == 92;
    v15 = v14;
    if ( codepoint <= 31 )
      v15 |= 1u;
    if ( v15 || ((codepoint == 47) & (flags >> 10)) != 0 || ((codepoint > 127) & (flags >> 6)) != 0 )
    {
      if ( v11 != str && dump(str, v11 - str, data) )
        return -1;
      if ( v11 == v13 )
        goto LABEL_46;
      if ( codepoint == 12 )
      {
        v16 = 2;
        HIWORD(v8) = (unsigned int)"                        " >> 16;
        v17 = v8;
        goto LABEL_26;
      }
      if ( codepoint <= 12 )
      {
        switch ( codepoint )
        {
          case 9:
            LOWORD(v17) = -20316;
            v16 = 2;
            HIWORD(v17) = (unsigned int)"            " >> 16;
            goto LABEL_26;
          case 10:
            LOWORD(v17) = -20324;
            v16 = 2;
            HIWORD(v17) = (unsigned int)"                    " >> 16;
            goto LABEL_26;
          case 8:
            LOWORD(v17) = -20332;
            v16 = 2;
            HIWORD(v17) = (unsigned int)"                            " >> 16;
            goto LABEL_26;
        }
        goto LABEL_31;
      }
      if ( codepoint == 34 )
      {
        LOWORD(v17) = -20336;
        v16 = 2;
        HIWORD(v17) = (unsigned int)"                                " >> 16;
        goto LABEL_26;
      }
      if ( codepoint > 34 )
      {
        if ( codepoint == 47 )
        {
          LOWORD(v17) = -20312;
          v16 = 2;
          HIWORD(v17) = (unsigned int)"        " >> 16;
          goto LABEL_26;
        }
        if ( codepoint == 92 )
        {
          LOWORD(v17) = -20340;
          v16 = 2;
          HIWORD(v17) = (unsigned int)"d.\n" >> 16;
          goto LABEL_26;
        }
LABEL_31:
        if ( codepoint < 0x10000 )
          goto LABEL_32;
        HIWORD(v9) = (unsigned int)"do_dump" >> 16;
        v18 = (codepoint - 0x10000) & 0x3FF | 0xDC00;
        v19 = ((unsigned int)(codepoint - 0x10000) >> 10) & 0x3FF | 0xD800;
        codepoint -= 0x10000;
        sprintf(seq, v9, v19, v18);
        v17 = seq;
        v16 = 12;
        goto LABEL_26;
      }
      if ( codepoint != 13 )
      {
LABEL_32:
        HIWORD(v10) = (unsigned int)"    " >> 16;
        sprintf(seq, v10);
        v17 = seq;
        v16 = 6;
        goto LABEL_26;
      }
      LOWORD(v17) = -20320;
      v16 = 2;
      HIWORD(v17) = (unsigned int)"                " >> 16;
LABEL_26:
      if ( dump(v17, v16, data) )
        return -1;
      str = v13;
      v11 = v13;
    }
    else
    {
      v11 = v13;
    }
  }
  if ( v11 == str || !dump(str, v11 - str, data) )
  {
LABEL_46:
    LOWORD(v20) = -2120;
    HIWORD(v20) = (unsigned int)",\n\"round-robin\" : true" >> 16;
    return dump(v20, 1, data);
  }
  return -1;
}
