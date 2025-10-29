int __fastcall save_freq_PIC16F1704_new(unsigned __int16 freq)
{
  char *v1; // r4
  int i; // r3
  int v3; // t1
  int v4; // r4
  int v5; // r6
  bool v6; // zf
  int result; // r0
  const char *v8; // r2
  const char *v9; // r2
  unsigned __int8 send_data[8]; // [sp+8h] [bp-1008h] BYREF
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  send_data[4] = HIBYTE(freq);
  send_data[7] = freq + HIBYTE(freq) + 42;
  *(_DWORD *)send_data = 604416597;
  v1 = (char *)&send_data[1];
  send_data[5] = freq;
  send_data[6] = (unsigned __int16)((unsigned __int8)freq + HIBYTE(freq) + 42) >> 8;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 85; ; i = v3 )
  {
    i2c_write(i | 0xA00000 | (i2c_slave_addr << 16));
    if ( tmp42 == v1 )
      break;
    v3 = (unsigned __int8)*v1++;
  }
  usleep(0x493E0u);
  v4 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  v5 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  pthread_mutex_unlock(&i2c_mutex);
  usleep(0x30D40u);
  v6 = v5 == 1;
  if ( v5 == 1 )
    v6 = v4 == 36;
  if ( v6 )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v9) = -27212;
      HIWORD(v9) = (unsigned int)"d times" >> 16;
      snprintf(tmp42, 0x1000u, v9, "save_freq_PIC16F1704_new");
      applog(7, tmp42, 0);
      return 1;
    }
    else
    {
      return 1;
    }
  }
  else if ( use_syslog || (result = opt_log_output) != 0 || opt_log_level > 2 )
  {
    LOWORD(v8) = -27288;
    HIWORD(v8) = (unsigned int)"%s: create thread error for pic_heart_beat_func" >> 16;
    snprintf(tmp42, 0x1000u, v8, "save_freq_PIC16F1704_new", v4, v5, *(_DWORD *)send_data);
    applog(3, tmp42, 0);
    return 0;
  }
  return result;
}
