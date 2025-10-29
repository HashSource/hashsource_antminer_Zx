void __fastcall sub_4420C(int a1)
{
  int v1; // r3
  int v2; // r6
  int v3; // r0
  void *v4; // r5
  int v5; // r4
  int v6; // r1

  v1 = *(_DWORD *)(a1 + 16);
  v2 = a1 + 12;
  if ( v1 != a1 + 12 )
  {
    do
    {
      v3 = *(_DWORD *)(v1 + 8);
      v4 = (void *)(v1 - 4);
      v5 = *(_DWORD *)(v1 + 4);
      if ( v3 )
      {
        v6 = *(_DWORD *)(v3 + 4);
        if ( v6 != -1 )
        {
          *(_DWORD *)(v3 + 4) = v6 - 1;
          if ( v6 == 1 )
            sub_46C5C((void **)v3);
        }
      }
      sub_45E0C(v4);
      v1 = v5;
    }
    while ( v5 != v2 );
  }
}
