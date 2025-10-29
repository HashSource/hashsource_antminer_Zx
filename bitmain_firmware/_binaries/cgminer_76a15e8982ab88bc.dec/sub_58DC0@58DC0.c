unsigned __int8 *__fastcall sub_58DC0(unsigned int *a1, unsigned __int8 **a2)
{
  unsigned __int8 *v4; // r0

  v4 = sub_589A4(a1, a2);
  if ( !v4 )
    return 0;
  while ( *v4 != 45 )
  {
    v4 = sub_58A8C(v4, a1, a2);
    if ( !v4 )
      return 0;
  }
  --*a2;
  return v4 + 1;
}
