int bitmain_axi_init()
{
  char tmp42[1024]; // [sp+8h] [bp+0h] BYREF
  unsigned int data; // [sp+408h] [bp+400h]
  int ret; // [sp+40Ch] [bp+404h]

  ret = 0;
  fd_fpga = open("/dev/axi_fpga_dev", 2);
  if ( fd_fpga >= 0 )
  {
    axi_fpga_addr = (unsigned int *)mmap(0, 0x1200u, 3, 1, fd_fpga, 0);
    if ( axi_fpga_addr )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "mmap axi_fpga_addr = 0x%p\n", axi_fpga_addr);
        applog(2, tmp42, 0);
      }
      data = (unsigned __int16)*axi_fpga_addr;
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "axi_fpga_addr data = 0x%x\n", data);
        applog(2, tmp42, 0);
      }
      fd_fpga_mem = open("/dev/fpga_mem", 2);
      if ( fd_fpga_mem >= 0 )
      {
        fpga_mem_addr = (unsigned int *)mmap(0, 0x1000000u, 3, 1, fd_fpga_mem, 0);
        if ( fpga_mem_addr )
        {
          if ( use_syslog || opt_log_output || opt_log_level > 1 )
          {
            snprintf(tmp42, 0x400u, "mmap fpga_mem_addr = 0x%p\n", fpga_mem_addr);
            applog(2, tmp42, 0);
          }
          return ret;
        }
        else
        {
          if ( use_syslog || opt_log_output || opt_log_level > 1 )
          {
            snprintf(tmp42, 0x400u, "mmap fpga_mem_addr failed. fpga_mem_addr = 0x%p\n", fpga_mem_addr);
            applog(2, tmp42, 0);
          }
          return -1;
        }
      }
      else
      {
        if ( use_syslog || opt_log_output || opt_log_level > 1 )
        {
          snprintf(tmp42, 0x400u, "/dev/fpga_mem open failed. fd_fpga_mem = %d\n", fd_fpga_mem);
          applog(2, tmp42, 0);
        }
        return -1;
      }
    }
    else
    {
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "mmap axi_fpga_addr failed. axi_fpga_addr = 0x%p\n", axi_fpga_addr);
        applog(2, tmp42, 0);
      }
      return -1;
    }
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "/dev/axi_fpga_dev open failed. fd = %d\n", fd_fpga);
      applog(2, tmp42, 0);
    }
    return -1;
  }
}
