bool __fastcall sub_16030(int a1, int a2)
{
  double v2; // d0
  double v4; // d16
  unsigned __int64 v5; // r0

  *(_DWORD *)(a1 + 76) = a2;
  if ( byte_63DF9 )
    sub_14A88(a1);
  else
    sub_117A4(a1);
  v4 = 2.81470682e14;
  if ( !byte_63DF9 )
    v4 = 4294901760.0;
  LODWORD(v5) = sub_494C0(v4 / v2);
  return v5 >= *(_QWORD *)(a1 + 216);
}
