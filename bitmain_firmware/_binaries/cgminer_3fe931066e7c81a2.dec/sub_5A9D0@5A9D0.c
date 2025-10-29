int __fastcall sub_5A9D0(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v4; // r0
  char *i; // r4
  int v6; // r0
  int v7; // r0

  if ( !a1 || *a1 || !a2 || *a2 )
    return -1;
  v4 = sub_59E9C(a2);
  for ( i = (char *)sub_59F14((int)v4); i; i = (char *)sub_59F14(v6) )
  {
    v7 = sub_59F20((int)(i - 16));
    if ( !v7 )
      break;
    if ( *(_DWORD *)(v7 + 4) != -1 )
      ++*(_DWORD *)(v7 + 4);
    if ( sub_5A820(a1, i, v7) )
      return -1;
    v6 = sub_59EE8(a2, (int)(i - 16));
  }
  return 0;
}
