int __fastcall sub_3C708(int a1)
{
  int v1; // r4
  int v2; // r3

  sub_3C66C(a1 | 0x2000000);
  v1 = 22;
  do
  {
    usleep(0x1388u);
    v2 = *(_DWORD *)(dword_78E10[0] + 48);
    if ( v2 < 0 )
      return (unsigned __int8)v2;
    --v1;
  }
  while ( v1 );
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    return sub_3AE24();
  else
    return 255;
}
