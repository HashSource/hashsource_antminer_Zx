int bitmain_axi_close()
{
  const char *v0; // r0

  LOWORD(v0) = -31460;
  HIWORD(v0) = (unsigned int)"/fpga_mem open failed. fd_fpga_mem = %d\n" >> 16;
  printf(v0, "bitmain_axi_close");
  if ( munmap(axi_fpga_addr, 0x1200u) < 0 )
    puts("munmap failed!");
  if ( munmap(fpga_mem_addr, 0x1000000u) < 0 )
    puts("munmap failed!");
  close(fpga_fd);
  return j_close(fd_fpga_mem);
}
