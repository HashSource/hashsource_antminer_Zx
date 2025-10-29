void *__fastcall str_text(char *ptr)
{
  size_t v2; // r0
  void *v3; // r0
  void *v4; // r7
  const char *v5; // r6
  char *v6; // r5
  char *i; // r4
  char v8; // r2
  int v9; // t1
  char *v11; // r3
  int v12; // r3
  const char *v13; // r2
  int v14; // r3
  const char *v15; // r2
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( !ptr )
  {
    v11 = (char *)malloc(7u);
    if ( !v11 )
    {
      LOWORD(v14) = 15984;
      LOWORD(v15) = 19644;
      HIWORD(v14) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
      HIWORD(v15) = (unsigned int)"Stratum extranonce subscribe for pool %d" >> 16;
      snprintf(tmp42, 0x1000u, v15, v14, "str_text", 3730);
      applog(3, tmp42, 1);
      quit(1);
    }
    strcpy(v11, "(null)");
  }
  v2 = strlen(ptr);
  v3 = malloc(4 * v2 + 5);
  v4 = v3;
  if ( !v3 )
  {
    LOWORD(v12) = 15984;
    LOWORD(v13) = 19608;
    HIWORD(v12) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
    HIWORD(v13) = (unsigned int)" extranonce subscribe failed: %s" >> 16;
    snprintf(tmp42, 0x1000u, v13, v12, "str_text", 3737);
    applog(3, tmp42, 1);
    quit(1);
  }
  LOWORD(v5) = -29596;
  v6 = ptr - 1;
  for ( i = (char *)v3; ; i += 4 )
  {
    while ( 1 )
    {
      v9 = (unsigned __int8)*++v6;
      v8 = v9;
      if ( (unsigned int)(v9 - 32) > 0x5E )
        break;
      *i++ = v8;
    }
    HIWORD(v5) = (unsigned int)"%s chain %d failed!" >> 16;
    sprintf(i, v5);
    if ( !*v6 )
      break;
  }
  i[4] = 0;
  return v4;
}
