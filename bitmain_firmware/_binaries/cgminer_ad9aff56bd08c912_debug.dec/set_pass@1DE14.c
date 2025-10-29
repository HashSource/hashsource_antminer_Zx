char *__fastcall set_pass(const char *arg)
{
  int v3; // r3

  if ( total_userpasses )
    return "Use only user + pass or userpass, but not both";
  v3 = total_passes + 1;
  total_passes = v3;
  if ( v3 > total_pools )
  {
    add_pool();
    v3 = total_passes;
  }
  opt_set_charp(arg, &(*(&pools[v3] + 0x3FFFFFFF))->rpc_pass);
  return 0;
}
