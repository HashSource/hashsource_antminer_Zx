void reset_all_hash_board_low()
{
  int v0; // r3
  const char *v1; // r2
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v0) = 28216;
    LOWORD(v1) = 3828;
    HIWORD(v1) = (unsigned int)"d:%02d" >> 16;
    HIWORD(v0) = (unsigned int)"s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v1, v0, 4392);
    applog(5, tmp42, 0);
  }
  axi_fpga_addr[13] = 0xFFFF;
}
