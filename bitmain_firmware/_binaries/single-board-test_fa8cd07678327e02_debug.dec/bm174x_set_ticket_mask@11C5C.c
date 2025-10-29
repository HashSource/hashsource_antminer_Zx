void __cdecl bm174x_set_ticket_mask(int fd, uint32_t tm)
{
  char tmp42[1024]; // [sp+8h] [bp+8h] BYREF
  base_type_t item; // [sp+408h] [bp+408h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "Set ticket mask %u\n", tm);
    applog(2, tmp42, 0);
  }
  item.chip_addr = 0;
  item.all = 1;
  item.addr = 20;
  item.data = tm;
  reg_value.ticket_mask = tm;
  midd_ioctl(fd, 1u, &item);
}
