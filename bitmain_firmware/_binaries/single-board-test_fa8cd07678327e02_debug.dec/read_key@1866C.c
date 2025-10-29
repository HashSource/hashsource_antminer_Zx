ssize_t __cdecl read_key(unsigned __int8 value)
{
  unsigned __int8 valuea[5]; // [sp+7h] [bp+7h] BYREF
  char tmp42[1024]; // [sp+Ch] [bp+Ch] BYREF
  ssize_t ret_len; // [sp+40Ch] [bp+40Ch]

  valuea[0] = value;
  ret_len = 0;
  lseek(cgpu.key_fd, 0, 0);
  ret_len = read(cgpu.key_fd, valuea, 1u);
  if ( ret_len == 1 )
    return 1;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "%s: can't read out key value\n", "read_key");
    applog(2, tmp42, 0);
  }
  return -1;
}
