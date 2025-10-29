void check_fpga_version()
{
  const char *v0; // r2
  int v1; // [sp+4h] [bp-1004h]
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  v1 = *axi_fpga_addr;
  *axi_fpga_addr |= 0x60000000u;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v0) = -31432;
    HIWORD(v0) = (unsigned int)"ga_mem = %d\n" >> 16;
    snprintf(tmp42, 0x1000u, v0, (unsigned __int16)*axi_fpga_addr, *axi_fpga_addr, v1);
    applog(5, tmp42, 0);
  }
}
