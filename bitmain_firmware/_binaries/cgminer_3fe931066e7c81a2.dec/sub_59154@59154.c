int *__fastcall sub_59154(_DWORD *a1, unsigned int a2, int a3)
{
  unsigned int v6; // r7
  int v8; // r3
  int v9; // r3
  void **v10; // r0

  sub_5852C((int)a1, a3);
  v6 = a2 & 4;
  if ( (a2 & 4) == 0 && (a1[13] & 0xFFFFFFDF) != 0x5B )
  {
    sub_58034(a3, a1, "'[' or '{' expected");
    return (int *)v6;
  }
  v6 = (unsigned int)sub_58D00(COERCE_DOUBLE(__PAIR64__(a2, (unsigned int)a1)), a3);
  if ( !v6 )
    return 0;
  if ( (a2 & 2) == 0 )
  {
    sub_5852C((int)a1, a3);
    if ( a1[13] )
    {
      sub_58034(a3, a1, "end of file expected");
      v8 = *(_DWORD *)(v6 + 4);
      if ( v8 != -1 )
      {
        v9 = v8 - 1;
        *(_DWORD *)(v6 + 4) = v9;
        if ( !v9 )
        {
          v10 = (void **)v6;
          v6 = 0;
          sub_5A3E4(v10);
          return (int *)v6;
        }
      }
      return 0;
    }
  }
  if ( a3 )
    *(_DWORD *)(a3 + 8) = a1[9];
  return (int *)v6;
}
