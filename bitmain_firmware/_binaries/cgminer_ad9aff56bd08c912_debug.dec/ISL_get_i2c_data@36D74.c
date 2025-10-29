int __fastcall ISL_get_i2c_data(uint8_t i2c_reg_addr, uint8_t *i2c_reg_data, int len)
{
  uint8_t *chain_exist; // r5
  int v5; // r4
  int v6; // t1
  const char *v7; // r8
  int v8; // r6
  int result; // r0
  uint8_t reg[4]; // [sp+1Ch] [bp-1018h]
  char tmp42[4100]; // [sp+30h] [bp-1004h] BYREF

  chain_exist = dev.chain_exist;
  v5 = 0;
  *(_DWORD *)reg = i2c_reg_addr;
  do
  {
    v6 = *chain_exist++;
    if ( v6 == 1 )
    {
      LOWORD(v7) = -29352;
      pthread_mutex_lock(&iic_mutex);
      v8 = 0;
      i2c_slave_addr = v5;
      do
      {
        read_dc_dc(isl_dev_addr[v8], reg[0], i2c_reg_data, len);
        if ( len == 1 )
        {
          if ( use_syslog || opt_log_output || opt_log_level > 4 )
          {
            snprintf(
              tmp42,
              0x1000u,
              "chain%d asic%d, slave:%02x, addr:%02x %02x\n",
              v5,
              v8,
              isl_dev_addr[v8],
              *(_DWORD *)reg,
              *i2c_reg_data);
            applog(5, tmp42, 0);
          }
        }
        else if ( use_syslog || opt_log_output || opt_log_level > 4 )
        {
          HIWORD(v7) = (unsigned int)"%d vol=%u\n" >> 16;
          snprintf(tmp42, 0x1000u, v7, v5, v8, isl_dev_addr[v8], *(_DWORD *)reg, *i2c_reg_data, i2c_reg_data[1]);
          applog(5, tmp42, 0);
        }
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
