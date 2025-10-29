int __cdecl write_PIC16F1705_iic_slave(
        unsigned int which_i2c,
        unsigned __int8 which_chain,
        unsigned __int8 *buf,
        unsigned __int8 buf_len)
{
  int v4; // r4
  unsigned __int8 which_i2ca; // [sp+24h] [bp+Ch]
  char tmp42[1024]; // [sp+2Ch] [bp+14h] BYREF
  unsigned __int8 send_data[100]; // [sp+42Ch] [bp+414h] BYREF
  unsigned __int8 read_back_data[8]; // [sp+490h] [bp+478h]
  unsigned __int8 crc_data[4]; // [sp+498h] [bp+480h]
  unsigned __int8 length; // [sp+49Ch] [bp+484h]
  unsigned __int8 i; // [sp+49Dh] [bp+485h]
  unsigned __int16 crc; // [sp+49Eh] [bp+486h]
  _BYTE vars0[16]; // [sp+4A0h] [bp+488h] BYREF

  which_i2ca = which_i2c;
  length = buf_len + 4;
  *(_WORD *)crc_data = 255;
  *(_DWORD *)read_back_data = 255;
  read_back_data[4] = 0;
  crc = 0;
  memset(send_data, 0, sizeof(send_data));
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "--- %s\n", "write_PIC16F1705_iic_slave");
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
      "write_PIC16F1705_iic_slave",
      crc_data[0],
      crc_data[1]);
    applog(2, tmp42, 0);
  }
  send_data[0] = 85;
  send_data[1] = -86;
  send_data[2] = length;
  send_data[3] = 38;
  for ( i = 0; i < (unsigned int)buf_len; ++i )
    vars0[i - 112] = buf[i];
  vars0[buf_len - 112] = crc_data[0];
  vars0[buf_len - 111] = crc_data[1];
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i < length + 2; ++i )
    write_pic(which_i2ca, which_chain, vars0[i - 116]);
  usleep(0x30D40u);
  for ( i = 0; i <= 4u; ++i )
  {
    v4 = i;
    read_back_data[v4] = read_pic(which_i2ca, which_chain);
  }
  pthread_mutex_unlock(&i2c_mutex);
  usleep(0x30D40u);
  if ( read_back_data[1] == 38 && read_back_data[2] == 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s ok\n\n", "write_PIC16F1705_iic_slave");
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
        "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x, read_back_dat"
        "a[3] = 0x%02x, read_back_data[4] = 0x%02x\n"
        "\n",
        "write_PIC16F1705_iic_slave",
        read_back_data[0],
        read_back_data[1],
        read_back_data[2],
        read_back_data[3],
        read_back_data[4]);
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
