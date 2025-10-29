void __fastcall cg_memcpy(
        void *dest,
        const void *src,
        unsigned int n,
        const char *file,
        const char *func,
        const int line)
{
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  if ( (int)(n - 1) < 0 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      snprintf(tmp42, 0x1000u, "ERR: Asked to memcpy %u bytes from %s %s():%d", n, file, func, line);
      applog(3, tmp42, 0);
    }
  }
  else
  {
    sub_12058(dest, src, n);
  }
}
