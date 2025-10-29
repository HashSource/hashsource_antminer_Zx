int __fastcall sub_154B4(int a1, char *a2)
{
  char *v5; // r0
  int v6; // r2

  sub_2A9C0(a1, a2);
  if ( !sub_2AAAC(a2, (_DWORD *)(a1 + 624), (char **)(a1 + 608)) || strncasecmp(a2, "stratum+tcp://", 0xEu) )
    return 0;
  v5 = _strdup(a2);
  v6 = *(_DWORD *)(a1 + 624);
  *(_BYTE *)(a1 + 664) = 1;
  *(_DWORD *)(a1 + 600) = v6;
  *(_DWORD *)(a1 + 196) = v5;
  return 1;
}
