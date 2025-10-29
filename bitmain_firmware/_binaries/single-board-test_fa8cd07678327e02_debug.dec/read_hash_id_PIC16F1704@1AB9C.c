int __cdecl read_hash_id_PIC16F1704(unsigned int which_i2c, unsigned __int8 which_chain, unsigned __int8 *buf)
{
  int v3; // r4
  unsigned __int8 which_i2ca; // [sp+74h] [bp+34h]
  char tmp42[1024]; // [sp+78h] [bp+38h] BYREF
  unsigned __int8 send_data[6]; // [sp+478h] [bp+438h]
  unsigned __int8 read_back_data[16]; // [sp+480h] [bp+440h] BYREF
  unsigned __int8 crc_data[4]; // [sp+490h] [bp+450h]
  unsigned __int16 crc; // [sp+494h] [bp+454h]
  unsigned __int8 length; // [sp+496h] [bp+456h]
  unsigned __int8 i; // [sp+497h] [bp+457h]
  _BYTE v16[4]; // [sp+498h] [bp+458h] BYREF

  which_i2ca = which_i2c;
  length = 4;
  crc_data[0] = 0;
  *(_DWORD *)read_back_data = 255;
  memset(&read_back_data[4], 0, 12);
  *(_DWORD *)send_data = 319072853;
  crc = 23;
  crc_data[1] = 23;
  send_data[4] = 0;
  send_data[5] = 23;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 5u; ++i )
    write_pic(which_i2ca, which_chain, v16[i - 32]);
  usleep(0x30D40u);
  for ( i = 0; i <= 0xFu; ++i )
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
      "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x,\t\t"
      "read_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x,\t\tread_ba"
      "ck_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x,\t\tread_back_da"
      "ta[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n",
      "read_hash_id_PIC16F1704",
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
      read_back_data[11],
      read_back_data[12],
      read_back_data[13],
      read_back_data[14],
      read_back_data[15]);
    applog(2, tmp42, 0);
  }
  if ( read_back_data[1] == 19 && read_back_data[0] == 16 )
  {
    crc = read_back_data[13]
        + read_back_data[12]
        + read_back_data[11]
        + read_back_data[10]
        + read_back_data[9]
        + read_back_data[8]
        + read_back_data[7]
        + read_back_data[6]
        + read_back_data[5]
        + read_back_data[4]
        + read_back_data[3]
        + read_back_data[2]
        + read_back_data[1]
        + read_back_data[0];
    if ( HIBYTE(crc) == read_back_data[14] && (unsigned __int8)crc == read_back_data[15] )
    {
      for ( i = 0; i <= 0xBu; ++i )
        buf[i] = v16[i - 22];
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "--- %s ok\n\n", "read_hash_id_PIC16F1704");
        applog(2, tmp42, 0);
      }
      return 1;
    }
    else
    {
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "--- %s failed! crc = 0x%04x\n\n", "read_hash_id_PIC16F1704", crc);
        applog(2, tmp42, 0);
      }
      return 0;
    }
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s failed!\n\n", "read_hash_id_PIC16F1704");
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
