int __fastcall get_PIC16F1704_voltage_new(unsigned __int8 *voltage)
{
  unsigned __int8 *v2; // r4
  int i; // r3
  int v4; // t1
  unsigned __int8 *v5; // r4
  int v6; // r7
  int v7; // r8
  int v9; // r0
  unsigned __int16 v10; // r3
  unsigned __int8 read_back_data[5]; // [sp+18h] [bp-Dh] BYREF
  _BYTE v12[3]; // [sp+1Dh] [bp-8h] BYREF
  unsigned __int8 send_data[6]; // [sp+20h] [bp-5h] BYREF
  char tmp42[4096]; // [sp+28h] [bp+3h] BYREF

  *(_DWORD *)read_back_data = 255;
  send_data[4] = 0;
  v2 = send_data;
  read_back_data[4] = 0;
  *(_DWORD *)send_data = 402958933;
  send_data[5] = 28;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 85; ; i = v4 )
  {
    i2c_write(i | 0xA00000 | (i2c_slave_addr << 16));
    if ( &send_data[5] == v2 )
      break;
    v4 = *++v2;
  }
  v5 = read_back_data;
  usleep((__useconds_t)&loc_30D3E + 2);
  do
    *v5++ = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  while ( v12 != v5 );
  pthread_mutex_unlock(&i2c_mutex);
  v6 = read_back_data[1];
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
  {
    if ( read_back_data[1] != 24 )
    {
LABEL_11:
      if ( opt_log_level <= 2 )
        return 0;
      goto LABEL_12;
    }
    if ( read_back_data[0] == 5 )
      goto LABEL_18;
LABEL_10:
    if ( !opt_log_output )
      goto LABEL_11;
LABEL_12:
    snprintf(tmp42, 0x1000u, "%s chain %d failed!", "get_PIC16F1704_voltage_new", i2c_slave_addr);
LABEL_13:
    applog(3, tmp42, 0);
    return 0;
  }
  v7 = read_back_data[0];
  snprintf(
    tmp42,
    0x1000u,
    "%s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_bac"
    "k_data[4] = 0x%x\n",
    "get_PIC16F1704_voltage_new",
    read_back_data[0],
    read_back_data[1],
    read_back_data[2],
    read_back_data[3],
    read_back_data[4]);
  applog(5, tmp42, 0);
  if ( v6 != 24 || v7 != 5 )
  {
    if ( use_syslog )
      goto LABEL_12;
    goto LABEL_10;
  }
LABEL_18:
  v9 = read_back_data[2];
  v10 = read_back_data[2] + 29;
  if ( read_back_data[3] != HIBYTE(v10) || read_back_data[4] != (unsigned __int8)v10 )
  {
    if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return 0;
    snprintf(tmp42, 0x1000u, "%s failed! crc = 0x%04x", "get_PIC16F1704_voltage_new", v10);
    goto LABEL_13;
  }
  *voltage = read_back_data[2];
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
    return 1;
  snprintf(tmp42, 0x1000u, "%s ok, voltage = 0x%02x", "get_PIC16F1704_voltage_new", v9);
  applog(5, tmp42, 0);
  return 1;
}
