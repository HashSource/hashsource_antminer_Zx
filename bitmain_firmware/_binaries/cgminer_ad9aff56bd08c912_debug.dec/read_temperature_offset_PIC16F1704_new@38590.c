int __fastcall read_temperature_offset_PIC16F1704_new(unsigned __int8 *buf)
{
  unsigned __int8 *v2; // r4
  int i; // r3
  int v4; // t1
  unsigned __int8 *v5; // r4
  int v6; // r6
  const char *v7; // r2
  int v8; // r8
  const char *v9; // r2
  unsigned __int8 v11; // r6
  unsigned int v12; // r3
  const char *v13; // r2
  unsigned __int8 *v14; // r3
  unsigned __int8 *v15; // r2
  unsigned __int8 *v16; // r7
  unsigned __int8 v17; // t1
  const char *v18; // r2
  unsigned __int8 send_data[6]; // [sp+34h] [bp-1014h] BYREF
  unsigned __int8 read_back_data[12]; // [sp+3Ch] [bp-100Ch] BYREF
  char tmp42[4096]; // [sp+48h] [bp-1000h] BYREF

  *(_DWORD *)read_back_data = 255;
  send_data[4] = 0;
  *(_DWORD *)&read_back_data[4] = 0;
  v2 = send_data;
  *(_DWORD *)&read_back_data[8] = 0;
  *(_DWORD *)send_data = 587508309;
  send_data[5] = 39;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 85; ; i = v4 )
  {
    i2c_write(i | 0xA00000 | (i2c_slave_addr << 16));
    if ( v2 == &send_data[5] )
      break;
    v4 = *++v2;
  }
  v5 = read_back_data;
  usleep((__useconds_t)&loc_30D40);
  do
    *v5++ = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  while ( tmp42 != (char *)v5 );
  pthread_mutex_unlock(&i2c_mutex);
  v6 = read_back_data[1];
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
  {
    if ( read_back_data[1] != 35 )
    {
LABEL_11:
      if ( opt_log_level <= 2 )
        return 0;
      goto LABEL_12;
    }
    if ( read_back_data[0] == 12 )
      goto LABEL_18;
LABEL_10:
    if ( !opt_log_output )
      goto LABEL_11;
LABEL_12:
    LOWORD(v9) = -27796;
    HIWORD(v9) = (unsigned int)"ta[7] = 0x%x, \t\tread_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x\n" >> 16;
    snprintf(tmp42, 0x1000u, v9, "read_temperature_offset_PIC16F1704_new");
LABEL_13:
    applog(3, tmp42, 0);
    return 0;
  }
  LOWORD(v7) = -28120;
  HIWORD(v7) = (unsigned int)", read_back_data[3] = 0x%x, read_back_data[4] = 0x%x\n" >> 16;
  v8 = read_back_data[0];
  snprintf(
    tmp42,
    0x1000u,
    v7,
    "read_temperature_offset_PIC16F1704_new",
    read_back_data[0],
    read_back_data[1],
    read_back_data[2],
    read_back_data[3],
    read_back_data[4],
    read_back_data[5],
    read_back_data[6],
    read_back_data[7],
    read_back_data[8],
    read_back_data[9],
    read_back_data[10],
    read_back_data[11]);
  applog(5, tmp42, 0);
  if ( v6 != 35 || v8 != 12 )
  {
    if ( use_syslog )
      goto LABEL_12;
    goto LABEL_10;
  }
LABEL_18:
  v11 = read_back_data[2];
  v12 = read_back_data[9]
      + read_back_data[8]
      + read_back_data[7]
      + read_back_data[6]
      + read_back_data[3]
      + read_back_data[2]
      + 47
      + read_back_data[4]
      + read_back_data[5];
  if ( read_back_data[10] != v12 >> 8 || read_back_data[11] != (unsigned __int8)v12 )
  {
    if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return 0;
    LOWORD(v13) = -28572;
    HIWORD(v13) = (unsigned int)"ata[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
    snprintf(
      tmp42,
      0x1000u,
      v13,
      "read_temperature_offset_PIC16F1704_new",
      read_back_data[9]
    + read_back_data[8]
    + read_back_data[7]
    + read_back_data[6]
    + read_back_data[3]
    + read_back_data[2]
    + 47
    + read_back_data[4]
    + read_back_data[5]);
    goto LABEL_13;
  }
  v14 = buf - 1;
  v15 = &read_back_data[3];
  v16 = buf + 7;
  while ( 1 )
  {
    *++v14 = v11;
    if ( v16 == v14 )
      break;
    v17 = *v15++;
    v11 = v17;
  }
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
    return 1;
  LOWORD(v18) = -30676;
  HIWORD(v18) = (unsigned int)"a[2] = 0x%02x, read_back_data[3] = 0x%02x\n" >> 16;
  snprintf(tmp42, 0x1000u, v18, "read_temperature_offset_PIC16F1704_new");
  applog(5, tmp42, 0);
  return 1;
}
