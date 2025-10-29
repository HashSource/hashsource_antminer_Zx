void init_fpga()
{
  char tmp42[1024]; // [sp+4h] [bp+4h] BYREF
  unsigned int data; // [sp+404h] [bp+404h]

  data = -2147450880;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "--- %s\n", "init_fpga");
    applog(2, tmp42, 0);
  }
  write_axi_fpga(0x20u, data);
  while ( (read_axi_fpga(0x20u) & 0x80000000) != 0 )
    usleep(0x2710u);
  usleep(0x186A0u);
}
