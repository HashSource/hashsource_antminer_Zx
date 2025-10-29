void *__fastcall realloc_strcat(char *ptr, char *s)
{
  char *v4; // r4
  size_t v5; // r0
  size_t v6; // r4
  char *v7; // r0
  size_t v8; // r0
  char *v9; // r0
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
    snprintf(tmp42, 0x1000u, "Failed to malloc in %s %s():%d", "util.c", &_func___12266.__size[16], 3705);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( ptr )
  {
    sprintf(v9, "%s%s", ptr, s);
    free(ptr);
    return v4;
  }
  strcpy(v9, s);
  return v4;
}
