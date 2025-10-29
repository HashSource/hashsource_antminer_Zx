void __cdecl bm174x_set_core_timeout(int fd, uint32_t timeout)
{
  char tmp42[1024]; // [sp+8h] [bp+8h] BYREF
  base_type_t item; // [sp+408h] [bp+408h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "Set core timeout %u\n", timeout);
    applog(2, tmp42, 0);
  }
  item.chip_addr = 0;
  item.all = 1;
  item.addr = 40;
  item.data = timeout;
  reg_value.core_timeout = timeout;
  midd_ioctl(fd, 1u, &item);
}
