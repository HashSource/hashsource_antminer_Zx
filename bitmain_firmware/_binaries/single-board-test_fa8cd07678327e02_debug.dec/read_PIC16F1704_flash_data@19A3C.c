int __cdecl read_PIC16F1704_flash_data(unsigned int which_i2c, unsigned __int8 which_chain, unsigned __int8 *buf)
{
  int v3; // r4
  unsigned __int8 which_i2ca; // [sp+94h] [bp+44h]
  char tmp42[1024]; // [sp+9Ch] [bp+4Ch] BYREF
  unsigned __int8 send_data[6]; // [sp+49Ch] [bp+44Ch]
  unsigned __int8 read_back_data[20]; // [sp+4A4h] [bp+454h] BYREF
  unsigned __int8 crc_data[4]; // [sp+4B8h] [bp+468h]
  unsigned __int16 crc; // [sp+4BCh] [bp+46Ch]
  unsigned __int8 length; // [sp+4BEh] [bp+46Eh]
  unsigned __int8 i; // [sp+4BFh] [bp+46Fh]
  _BYTE v16[4]; // [sp+4C0h] [bp+470h] BYREF

  which_i2ca = which_i2c;
  length = 4;
  crc_data[0] = 0;
  *(_DWORD *)read_back_data = 255;
  memset(&read_back_data[4], 0, 16);
  *(_DWORD *)send_data = 50637397;
  crc = 7;
  crc_data[1] = 7;
  send_data[4] = 0;
  send_data[5] = 7;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 5u; ++i )
    write_pic(which_i2ca, which_chain, v16[i - 36]);
  usleep((__useconds_t)&buf_7545[4072]);
  for ( i = 0; i <= 0x13u; ++i )
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
      "_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x, \t\tread_bac"
      "k_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x, \t\tread_back_"
      "data[16] = 0x%x, read_back_data[17] = 0x%x, read_back_data[18] = 0x%x, read_back_data[19] = 0x%x\n",
      "read_PIC16F1704_flash_data",
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
      read_back_data[15],
      read_back_data[16],
      read_back_data[17],
      read_back_data[18],
      read_back_data[19]);
    applog(2, tmp42, 0);
  }
  usleep(0x186A0u);
  if ( read_back_data[1] == 3 && read_back_data[0] == 20 )
  {
    crc = read_back_data[17]
        + read_back_data[16]
        + read_back_data[15]
        + read_back_data[14]
        + read_back_data[13]
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
    if ( HIBYTE(crc) == read_back_data[18] && (unsigned __int8)crc == read_back_data[19] )
    {
      for ( i = 0; i <= 0xFu; ++i )
        buf[i] = v16[i - 26];
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "--- %s ok\n\n", "read_PIC16F1704_flash_data");
        applog(2, tmp42, 0);
      }
      return 1;
    }
    else
    {
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "--- %s failed! crc = 0x%04x\n\n", "read_PIC16F1704_flash_data", crc);
        applog(2, tmp42, 0);
      }
      return 0;
    }
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s failed!\n\n", "read_PIC16F1704_flash_data");
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
