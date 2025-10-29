void __fastcall sub_33DE0(unsigned int *a1, int a2, char *nptr, int a4, int a5)
{
  unsigned int *v6; // r6
  int v7; // r2
  int v8; // r3
  int v9; // r1
  int v10; // r0
  int v11; // r7
  int v12; // r4
  char *v13; // r0
  char *v14; // r8
  unsigned __int8 v15; // [sp+20h] [bp+18h]

  v6 = a1;
  if ( !dword_77FC0 )
  {
    v15 = a4;
    v7 = 0;
    v8 = 0;
    v9 = 8;
    goto LABEL_5;
  }
  if ( !nptr || !*nptr )
  {
    v7 = 0;
    v15 = a4;
    v8 = 0;
    v9 = 25;
LABEL_5:
    sub_32ECC(a1, v9, v7, v8, v15);
    return;
  }
  v10 = strtol(nptr, 0, 10);
  v11 = v10;
  if ( v10 < 0 || v10 >= dword_77FC0 )
  {
    v15 = a4;
    a1 = v6;
    v7 = v11;
    v9 = 26;
    v8 = 0;
    goto LABEL_5;
  }
  if ( dword_77FC0 <= 1 )
  {
    v15 = a4;
    a1 = v6;
    v7 = v11;
    v9 = 66;
    v8 = 0;
    goto LABEL_5;
  }
  v12 = *(_DWORD *)(dword_78260 + 4 * v10);
  if ( v12 == sub_1D9A0() )
    sub_1A600(0);
  if ( v12 == sub_1D9A0() )
  {
    v15 = a4;
    a1 = v6;
    v7 = v11;
    v9 = 67;
    v8 = 0;
    goto LABEL_5;
  }
  v13 = *(char **)(v12 + 196);
  *(_DWORD *)(v12 + 132) = 0;
  v14 = sub_30370(v13, a4);
  if ( v14 == *(char **)(v12 + 196) )
  {
    sub_15A00(v12);
    v15 = a4;
    a1 = v6;
    v7 = v11;
    v8 = (int)v14;
    v9 = 68;
    goto LABEL_5;
  }
  sub_15A00(v12);
  sub_32ECC(v6, 68, v11, (int)v14, a4);
  free(v14);
}
