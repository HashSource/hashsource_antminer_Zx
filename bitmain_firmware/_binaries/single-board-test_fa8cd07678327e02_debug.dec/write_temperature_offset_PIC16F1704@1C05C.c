int __cdecl write_temperature_offset_PIC16F1704(
        unsigned int which_i2c,
        unsigned __int8 which_chain,
        unsigned __int8 *buf)
{
  int v3; // r4
  unsigned __int8 which_i2ca; // [sp+14h] [bp+Ch]
  char tmp42[1024]; // [sp+1Ch] [bp+14h] BYREF
  unsigned __int8 send_data[16]; // [sp+41Ch] [bp+414h] BYREF
  unsigned __int8 read_back_data[4]; // [sp+42Ch] [bp+424h]
  unsigned __int8 crc_data[4]; // [sp+430h] [bp+428h]
  unsigned __int8 length; // [sp+434h] [bp+42Ch]
  unsigned __int8 i; // [sp+435h] [bp+42Dh]
  unsigned __int16 crc; // [sp+436h] [bp+42Eh]
  _BYTE v15[4]; // [sp+438h] [bp+430h] BYREF

  which_i2ca = which_i2c;
  length = 12;
  *(_WORD *)crc_data = 255;
  *(_WORD *)read_back_data = 255;
  memset(send_data, 0, 14);
  crc = 46;
  for ( i = 0; i <= 7u; ++i )
    crc += buf[i];
  crc_data[0] = HIBYTE(crc);
  crc_data[1] = crc;
  send_data[0] = 85;
  send_data[1] = -86;
  send_data[2] = length;
  send_data[3] = 34;
  for ( i = 0; i <= 7u; ++i )
    v15[i - 24] = buf[i];
  send_data[12] = crc_data[0];
  send_data[13] = crc_data[1];
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 0xDu; ++i )
    write_pic(which_i2ca, which_chain, v15[i - 28]);
  usleep(0x30D40u);
  for ( i = 0; i <= 1u; ++i )
  {
    v3 = i;
    read_back_data[v3] = read_pic(which_i2ca, which_chain);
  }
  pthread_mutex_unlock(&i2c_mutex);
  usleep(0x30D40u);
  if ( read_back_data[0] == 34 && read_back_data[1] == 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s ok\n\n", "write_temperature_offset_PIC16F1704");
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
        "write_temperature_offset_PIC16F1704",
        read_back_data[0],
        read_back_data[1]);
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
