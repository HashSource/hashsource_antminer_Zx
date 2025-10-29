bool __fastcall sub_1654C(int a1, int a2)
{
  unsigned int v3; // r0

  *(_DWORD *)(a1 + 76) = a2;
  if ( byte_7B859 )
    sub_14F30(a1);
  else
    sub_11F60(a1);
  if ( byte_7B859 )
    v3 = 0xFFFF;
  else
    v3 = 0;
  return v3 >= *(_DWORD *)(a1 + 220);
}
