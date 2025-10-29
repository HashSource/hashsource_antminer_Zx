void close_key()
{
  char tmp42[1028]; // [sp+0h] [bp+0h] BYREF

  close(cgpu.key_fd);
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    strcpy(tmp42, "key closed!!!\n");
    applog(2, tmp42, 0);
  }
}
