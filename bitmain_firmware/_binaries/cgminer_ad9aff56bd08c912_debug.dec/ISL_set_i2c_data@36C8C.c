int __fastcall ISL_set_i2c_data(uint8_t i2c_reg_addr, uint8_t *i2c_reg_data, int len)
{
  uint8_t *chain_exist; // r5
  const char *v4; // r11
  int v6; // r4
  int v7; // t1
  unsigned __int8 *v8; // r9
  int v9; // r6
  uint8_t v10; // t1
  int result; // r0
  uint8_t reg[4]; // [sp+20h] [bp-1014h]
  char tmp42[4100]; // [sp+30h] [bp-1004h] BYREF

  chain_exist = dev.chain_exist;
  LOWORD(v4) = -29464;
  v6 = 0;
  *(_DWORD *)reg = i2c_reg_addr;
  do
  {
    v7 = *chain_exist++;
    if ( v7 == 1 )
    {
      v8 = isl_dev_addr;
      v9 = 0;
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = v6;
      do
      {
        if ( use_syslog || opt_log_output || opt_log_level > 4 )
        {
          HIWORD(v4) = (unsigned int)"write pic i2c[%d] %02x\n" >> 16;
          snprintf(tmp42, 0x1000u, v4, v6, v9, *v8, *(_DWORD *)reg, *i2c_reg_data, i2c_reg_data[1], len);
          applog(5, tmp42, 0);
        }
        v10 = *v8++;
        write_dc_dc(v10, reg[0], i2c_reg_data, len);
        ++v9;
        cgsleep_ms(200);
      }
      while ( v9 != 3 );
      *(_DWORD *)&i2c_reg_addr = pthread_mutex_unlock(&iic_mutex);
    }
    ++v6;
  }
  while ( v6 != 4 );
  LOBYTE(result) = i2c_reg_addr;
  return result;
}
