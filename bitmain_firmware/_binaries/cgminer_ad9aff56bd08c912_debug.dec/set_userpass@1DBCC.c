char *__fastcall set_userpass(const char *arg)
{
  int v2; // r3
  int v3; // r6
  char *v4; // r4
  const char *v5; // r1
  char *v6; // r0
  char *v7; // r0
  char *v8; // r4
  const char *v9; // r1

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
  LOWORD(v5) = 16004;
  v6 = v4;
  HIWORD(v5) = (unsigned int)"proxy: %s" >> 16;
  LOWORD(v8) = 1436;
  v7 = strtok(v6, v5);
  HIWORD(v8) = (unsigned int)" user + pass or userpass, but not both" >> 16;
  *(_DWORD *)(v3 + 204) = v7;
  if ( v7 )
  {
    LOWORD(v9) = 16004;
    HIWORD(v9) = (unsigned int)"proxy: %s" >> 16;
    v8 = strtok(0, v9);
    *(_DWORD *)(v3 + 208) = v8;
    if ( v8 )
      return 0;
    *(_DWORD *)(v3 + 208) = calloc(1u, 1u);
  }
  return v8;
}
