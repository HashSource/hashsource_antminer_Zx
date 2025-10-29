int __fastcall sub_11994(int a1)
{
  double v1; // d0
  int v3; // r4
  double *v4; // r6
  int v5; // r0
  double v6; // d8
  double v7; // d0
  unsigned __int64 v8; // r0
  int result; // r0
  double v10; // d16
  double v11; // d16
  __int64 v12; // r0
  double v13; // d9
  double v14; // r0
  double v15; // d8
  double v16; // r0
  double v17; // d8
  double v18; // r0
  double v19; // d8
  double v20; // r0
  double v21; // d8

  v3 = *(_DWORD *)(a1 + 1748);
  if ( v1 == 0.0 )
  {
    v12 = *(_QWORD *)(a1 + 184);
    v13 = 65536.0;
    if ( !byte_78681 )
      v13 = 2.69595353e67;
    LODWORD(v14) = sub_59F08(v12);
    v15 = v14 * 6.27710174e57;
    LODWORD(v16) = sub_59F08(*(_QWORD *)(a1 + 176));
    v17 = v15 + v16 * 3.40282367e38;
    LODWORD(v18) = sub_59F08(*(_QWORD *)(a1 + 168));
    v19 = v17 + v18 * 1.84467441e19;
    LODWORD(v20) = sub_59F08(*(_QWORD *)(a1 + 160));
    v21 = v19 + v20;
    if ( v21 == 0.0 )
      v21 = 1.0;
    *(double *)(a1 + 1864) = v13 / v21;
    v4 = (double *)(a1 + 1864);
  }
  else
  {
    v4 = (double *)(a1 + 1864);
    *(double *)(a1 + 1864) = v1;
  }
  v5 = sub_484C8(a1 + 160);
  v6 = (double)v5;
  *v4 = (double)v5;
  v7 = (double)v5;
  *(double *)(v3 + 504) = (double)v5;
  round(v5);
  LODWORD(v8) = sub_5A000(v7);
  result = sub_114B8(v8, (char *)(*(_DWORD *)(a1 + 1748) + 48), 8u, 0);
  v10 = *(double *)(v3 + 488);
  if ( v6 == v10 )
  {
    ++*(_DWORD *)(v3 + 512);
    goto LABEL_5;
  }
  if ( v6 >= v10 )
  {
    if ( v10 != 0.0 )
    {
LABEL_5:
      v11 = *(double *)(v3 + 496);
      if ( v6 != v11 )
        goto LABEL_6;
LABEL_17:
      ++*(_DWORD *)(v3 + 516);
      return result;
    }
    *(double *)(v3 + 488) = v6;
    *(_DWORD *)(v3 + 512) = 1;
  }
  else
  {
    *(double *)(v3 + 488) = v6;
    *(_DWORD *)(v3 + 512) = 1;
  }
  v11 = *(double *)(v3 + 496);
  if ( v6 == v11 )
    goto LABEL_17;
LABEL_6:
  if ( v6 > v11 )
  {
    *(double *)(v3 + 496) = v6;
    *(_DWORD *)(v3 + 516) = 1;
  }
  return result;
}
