int sub_3B704()
{
  int fd; // r0
  void *v1; // r1
  int v2; // r0
  void *v3; // r1

  fd = open("/dev/axi_fpga_dev", 2);
  dword_7BD90 = fd;
  if ( fd < 0 )
  {
    printf("/dev/axi_fpga_dev open failed. fd = %d\n", fd);
    return -1;
  }
  else
  {
    v1 = mmap(0, 0x1200u, 3, 1, fd, 0);
    dword_78E10[0] = (int)v1;
    if ( v1 )
    {
      printf("mmap axi_fpga_addr = 0x%x\n", v1);
      printf("axi_fpga_addr data = 0x%x\n", *(unsigned __int16 *)dword_78E10[0]);
      v2 = open("/dev/fpga_mem", 2);
      dword_7C0E8 = v2;
      if ( v2 < 0 )
      {
        printf("/dev/fpga_mem open failed. fd_fpga_mem = %d\n", v2);
        return -1;
      }
      else
      {
        v3 = mmap(0, 0x1000000u, 3, 1, v2, 0);
        dword_78EB8 = (int)v3;
        if ( v3 )
        {
          printf("mmap fpga_mem_addr = 0x%x\n", v3);
          return 0;
        }
        else
        {
          printf("mmap fpga_mem_addr failed. fpga_mem_addr = 0x%x\n", 0);
          return -1;
        }
      }
    }
    else
    {
      printf("mmap axi_fpga_addr failed. axi_fpga_addr = 0x%x\n", 0);
      return -1;
    }
  }
}
