int __cdecl read_last_line(char *buf, size_t len, int block)
{
  int *v4; // r0
  char *v5; // r0
  int *v6; // r0
  char *v7; // r0
  char tmp42[1024]; // [sp+14h] [bp+14h] BYREF
  char *start; // [sp+414h] [bp+414h]
  ssize_t n; // [sp+418h] [bp+418h]
  size_t pos; // [sp+41Ch] [bp+41Ch]

  pos = 0;
  set_blocking_mode(0, block);
  do
  {
    while ( 1 )
    {
      do
        n = read(0, &buf[pos], len - pos);
      while ( n == -1 && *_errno_location() == 4 );
      if ( n != -1 || *_errno_location() != 11 && *_errno_location() != 11 )
        break;
      if ( !pos )
        return 0;
      if ( use_syslog || opt_log_output || opt_log_level > 0 )
      {
        v4 = _errno_location();
        v5 = strerror(*v4);
        snprintf(tmp42, 0x400u, "strange: a partial line was read %s\n", v5);
        applog(1, tmp42, 0);
      }
      set_blocking_mode(0, 1);
    }
    if ( n == -1 )
    {
      if ( use_syslog || opt_log_output || opt_log_level >= 0 )
      {
        v6 = _errno_location();
        v7 = strerror(*v6);
        snprintf(tmp42, 0x400u, "read stdin: %s\n", v7);
        applog(0, tmp42, 0);
      }
    }
    else if ( !n && (use_syslog || opt_log_output || opt_log_level >= 0) )
    {
      snprintf(tmp42, 0x400u, "%s EOF on stdin\n", "read_last_line");
      applog(0, tmp42, 0);
    }
    pos += n;
  }
  while ( buf[pos - 1] != 10 );
  start = (char *)memrchr(buf, 10, pos - 1);
  if ( start )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 0 )
    {
      snprintf(tmp42, 0x400u, "%s strange: more than 1 line was read\n", "read_last_line");
      applog(1, tmp42, 0);
    }
    pos -= start + 1 - buf;
    memmove(buf, start + 1, pos);
  }
  buf[pos - 1] = 0;
  return 1;
}
