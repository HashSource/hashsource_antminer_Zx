int __cdecl get_PIC16F1704_freq(unsigned int which_chain, unsigned __int8 which_i2c, unsigned __int16 *freq)
{
  int v3; // r4
  unsigned __int8 which_chaina; // [sp+24h] [bp+Ch]
  char tmp42[1024]; // [sp+28h] [bp+10h] BYREF
  unsigned __int8 send_data[6]; // [sp+428h] [bp+410h]
  unsigned __int8 read_back_data[6]; // [sp+430h] [bp+418h]
  unsigned __int8 crc_data[4]; // [sp+438h] [bp+420h]
  unsigned __int16 crc; // [sp+43Ch] [bp+424h]
  unsigned __int8 length; // [sp+43Eh] [bp+426h]
  unsigned __int8 i; // [sp+43Fh] [bp+427h]
  _BYTE v16[4]; // [sp+440h] [bp+428h] BYREF

  which_chaina = which_chain;
  length = 4;
  crc_data[0] = 0;
  *(_DWORD *)read_back_data = 255;
  *(_WORD *)&read_back_data[4] = 0;
  *(_DWORD *)send_data = 621062741;
  crc = 41;
  crc_data[1] = 41;
  send_data[4] = 0;
  send_data[5] = 41;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 5u; ++i )
    write_pic(which_i2c, which_chaina, v16[i - 24]);
  usleep((__useconds_t)&buf_7545[4072]);
  for ( i = 0; i <= 5u; ++i )
  {
    v3 = i;
    read_back_data[v3] = read_pic(which_i2c, which_chaina);
  }
  pthread_mutex_unlock(&i2c_mutex);
  usleep(0x30D40u);
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(
      tmp42,
      0x400u,
      "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, re"
      "ad_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n",
      "get_PIC16F1704_freq",
      read_back_data[0],
      read_back_data[1],
      read_back_data[2],
      read_back_data[3],
      read_back_data[4],
      read_back_data[5]);
    applog(2, tmp42, 0);
  }
  if ( read_back_data[1] == 37 && read_back_data[0] == 6 )
  {
    crc = read_back_data[3] + read_back_data[2] + read_back_data[1] + read_back_data[0];
    if ( HIBYTE(crc) == read_back_data[4] && (unsigned __int8)crc == read_back_data[5] )
    {
      *freq = _byteswap_ushort(*(unsigned __int16 *)&read_back_data[2]);
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "--- %s ok, freq = %d\n\n", "get_PIC16F1704_freq", *freq);
        applog(2, tmp42, 0);
      }
      return 1;
    }
    else
    {
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "--- %s failed! crc = 0x%04x\n\n", "get_PIC16F1704_freq", crc);
        applog(2, tmp42, 0);
      }
      return 0;
    }
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s failed!\n\n", "get_PIC16F1704_freq");
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
