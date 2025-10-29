int __cdecl send_data_to_PIC16F1704(unsigned int which_i2c, unsigned __int8 which_chain, unsigned __int8 *buf)
{
  int v3; // r4
  unsigned __int8 which_i2ca; // [sp+14h] [bp+Ch]
  char tmp42[1024]; // [sp+1Ch] [bp+14h] BYREF
  unsigned __int8 send_data[24]; // [sp+41Ch] [bp+414h] BYREF
  unsigned __int8 read_back_data[4]; // [sp+434h] [bp+42Ch]
  unsigned __int8 crc_data[4]; // [sp+438h] [bp+430h]
  unsigned __int8 length; // [sp+43Ch] [bp+434h]
  unsigned __int8 i; // [sp+43Dh] [bp+435h]
  unsigned __int16 crc; // [sp+43Eh] [bp+436h]
  _BYTE v15[4]; // [sp+440h] [bp+438h] BYREF

  which_i2ca = which_i2c;
  length = 20;
  *(_WORD *)crc_data = 255;
  *(_WORD *)read_back_data = 255;
  memset(send_data, 0, 22);
  crc = 22;
  for ( i = 0; i <= 0xFu; ++i )
    crc += buf[i];
  crc_data[0] = HIBYTE(crc);
  crc_data[1] = crc;
  send_data[0] = 85;
  send_data[1] = -86;
  send_data[2] = length;
  send_data[3] = 2;
  for ( i = 0; i <= 0xFu; ++i )
    v15[i - 32] = buf[i];
  send_data[20] = crc_data[0];
  send_data[21] = crc_data[1];
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 0x15u; ++i )
    write_pic(which_i2ca, which_chain, v15[i - 36]);
  usleep(0x186A0u);
  for ( i = 0; i <= 1u; ++i )
  {
    v3 = i;
    read_back_data[v3] = read_pic(which_i2ca, which_chain);
  }
  pthread_mutex_unlock(&i2c_mutex);
  if ( read_back_data[0] == 2 && read_back_data[1] == 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s ok\n\n", "send_data_to_PIC16F1704");
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
        "send_data_to_PIC16F1704",
        read_back_data[0],
        read_back_data[1]);
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
