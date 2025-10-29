int __fastcall sub_113C4(int a1)
{
  double v1; // d0
  int v3; // r4
  double v4; // d8
  __int64 v5; // r0
  double v6; // d8
  double v7; // r0
  double v8; // d9
  double v9; // r0
  double v10; // d9
  double v11; // r0
  double v12; // d9
  double v13; // r0
  double v14; // d9
  unsigned __int64 v15; // r0
  int result; // r0
  double v17; // d16
  double v18; // d16

  v3 = *(_DWORD *)(a1 + 260);
  v4 = v1;
  if ( v1 == 0.0 )
  {
    v5 = *(_QWORD *)(a1 + 184);
    v6 = 65536.0;
    if ( !byte_63DF9 )
      v6 = 2.69595353e67;
    LODWORD(v7) = sub_493C8(v5);
    v8 = v7 * 6.27710174e57;
    LODWORD(v9) = sub_493C8(*(_QWORD *)(a1 + 176));
    v10 = v8 + v9 * 3.40282367e38;
    LODWORD(v11) = sub_493C8(*(_QWORD *)(a1 + 168));
    v12 = v10 + v11 * 1.84467441e19;
    LODWORD(v13) = sub_493C8(*(_QWORD *)(a1 + 160));
    v14 = v12 + v13;
    if ( v14 == 0.0 )
      v14 = 1.0;
    v4 = v6 / v14;
  }
  *(double *)(a1 + 376) = v4;
  *(double *)(v3 + 472) = v4;
  round();
  LODWORD(v15) = sub_494C0(v4);
  result = sub_11130(v15, (char *)(*(_DWORD *)(a1 + 260) + 48), 8u, 0);
  v17 = *(double *)(v3 + 456);
  if ( v17 == v4 )
  {
    ++*(_DWORD *)(v3 + 480);
    goto LABEL_9;
  }
  if ( v17 <= v4 )
  {
    if ( v17 != 0.0 )
    {
LABEL_9:
      v18 = *(double *)(v3 + 464);
      if ( v18 != v4 )
        goto LABEL_10;
LABEL_16:
      ++*(_DWORD *)(v3 + 484);
      return result;
    }
    *(double *)(v3 + 456) = v4;
    *(_DWORD *)(v3 + 480) = 1;
  }
  else
  {
    *(double *)(v3 + 456) = v4;
    *(_DWORD *)(v3 + 480) = 1;
  }
  v18 = *(double *)(v3 + 464);
  if ( v18 == v4 )
    goto LABEL_16;
LABEL_10:
  if ( v18 < v4 )
  {
    *(double *)(v3 + 464) = v4;
    *(_DWORD *)(v3 + 484) = 1;
  }
  return result;
}
