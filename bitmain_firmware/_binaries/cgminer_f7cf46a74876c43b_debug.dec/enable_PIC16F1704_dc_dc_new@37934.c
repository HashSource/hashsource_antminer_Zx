bool enable_PIC16F1704_dc_dc_new()
{
  unsigned __int8 *v0; // r4
  int i; // r3
  int v2; // t1
  int v3; // r4
  int v4; // r6
  bool v5; // zf
  _BOOL4 result; // r0
  unsigned __int8 send_data[7]; // [sp+10h] [bp-1008h] BYREF
  char v8; // [sp+17h] [bp-1001h] BYREF
  char tmp42[4096]; // [sp+18h] [bp-1000h] BYREF

  send_data[5] = 0;
  *(_DWORD *)send_data = 352692821;
  send_data[4] = 1;
  send_data[6] = 27;
  v0 = &send_data[1];
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 85; ; i = v2 )
  {
    i2c_write(i | 0xA00000 | (i2c_slave_addr << 16));
    if ( &v8 == (char *)v0 )
      break;
    v2 = *v0++;
  }
  usleep(0x186A0u);
  v3 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  v4 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  pthread_mutex_unlock(&i2c_mutex);
  v5 = v4 == 1;
  if ( v4 == 1 )
    v5 = v3 == 21;
  if ( v5 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      snprintf(tmp42, 0x1000u, "%s ok", "enable_PIC16F1704_dc_dc_new");
      applog(5, tmp42, 0);
      return 1;
    }
    else
    {
      return 1;
    }
  }
  else if ( use_syslog || (result = opt_log_output) || opt_log_level > 2 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "%s chain %d failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x",
      "enable_PIC16F1704_dc_dc_new",
      i2c_slave_addr,
      v3,
      v4);
    applog(3, tmp42, 0);
    return 0;
  }
  return result;
}
