void *__fastcall realloc_strcat(char *ptr, char *s)
{
  char *v4; // r4
  size_t v5; // r0
  size_t v6; // r4
  char *v7; // r0
  size_t v8; // r0
  char *v9; // r0
  const char *v10; // r1
  int v12; // r3
  const char *v13; // r2
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  v4 = ptr;
  v5 = strlen(s);
  if ( !v5 )
    return v4;
  v6 = v5;
  v7 = ptr;
  if ( ptr )
    v7 = (char *)strlen(ptr);
  v8 = (size_t)&v7[v6 + 1];
  if ( v8 << 30 )
    v8 = (v8 & 0xFFFFFFFC) + 4;
  v9 = (char *)malloc(v8);
  v4 = v9;
  if ( !v9 )
  {
    LOWORD(v12) = 15984;
    LOWORD(v13) = 19560;
    HIWORD(v12) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
    HIWORD(v13) = (unsigned int)"d" >> 16;
    snprintf(tmp42, 0x1000u, v13, v12, &_func___12266.__align + 4, 3705);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( ptr )
  {
    LOWORD(v10) = 19592;
    HIWORD(v10) = (unsigned int)"d" >> 16;
    sprintf(v9, v10, ptr, s);
    free(ptr);
    return v4;
  }
  strcpy(v9, s);
  return v4;
}
