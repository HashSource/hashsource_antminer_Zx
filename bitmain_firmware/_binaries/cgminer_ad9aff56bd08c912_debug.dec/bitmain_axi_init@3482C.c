int bitmain_axi_init()
{
  const char *v0; // r0
  int fd; // r0
  unsigned int *v2; // r1
  const char *v3; // r0
  int v4; // r0
  unsigned int *v5; // r1

  LOWORD(v0) = -31772;
  HIWORD(v0) = (unsigned int)"r:scanhash chainid=%u\n" >> 16;
  fd = open(v0, 2);
  fpga_fd = fd;
  if ( fd < 0 )
  {
    printf("/dev/axi_fpga_dev open failed. fd = %d\n", fd);
    return -1;
  }
  else
  {
    v2 = (unsigned int *)mmap(0, 0x1200u, 3, 1, fd, 0);
    axi_fpga_addr = v2;
    if ( v2 )
    {
      printf("mmap axi_fpga_addr = 0x%x\n", v2);
      printf("axi_fpga_addr data = 0x%x\n", *(unsigned __int16 *)axi_fpga_addr);
      LOWORD(v3) = -31604;
      HIWORD(v3) = (unsigned int)"ailed. fd = %d\n" >> 16;
      v4 = open(v3, 2);
      fd_fpga_mem = v4;
      if ( v4 < 0 )
      {
        printf("/dev/fpga_mem open failed. fd_fpga_mem = %d\n", v4);
        return -1;
      }
      else
      {
        v5 = (unsigned int *)mmap(0, 0x1000000u, 3, 1, v4, 0);
        fpga_mem_addr = v5;
        if ( v5 )
        {
          printf("mmap fpga_mem_addr = 0x%x\n", v5);
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
