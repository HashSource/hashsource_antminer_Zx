bool __fastcall sub_165A0(int a1, int a2)
{
  double v2; // d0
  double v4; // d16
  unsigned __int64 v5; // r0

  *(_DWORD *)(a1 + 76) = a2;
  if ( byte_7B859 )
    sub_14F30(a1);
  else
    sub_11F60(a1);
  v4 = 2.81470682e14;
  if ( !byte_7B859 )
    v4 = 4294901760.0;
  LODWORD(v5) = sub_5CC48(v4 / v2);
  return v5 >= *(_QWORD *)(a1 + 216);
}
