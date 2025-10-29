int __fastcall sub_43204(int a1)
{
  int v2; // r5
  int i; // r4
  int v4; // t1

  v2 = 631471;
  for ( i = 0; i != 4; i = (unsigned __int8)(i + 1) )
  {
    v4 = *(unsigned __int8 *)++v2;
    if ( v4 == 1 )
      sub_425E8(i, a1);
  }
  return sub_2A884();
}
