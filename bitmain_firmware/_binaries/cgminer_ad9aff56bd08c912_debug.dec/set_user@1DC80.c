char *__fastcall set_user(const char *arg)
{
  int v3; // r3

  if ( total_userpasses )
    return "Use only user + pass or userpass, but not both";
  v3 = total_users + 1;
  total_users = v3;
  if ( v3 > total_pools )
  {
    add_pool();
    v3 = total_users;
  }
  opt_set_charp(arg, &(*(&pools[v3] + 0x3FFFFFFF))->rpc_user);
  return 0;
}
