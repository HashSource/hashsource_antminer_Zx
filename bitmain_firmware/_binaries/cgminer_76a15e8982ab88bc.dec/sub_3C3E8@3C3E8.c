int __fastcall sub_3C3E8(int a1)
{
  int v1; // r4
  int v2; // r3

  sub_3C378(a1 | 0x2000000);
  v1 = 22;
  do
  {
    usleep(0x1388u);
    v2 = *(_DWORD *)(dword_75C50[0] + 48);
    if ( v2 < 0 )
      return (unsigned __int8)v2;
    --v1;
  }
  while ( v1 );
  printf("%s: i2c always busy, break\n", "i2c_read");
  return 255;
}
