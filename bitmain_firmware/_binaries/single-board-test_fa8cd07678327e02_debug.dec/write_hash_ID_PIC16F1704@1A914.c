int __cdecl write_hash_ID_PIC16F1704(unsigned int which_chain, unsigned __int8 which_i2c, unsigned __int8 *buf)
{
  int v3; // r4
  unsigned __int8 which_chaina; // [sp+14h] [bp+Ch]
  char tmp42[1024]; // [sp+18h] [bp+10h] BYREF
  unsigned __int8 send_data[20]; // [sp+418h] [bp+410h] BYREF
  unsigned __int8 read_back_data[4]; // [sp+42Ch] [bp+424h]
  unsigned __int8 crc_data[4]; // [sp+430h] [bp+428h]
  unsigned __int8 length; // [sp+434h] [bp+42Ch]
  unsigned __int8 i; // [sp+435h] [bp+42Dh]
  unsigned __int16 crc; // [sp+436h] [bp+42Eh]
  _BYTE v15[4]; // [sp+438h] [bp+430h] BYREF

  which_chaina = which_chain;
  length = 16;
  *(_WORD *)crc_data = 255;
  *(_WORD *)read_back_data = 255;
  memset(send_data, 0, 18);
  crc = 34;
  for ( i = 0; i <= 0xBu; ++i )
    crc += buf[i];
  crc_data[0] = HIBYTE(crc);
  crc_data[1] = crc;
  send_data[0] = 85;
  send_data[1] = -86;
  send_data[2] = length;
  send_data[3] = 18;
  for ( i = 0; i <= 0xBu; ++i )
    v15[i - 28] = buf[i];
  send_data[16] = crc_data[0];
  send_data[17] = crc_data[1];
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 0x11u; ++i )
    write_pic(which_i2c, which_chaina, v15[i - 32]);
  usleep((__useconds_t)&nonce_fifo.nonce_buffer[66].Nonce[982]);
  for ( i = 0; i <= 1u; ++i )
  {
    v3 = i;
    read_back_data[v3] = read_pic(which_i2c, which_chaina);
  }
  pthread_mutex_unlock(&i2c_mutex);
  usleep(0x30D40u);
  if ( read_back_data[0] == 18 && read_back_data[1] == 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s ok\n\n", "write_hash_ID_PIC16F1704");
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
        "write_hash_ID_PIC16F1704",
        read_back_data[0],
        read_back_data[1]);
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
