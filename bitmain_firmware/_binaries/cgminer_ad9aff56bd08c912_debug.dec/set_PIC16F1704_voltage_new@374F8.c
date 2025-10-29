int __fastcall set_PIC16F1704_voltage_new(unsigned __int8 voltage)
{
  int v1; // r7
  unsigned __int8 *v2; // r4
  int i; // r3
  int v4; // t1
  int v5; // r4
  int v6; // r6
  bool v7; // zf
  int result; // r0
  const char *v9; // r2
  unsigned __int8 send_data[7]; // [sp+10h] [bp-100Ch] BYREF
  char v11; // [sp+17h] [bp-1005h] BYREF
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  v1 = voltage;
  send_data[6] = voltage + 21;
  *(_DWORD *)send_data = 268806741;
  send_data[5] = (unsigned __int16)(voltage + 21) >> 8;
  send_data[4] = voltage;
  pthread_mutex_lock(&i2c_mutex);
  v2 = &send_data[1];
  for ( i = 85; ; i = v4 )
  {
    i2c_write(i | 0xA00000 | (i2c_slave_addr << 16));
    if ( &v11 == (char *)v2 )
      break;
    v4 = *v2++;
  }
  usleep(0x30D40u);
  v5 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  v6 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  pthread_mutex_unlock(&i2c_mutex);
  usleep(0x30D40u);
  v7 = v6 == 1;
  if ( v6 == 1 )
    v7 = v5 == 16;
  if ( v7 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      LOWORD(v9) = -29052;
      HIWORD(v9) = (unsigned int)"voltage [%d, %d]\n" >> 16;
      snprintf(tmp42, 0x1000u, v9, "set_PIC16F1704_voltage_new", v1);
      applog(5, tmp42, 0);
      return 1;
    }
    else
    {
      return 1;
    }
  }
  else if ( use_syslog || (result = opt_log_output) != 0 || opt_log_level > 2 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "%s chain %d failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
      "set_PIC16F1704_voltage_new",
      i2c_slave_addr,
      v5,
      v6);
    applog(3, tmp42, 0);
    return 0;
  }
  return result;
}
