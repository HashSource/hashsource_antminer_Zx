int __fastcall get_PIC16F1704_freq_new(unsigned __int16 *freq)
{
  unsigned __int8 *v2; // r4
  int i; // r3
  int v4; // t1
  unsigned __int8 *v5; // r4
  int v6; // r5
  const char *v7; // r2
  int v8; // r7
  const char *v9; // r2
  unsigned int v11; // r3
  const char *v12; // r2
  int v13; // r1
  const char *v14; // r2
  unsigned __int8 read_back_data[6]; // [sp+18h] [bp-Dh] BYREF
  __int16 v16; // [sp+1Eh] [bp-7h] BYREF
  unsigned __int8 send_data[6]; // [sp+20h] [bp-5h] BYREF
  char tmp42[4100]; // [sp+28h] [bp+3h] BYREF

  *(_DWORD *)read_back_data = 255;
  send_data[4] = 0;
  v2 = send_data;
  *(_WORD *)&read_back_data[4] = 0;
  *(_DWORD *)send_data = 621062741;
  send_data[5] = 41;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 85; ; i = v4 )
  {
    i2c_write(i | 0xA00000 | (i2c_slave_addr << 16));
    if ( &send_data[5] == v2 )
      break;
    v4 = *++v2;
  }
  v5 = read_back_data;
  usleep((__useconds_t)&loc_493E0);
  do
    *v5++ = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  while ( &v16 != (__int16 *)v5 );
  pthread_mutex_unlock(&i2c_mutex);
  usleep((__useconds_t)&loc_30D40);
  v6 = read_back_data[1];
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
  {
    if ( read_back_data[1] != 37 )
    {
LABEL_11:
      if ( opt_log_level <= 2 )
        return 0;
      goto LABEL_12;
    }
    if ( read_back_data[0] == 6 )
      goto LABEL_18;
LABEL_10:
    if ( !opt_log_output )
      goto LABEL_11;
LABEL_12:
    LOWORD(v9) = -27032;
    HIWORD(v9) = (unsigned int)"ack_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n" >> 16;
    snprintf(tmp42, 0x1000u, v9, "get_PIC16F1704_freq_new");
LABEL_13:
    applog(3, tmp42, 0);
    return 0;
  }
  LOWORD(v7) = -27196;
  HIWORD(v7) = (unsigned int)"ether_need_update_pic_program" >> 16;
  v8 = read_back_data[0];
  snprintf(
    tmp42,
    0x1000u,
    v7,
    "get_PIC16F1704_freq_new",
    read_back_data[0],
    read_back_data[1],
    read_back_data[2],
    read_back_data[3],
    read_back_data[4],
    read_back_data[5]);
  applog(5, tmp42, 0);
  if ( v6 != 37 || v8 != 6 )
  {
    if ( use_syslog )
      goto LABEL_12;
    goto LABEL_10;
  }
LABEL_18:
  v11 = read_back_data[2] + read_back_data[3] + 43;
  if ( read_back_data[4] != v11 >> 8 || read_back_data[5] != (unsigned __int8)v11 )
  {
    if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return 0;
    LOWORD(v12) = -27012;
    HIWORD(v12) = (unsigned int)"read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n" >> 16;
    snprintf(tmp42, 0x1000u, v12, "get_PIC16F1704_freq_new", read_back_data[2] + read_back_data[3] + 43);
    goto LABEL_13;
  }
  v13 = read_back_data[3] | (read_back_data[2] << 8);
  *freq = _byteswap_ushort(*(unsigned __int16 *)&read_back_data[2]);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
    return 1;
  LOWORD(v14) = -26980;
  HIWORD(v14) = (unsigned int)"ack_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n" >> 16;
  snprintf(tmp42, 0x1000u, v14, "get_PIC16F1704_freq_new", v13);
  applog(5, tmp42, 0);
  return 1;
}
