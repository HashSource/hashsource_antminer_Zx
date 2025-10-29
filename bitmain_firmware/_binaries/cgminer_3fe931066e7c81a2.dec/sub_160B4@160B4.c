int sub_160B4()
{
  int result; // r0
  int *v1; // r3
  int v2; // r1
  int v3; // t1

  dword_75DC4 = 0;
  dword_75DC8 = 0;
  qword_76F18 = 0;
  result = sub_11580(0, (char *)&dword_75DC4, 8u, 0);
  if ( dword_7B198 > 0 )
  {
    result = 0;
    v1 = (int *)dword_7B438;
    v2 = dword_7B438 + 4 * dword_7B198;
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
