unsigned int __fastcall sub_3E9FC(int a1)
{
  int v2; // r6
  int i; // r4
  int v4; // t1

  v2 = 631471;
  for ( i = 0; i != 4; ++i )
  {
    v4 = *(unsigned __int8 *)++v2;
    if ( v4 == 1 )
    {
      sub_3E968(i, 0, a1);
      sub_3E968(i, 1, a1);
      sub_3E968(i, 2, a1);
    }
  }
  return sleep(1u);
}
