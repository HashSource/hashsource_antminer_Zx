int __cdecl user_read_iic(
        runtime_base_t *runtime,
        int chip_addr,
        uint8_t i2c_dev_addr,
        uint8_t i2c_reg_addr,
        uint8_t *i2c_reg_data,
        int len)
{
  char tmp42[1024]; // [sp+1Ch] [bp+14h] BYREF
  reg_list_item_t itemreg; // [sp+41Ch] [bp+414h] BYREF
  int fd; // [sp+428h] [bp+420h]
  int chainid; // [sp+42Ch] [bp+424h]
  int i; // [sp+430h] [bp+428h]
  int ret; // [sp+434h] [bp+42Ch]

  ret = 1;
  chainid = runtime->chain_id;
  fd = runtime->chain_status[chainid].fd;
  if ( user_i2c_state(runtime, chip_addr) )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      strcpy(tmp42, "i2c state check failed\n");
      applog(2, tmp42, 0);
    }
    return 1;
  }
  else
  {
    if ( runtime->i2c_recv(fd, chip_addr, i2c_dev_addr, i2c_reg_addr, len) )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 0 )
      {
        snprintf(tmp42, 0x400u, "Read i2c failed chipaddr=%02x, i2c-regaddr=%02x\n", chip_addr, i2c_reg_addr);
        applog(1, tmp42, 0);
      }
      return 1;
    }
    else
    {
      itemreg.chainid = chainid;
      itemreg.chip_addr = chip_addr;
      itemreg.reg_addr = 32;
      itemreg.reg_data = 0;
      itemreg.age = 0;
      for ( i = 0; i < len; ++i )
      {
        if ( read_reg_item(&itemreg, 500) <= 0 || (itemreg.reg_data & 0xC0000000) != 0 )
        {
          if ( use_syslog || opt_log_output || opt_log_level > 0 )
          {
            snprintf(
              tmp42,
              0x400u,
              "Read i2c failed chipaddr=%02x, i2c-regaddr=%02x i2c-regdata=%08x\n",
              chip_addr,
              i2c_reg_addr,
              itemreg.reg_data);
            applog(1, tmp42, 0);
          }
          ret = 1;
        }
        else
        {
          i2c_reg_data[i] = itemreg.reg_data;
          ret = 0;
        }
      }
    }
    return ret;
  }
}
