int __fastcall sub_550C4(_DWORD *a1, char *a2)
{
  int v2; // r3
  char *v4; // r12
  unsigned int v5; // r4
  int v6; // lr
  int v7; // t1
  int v8; // r7
  int *v9; // r6
  int v10; // r8
  _DWORD *v11; // r0
  _DWORD *v12; // r4
  _DWORD *v13; // r3
  int v14; // r2
  int v15; // r3
  int v16; // r0
  int v17; // r3
  int v18; // r3
  _DWORD *v20; // r3

  v2 = (unsigned __int8)*a2;
  if ( *a2 )
  {
    v4 = a2;
    v5 = 5381;
    do
    {
      v6 = v2 + 32 * v5;
      v7 = (unsigned __int8)*++v4;
      v2 = v7;
      v5 += v6;
    }
    while ( v7 );
  }
  else
  {
    v5 = 5381;
  }
  v8 = a1[1];
  v9 = (int *)(v8 + 8 * (v5 % dword_6956C[a1[2]]));
  v10 = v5 % dword_6956C[a1[2]];
  v11 = (_DWORD *)sub_54CD4((int)a1, v9, a2, v5);
  v12 = v11;
  if ( !v11 )
    return -1;
  v13 = v11 + 1;
  v14 = v9[1];
  if ( v11 + 1 == *(_DWORD **)(v8 + 8 * v10) )
  {
    if ( v13 == (_DWORD *)v14 )
    {
      v20 = a1 + 3;
      v9[1] = (int)(a1 + 3);
    }
    else
    {
      v20 = (_DWORD *)v11[2];
    }
    *(_DWORD *)(v8 + 8 * v10) = v20;
  }
  else if ( v13 == (_DWORD *)v14 )
  {
    v9[1] = v11[1];
  }
  v15 = v11[1];
  v16 = v11[3];
  *(_DWORD *)(v15 + 4) = v12[2];
  *(_DWORD *)v12[2] = v15;
  if ( v16 )
  {
    v17 = *(_DWORD *)(v16 + 4);
    if ( v17 != -1 )
    {
      v18 = v17 - 1;
      *(_DWORD *)(v16 + 4) = v18;
      if ( !v18 )
        sub_5779C((void **)v16);
    }
  }
  sub_5694C(v12);
  --*a1;
  return 0;
}
