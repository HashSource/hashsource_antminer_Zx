int __fastcall sub_3C378(int a1)
{
  int v2; // r4
  int result; // r0

  v2 = 22;
  do
  {
    result = 5000;
    if ( *(int *)(dword_75C50[0] + 48) < 0 )
    {
      *(_DWORD *)(dword_75C50[0] + 48) = a1;
      return result;
    }
    usleep(0x1388u);
    --v2;
  }
  while ( v2 );
  return printf("%s: i2c always busy, break\n", "i2c_write");
}
