_DWORD *__fastcall sub_5A0EC(const char *a1)
{
  _DWORD *v2; // r4
  void *v3; // r5
  _DWORD *result; // r0

  if ( !a1 )
    return 0;
  v2 = sub_5956C(0xCu);
  if ( !v2 )
    return 0;
  *v2 = 2;
  v2[1] = 1;
  v3 = sub_595B4(a1);
  result = v2;
  v2[2] = v3;
  if ( !v3 )
  {
    sub_59594(v2);
    return 0;
  }
  return result;
}
