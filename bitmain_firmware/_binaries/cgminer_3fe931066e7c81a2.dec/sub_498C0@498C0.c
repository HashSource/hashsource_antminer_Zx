int __fastcall sub_498C0(int a1, int a2)
{
  int v2; // r3
  unsigned int v3; // r12
  unsigned int v4; // r2

  v2 = 31;
  while ( 1 )
  {
    v3 = *(unsigned __int8 *)(a1 + v2);
    v4 = *(unsigned __int8 *)(a2 + v2--);
    if ( v3 < v4 )
      return 1;
    if ( v3 > v4 )
      break;
    if ( v2 == -1 )
      return 1;
  }
  return 0;
}
