void __cdecl set_asic_address(runtime_base_t *runtime, unsigned __int8 chainid)
{
  int i; // [sp+Ch] [bp+Ch]

  runtime->chain_inactive(runtime->chain_status[chainid].fd);
  for ( i = 0; runtime->chain_status[chainid].design_asic_num > i; ++i )
    runtime->set_address(runtime->chain_status[chainid].fd, runtime->addr_interval * i);
}
