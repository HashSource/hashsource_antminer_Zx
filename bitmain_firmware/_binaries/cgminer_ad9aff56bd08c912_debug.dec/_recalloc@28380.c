void __fastcall recalloc(void **ptr, size_t old, size_t a3, const char *file, const char *func, const int line)
{
  void *v10; // r0
  const char *v11; // r2
  char tmp42[4120]; // [sp+8h] [bp-1018h] BYREF

  if ( a3 != old )
  {
    v10 = realloc(*ptr, a3);
    *ptr = v10;
    if ( !v10 )
    {
      LOWORD(v11) = 16404;
      HIWORD(v11) = (unsigned int)"arget: %s\nTrgVal? %s" >> 16;
      snprintf(tmp42, 0x1000u, v11, file, func, line);
      applog(3, tmp42, 1);
      quit(1);
    }
    if ( a3 > old )
      memset((char *)*ptr + old, 0, a3 - old);
  }
}
