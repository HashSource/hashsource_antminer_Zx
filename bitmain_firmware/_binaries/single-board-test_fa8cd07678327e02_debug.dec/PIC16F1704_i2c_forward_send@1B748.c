int __cdecl PIC16F1704_i2c_forward_send(
        uint32_t i2c,
        uint8_t chain,
        uint8_t dev_addr,
        int rw_flag,
        uint8_t reg_addr,
        int len,
        uint8_t *data)
{
  unsigned __int8 i2ca; // [sp+14h] [bp+Ch]
  char tmp42[1024]; // [sp+18h] [bp+10h] BYREF
  uint8_t recv_data[12]; // [sp+418h] [bp+410h] BYREF
  uint8_t send_data[32]; // [sp+424h] [bp+41Ch] BYREF
  int i_1; // [sp+444h] [bp+43Ch]
  int i_0; // [sp+448h] [bp+440h]
  int i; // [sp+44Ch] [bp+444h]
  int body_len; // [sp+450h] [bp+448h]
  uint16_t crc; // [sp+456h] [bp+44Eh]
  _BYTE v21[4]; // [sp+458h] [bp+450h] BYREF

  i2ca = i2c;
  memset(send_data, 0, sizeof(send_data));
  memset(recv_data, 0, sizeof(recv_data));
  crc = 0;
  body_len = 0;
  i = 0;
  send_data[0] = 85;
  send_data[1] = -86;
  send_data[2] = 0;
  send_data[3] = 38;
  send_data[4] = rw_flag | (2 * dev_addr);
  send_data[5] = reg_addr;
  if ( rw_flag )
  {
    body_len = 5;
    send_data[6] = len;
  }
  else
  {
    body_len = len + 4;
    memcpy(&send_data[6], data, len);
  }
  send_data[2] = body_len + 2;
  for ( i_0 = 0; i_0 < body_len; ++i_0 )
    crc += (unsigned __int8)v21[i_0 - 50];
  v21[body_len - 50] = HIBYTE(crc);
  v21[body_len - 49] = crc;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; body_len + 4 > i; ++i )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "write pic i2c[%d] %02x\n", i, send_data[i]);
      applog(2, tmp42, 0);
    }
    write_pic(i2ca, chain, send_data[i]);
  }
  usleep(0x30D40u);
  if ( rw_flag != 1 )
    goto LABEL_40;
  for ( i = 0; len + 5 > i; ++i )
  {
    recv_data[i] = read_pic(i2ca, chain);
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "read pic i2c[%d] %02x\n", i, recv_data[i]);
      applog(2, tmp42, 0);
    }
  }
  for ( i_1 = 0; len + 3 > i_1; ++i_1 )
    crc += recv_data[i_1];
  if ( crc == *(unsigned __int16 *)&recv_data[len + 3] )
  {
    if ( recv_data[0] != body_len + 2 || recv_data[1] != 38 || recv_data[2] != 1 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "pic read failed %d %d %d\n", *data, data[1], data[2]);
        applog(2, tmp42, 0);
      }
      goto LABEL_30;
    }
    memcpy(data, &recv_data[3], len);
LABEL_40:
    pthread_mutex_unlock(&i2c_mutex);
    return 0;
  }
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "crc failed 0x%x\n", crc);
    applog(2, tmp42, 0);
  }
LABEL_30:
  pthread_mutex_unlock(&i2c_mutex);
  return -1;
}
