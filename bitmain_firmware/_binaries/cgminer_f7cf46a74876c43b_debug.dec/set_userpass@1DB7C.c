char *__fastcall set_userpass(const char *arg)
{
  int v2; // r3
  int v3; // r6
  char *v4; // r4
  char *v5; // r0
  const char *v6; // r4
  char *v7; // r0

  if ( total_users || total_passes )
    return "Use only user + pass or userpass, but not both";
  v2 = total_userpasses + 1;
  total_userpasses = v2;
  if ( v2 > total_pools )
  {
    add_pool();
    v2 = total_userpasses;
  }
  v3 = (int)*(&pools[v2] + 0x3FFFFFFF);
  v4 = _strdup(arg);
  opt_set_charp(arg, (char **)(v3 + 200));
  v5 = v4;
  v6 = "Failed to find : delimited user info";
  v7 = strtok(v5, ":");
  *(_DWORD *)(v3 + 204) = v7;
  if ( v7 )
  {
    v6 = strtok(0, ":");
    *(_DWORD *)(v3 + 208) = v6;
    if ( v6 )
      return 0;
    *(_DWORD *)(v3 + 208) = calloc(1u, 1u);
  }
  return (char *)v6;
}
