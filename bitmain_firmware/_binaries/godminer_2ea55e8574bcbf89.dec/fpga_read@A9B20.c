int __fastcall fpga_read(int a1, _DWORD *a2)
{
  unsigned int v2; // r2

  v2 = a1 & 0xFFFFFFFC;
  *a2 = *(_DWORD *)(dword_1852EC + v2);
  return 0;
}
