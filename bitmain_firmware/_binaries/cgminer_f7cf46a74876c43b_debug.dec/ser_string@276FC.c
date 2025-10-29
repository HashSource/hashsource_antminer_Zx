unsigned __int8 *__fastcall ser_string(char *s, int *slen)
{
  size_t v4; // r4
  unsigned __int8 *v5; // r0
  unsigned __int8 *v6; // r5
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  v4 = strlen(s);
  v5 = (unsigned __int8 *)malloc(v4 + 9);
  v6 = v5;
  if ( !v5 )
  {
    strcpy(tmp42, "Failed to malloc ret in ser_string");
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( v4 <= 0xFC )
  {
    *v5 = v4;
    memcpy(v5 + 1, s, v4);
    *slen = v4 + 1;
    return v6;
  }
  else
  {
    if ( v4 < 0x10000 )
    {
      *v5 = -3;
      *(_WORD *)(v5 + 1) = __rev16(v4);
      memcpy(v5 + 3, s, v4);
      *slen = v4 + 3;
    }
    else
    {
      *v5 = -2;
      *(_DWORD *)(v5 + 1) = bswap32(v4);
      memcpy(v5 + 5, s, v4);
      *slen = v4 + 5;
    }
    return v6;
  }
}
