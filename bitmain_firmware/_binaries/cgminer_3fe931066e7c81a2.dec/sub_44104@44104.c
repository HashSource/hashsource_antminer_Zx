int __fastcall sub_44104(int result)
{
  int v1; // r6
  int v2; // r5
  int i; // r4
  int v4; // t1

  v1 = result;
  v2 = 644283;
  for ( i = 0; i != 4; i = (unsigned __int8)(i + 1) )
  {
    v4 = *(unsigned __int8 *)++v2;
    if ( v4 == 1 )
      result = sub_44004(i, v1);
  }
  return result;
}
