void reset_all_hash_board_low()
{
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "%s %d", "reset_all_hash_board_low", 4392);
    applog(5, tmp42, 0);
  }
  axi_fpga_addr[13] = 0xFFFF;
}
