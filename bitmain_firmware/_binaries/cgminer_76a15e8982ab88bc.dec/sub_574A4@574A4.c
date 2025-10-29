_DWORD *__fastcall sub_574A4(const char *a1)
{
  _DWORD *v2; // r4
  void *v3; // r5
  _DWORD *result; // r0

  if ( !a1 )
    return 0;
  v2 = sub_56924(0xCu);
  if ( !v2 )
    return 0;
  *v2 = 2;
  v2[1] = 1;
  v3 = sub_5696C(a1);
  result = v2;
  v2[2] = v3;
  if ( !v3 )
  {
    sub_5694C(v2);
    return 0;
  }
  return result;
}
