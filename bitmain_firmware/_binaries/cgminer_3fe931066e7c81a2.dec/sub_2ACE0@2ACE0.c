char *__fastcall sub_2ACE0(char *s1, int a2)
{
  const char *v2; // r4
  int v5; // r5
  size_t v6; // r6
  char *v7; // r0
  char *v8; // r8
  char *v9; // r0
  const char *v10; // r1
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  v2 = "http:";
  v5 = 0;
  v6 = 5;
  *(_DWORD *)(a2 + 216) = 0;
  while ( strncmp(s1, v2, v6) )
  {
    ++v5;
    v2 = (&off_64E3C)[2 * v5];
    if ( !v2 )
      return s1;
    v6 = strlen((&off_64E3C)[2 * v5]);
  }
  v7 = strchr(s1, 124);
  v8 = v7;
  if ( v7 )
  {
    *v7 = 0;
    v9 = (char *)malloc(v7 - s1 + 1 - v6);
    *(_DWORD *)(a2 + 216) = v9;
    if ( !v9 )
    {
      snprintf(s, 0x1000u, "Failed to malloc rpc_proxy in %s %s():%d", "util.c", "get_proxy", 881);
      sub_38730(3, s, 1);
      sub_16CA8(1);
    }
    v10 = &s1[v6];
    s1 = v8 + 1;
    strcpy(v9, v10);
    sub_2AB54(*(char **)(a2 + 216), (char **)(a2 + 628), (char **)(a2 + 632));
    *(_DWORD *)(a2 + 212) = *(_DWORD *)&aClearSock[8 * v5 + 32];
  }
  return s1;
}
