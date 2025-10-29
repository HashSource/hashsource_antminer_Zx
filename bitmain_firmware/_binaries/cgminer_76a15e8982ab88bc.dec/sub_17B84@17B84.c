const char *__fastcall sub_17B84(char *s)
{
  int v2; // r3
  _DWORD *v3; // r4
  char *v4; // r6
  char *v5; // r0
  char *v6; // r5
  int v7; // r3
  void *v8; // r0

  if ( dword_73E40 || dword_73E44 )
    return "Use only user + pass or userpass, but not both";
  v2 = dword_73E48 + 1;
  dword_73E48 = v2;
  if ( v2 > dword_77FC0 )
  {
    sub_17974();
    v2 = dword_73E48;
  }
  v3 = *(_DWORD **)(dword_78260 + 4 * (v2 - 1));
  v4 = _strdup(s);
  sub_5858C((int)s, v3 + 50);
  v5 = strtok(v4, ":");
  v3[51] = v5;
  if ( !v5 )
    return "Failed to find : delimited user info";
  v6 = strtok(0, ":");
  v3[52] = v6;
  if ( v6 )
    return 0;
  v8 = calloc(1u, 1u);
  v7 = 0;
  v3[52] = v8;
  return (const char *)v7;
}
