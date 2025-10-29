_DWORD *__fastcall sub_37D54(_DWORD *a1, int a2, int a3)
{
  _DWORD *v6; // r7
  unsigned int *v8; // r3
  unsigned int v9; // r2
  unsigned int v10; // r2
  _DWORD *v11; // r0

  a1[14] = 0;
  sub_37084((int)a1, a3);
  v6 = (_DWORD *)(a2 & 4);
  if ( (a2 & 4) == 0 && (a1[15] & 0xFFFFFFDF) != 0x5B )
  {
    sub_36CCC(a3, a1, 8, "'[' or '{' expected");
    return v6;
  }
  v6 = sub_378B0((int)a1, a2, a3);
  if ( v6 )
  {
    if ( (a2 & 2) != 0 || (sub_37084((int)a1, a3), !a1[15]) )
    {
      if ( a3 )
        *(_DWORD *)(a3 + 8) = a1[9];
      return v6;
    }
    sub_36CCC(a3, a1, 7, "end of file expected");
    if ( v6[1] != -1 )
    {
      v8 = v6 + 1;
      __dmb(0xBu);
      do
      {
        v9 = __ldrex(v8);
        v10 = v9 - 1;
      }
      while ( __strex(v10, v8) );
      if ( !v10 )
      {
        v11 = v6;
        v6 = 0;
        json_delete(v11);
        return v6;
      }
    }
  }
  return 0;
}
