void __fastcall sub_57E28(_DWORD *a1)
{
  int v2; // r4
  int v3; // r1
  int v4; // r4
  _DWORD *v5; // r2
  int v6; // r3

  sub_57994((int)a1);
  v2 = dword_6CB74[a1[2]];
  if ( v2 )
  {
    v3 = a1[1];
    v4 = 8 * v2;
    v5 = a1 + 3;
    v6 = 0;
    do
    {
      *(_DWORD *)(v3 + v6 + 4) = v5;
      *(_DWORD *)(v3 + v6) = v5;
      v6 += 8;
    }
    while ( v6 != v4 );
  }
  else
  {
    v5 = a1 + 3;
  }
  a1[4] = v5;
  a1[3] = v5;
  *a1 = 0;
}
