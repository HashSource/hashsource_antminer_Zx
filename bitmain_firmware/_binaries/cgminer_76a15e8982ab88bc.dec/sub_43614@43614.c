int __fastcall sub_43614(int result, int a2)
{
  int v2; // r7
  int v3; // r5
  int i; // r4
  int v6; // t1

  v2 = result;
  v3 = 631471;
  for ( i = 0; i != 4; i = (unsigned __int8)(i + 1) )
  {
    v6 = *(unsigned __int8 *)++v3;
    if ( v6 == 1 )
      result = sub_43500(i, v2, a2);
  }
  return result;
}
