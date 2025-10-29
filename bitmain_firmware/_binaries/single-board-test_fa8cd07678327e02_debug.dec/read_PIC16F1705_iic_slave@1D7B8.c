int __cdecl read_PIC16F1705_iic_slave(
        unsigned int which_i2c,
        unsigned __int8 which_chain,
        unsigned __int8 *buf,
        unsigned __int8 buf_len,
        unsigned __int8 *read_back_buf)
{
  int v5; // r4
  unsigned __int8 which_i2ca; // [sp+14h] [bp+Ch]
  char tmp42[1024]; // [sp+18h] [bp+10h] BYREF
  unsigned __int8 send_data[100]; // [sp+418h] [bp+410h] BYREF
  unsigned __int8 read_back_data[100]; // [sp+47Ch] [bp+474h] BYREF
  unsigned __int8 crc_data[4]; // [sp+4E0h] [bp+4D8h]
  unsigned __int8 length; // [sp+4E4h] [bp+4DCh]
  unsigned __int8 i; // [sp+4E5h] [bp+4DDh]
  unsigned __int16 crc; // [sp+4E6h] [bp+4DEh]
  _BYTE v19[4]; // [sp+4E8h] [bp+4E0h] BYREF

  which_i2ca = which_i2c;
  length = buf_len + 4;
  *(_WORD *)crc_data = 255;
  memset(read_back_data, 0, sizeof(read_back_data));
  read_back_data[0] = -1;
  crc = 0;
  memset(send_data, 0, sizeof(send_data));
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "--- %s\n", "read_PIC16F1705_iic_slave");
    applog(2, tmp42, 0);
  }
  crc = length + 38;
  for ( i = 0; i < (unsigned int)buf_len; ++i )
    crc += buf[i];
  crc_data[0] = HIBYTE(crc);
  crc_data[1] = crc;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(
      tmp42,
      0x400u,
      "--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n",
      "read_PIC16F1705_iic_slave",
      crc_data[0],
      crc_data[1]);
    applog(2, tmp42, 0);
  }
  send_data[0] = 85;
  send_data[1] = -86;
  send_data[2] = length;
  send_data[3] = 38;
  for ( i = 0; i < (unsigned int)buf_len; ++i )
    v19[i - 204] = buf[i];
  v19[buf_len - 204] = crc_data[0];
  v19[buf_len - 203] = crc_data[1];
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i < length + 2; ++i )
    write_pic(which_i2ca, which_chain, v19[i - 208]);
  usleep(0x30D40u);
  for ( i = 0; i < buf[2] + 3; ++i )
  {
    v5 = i;
    read_back_data[v5] = read_pic(which_i2ca, which_chain);
  }
  pthread_mutex_unlock(&i2c_mutex);
  usleep(0x30D40u);
  if ( read_back_data[1] == 38 && read_back_data[2] == 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s ok\n\n", "read_PIC16F1705_iic_slave");
      applog(2, tmp42, 0);
    }
    return 1;
  }
  else
  {
    for ( i = 0; i < buf[2] + 3; ++i )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(
          tmp42,
          0x400u,
          "--- %s failed! read_back_data[%d] = 0x%02x\n\n",
          "read_PIC16F1705_iic_slave",
          i,
          (unsigned __int8)v19[i - 108]);
        applog(2, tmp42, 0);
      }
    }
    return 0;
  }
}
