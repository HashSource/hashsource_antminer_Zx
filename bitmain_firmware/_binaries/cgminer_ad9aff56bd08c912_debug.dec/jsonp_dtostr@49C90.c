int __fastcall jsonp_dtostr(char *buffer, size_t size, double value)
{
  int v3; // s0
  int v4; // s1
  unsigned int v7; // r0
  unsigned int v8; // r6
  int v9; // r1
  char *v10; // r0
  char *v11; // r5
  char *v12; // r0
  unsigned __int8 *v13; // r4
  int v14; // r3
  _BYTE *v15; // r5
  int v16; // t1
  size_t v17; // r2
  char *v19; // r3

  LOWORD(value) = -19236;
  WORD1(value) = (unsigned int)"c" >> 16;
  v7 = snprintf(buffer, size, (const char *)LODWORD(value), HIDWORD(value), v3, v4);
  if ( size > v7 )
  {
    v8 = v7;
    v9 = *(unsigned __int8 *)localeconv()->decimal_point;
    if ( v9 != 46 )
    {
      v10 = strchr(buffer, v9);
      if ( v10 )
        *v10 = 46;
    }
    v11 = strchr(buffer, 46);
    v12 = strchr(buffer, 101);
    if ( v11 )
    {
      if ( !v12 )
        return v8;
      goto LABEL_7;
    }
    if ( v12 )
    {
LABEL_7:
      v13 = (unsigned __int8 *)(v12 + 2);
      v14 = (unsigned __int8)v12[2];
      if ( v12[1] != 45 )
      {
        v15 = v12 + 1;
        if ( v14 != 48 )
        {
LABEL_10:
          if ( v13 != v15 )
          {
            v17 = v8 - (v13 - (unsigned __int8 *)buffer);
            v8 -= v13 - v15;
            memmove(v15, v13, v17);
          }
          return v8;
        }
        do
LABEL_9:
          v16 = *++v13;
        while ( v16 == 48 );
        goto LABEL_10;
      }
      if ( v14 == 48 )
      {
        v15 = v12 + 2;
        goto LABEL_9;
      }
      return v8;
    }
    if ( v8 + 3 < size )
    {
      v19 = &buffer[v8];
      buffer[v8] = 46;
      v8 += 2;
      v19[1] = 48;
      buffer[v8] = 0;
      v12 = strchr(buffer, 101);
      if ( !v12 )
        return v8;
      goto LABEL_7;
    }
  }
  return -1;
}
