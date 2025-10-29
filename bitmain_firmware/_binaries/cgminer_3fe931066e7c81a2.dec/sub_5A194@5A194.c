int __fastcall sub_5A194(int a1, const char *a2)
{
  void *v3; // r5

  if ( !a1 )
    return -1;
  if ( *(_DWORD *)a1 != 2 )
    return -1;
  if ( !a2 )
    return -1;
  v3 = sub_595B4(a2);
  if ( !v3 )
    return -1;
  sub_59594(*(void **)(a1 + 8));
  *(_DWORD *)(a1 + 8) = v3;
  return 0;
}
