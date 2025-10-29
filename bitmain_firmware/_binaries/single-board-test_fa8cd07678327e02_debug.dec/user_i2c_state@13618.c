int __cdecl user_i2c_state(runtime_base_t *runtime, int chip_addr)
{
  int v2; // r3
  char tmp42[1024]; // [sp+Ch] [bp+Ch] BYREF
  reg_list_item_t item; // [sp+40Ch] [bp+40Ch] BYREF
  int chainid; // [sp+418h] [bp+418h]
  int check_loop; // [sp+41Ch] [bp+41Ch]

  chainid = runtime->chain_id;
  check_loop = 3;
  do
  {
    runtime->i2c_status(runtime->chain_status[chainid].fd, chip_addr);
    memset(&item, 0, sizeof(item));
    item.chainid = runtime->chain_id;
    item.chip_addr = chip_addr;
    item.reg_addr = 32;
    if ( read_reg_item(&item, 1000) >= 0 )
    {
      if ( (item.reg_data & 0x80000000) == 0 )
        break;
      if ( use_syslog || opt_log_output || opt_log_level > 0 )
      {
        snprintf(tmp42, 0x400u, "chipaddr %02x - i2c is busy\n", chip_addr);
        applog(1, tmp42, 0);
      }
    }
    else if ( use_syslog || opt_log_output || opt_log_level > 0 )
    {
      snprintf(tmp42, 0x400u, "chipaddr %02x - i2c no-response\n", chip_addr);
      applog(1, tmp42, 0);
    }
    v2 = check_loop--;
  }
  while ( v2 > 0 );
  if ( check_loop > 0 )
    return 0;
  else
    return -1;
}
