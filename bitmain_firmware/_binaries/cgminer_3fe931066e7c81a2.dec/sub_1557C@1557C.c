int __fastcall sub_1557C(int a1, char *a2)
{
  char *v5; // r0
  int v6; // r2

  sub_2AA68(a1, a2);
  if ( !sub_2AB54(a2, (_DWORD *)(a1 + 624), (char **)(a1 + 608)) || strncasecmp(a2, "stratum+tcp://", 0xEu) )
    return 0;
  v5 = _strdup(a2);
  v6 = *(_DWORD *)(a1 + 624);
  *(_BYTE *)(a1 + 664) = 1;
  *(_DWORD *)(a1 + 600) = v6;
  *(_DWORD *)(a1 + 196) = v5;
  return 1;
}
