int __fastcall read_PIC16F1704_flash_data_new(unsigned __int8 *buf)
{
  unsigned __int8 *v2; // r4
  int i; // r3
  int v4; // t1
  unsigned __int8 *v5; // r4
  int v6; // r6
  int result; // r0
  unsigned __int8 v8; // r1
  unsigned __int8 *v9; // r7
  unsigned __int8 *j; // r2
  unsigned __int8 v11; // t1
  unsigned __int8 send_data[6]; // [sp+54h] [bp-1020h] BYREF
  char v13; // [sp+5Bh] [bp-1019h] BYREF
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
  v5 = (unsigned __int8 *)&v13;
  usleep((__useconds_t)&loc_493DE + 2);
  do
    *++v5 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  while ( v5 != &read_back_data[19] );
  pthread_mutex_unlock(&i2c_mutex);
  v6 = read_back_data[1];
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "%s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, \t\tre"
      "ad_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x, \t\tread_bac"
      "k_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x, \t\tread_back_da"
      "ta[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x, \t\tread_back_data"
      "[16] = 0x%x, read_back_data[17] = 0x%x, read_back_data[18] = 0x%x, read_back_data[19] = 0x%x\n",
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
    snprintf(tmp42, 0x1000u, "%s chain %d failed!", "read_PIC16F1704_flash_data_new", i2c_slave_addr);
    goto LABEL_13;
  }
  v8 = read_back_data[2];
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
    snprintf(
      tmp42,
      0x1000u,
      "%s failed! crc = 0x%04x\n\n",
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
  v9 = buf - 1;
  for ( j = &read_back_data[3]; ; ++j )
  {
    *++v9 = v8;
    if ( &read_back_data[18] == j )
      break;
    v11 = *j;
    v8 = v11;
  }
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
    return 1;
  snprintf(tmp42, 0x1000u, "%s ok", "read_PIC16F1704_flash_data_new");
  applog(5, tmp42, 0);
  return 1;
}
