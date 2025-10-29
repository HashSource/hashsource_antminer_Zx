void bitmain_axi_close()
{
  char tmp42[1024]; // [sp+4h] [bp+4h] BYREF
  int ret; // [sp+404h] [bp+404h]

  ret = 0;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "--- %s\n", "bitmain_axi_close");
    applog(2, tmp42, 0);
  }
  ret = munmap(axi_fpga_addr, 0x1200u);
  if ( ret < 0 && (use_syslog || opt_log_output || opt_log_level > 1) )
  {
    strcpy(tmp42, "munmap failed!\n");
    applog(2, tmp42, 0);
  }
  ret = munmap(fpga_mem_addr, 0x1000000u);
  if ( ret < 0 && (use_syslog || opt_log_output || opt_log_level > 1) )
  {
    strcpy(tmp42, "munmap failed!\n");
    applog(2, tmp42, 0);
  }
  close(fd_fpga);
  close(fd_fpga_mem);
}
