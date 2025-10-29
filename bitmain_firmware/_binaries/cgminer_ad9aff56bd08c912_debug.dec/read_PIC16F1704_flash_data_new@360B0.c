int __fastcall read_PIC16F1704_flash_data_new(unsigned __int8 *buf)
{
  unsigned __int8 *v2; // r4
  int i; // r3
  int v4; // t1
  unsigned __int8 *v5; // r4
  int v6; // r6
  const char *v7; // r2
  int result; // r0
  const char *v9; // r2
  unsigned __int8 v10; // r1
  const char *v11; // r2
  unsigned __int8 *v12; // r7
  unsigned __int8 *j; // r2
  unsigned __int8 v14; // t1
  const char *v15; // r2
  unsigned __int8 send_data[6]; // [sp+54h] [bp-1020h] BYREF
  char v17; // [sp+5Bh] [bp-1019h] BYREF
  unsigned __int8 read_back_data[20]; // [sp+5Ch] [bp-1018h] BYREF
  char tmp42[4100]; // [sp+70h] [bp-1004h] BYREF

  *(_DWORD *)read_back_data = 255;
  send_data[4] = 0;
  v2 = send_data;
  memset(&read_back_data[4], 0, 16);
  *(_DWORD *)send_data = 50637397;
  send_data[5] = 7;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 85; ; i = v4 )
  {
    i2c_write(i | 0xA00000 | (i2c_slave_addr << 16));
    if ( v2 == &send_data[5] )
      break;
    v4 = *++v2;
  }
  v5 = (unsigned __int8 *)&v17;
  usleep((__useconds_t)&loc_493E0);
  do
    *++v5 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  while ( v5 != &read_back_data[19] );
  pthread_mutex_unlock(&i2c_mutex);
  v6 = read_back_data[1];
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v7) = -30264;
    HIWORD(v7) = (unsigned int)"_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n\n" >> 16;
    snprintf(
      tmp42,
      0x1000u,
      v7,
      "read_PIC16F1704_flash_data_new",
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
      read_back_data[11],
      read_back_data[12],
      read_back_data[13],
      read_back_data[14],
      read_back_data[15],
      read_back_data[16],
      read_back_data[17],
      read_back_data[18],
      read_back_data[19]);
    applog(5, tmp42, 0);
    usleep(0x186A0u);
    if ( v6 != 3 )
      goto LABEL_9;
  }
  else
  {
    usleep(0x186A0u);
    if ( v6 != 3 )
      goto LABEL_9;
  }
  if ( read_back_data[0] != 20 )
  {
LABEL_9:
    if ( !use_syslog )
    {
      result = opt_log_output;
      if ( !opt_log_output && opt_log_level <= 2 )
        return result;
    }
    LOWORD(v9) = -29720;
    HIWORD(v9) = (unsigned int)"15] = 0x%x, \t\tread_back_data[16] = 0x%x, read_back_data[17] = 0x%x, read_back_data[18] = 0x%x, read_back_data[19] = 0x%x\n" >> 16;
    snprintf(tmp42, 0x1000u, v9, "read_PIC16F1704_flash_data_new", i2c_slave_addr);
    goto LABEL_13;
  }
  v10 = read_back_data[2];
  if ( read_back_data[18] != (unsigned __int16)(read_back_data[17]
                                              + read_back_data[16]
                                              + read_back_data[15]
                                              + read_back_data[14]
                                              + read_back_data[13]
                                              + read_back_data[12]
                                              + read_back_data[11]
                                              + read_back_data[10]
                                              + read_back_data[9]
                                              + read_back_data[8]
                                              + read_back_data[7]
                                              + read_back_data[6]
                                              + read_back_data[3]
                                              + read_back_data[2]
                                              + 23
                                              + read_back_data[4]
                                              + read_back_data[5]) >> 8
    || read_back_data[19] != (unsigned __int8)(read_back_data[17]
                                             + read_back_data[16]
                                             + read_back_data[15]
                                             + read_back_data[14]
                                             + read_back_data[13]
                                             + read_back_data[12]
                                             + read_back_data[11]
                                             + read_back_data[10]
                                             + read_back_data[9]
                                             + read_back_data[8]
                                             + read_back_data[7]
                                             + read_back_data[6]
                                             + read_back_data[3]
                                             + read_back_data[2]
                                             + 23
                                             + read_back_data[4]
                                             + read_back_data[5]) )
  {
    if ( !use_syslog )
    {
      result = opt_log_output;
      if ( !opt_log_output && opt_log_level <= 2 )
        return result;
    }
    LOWORD(v11) = -29700;
    HIWORD(v11) = (unsigned int)"ack_data[16] = 0x%x, read_back_data[17] = 0x%x, read_back_data[18] = 0x%x, read_back_data[19] = 0x%x\n" >> 16;
    snprintf(
      tmp42,
      0x1000u,
      v11,
      "read_PIC16F1704_flash_data_new",
      (unsigned __int16)(read_back_data[17]
                       + read_back_data[16]
                       + read_back_data[15]
                       + read_back_data[14]
                       + read_back_data[13]
                       + read_back_data[12]
                       + read_back_data[11]
                       + read_back_data[10]
                       + read_back_data[9]
                       + read_back_data[8]
                       + read_back_data[7]
                       + read_back_data[6]
                       + read_back_data[3]
                       + read_back_data[2]
                       + 23
                       + read_back_data[4]
                       + read_back_data[5]));
LABEL_13:
    applog(3, tmp42, 0);
    return 0;
  }
  v12 = buf - 1;
  for ( j = &read_back_data[3]; ; ++j )
  {
    *++v12 = v10;
    if ( &read_back_data[18] == j )
      break;
    v14 = *j;
    v10 = v14;
  }
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
    return 1;
  LOWORD(v15) = -30676;
  HIWORD(v15) = (unsigned int)"a[2] = 0x%02x, read_back_data[3] = 0x%02x\n" >> 16;
  snprintf(tmp42, 0x1000u, v15, "read_PIC16F1704_flash_data_new");
  applog(5, tmp42, 0);
  return 1;
}
