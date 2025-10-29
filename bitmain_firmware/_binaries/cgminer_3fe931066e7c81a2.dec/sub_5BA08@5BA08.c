unsigned __int8 *__fastcall sub_5BA08(unsigned int *a1, unsigned __int8 **a2)
{
  unsigned __int8 *v4; // r0

  v4 = sub_5B5EC(a1, a2);
  if ( !v4 )
    return 0;
  while ( *v4 != 45 )
  {
    v4 = sub_5B6D4(v4, a1, a2);
    if ( !v4 )
      return 0;
  }
  --*a2;
  return v4 + 1;
}
