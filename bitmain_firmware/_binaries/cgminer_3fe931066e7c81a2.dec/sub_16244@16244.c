__int64 __fastcall sub_16244(int a1)
{
  double v1; // d0
  double v3; // d8
  double v4; // d8
  __int64 v5; // r0
  double v6; // r0
  double v7; // d8
  __int64 v8; // r0
  double v9; // r0
  double v10; // d8
  __int64 v11; // r0
  double v12; // r0
  int v13; // r1
  int v14; // r1
  __int64 v15; // r2
  __int64 result; // r0
  __int64 v17; // r2
  char *v18; // r6
  unsigned int v19; // [sp+0h] [bp-1020h] BYREF
  int v20; // [sp+4h] [bp-101Ch]
  __int64 v21; // [sp+8h] [bp-1018h]
  __int64 v22; // [sp+10h] [bp-1010h]
  __int64 v23; // [sp+18h] [bp-1008h]
  char s[4096]; // [sp+20h] [bp-1000h] BYREF

  if ( v1 == 0.0 )
  {
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
    {
      strcpy(s, "Diff zero passed to set_target");
      sub_38730(3, s, 0);
      v1 = 1.0;
    }
    else
    {
      v1 = 1.0;
    }
  }
  v3 = 1.7668201e72;
  if ( !byte_7B859 )
    v3 = 2.69595353e67;
  v4 = v3 / v1;
  LODWORD(v5) = sub_5CC48(v4 * 1.59309191e-58);
  v23 = v5;
  LODWORD(v6) = sub_5CB50(v5);
  v7 = v4 - v6 * 6.27710174e57;
  LODWORD(v8) = sub_5CC48(v7 * 2.93873588e-39);
  v22 = v8;
  LODWORD(v9) = sub_5CB50(v8);
  v10 = v7 - v9 * 3.40282367e38;
  LODWORD(v11) = sub_5CC48(v10 * 5.42101086e-20);
  v21 = v11;
  LODWORD(v12) = sub_5CB50(v11);
  v19 = sub_5CC48(v10 - v12 * 1.84467441e19);
  v20 = v13;
  if ( byte_78E09 )
  {
    v18 = sub_29730((int)&v19, 32);
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(s, 0x1000u, "Generated target %s", v18);
      sub_38730(7, s, 0);
    }
    free(v18);
  }
  v14 = v20;
  v15 = v21;
  *(_DWORD *)a1 = v19;
  *(_DWORD *)(a1 + 4) = v14;
  *(_QWORD *)(a1 + 8) = v15;
  result = v22;
  v17 = v23;
  *(_QWORD *)(a1 + 16) = v22;
  *(_QWORD *)(a1 + 24) = v17;
  return result;
}
