int __fastcall jsonp_dtostr(char *buffer, size_t size, double value)
{
  double v3; // d0
  unsigned int v6; // r0
  unsigned int v7; // r6
  int v8; // r1
  char *v9; // r0
  char *v10; // r5
  char *v11; // r0
  unsigned __int8 *v12; // r4
  int v13; // r3
  _BYTE *v14; // r5
  int v15; // t1
  size_t v16; // r2
  char *v18; // r3

  v6 = snprintf(buffer, size, "%.17g", v3);
  if ( size > v6 )
  {
    v7 = v6;
    v8 = *(unsigned __int8 *)localeconv()->decimal_point;
    if ( v8 != 46 )
    {
      v9 = strchr(buffer, v8);
      if ( v9 )
        *v9 = 46;
    }
    v10 = strchr(buffer, 46);
    v11 = strchr(buffer, 101);
    if ( v10 )
    {
      if ( !v11 )
        return v7;
      goto LABEL_7;
    }
    if ( v11 )
    {
LABEL_7:
      v12 = (unsigned __int8 *)(v11 + 2);
      v13 = (unsigned __int8)v11[2];
      if ( v11[1] != 45 )
      {
        v14 = v11 + 1;
        if ( v13 != 48 )
        {
LABEL_10:
          if ( v12 != v14 )
          {
            v16 = v7 - (v12 - (unsigned __int8 *)buffer);
            v7 -= v12 - v14;
            memmove(v14, v12, v16);
          }
          return v7;
        }
        do
LABEL_9:
          v15 = *++v12;
        while ( v15 == 48 );
        goto LABEL_10;
      }
      if ( v13 == 48 )
      {
        v14 = v11 + 2;
        goto LABEL_9;
      }
      return v7;
    }
    if ( v7 + 3 < size )
    {
      v18 = &buffer[v7];
      buffer[v7] = 46;
      v7 += 2;
      v18[1] = 48;
      buffer[v7] = 0;
      v11 = strchr(buffer, 101);
      if ( !v11 )
        return v7;
      goto LABEL_7;
    }
  }
  return -1;
}
