void check_fpga_version()
{
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  *axi_fpga_addr |= 0x60000000u;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "FPGA version: %04X", (unsigned __int16)*axi_fpga_addr);
    applog(5, tmp42, 0);
  }
}
