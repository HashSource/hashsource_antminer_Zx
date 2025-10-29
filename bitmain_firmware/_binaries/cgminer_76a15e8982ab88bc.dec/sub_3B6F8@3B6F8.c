int sub_3B6F8()
{
  printf("\n\n--- %s\n", "bitmain_axi_close");
  if ( munmap((void *)dword_75C50[0], 0x1200u) < 0 )
    puts("munmap failed!");
  if ( munmap((void *)dword_75CF8, 0x1000000u) < 0 )
    puts("munmap failed!");
  close(dword_78BB8);
  return close(dword_78F10);
}
