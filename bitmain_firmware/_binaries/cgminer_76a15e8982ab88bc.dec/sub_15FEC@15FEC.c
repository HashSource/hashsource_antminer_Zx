int sub_15FEC()
{
  int result; // r0
  int *v1; // r3
  int v2; // r1
  int v3; // t1

  dword_72C04 = 0;
  dword_72C08 = 0;
  qword_73D50 = 0;
  result = sub_114B8(0, (char *)&dword_72C04, 8u, 0);
  if ( dword_77FC0 > 0 )
  {
    result = 0;
    v1 = (int *)dword_78260;
    v2 = dword_78260 + 4 * dword_77FC0;
    do
    {
      v3 = *v1++;
      *(_DWORD *)(v3 + 400) = 0;
      *(_DWORD *)(v3 + 404) = 0;
    }
    while ( v1 != (int *)v2 );
  }
  return result;
}
