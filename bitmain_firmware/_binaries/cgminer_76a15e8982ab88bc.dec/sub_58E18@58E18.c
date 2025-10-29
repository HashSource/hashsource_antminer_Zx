unsigned __int8 *__fastcall sub_58E18(unsigned __int8 *a1, unsigned int *a2, unsigned __int8 **a3)
{
  unsigned __int8 *v5; // r0

  v5 = sub_58A8C(a1, a2, a3);
  if ( !v5 )
    return 0;
  while ( *v5 != 45 )
  {
    v5 = sub_58A8C(v5, a2, a3);
    if ( !v5 )
      return 0;
  }
  --*a3;
  return v5 + 1;
}
