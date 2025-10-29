int __cdecl read_temperature_offset_PIC16F1704(
        unsigned int which_i2c,
        unsigned __int8 which_chain,
        unsigned __int8 *buf)
{
  int v3; // r4
  unsigned __int8 which_i2ca; // [sp+54h] [bp+24h]
  char tmp42[1024]; // [sp+5Ch] [bp+2Ch] BYREF
  unsigned __int8 send_data[6]; // [sp+45Ch] [bp+42Ch]
  unsigned __int8 read_back_data[12]; // [sp+464h] [bp+434h]
  unsigned __int8 crc_data[4]; // [sp+470h] [bp+440h]
  unsigned __int16 crc; // [sp+474h] [bp+444h]
  unsigned __int8 length; // [sp+476h] [bp+446h]
  unsigned __int8 i; // [sp+477h] [bp+447h]
  _BYTE v16[4]; // [sp+478h] [bp+448h] BYREF

  which_i2ca = which_i2c;
  length = 4;
  crc_data[0] = 0;
  *(_DWORD *)read_back_data = 255;
  *(_DWORD *)&read_back_data[4] = 0;
  *(_DWORD *)&read_back_data[8] = 0;
  *(_DWORD *)send_data = 587508309;
  crc = 39;
  crc_data[1] = 39;
  send_data[4] = 0;
  send_data[5] = 39;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 5u; ++i )
    write_pic(which_i2ca, which_chain, v16[i - 28]);
  usleep(0x30D40u);
  for ( i = 0; i <= 0xBu; ++i )
  {
    v3 = i;
    read_back_data[v3] = read_pic(which_i2ca, which_chain);
  }
  pthread_mutex_unlock(&i2c_mutex);
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(
      tmp42,
      0x400u,
      "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, \t"
      "\tread_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x, \t\tread"
      "_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x\n",
      "read_temperature_offset_PIC16F1704",
      read_back_data[0],
      read_back_data[1],
      read_back_data[2],
      read_back_data[3],
      read_back_data[4],
      read_back_data[5],
      read_back_data[6],
      read_back_data[7],
      read_back_data[8],
      read_back_data[9],
      read_back_data[10],
      read_back_data[11]);
    applog(2, tmp42, 0);
  }
  if ( read_back_data[1] == 35 && read_back_data[0] == 12 )
  {
    crc = read_back_data[9]
        + read_back_data[8]
        + read_back_data[7]
        + read_back_data[6]
        + read_back_data[5]
        + read_back_data[4]
        + read_back_data[3]
        + read_back_data[2]
        + read_back_data[1]
        + read_back_data[0];
    if ( HIBYTE(crc) == read_back_data[10] && (unsigned __int8)crc == read_back_data[11] )
    {
      for ( i = 0; i <= 7u; ++i )
        buf[i] = v16[i - 18];
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "--- %s ok\n\n", "read_temperature_offset_PIC16F1704");
        applog(2, tmp42, 0);
      }
      return 1;
    }
    else
    {
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "--- %s failed! crc = 0x%04x\n\n", "read_temperature_offset_PIC16F1704", crc);
        applog(2, tmp42, 0);
      }
      return 0;
    }
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s failed!\n\n", "read_temperature_offset_PIC16F1704");
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
