int __fastcall sub_3DFBC(int a1, int a2)
{
  const char *v2; // r3
  const char *v3; // r2

  v2 = *(const char **)(a1 + 1124);
  if ( !v2 )
    return 2;
  v3 = *(const char **)(a2 + 1580);
  if ( !v3 )
    return 2;
  if ( strcmp(v2, v3) )
    return 2;
  if ( *(double *)(a2 + 1520) == *(double *)(a1 + 1064) )
    return 0;
  return 2;
}
