__int64 __fastcall sub_15D7C(int a1)
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
  const char *v18; // r0
  char *v19; // r6
  unsigned int v20; // [sp+0h] [bp-820h] BYREF
  int v21; // [sp+4h] [bp-81Ch]
  __int64 v22; // [sp+8h] [bp-818h]
  __int64 v23; // [sp+10h] [bp-810h]
  __int64 v24; // [sp+18h] [bp-808h]
  char s[2048]; // [sp+20h] [bp-800h] BYREF

  if ( v1 == 0.0 )
  {
    if ( byte_632F0 || byte_630C0 || dword_60964 > 2 )
    {
      strcpy(s, "Diff zero passed to set_target");
      sub_38438(3, s, 0);
      v1 = 1.0;
    }
    else
    {
      v1 = 1.0;
    }
  }
  v3 = 1.7668201e72;
  if ( !byte_63DF9 )
    v3 = 2.69595353e67;
  v4 = v3 / v1;
  LODWORD(v5) = sub_494C0(v4 * 1.59309191e-58);
  v24 = v5;
  LODWORD(v6) = sub_493C8(v5);
  v7 = v4 - v6 * 6.27710174e57;
  LODWORD(v8) = sub_494C0(v7 * 2.93873588e-39);
  v23 = v8;
  LODWORD(v9) = sub_493C8(v8);
  v10 = v7 - v9 * 3.40282367e38;
  LODWORD(v11) = sub_494C0(v10 * 5.42101086e-20);
  v22 = v11;
  LODWORD(v12) = sub_493C8(v11);
  v20 = sub_494C0(v10 - v12 * 1.84467441e19);
  v21 = v13;
  if ( byte_630C1 )
  {
    v18 = sub_294B8((int)&v20, 32);
    v19 = (char *)v18;
    if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
    {
      snprintf(s, 0x800u, "Generated target %s", v18);
      sub_38438(7, s, 0);
    }
    free(v19);
  }
  v14 = v21;
  v15 = v22;
  *(_DWORD *)a1 = v20;
  *(_DWORD *)(a1 + 4) = v14;
  *(_QWORD *)(a1 + 8) = v15;
  result = v23;
  v17 = v24;
  *(_QWORD *)(a1 + 16) = v23;
  *(_QWORD *)(a1 + 24) = v17;
  return result;
}
