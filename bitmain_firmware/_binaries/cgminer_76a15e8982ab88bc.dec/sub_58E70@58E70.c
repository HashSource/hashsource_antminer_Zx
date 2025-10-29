unsigned __int8 *__fastcall sub_58E70(unsigned int *a1)
{
  unsigned __int8 *result; // r0
  unsigned __int8 *v3; // [sp+4h] [bp-8h] BYREF

  v3 = 0;
  result = sub_589A4(a1, &v3);
  if ( !result )
    return 0;
  while ( *result == 45 )
  {
    result = sub_58A8C(result, a1, &v3);
    if ( !result )
      return 0;
  }
  return result;
}
