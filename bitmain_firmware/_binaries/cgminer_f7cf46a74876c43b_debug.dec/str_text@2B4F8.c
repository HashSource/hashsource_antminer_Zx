void *__fastcall str_text(char *ptr)
{
  size_t v2; // r0
  void *v3; // r0
  void *v4; // r7
  char *v5; // r5
  char *i; // r4
  int v7; // r2
  int v8; // t1
  char *v10; // r3
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( !ptr )
  {
    v10 = (char *)malloc(7u);
    if ( !v10 )
    {
      snprintf(tmp42, 0x1000u, "Failed to malloc null in %s %s():%d", "util.c", "str_text", 3730);
      applog(3, tmp42, 1);
      quit(1);
    }
    strcpy(v10, "(null)");
  }
  v2 = strlen(ptr);
  v3 = malloc(4 * v2 + 5);
  v4 = v3;
  if ( !v3 )
  {
    snprintf(tmp42, 0x1000u, "Failed to malloc txt in %s %s():%d", "util.c", "str_text", 3737);
    applog(3, tmp42, 1);
    quit(1);
  }
  v5 = ptr - 1;
  for ( i = (char *)v3; ; i += 4 )
  {
    while ( 1 )
    {
      v8 = (unsigned __int8)*++v5;
      v7 = v8;
      if ( (unsigned int)(v8 - 32) > 0x5E )
        break;
      *i++ = v7;
    }
    sprintf(i, "0x%02x", v7);
    if ( !*v5 )
      break;
  }
  i[4] = 0;
  return v4;
}
