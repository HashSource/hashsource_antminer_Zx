int __cdecl get_PIC16F1704_voltage(unsigned int which_i2c, unsigned __int8 which_chain, unsigned __int8 *voltage)
{
  int v3; // r4
  unsigned __int8 which_i2ca; // [sp+24h] [bp+Ch]
  char tmp42[1024]; // [sp+28h] [bp+10h] BYREF
  unsigned __int8 send_data[6]; // [sp+428h] [bp+410h]
  unsigned __int8 read_back_data[8]; // [sp+430h] [bp+418h]
  unsigned __int8 crc_data[4]; // [sp+438h] [bp+420h]
  unsigned __int16 crc; // [sp+43Ch] [bp+424h]
  unsigned __int8 length; // [sp+43Eh] [bp+426h]
  unsigned __int8 i; // [sp+43Fh] [bp+427h]
  _BYTE vars0[16]; // [sp+440h] [bp+428h] BYREF

  which_i2ca = which_i2c;
  length = 4;
  crc_data[0] = 0;
  *(_DWORD *)read_back_data = 255;
  read_back_data[4] = 0;
  *(_DWORD *)send_data = 402958933;
  crc = 28;
  crc_data[1] = 28;
  send_data[4] = 0;
  send_data[5] = 28;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 5u; ++i )
    write_pic(which_i2ca, which_chain, vars0[i - 24]);
  usleep(0x30D40u);
  for ( i = 0; i <= 4u; ++i )
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
      "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, re"
      "ad_back_data[4] = 0x%x\n",
      "get_PIC16F1704_voltage",
      read_back_data[0],
      read_back_data[1],
      read_back_data[2],
      read_back_data[3],
      read_back_data[4]);
    applog(2, tmp42, 0);
  }
  if ( read_back_data[1] == 24 && read_back_data[0] == 5 )
  {
    crc = read_back_data[2] + read_back_data[1] + read_back_data[0];
    if ( HIBYTE(crc) == read_back_data[3] && (unsigned __int8)crc == read_back_data[4] )
    {
      *voltage = read_back_data[2];
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "--- %s ok, voltage = 0x%02x\n\n", "get_PIC16F1704_voltage", *voltage);
        applog(2, tmp42, 0);
      }
      return 1;
    }
    else
    {
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "--- %s failed! crc = 0x%04x\n\n", "get_PIC16F1704_voltage", crc);
        applog(2, tmp42, 0);
      }
      return 0;
    }
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s failed!\n\n", "get_PIC16F1704_voltage");
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
