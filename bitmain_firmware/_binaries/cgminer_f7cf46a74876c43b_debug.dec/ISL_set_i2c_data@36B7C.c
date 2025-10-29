int __fastcall ISL_set_i2c_data(uint8_t i2c_reg_addr, uint8_t *i2c_reg_data, int len)
{
  uint8_t *chain_exist; // r5
  int v5; // r4
  int v6; // t1
  unsigned __int8 *v7; // r9
  int v8; // r6
  uint8_t v9; // t1
  int result; // r0
  uint8_t reg[4]; // [sp+20h] [bp-1014h]
  char tmp42[4100]; // [sp+30h] [bp-1004h] BYREF

  chain_exist = dev.chain_exist;
  v5 = 0;
  *(_DWORD *)reg = i2c_reg_addr;
  do
  {
    v6 = *chain_exist++;
    if ( v6 == 1 )
    {
      v7 = isl_dev_addr;
      v8 = 0;
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = v5;
      do
      {
        if ( use_syslog || opt_log_output || opt_log_level > 4 )
        {
          snprintf(
            tmp42,
            0x1000u,
            "chain%d asic%d, set data slave:%02x addr:%02x %02x %02x, len=%d\n",
            v5,
            v8,
            *v7,
            *(_DWORD *)reg,
            *i2c_reg_data,
            i2c_reg_data[1],
            len);
          applog(5, tmp42, 0);
        }
        v9 = *v7++;
        write_dc_dc(v9, reg[0], i2c_reg_data, len);
        ++v8;
        cgsleep_ms(200);
      }
      while ( v8 != 3 );
      *(_DWORD *)&i2c_reg_addr = pthread_mutex_unlock(&iic_mutex);
    }
    ++v5;
  }
  while ( v5 != 4 );
  LOBYTE(result) = i2c_reg_addr;
  return result;
}
