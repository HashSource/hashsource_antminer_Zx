void __cdecl set_blocking_mode(int fd, int block)
{
  int *v2; // r0
  char *v3; // r0
  unsigned int v4; // r3
  int *v5; // r0
  char *v6; // r0
  int fda; // [sp+4h] [bp+4h]
  char tmp42[1024]; // [sp+Ch] [bp+Ch] BYREF
  int f; // [sp+40Ch] [bp+40Ch]

  fda = fd;
  f = fcntl(fd, 3);
  if ( f == -1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      v2 = _errno_location();
      v3 = strerror(*v2);
      snprintf(tmp42, 0x400u, "fcntl F_GETFL: %s\n", v3);
      applog(0, tmp42, 0);
    }
    exit(1);
  }
  if ( block )
    v4 = f & 0xFFFFF7FF;
  else
    v4 = f | 0x800;
  if ( fcntl(fda, 4, v4) == -1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      v5 = _errno_location();
      v6 = strerror(*v5);
      snprintf(tmp42, 0x400u, "fcntl F_SETFL: %s\n", v6);
      applog(0, tmp42, 0);
    }
    exit(1);
  }
}
