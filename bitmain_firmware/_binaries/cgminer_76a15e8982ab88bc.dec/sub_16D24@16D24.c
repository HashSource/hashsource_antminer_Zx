char *__fastcall sub_16D24(_DWORD *a1, int a2)
{
  _DWORD *v4; // r6
  const char *v5; // r0
  char *v6; // r11
  _DWORD *v7; // r0
  _DWORD *v8; // r5
  int v9; // r2
  char *v10; // r2
  int v11; // r3
  unsigned int v12; // r4
  _DWORD *v13; // r0
  _DWORD *v15; // r11
  _DWORD *v16; // r4
  _DWORD *v17; // r0
  char *v18; // r0
  char *v19; // [sp+Ch] [bp-1010h]
  char *v20; // [sp+Ch] [bp-1010h]
  char *ptr; // [sp+10h] [bp-100Ch]
  char *v22; // [sp+14h] [bp-1008h]
  char s[4100]; // [sp+18h] [bp-1004h] BYREF

  if ( a2 && !dword_73E2C )
    dword_73E2C = 1;
  if ( dword_72444 == 16 )
    goto LABEL_46;
  if ( (dword_72444 & 8) != 0 )
    goto LABEL_28;
  v4 = &unk_7245C;
  while ( 2 )
  {
    v5 = (const char *)*(v4 - 7);
    if ( !v5 )
      goto LABEL_26;
    ptr = _strdup(v5);
    v6 = strtok(ptr, delim);
    if ( !v6 )
      goto LABEL_25;
    while ( 2 )
    {
      if ( v6[1] != 45 )
        goto LABEL_10;
      v7 = (_DWORD *)sub_571D8(a1, v6 + 2);
      v8 = v7;
      if ( !v7 )
        goto LABEL_10;
      v9 = *(v4 - 6);
      if ( (v9 & 6) == 0 )
        goto LABEL_17;
      if ( *v7 == 2 )
      {
        v16 = sub_57530(v7);
        v10 = (char *)((int (__fastcall *)(_DWORD *, _DWORD))*(v4 - 4))(v16, *(v4 - 2));
        if ( *(v4 - 6) == 4 )
        {
          v20 = v10;
          sub_5858C((int)v16, (_DWORD *)*(v4 - 2));
          v10 = v20;
        }
        goto LABEL_43;
      }
      if ( *v7 != 1 )
      {
LABEL_17:
        if ( (v9 & 1) == 0 || *v7 != 5 )
        {
          v10 = "Invalid value";
          goto LABEL_19;
        }
        v10 = (char *)((int (__fastcall *)(_DWORD))*(v4 - 5))(*(v4 - 2));
LABEL_43:
        if ( !v10 )
          goto LABEL_10;
LABEL_19:
        if ( !a2 )
          goto LABEL_38;
        goto LABEL_20;
      }
      v12 = 0;
      v22 = v6;
      while ( 1 )
      {
        if ( v12 >= (unsigned int)sub_573A4(v8) )
          goto LABEL_10;
        v13 = sub_573C0(v8, v12);
        if ( !v13 )
          goto LABEL_10;
        if ( *v13 == 2 )
        {
          v15 = sub_57530(v13);
          v10 = (char *)((int (__fastcall *)(_DWORD *, _DWORD))*(v4 - 4))(v15, *(v4 - 2));
          if ( *(v4 - 6) == 4 )
          {
            v19 = v10;
            sub_5858C((int)v15, (_DWORD *)*(v4 - 2));
            v10 = v19;
          }
        }
        else
        {
          if ( *v13 )
            goto LABEL_30;
          v10 = sub_16D24(v13, 0);
        }
        if ( v10 )
          break;
LABEL_30:
        ++v12;
      }
      v6 = v22;
      if ( !a2 )
      {
LABEL_38:
        snprintf(byte_73D64, 0xC8u, "Parsing JSON option %s: %s", v6, v10);
        return byte_73D64;
      }
LABEL_20:
      if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
      {
        snprintf(s, 0x1000u, "Invalid config option %s: %s", v6, v10);
        sub_385C8(3, s, 0);
      }
      dword_73E2C = -1;
LABEL_10:
      v6 = strtok(0, delim);
      if ( v6 )
        continue;
      break;
    }
LABEL_25:
    free(ptr);
LABEL_26:
    v11 = v4[1];
    if ( v11 != 16 )
    {
      v4 += 7;
      if ( (v11 & 8) != 0 )
LABEL_28:
        _assert_fail("!(opt->type & OPT_SUBTABLE)", "cgminer.c", 0x7A0u, "parse_config");
      continue;
    }
    break;
  }
LABEL_46:
  v17 = (_DWORD *)sub_571D8(a1, "include");
  if ( !v17 )
    return 0;
  if ( *v17 != 2 )
    return 0;
  v18 = (char *)sub_57530(v17);
  return sub_16CD0(v18);
}
