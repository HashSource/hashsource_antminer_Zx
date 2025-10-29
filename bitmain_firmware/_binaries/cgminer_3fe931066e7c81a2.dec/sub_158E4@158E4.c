__int64 __fastcall sub_158E4(__int64 *a1)
{
  __int64 v2; // r0
  double v3; // d9
  double v4; // r0
  double v5; // d8
  double v6; // r0
  double v7; // d8
  double v8; // r0
  double v9; // d17
  double v10; // r0
  double v11; // d8
  int v12; // r1
  __int64 v13; // d16

  if ( !a1 )
    return 0;
  v2 = a1[27];
  v3 = 1.7668201e72;
  if ( !byte_7B859 )
    v3 = 2.69595353e67;
  LODWORD(v4) = sub_5CB50(v2);
  v5 = v4 * 6.27710174e57;
  LODWORD(v6) = sub_5CB50(a1[26]);
  v7 = v5 + v6 * 3.40282367e38;
  LODWORD(v8) = sub_5CB50(a1[25]);
  v9 = v8;
  LODWORD(v10) = sub_5CB50(a1[24]);
  v11 = v7 + v9 * 1.84467441e19 + v10;
  if ( v11 == 0.0 )
    return 0;
  LODWORD(v13) = sub_5CC48(v3 / v11);
  HIDWORD(v13) = v12;
  return v13;
}
