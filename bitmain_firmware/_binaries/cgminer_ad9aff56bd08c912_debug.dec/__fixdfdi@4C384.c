// Alternative name is '__aeabi_d2lz'
DItype __fastcall _fixdfdi(DFtype a)
{
  DItype result; // r0
  unsigned __int64 v2; // r0
  bool v3; // cf

  if ( a >= 0.0 )
    return (unsigned __int64)a;
  HIDWORD(a) ^= 0x80000000;
  v2 = (unsigned __int64)a;
  v3 = (_DWORD)v2 == 0;
  LODWORD(result) = -(int)v2;
  HIDWORD(result) = HIDWORD(v2) - (2 * HIDWORD(v2) + !v3);
  return result;
}
