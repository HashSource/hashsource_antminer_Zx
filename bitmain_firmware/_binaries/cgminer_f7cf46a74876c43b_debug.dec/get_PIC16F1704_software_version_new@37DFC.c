int __fastcall get_PIC16F1704_software_version_new(unsigned __int8 *version)
{
  unsigned __int8 *v2; // r4
  int i; // r3
  int v4; // t1
  unsigned __int8 *v5; // r4
  int v6; // r7
  unsigned __int16 v7; // r3
  unsigned __int8 read_back_data[5]; // [sp+18h] [bp-Dh] BYREF
  _BYTE v10[3]; // [sp+1Dh] [bp-8h] BYREF
  unsigned __int8 send_data[6]; // [sp+20h] [bp-5h] BYREF
  char tmp42[4100]; // [sp+28h] [bp+3h] BYREF

  *(_DWORD *)read_back_data = 255;
  send_data[4] = 0;
  v2 = send_data;
  read_back_data[4] = 0;
  *(_DWORD *)send_data = 386181717;
  send_data[5] = 27;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 85; ; i = v4 )
  {
    i2c_write(i | 0xA00000 | (i2c_slave_addr << 16));
    if ( &send_data[5] == v2 )
      break;
    v4 = *++v2;
  }
  v5 = read_back_data;
  usleep(0x61A80u);
  do
    *v5++ = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  while ( v10 != v5 );
  pthread_mutex_unlock(&i2c_mutex);
  v6 = read_back_data[1];
  if ( opt_debug )
  {
    if ( !use_syslog && !opt_log_output && opt_log_level <= 6 )
    {
      if ( read_back_data[1] != 23 )
        goto LABEL_26;
      if ( read_back_data[0] == 5 )
        goto LABEL_12;
LABEL_20:
      if ( opt_log_output )
      {
LABEL_21:
        snprintf(tmp42, 0x1000u, "%s chain %d failed!", "get_PIC16F1704_software_version_new", i2c_slave_addr);
        applog(3, tmp42, 0);
        if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
          return 0;
        snprintf(
          tmp42,
          0x1000u,
          "%s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, re"
          "ad_back_data[4] = 0x%x",
          "get_PIC16F1704_software_version_new",
          read_back_data[0],
          v6,
          read_back_data[2],
          read_back_data[3],
          read_back_data[4]);
LABEL_24:
        applog(3, tmp42, 0);
        return 0;
      }
LABEL_26:
      if ( opt_log_level <= 2 )
        return 0;
      goto LABEL_21;
    }
    snprintf(
      tmp42,
      0x1000u,
      "%s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_b"
      "ack_data[4] = 0x%x",
      "get_PIC16F1704_software_version_new",
      read_back_data[0],
      read_back_data[1],
      read_back_data[2],
      read_back_data[3],
      read_back_data[4]);
    applog(7, tmp42, 0);
  }
  if ( v6 != 23 || read_back_data[0] != 5 )
  {
    if ( use_syslog )
      goto LABEL_21;
    goto LABEL_20;
  }
LABEL_12:
  v7 = read_back_data[2] + 28;
  if ( read_back_data[3] != HIBYTE(v7) || read_back_data[4] != (unsigned __int8)v7 )
  {
    if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return 0;
    snprintf(tmp42, 0x1000u, "%s failed! crc = 0x%04x", "get_PIC16F1704_software_version_new", v7);
    goto LABEL_24;
  }
  *version = read_back_data[2];
  return 1;
}
