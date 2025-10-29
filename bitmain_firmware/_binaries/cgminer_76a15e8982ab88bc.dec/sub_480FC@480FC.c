int sub_480FC()
{
  int v0; // r4
  int v1; // r5
  int v2; // t1
  int result; // r0

  v0 = 0;
  v1 = 631471;
  do
  {
    v2 = *(unsigned __int8 *)++v1;
    if ( v2 == 1 )
    {
      sub_47F54(v0);
      result = sub_2A884();
    }
    v0 = (unsigned __int8)(v0 + 1);
  }
  while ( v0 != 4 );
  return result;
}
