int __fastcall read_hash_id_PIC16F1704_new(unsigned __int8 *buf)
{
  unsigned __int8 *v2; // r4
  int i; // r3
  int v4; // t1
  unsigned __int8 *v5; // r4
  int v6; // r6
  const char *v7; // r2
  int v8; // r8
  const char *v9; // r2
  unsigned __int8 v11; // r2
  const char *v12; // r2
  unsigned __int8 *v13; // r3
  unsigned __int8 *v14; // r1
  unsigned __int8 *v15; // r7
  unsigned __int8 v16; // t1
  const char *v17; // r2
  unsigned __int8 send_data[6]; // [sp+40h] [bp-1018h] BYREF
  char v19; // [sp+47h] [bp-1011h] BYREF
  unsigned __int8 read_back_data[16]; // [sp+48h] [bp-1010h] BYREF
  char tmp42[4096]; // [sp+58h] [bp-1000h] BYREF

  *(_DWORD *)read_back_data = 255;
  send_data[4] = 0;
  v2 = send_data;
  memset(&read_back_data[4], 0, 12);
  *(_DWORD *)send_data = 319072853;
  send_data[5] = 23;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 85; ; i = v4 )
  {
    i2c_write(i | 0xA00000 | (i2c_slave_addr << 16));
    if ( &send_data[5] == v2 )
      break;
    v4 = *++v2;
  }
  v5 = (unsigned __int8 *)&v19;
  usleep((__useconds_t)&loc_30D40);
  do
    *++v5 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  while ( v5 != &read_back_data[15] );
  pthread_mutex_unlock(&i2c_mutex);
  v6 = read_back_data[1];
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
  {
    if ( read_back_data[1] != 19 )
    {
LABEL_11:
      if ( opt_log_level <= 2 )
        return 0;
      goto LABEL_12;
    }
    if ( read_back_data[0] == 16 )
      goto LABEL_18;
LABEL_10:
    if ( !opt_log_output )
      goto LABEL_11;
LABEL_12:
    LOWORD(v9) = -28596;
    HIWORD(v9) = (unsigned int)"11] = 0x%x,\t\tread_back_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
    snprintf(tmp42, 0x1000u, v9, "read_hash_id_PIC16F1704_new", i2c_slave_addr);
LABEL_13:
    applog(3, tmp42, 0);
    return 0;
  }
  LOWORD(v7) = -29028;
  HIWORD(v7) = (unsigned int)"n%d asic%d addr %02x, %s set vol %d, get vol %d" >> 16;
  v8 = read_back_data[0];
  snprintf(
    tmp42,
    0x1000u,
    v7,
    "read_hash_id_PIC16F1704_new",
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
    read_back_data[15]);
  applog(5, tmp42, 0);
  if ( v6 != 19 || v8 != 16 )
  {
    if ( use_syslog )
      goto LABEL_12;
    goto LABEL_10;
  }
LABEL_18:
  v11 = read_back_data[2];
  if ( read_back_data[14] != (unsigned __int16)(read_back_data[13]
                                              + read_back_data[12]
                                              + read_back_data[11]
                                              + read_back_data[10]
                                              + read_back_data[9]
                                              + read_back_data[8]
                                              + read_back_data[7]
                                              + read_back_data[6]
                                              + read_back_data[3]
                                              + read_back_data[2]
                                              + 35
                                              + read_back_data[4]
                                              + read_back_data[5]) >> 8
    || read_back_data[15] != (unsigned __int8)(read_back_data[13]
                                             + read_back_data[12]
                                             + read_back_data[11]
                                             + read_back_data[10]
                                             + read_back_data[9]
                                             + read_back_data[8]
                                             + read_back_data[7]
                                             + read_back_data[6]
                                             + read_back_data[3]
                                             + read_back_data[2]
                                             + 35
                                             + read_back_data[4]
                                             + read_back_data[5]) )
  {
    if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return 0;
    LOWORD(v12) = -28572;
    HIWORD(v12) = (unsigned int)"ata[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
    snprintf(
      tmp42,
      0x1000u,
      v12,
      "read_hash_id_PIC16F1704_new",
      (unsigned __int16)(read_back_data[13]
                       + read_back_data[12]
                       + read_back_data[11]
                       + read_back_data[10]
                       + read_back_data[9]
                       + read_back_data[8]
                       + read_back_data[7]
                       + read_back_data[6]
                       + read_back_data[3]
                       + read_back_data[2]
                       + 35
                       + read_back_data[4]
                       + read_back_data[5]));
    goto LABEL_13;
  }
  v13 = buf - 1;
  v14 = &read_back_data[2];
  v15 = buf + 11;
  while ( 1 )
  {
    *++v13 = v11;
    if ( v15 == v13 )
      break;
    v16 = *++v14;
    v11 = v16;
  }
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
    return 1;
  LOWORD(v17) = -30676;
  HIWORD(v17) = (unsigned int)"a[2] = 0x%02x, read_back_data[3] = 0x%02x\n" >> 16;
  snprintf(tmp42, 0x1000u, v17, "read_hash_id_PIC16F1704_new");
  applog(5, tmp42, 0);
  return 1;
}
