_DWORD *__fastcall lex_unget_unsave(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r5

  if ( (unsigned int)a2 + 2 > 1 )
  {
    v2 = result;
    stream_unget(result, (int)a2);
    result = (_DWORD *)strbuffer_pop((strbuffer_t *)(v2 + 10));
    if ( result != a2 )
      _assert_fail("c == d", "load.c", 0x10Cu, "lex_unget_unsave");
  }
  return result;
}
