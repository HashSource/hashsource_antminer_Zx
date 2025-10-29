void __cdecl check_asic_num(runtime_base_t *runtime)
{
  reg_list_item_t item_r; // [sp+8h] [bp+8h] BYREF
  int asicid; // [sp+14h] [bp+14h]

  runtime->read_register(runtime->chain_status[runtime->chain_id].fd, 1, 0, 0);
  item_r.chainid = runtime->chain_id;
  item_r.chip_addr = 0;
  item_r.reg_addr = 0;
  item_r.reg_data = 0;
  item_r.age = 0;
  runtime->chain_status[runtime->chain_id].real_asic_num = 0;
  for ( asicid = 0; app_conf->asic_num > asicid; ++asicid )
  {
    if ( read_reg_item(&item_r, 500) > 0 )
      ++runtime->chain_status[runtime->chain_id].real_asic_num;
  }
}
