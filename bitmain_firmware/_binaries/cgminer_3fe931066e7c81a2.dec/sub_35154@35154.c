int __fastcall sub_35154(unsigned int *a1, int a2, const char *a3, const char *a4, int a5, unsigned __int8 a6)
{
  _DWORD *v9; // r0
  _DWORD *v10; // r0
  _DWORD *v11; // r0
  _DWORD *v12; // r0
  _DWORD *v13; // r0
  _DWORD *v14; // r0
  _DWORD *v15; // r0
  _DWORD *v16; // r0
  _DWORD *v17; // r0
  int v18; // r2
  int v19; // r1
  int v20; // r3
  _BOOL4 v21; // r3
  int v23; // [sp+4h] [bp-10h] BYREF
  double v24; // [sp+8h] [bp-Ch] BYREF

  v23 = a2;
  v24 = dbl_7ACC0 / dbl_755F8;
  v9 = sub_32ED0(0, "STATS", (const char *)&v23, 0);
  v10 = sub_32E1C(v9, "ID", a3, 0);
  v11 = sub_32FCC(v10, "Elapsed", (const char *)&dbl_755F8, 0);
  v12 = sub_32F18(v11, "Calls", a4, 0);
  v13 = sub_33014(v12, "Wait", a4 + 4, 0);
  v14 = sub_33014(v13, "Max", a4 + 12, 0);
  v15 = sub_33014(v14, "Min", a4 + 20, 0);
  v16 = sub_32E1C(v15, "GHS 5s", byte_78B84, 0);
  v17 = sub_34EB0(v16, "GHS av", (const char *)&v24, 0);
  v19 = (int)v17;
  if ( a5 )
  {
    if ( v17 )
      v18 = v17[4];
    else
      v19 = a5;
    if ( v17 )
    {
      v20 = *(_DWORD *)(a5 + 16);
      *(_DWORD *)(a5 + 16) = v18;
      *(_DWORD *)(v17[4] + 20) = a5;
      *(_DWORD *)(v20 + 20) = v17;
      v17[4] = v20;
    }
  }
  if ( a6 )
    v21 = v23 > 0;
  else
    v21 = 0;
  sub_32534(a1, v19, a6, v21);
  return v23 + 1;
}
