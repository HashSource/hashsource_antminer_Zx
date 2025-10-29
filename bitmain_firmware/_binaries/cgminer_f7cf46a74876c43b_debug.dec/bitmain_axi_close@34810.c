int bitmain_axi_close()
{
  printf("\n\n--- %s\n", "bitmain_axi_close");
  if ( munmap(axi_fpga_addr, 0x1200u) < 0 )
    puts("munmap failed!");
  if ( munmap(fpga_mem_addr, 0x1000000u) < 0 )
    puts("munmap failed!");
  close(fpga_fd);
  return j_close(fd_fpga_mem);
}
