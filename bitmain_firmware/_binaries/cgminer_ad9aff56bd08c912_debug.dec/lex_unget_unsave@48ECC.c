_DWORD *__fastcall lex_unget_unsave(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r5
  const char *v4; // r1
  const char *v5; // r0

  if ( (unsigned int)a2 + 2 > 1 )
  {
    v2 = result;
    stream_unget(result, (int)a2);
    result = (_DWORD *)strbuffer_pop((strbuffer_t *)(v2 + 10));
    if ( result != a2 )
    {
      LOWORD(v4) = -19996;
      LOWORD(v5) = -19868;
      HIWORD(v4) = (unsigned int)"scan_number" >> 16;
      HIWORD(v5) = (unsigned int)"s] == c" >> 16;
      _assert_fail(v5, v4, 0x10Cu, "lex_unget_unsave");
    }
  }
  return result;
}
