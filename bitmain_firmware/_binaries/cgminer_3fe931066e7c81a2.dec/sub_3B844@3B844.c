int sub_3B844()
{
  printf("\n\n--- %s\n", "bitmain_axi_close");
  if ( munmap((void *)dword_78E10[0], 0x1200u) < 0 )
    puts("munmap failed!");
  if ( munmap((void *)dword_78EB8, 0x1000000u) < 0 )
    puts("munmap failed!");
  close(dword_7BD90);
  return close(dword_7C0E8);
}
