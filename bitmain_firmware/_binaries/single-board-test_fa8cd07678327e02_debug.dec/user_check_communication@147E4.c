int __cdecl user_check_communication(runtime_base_t *runtime)
{
  char tmp42[1024]; // [sp+14h] [bp+Ch] BYREF
  reg_list_item_t item; // [sp+414h] [bp+40Ch] BYREF
  uint8_t regaddr; // [sp+422h] [bp+41Ah]
  uint8_t chipaddr; // [sp+423h] [bp+41Bh]
  int count_max; // [sp+424h] [bp+41Ch]
  int chainid; // [sp+428h] [bp+420h]
  int count; // [sp+42Ch] [bp+424h]

  chainid = runtime->chain_id;
  count = 0;
  count_max = 3;
  chipaddr = 0;
  regaddr = 0;
  item.chainid = chainid;
  item.chip_addr = 0;
  item.reg_addr = 0;
  item.reg_data = 0;
  item.age = 0;
  while ( 1 )
  {
    runtime->read_register(runtime->chain_status[chainid].fd, 1, 0, 0);
    if ( read_reg_item(&item, 500) >= 0 )
      break;
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "%s  failed %d\n", "user_check_communication", count);
      applog(2, tmp42, 0);
    }
    sleep(1u);
    if ( ++count >= count_max )
      return -1;
  }
  return count;
}
