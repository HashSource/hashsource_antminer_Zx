void __cdecl randomize(void *p, int l)
{
  int *v2; // r0
  char *v3; // r0
  int *v4; // r0
  char *v5; // r0
  int *v6; // r0
  char *v7; // r0
  char tmp42[1024]; // [sp+14h] [bp+Ch] BYREF
  int ret; // [sp+414h] [bp+40Ch]
  int fd; // [sp+418h] [bp+410h]
  const char *fname; // [sp+41Ch] [bp+414h]

  fname = "/dev/urandom";
  fd = open("/dev/urandom", 0);
  if ( fd == -1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      v2 = _errno_location();
      v3 = strerror(*v2);
      snprintf(tmp42, 0x400u, "open %s: %s\n", fname, v3);
      applog(0, tmp42, 0);
    }
    exit(1);
  }
  ret = read(fd, p, l);
  if ( ret == -1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      v4 = _errno_location();
      v5 = strerror(*v4);
      snprintf(tmp42, 0x400u, "read %s: %s\n", fname, v5);
      applog(0, tmp42, 0);
    }
    exit(1);
  }
  if ( ret != l )
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      snprintf(tmp42, 0x400u, "%s: short read %d bytes out of %d\n", fname, ret, l);
      applog(0, tmp42, 0);
    }
    exit(1);
  }
  if ( close(fd) == -1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      v6 = _errno_location();
      v7 = strerror(*v6);
      snprintf(tmp42, 0x400u, "close %s: %s\n", fname, v7);
      applog(0, tmp42, 0);
    }
    exit(1);
  }
}
