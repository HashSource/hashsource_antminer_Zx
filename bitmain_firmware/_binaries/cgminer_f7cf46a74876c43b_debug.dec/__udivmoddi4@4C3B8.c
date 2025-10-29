UDItype __fastcall _udivmoddi4(UDItype n, UDItype d, UDItype *rp)
{
  bool v3; // cf
  UDItype v4; // r4
  unsigned int v5; // r12
  unsigned int v6; // r1
  unsigned int v7; // r12
  char v8; // r8
  char v9; // r9
  UDItype v10; // r6
  UDItype v11; // r6
  unsigned int v12; // r2
  int v13; // off

  v3 = n >= d;
  LODWORD(v4) = n;
  if ( n < d )
    LODWORD(n) = 0;
  HIDWORD(v4) = HIDWORD(n);
  if ( !v3 )
  {
    HIDWORD(n) = n;
    goto LABEL_16;
  }
  v5 = __clz(HIDWORD(d));
  if ( HIDWORD(d) )
  {
    v6 = __clz(HIDWORD(n));
    if ( HIDWORD(v4) )
      goto LABEL_7;
    goto LABEL_19;
  }
  v6 = __clz(HIDWORD(n));
  v5 = __clz(d) + 32;
  if ( !HIDWORD(v4) )
LABEL_19:
    v6 = __clz(v4) + 32;
LABEL_7:
  v7 = v5 - v6;
  v8 = v7 - 32;
  v9 = 32 - v7;
  v10 = d << v7;
  if ( v4 >= d << v7 )
  {
    LODWORD(n) = 1 << v7;
    v4 -= v10;
    HIDWORD(n) = (1 << v8) | (1u >> v9);
  }
  else
  {
    n = 0;
  }
  if ( v7 )
  {
    v11 = v10 >> 1;
    v12 = v7;
    do
    {
      while ( v4 >= v11 )
      {
        v4 = 2 * (v4 - v11) + 1;
        if ( !--v12 )
          goto LABEL_15;
      }
      v13 = (v4 + (unsigned int)v4) >> 32;
      LODWORD(v4) = 2 * v4;
      HIDWORD(v4) += v13;
      --v12;
    }
    while ( v12 );
LABEL_15:
    v3 = __CFADD__((_DWORD)n, (_DWORD)v4);
    LODWORD(n) = n + v4;
    LODWORD(v4) = ((unsigned int)v4 >> v7) | (HIDWORD(v4) << v9) | (HIDWORD(v4) >> v8);
    HIDWORD(n) += v3 + HIDWORD(v4);
    HIDWORD(v4) >>= v7;
    n -= v4 << v7;
  }
LABEL_16:
  if ( rp )
    *rp = v4;
  return n;
}
