int __fastcall get_PIC16F1704_freq_new(unsigned __int16 *freq)
{
  unsigned __int8 *v2; // r4
  int i; // r3
  int v4; // t1
  unsigned __int8 *v5; // r4
  int v6; // r5
  int v7; // r7
  unsigned int v9; // r3
  int v10; // r1
  unsigned __int8 read_back_data[6]; // [sp+18h] [bp-Dh] BYREF
  __int16 v12; // [sp+1Eh] [bp-7h] BYREF
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
  usleep((__useconds_t)&loc_493DE + 2);
  do
    *v5++ = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  while ( &v12 != (__int16 *)v5 );
  pthread_mutex_unlock(&i2c_mutex);
  usleep((__useconds_t)&loc_30D3E + 2);
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
    snprintf(tmp42, 0x1000u, "\n--- %s failed!\n\n", "get_PIC16F1704_freq_new");
LABEL_13:
    applog(3, tmp42, 0);
    return 0;
  }
  v7 = read_back_data[0];
  snprintf(
    tmp42,
    0x1000u,
    "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read"
    "_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n",
    "get_PIC16F1704_freq_new",
    read_back_data[0],
    read_back_data[1],
    read_back_data[2],
    read_back_data[3],
    read_back_data[4],
    read_back_data[5]);
  applog(5, tmp42, 0);
  if ( v6 != 37 || v7 != 6 )
  {
    if ( use_syslog )
      goto LABEL_12;
    goto LABEL_10;
  }
LABEL_18:
  v9 = read_back_data[2] + read_back_data[3] + 43;
  if ( read_back_data[4] != v9 >> 8 || read_back_data[5] != (unsigned __int8)v9 )
  {
    if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return 0;
    snprintf(
      tmp42,
      0x1000u,
      "\n--- %s failed! crc = 0x%04x\n\n",
      "get_PIC16F1704_freq_new",
      read_back_data[2] + read_back_data[3] + 43);
    goto LABEL_13;
  }
  v10 = read_back_data[3] | (read_back_data[2] << 8);
  *freq = _byteswap_ushort(*(unsigned __int16 *)&read_back_data[2]);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
    return 1;
  snprintf(tmp42, 0x1000u, "\n--- %s ok, freq = %d\n\n", "get_PIC16F1704_freq_new", v10);
  applog(5, tmp42, 0);
  return 1;
}
