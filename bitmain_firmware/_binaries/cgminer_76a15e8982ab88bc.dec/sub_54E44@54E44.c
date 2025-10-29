int __fastcall sub_54E44(int a1, char *a2, int a3, int a4)
{
  unsigned int v6; // r1
  char *v7; // r9
  int v8; // r12
  char *v9; // lr
  unsigned int v10; // r4
  int v11; // r5
  int v12; // t1
  int *v13; // r9
  int v14; // r0
  int v15; // r5
  int v16; // r0
  int v17; // r3
  int v18; // r3
  int v20; // r3
  unsigned int v21; // r4
  _DWORD *v22; // r11
  int v23; // r3
  _DWORD *v24; // r10
  int v25; // r1
  _DWORD *v26; // r2
  size_t v27; // r0
  void *v28; // r0
  _DWORD *v29; // r11

  v6 = dword_6956C[*(_DWORD *)(a1 + 8)];
  if ( *(_DWORD *)a1 >= v6 )
  {
    sub_5694C(*(void **)(a1 + 4));
    v20 = *(_DWORD *)(a1 + 8) + 1;
    *(_DWORD *)(a1 + 8) = v20;
    v21 = dword_6956C[v20];
    v7 = (char *)sub_56924(8 * v21);
    *(_DWORD *)(a1 + 4) = v7;
    if ( !v7 )
      return -1;
    v6 = dword_6956C[*(_DWORD *)(a1 + 8)];
    if ( v6 )
    {
      v22 = (_DWORD *)(a1 + 12);
      v23 = 0;
      do
      {
        *(_DWORD *)&v7[v23 + 4] = v22;
        *(_DWORD *)&v7[v23] = v22;
        v23 += 8;
      }
      while ( v23 != 8 * v6 );
    }
    else
    {
      v22 = (_DWORD *)(a1 + 12);
    }
    v24 = *(_DWORD **)(a1 + 16);
    *(_DWORD *)(a1 + 12) = v22;
    *(_DWORD *)(a1 + 16) = v22;
    if ( v24 != v22 )
    {
      while ( 1 )
      {
        v25 = *(v24 - 1) % v21;
        v26 = v24;
        v24 = (_DWORD *)v24[1];
        sub_54C78(a1, (int)&v7[8 * v25], v26);
        if ( v22 == v24 )
          break;
        v7 = *(char **)(a1 + 4);
      }
      v7 = *(char **)(a1 + 4);
      v6 = dword_6956C[*(_DWORD *)(a1 + 8)];
    }
  }
  else
  {
    v7 = *(char **)(a1 + 4);
  }
  v8 = (unsigned __int8)*a2;
  if ( *a2 )
  {
    v9 = a2;
    v10 = 5381;
    do
    {
      v11 = v8 + 32 * v10;
      v12 = (unsigned __int8)*++v9;
      v8 = v12;
      v10 += v11;
    }
    while ( v12 );
  }
  else
  {
    v10 = 5381;
  }
  v13 = (int *)&v7[8 * (v10 % v6)];
  v14 = sub_54CD4(a1, v13, a2, v10);
  v15 = v14;
  if ( !v14 )
  {
    v27 = strlen(a2);
    v28 = sub_56924(v27 + 21);
    v29 = v28;
    if ( v28 )
    {
      *(_DWORD *)v28 = v10;
      *((_DWORD *)v28 + 4) = a3;
      strcpy((char *)v28 + 20, a2);
      v29[2] = v29 + 1;
      v29[3] = a4;
      v29[1] = v29 + 1;
      sub_54C78(a1, (int)v13, v29 + 1);
      ++*(_DWORD *)a1;
      return 0;
    }
    return -1;
  }
  v16 = *(_DWORD *)(v14 + 12);
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
  *(_DWORD *)(v15 + 12) = a4;
  return 0;
}
