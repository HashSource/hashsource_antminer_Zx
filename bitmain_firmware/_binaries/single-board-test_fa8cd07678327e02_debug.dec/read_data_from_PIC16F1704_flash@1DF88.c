int __cdecl read_data_from_PIC16F1704_flash(
        int which_chain,
        int which_i2c,
        unsigned __int8 *buf,
        unsigned __int8 read_len)
{
  int v4; // r4
  unsigned __int8 which_i2ca; // [sp+18h] [bp+8h]
  unsigned __int8 which_chaina; // [sp+1Ch] [bp+Ch]
  char tmp42[1024]; // [sp+20h] [bp+10h] BYREF
  unsigned __int8 send_data[8]; // [sp+420h] [bp+410h] BYREF
  unsigned __int8 read_back_data[40]; // [sp+428h] [bp+418h] BYREF
  unsigned __int8 crc_data[4]; // [sp+450h] [bp+440h]
  unsigned __int8 length; // [sp+454h] [bp+444h]
  unsigned __int8 i; // [sp+455h] [bp+445h]
  unsigned __int16 crc; // [sp+456h] [bp+446h]
  _BYTE v18[4]; // [sp+458h] [bp+448h] BYREF

  which_chaina = which_chain;
  which_i2ca = which_i2c;
  length = 6;
  *(_WORD *)crc_data = 255;
  memset(read_back_data, 0, sizeof(read_back_data));
  read_back_data[0] = -1;
  crc = 0;
  memset(send_data, 0, sizeof(send_data));
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "\n--- %s\n", "read_data_from_PIC16F1704_flash");
    applog(2, tmp42, 0);
  }
  crc = read_len + length + 52;
  crc_data[0] = HIBYTE(crc);
  crc_data[1] = read_len + length + 52;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(
      tmp42,
      0x400u,
      "--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n",
      "read_data_from_PIC16F1704_flash",
      crc_data[0],
      crc_data[1]);
    applog(2, tmp42, 0);
  }
  send_data[0] = 85;
  send_data[1] = -86;
  send_data[2] = length;
  strcpy((char *)&send_data[3], "4");
  send_data[5] = read_len;
  send_data[6] = crc_data[0];
  send_data[7] = crc_data[1];
  for ( i = 0; i <= 7u; ++i )
    printf("%02x ", (unsigned __int8)v18[i - 56]);
  putchar(10);
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 7u; ++i )
    write_pic(which_i2ca, which_chaina, v18[i - 56]);
  usleep(0x30D40u);
  for ( i = 0; i < read_len + 5; ++i )
  {
    v4 = i;
    read_back_data[v4] = read_pic(which_i2ca, which_chaina);
  }
  pthread_mutex_unlock(&i2c_mutex);
  usleep(0x30D40u);
  for ( i = 0; i < read_len + 5; ++i )
    printf("%02x ", (unsigned __int8)v18[i - 48]);
  putchar(10);
  if ( read_back_data[1] == 52 && read_back_data[0] == read_len + 5 && read_back_data[2] == 1 )
  {
    crc = 0;
    for ( i = 0; i < read_len + 3; ++i )
      crc += (unsigned __int8)v18[i - 48];
    if ( HIBYTE(crc) == (unsigned __int8)v18[read_len - 45]
      && (unsigned __int8)crc == (unsigned __int8)v18[read_len - 44] )
    {
      memcpy(buf, &read_back_data[3], read_len);
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "\n--- %s ok\n\n", "read_data_from_PIC16F1704_flash");
        applog(2, tmp42, 0);
      }
      return 1;
    }
    else
    {
      if ( use_syslog || opt_log_output || opt_log_level >= 0 )
      {
        snprintf(tmp42, 0x400u, "\n--- %s failed! crc = 0x%04x\n\n", "read_data_from_PIC16F1704_flash", crc);
        applog(0, tmp42, 0);
      }
      return 0;
    }
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      snprintf(
        tmp42,
        0x400u,
        "\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x\n\n",
        "read_data_from_PIC16F1704_flash",
        read_back_data[0],
        read_back_data[1],
        read_back_data[2]);
      applog(0, tmp42, 0);
    }
    return 0;
  }
}
