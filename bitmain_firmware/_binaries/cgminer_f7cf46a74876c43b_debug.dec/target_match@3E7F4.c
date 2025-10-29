bool __fastcall target_match(unsigned __int8 *result_value, unsigned __int8 *target)
{
  unsigned __int8 *v2; // r1
  unsigned __int8 *v3; // r3
  unsigned int v4; // r4
  unsigned int v5; // t1
  unsigned int v6; // t1
  bool v7; // cc

  v2 = target + 32;
  v3 = result_value + 32;
  while ( 1 )
  {
    v5 = *--v3;
    v4 = v5;
    v6 = *--v2;
    v7 = v4 > v6;
    if ( v4 < v6 )
      return 1;
    if ( v7 )
      break;
    if ( v3 == result_value )
      return 1;
  }
  return 0;
}
