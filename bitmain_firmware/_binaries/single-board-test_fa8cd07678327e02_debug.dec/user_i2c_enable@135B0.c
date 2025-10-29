void __cdecl user_i2c_enable(runtime_base_t *runtime, unsigned __int8 chainid)
{
  int i; // [sp+Ch] [bp+Ch]

  for ( i = 0; runtime->chain_status[runtime->chain_id].design_asic_num > i; ++i )
    runtime->i2c_enable(runtime->chain_status[chainid].fd, runtime->addr_interval * i);
}
