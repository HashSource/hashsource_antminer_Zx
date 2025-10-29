int __fastcall get_PIC16F1704_voltage_new(unsigned __int8 *voltage)
{
  unsigned __int8 *v2; // r4
  int i; // r3
  int v4; // t1
  unsigned __int8 *v5; // r4
  int v6; // r7
  const char *v7; // r2
  int v8; // r8
  const char *v9; // r2
  int v11; // r0
  unsigned __int16 v12; // r3
  const char *v13; // r2
  const char *v14; // r2
  unsigned __int8 read_back_data[5]; // [sp+18h] [bp-Dh] BYREF
  _BYTE v16[3]; // [sp+1Dh] [bp-8h] BYREF
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
  usleep((__useconds_t)&loc_30D40);
  do
    *v5++ = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  while ( v16 != v5 );
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
    LOWORD(v9) = -29720;
    HIWORD(v9) = (unsigned int)"15] = 0x%x, \t\tread_back_data[16] = 0x%x, read_back_data[17] = 0x%x, read_back_data[18] = 0x%x, read_back_data[19] = 0x%x\n" >> 16;
    snprintf(tmp42, 0x1000u, v9, "get_PIC16F1704_voltage_new", i2c_slave_addr);
LABEL_13:
    applog(3, tmp42, 0);
    return 0;
  }
  LOWORD(v7) = -28324;
  HIWORD(v7) = (unsigned int)"0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x" >> 16;
  v8 = read_back_data[0];
  snprintf(
    tmp42,
    0x1000u,
    v7,
    "get_PIC16F1704_voltage_new",
    read_back_data[0],
    read_back_data[1],
    read_back_data[2],
    read_back_data[3],
    read_back_data[4]);
  applog(5, tmp42, 0);
  if ( v6 != 24 || v8 != 5 )
  {
    if ( use_syslog )
      goto LABEL_12;
    goto LABEL_10;
  }
LABEL_18:
  v11 = read_back_data[2];
  v12 = read_back_data[2] + 29;
  if ( read_back_data[3] != HIBYTE(v12) || read_back_data[4] != (unsigned __int8)v12 )
  {
    if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return 0;
    LOWORD(v13) = -28572;
    HIWORD(v13) = (unsigned int)"ata[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
    snprintf(tmp42, 0x1000u, v13, "get_PIC16F1704_voltage_new", v12);
    goto LABEL_13;
  }
  *voltage = read_back_data[2];
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
    return 1;
  LOWORD(v14) = -29052;
  HIWORD(v14) = (unsigned int)"voltage [%d, %d]\n" >> 16;
  snprintf(tmp42, 0x1000u, v14, "get_PIC16F1704_voltage_new", v11);
  applog(5, tmp42, 0);
  return 1;
}
