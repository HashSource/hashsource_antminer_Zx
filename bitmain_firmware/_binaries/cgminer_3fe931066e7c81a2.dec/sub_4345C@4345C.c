int sub_4345C()
{
  int v0; // r4
  int v1; // r5
  int v2; // t1

  v0 = 0;
  v1 = 644283;
  do
  {
    v2 = *(unsigned __int8 *)++v1;
    if ( v2 == 1 )
      sub_43358(v0);
    v0 = (unsigned __int8)(v0 + 1);
  }
  while ( v0 != 4 );
  return sub_2A92C();
}
