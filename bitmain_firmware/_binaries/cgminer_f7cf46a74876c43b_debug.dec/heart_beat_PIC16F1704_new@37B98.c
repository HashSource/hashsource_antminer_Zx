int heart_beat_PIC16F1704_new()
{
  unsigned __int8 *v0; // r4
  int i; // r3
  int v2; // t1
  unsigned __int8 *v3; // r4
  int v4; // r6
  int result; // r0
  unsigned __int8 read_back_data[6]; // [sp+18h] [bp-1010h] BYREF
  char v7; // [sp+1Eh] [bp-100Ah] BYREF
  unsigned __int8 send_data[6]; // [sp+20h] [bp-1008h] BYREF
  char tmp42[4096]; // [sp+28h] [bp-1000h] BYREF

  *(_DWORD *)read_back_data = 255;
  send_data[4] = 0;
  *(_WORD *)&read_back_data[4] = 0;
  v0 = send_data;
  *(_DWORD *)send_data = 369404501;
  send_data[5] = 26;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 85; ; i = v2 )
  {
    i2c_write(i | 0xA00000 | (i2c_slave_addr << 16));
    if ( &send_data[5] == v0 )
      break;
    v2 = *++v0;
  }
  v3 = read_back_data;
  usleep((__useconds_t)&loc_1869E + 2);
  do
    *v3++ = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  while ( &v7 != (char *)v3 );
  pthread_mutex_unlock(&i2c_mutex);
  v4 = read_back_data[1];
  if ( read_back_data[1] == 22 && (result = read_back_data[2], read_back_data[2] == 1) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "%s ok", "heart_beat_PIC16F1704_new");
      applog(7, tmp42, 0);
      return 1;
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    snprintf(tmp42, 0x1000u, "%s chain %d failed!", "heart_beat_PIC16F1704_new", i2c_slave_addr);
    applog(3, tmp42, 0);
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      snprintf(
        tmp42,
        0x1000u,
        "%s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n",
        "heart_beat_PIC16F1704_new",
        read_back_data[0],
        v4,
        read_back_data[2],
        read_back_data[3],
        read_back_data[4],
        read_back_data[5]);
      applog(3, tmp42, 0);
      return 0;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 0;
  }
  return result;
}
