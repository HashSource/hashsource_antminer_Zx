int __cdecl enable_PIC16F1704_dc_dc(unsigned int which_chain, unsigned __int8 which_i2c, unsigned __int8 enable)
{
  int v3; // r4
  unsigned __int8 which_chaina; // [sp+Ch] [bp+4h]
  char tmp42[1024]; // [sp+14h] [bp+Ch] BYREF
  unsigned __int8 send_data[7]; // [sp+414h] [bp+40Ch]
  unsigned __int8 read_back_data[4]; // [sp+41Ch] [bp+414h]
  unsigned __int8 crc_data[4]; // [sp+420h] [bp+418h]
  unsigned __int16 crc; // [sp+424h] [bp+41Ch]
  unsigned __int8 length; // [sp+426h] [bp+41Eh]
  unsigned __int8 i; // [sp+427h] [bp+41Fh]
  _BYTE v15[4]; // [sp+428h] [bp+420h] BYREF

  which_chaina = which_chain;
  length = 5;
  *(_WORD *)read_back_data = 255;
  *(_WORD *)send_data = -21931;
  send_data[3] = 21;
  crc = enable + 26;
  crc_data[0] = HIBYTE(crc);
  crc_data[1] = enable + 26;
  send_data[2] = 5;
  send_data[4] = enable;
  send_data[5] = HIBYTE(crc);
  send_data[6] = enable + 26;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 6u; ++i )
    write_pic(which_i2c, which_chaina, v15[i - 20]);
  usleep(0x186A0u);
  for ( i = 0; i <= 1u; ++i )
  {
    v3 = i;
    read_back_data[v3] = read_pic(which_i2c, which_chaina);
  }
  pthread_mutex_unlock(&i2c_mutex);
  if ( read_back_data[0] == 21 && read_back_data[1] == 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s ok\n\n", "enable_PIC16F1704_dc_dc");
      applog(2, tmp42, 0);
    }
    usleep((__useconds_t)&nonce_fifo.nonce_buffer[140].Nonce[564]);
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
        "enable_PIC16F1704_dc_dc",
        read_back_data[0],
        read_back_data[1]);
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
