int __cdecl save_freq_PIC16F1704(unsigned int which_chain, unsigned __int8 which_i2c, unsigned __int16 freq)
{
  __int16 v3; // r2
  int v4; // r4
  unsigned __int8 which_chaina; // [sp+Ch] [bp+4h]
  char tmp42[1024]; // [sp+14h] [bp+Ch] BYREF
  unsigned __int8 send_data[8]; // [sp+414h] [bp+40Ch]
  unsigned __int8 read_back_data[4]; // [sp+41Ch] [bp+414h]
  unsigned __int8 crc_data[4]; // [sp+420h] [bp+418h]
  unsigned __int16 crc; // [sp+424h] [bp+41Ch]
  unsigned __int8 length; // [sp+426h] [bp+41Eh]
  unsigned __int8 i; // [sp+427h] [bp+41Fh]
  _BYTE v17[4]; // [sp+428h] [bp+420h] BYREF

  which_chaina = which_chain;
  length = 6;
  *(_WORD *)read_back_data = 255;
  *(_DWORD *)send_data = 604416597;
  v3 = HIBYTE(freq) + 6;
  crc = (unsigned __int8)freq + v3 + 36;
  crc_data[0] = HIBYTE(crc);
  crc_data[1] = freq + v3 + 36;
  send_data[4] = HIBYTE(freq);
  send_data[5] = freq;
  send_data[6] = HIBYTE(crc);
  send_data[7] = crc_data[1];
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 7u; ++i )
    write_pic(which_i2c, which_chaina, v17[i - 20]);
  usleep((__useconds_t)&buf_7545[4072]);
  for ( i = 0; i <= 1u; ++i )
  {
    v4 = i;
    read_back_data[v4] = read_pic(which_i2c, which_chaina);
  }
  pthread_mutex_unlock(&i2c_mutex);
  usleep(0x30D40u);
  if ( read_back_data[0] == 36 && read_back_data[1] == 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s ok\n\n", "save_freq_PIC16F1704");
      applog(2, tmp42, 0);
    }
    return 1;
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(
        tmp42,
        0x400u,
        "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
        "save_freq_PIC16F1704",
        read_back_data[0],
        read_back_data[1]);
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
