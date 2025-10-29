_DWORD *__fastcall sub_584B0(_DWORD *result, _DWORD *a2)
{
  _DWORD *v3; // r5
  int v4; // r1
  int v5; // r2

  v3 = result;
  if ( (unsigned int)a2 + 2 > 1 )
  {
    sub_58274(result, (int)a2);
    result = (_DWORD *)sub_597C0(v3 + 10, v4, v5);
    if ( result != a2 )
      _assert_fail("c == d", "load.c", 0x10Cu, "lex_unget_unsave");
  }
  return result;
}
