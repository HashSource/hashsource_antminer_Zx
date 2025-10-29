void __fastcall sub_16A78(int a1, _DWORD *a2)
{
  int v3; // r3
  int v4; // r0
  int v5; // r12
  bool v6; // zf
  int v7; // r0
  int v8; // r0
  int v9; // r3
  int v10; // r0
  int v11; // r3
  int v12; // r3

  --*(_DWORD *)(a1 + 360);
  v3 = a2[459];
  if ( v3 || a2[460] )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(a1 + 352) + 1832);
    v5 = *(_DWORD *)(v4 + 20);
    if ( (_DWORD *)(*(_DWORD *)(v4 + 16) - v5) == a2 )
    {
      *(_DWORD *)(v4 + 16) = v3 + v5;
      v3 = a2[459];
    }
    v6 = v3 == 0;
    if ( v3 )
    {
      v5 = *(_DWORD *)(a1 + 352);
      v4 = a2[460];
    }
    else
    {
      v3 = a2[460];
    }
    if ( v6 )
      *(_DWORD *)(a1 + 352) = v3;
    else
      v5 = *(_DWORD *)(v5 + 1832);
    if ( !v6 )
    {
      v3 += *(_DWORD *)(v5 + 20);
      *(_DWORD *)(v3 + 8) = v4;
    }
    v7 = a2[460];
    if ( !v6 )
      v3 = *(_DWORD *)(a1 + 352);
    if ( v7 )
    {
      *(_DWORD *)(v7 + *(_DWORD *)(*(_DWORD *)(v3 + 1832) + 20) + 4) = a2[459];
      v3 = *(_DWORD *)(a1 + 352);
    }
    v8 = **(_DWORD **)(v3 + 1832);
    v9 = 12 * ((*(_DWORD *)(*(_DWORD *)(v3 + 1832) + 4) - 1) & a2[465]);
    --*(_DWORD *)(v8 + v9 + 4);
    v10 = **(_DWORD **)(*(_DWORD *)(a1 + 352) + 1832);
    if ( *(_DWORD **)(v10 + v9) == a2 + 458 )
      *(_DWORD *)(v10 + v9) = a2[462];
    v11 = a2[461];
    if ( v11 )
      *(_DWORD *)(v11 + 16) = a2[462];
    v12 = a2[462];
    if ( v12 )
      *(_DWORD *)(v12 + 12) = a2[461];
    --*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 352) + 1832) + 12);
  }
  else
  {
    free(**(void ***)(*(_DWORD *)(a1 + 352) + 1832));
    free(*(void **)(*(_DWORD *)(a1 + 352) + 1832));
    *(_DWORD *)(a1 + 352) = 0;
  }
}
