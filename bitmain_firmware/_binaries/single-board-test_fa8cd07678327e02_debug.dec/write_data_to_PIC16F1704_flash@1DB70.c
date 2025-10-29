int __cdecl write_data_to_PIC16F1704_flash(int which_chain, int which_i2c, unsigned __int8 *buf, int buf_len)
{
  int v4; // r4
  unsigned __int8 which_i2ca; // [sp+18h] [bp+8h]
  unsigned __int8 which_chaina; // [sp+1Ch] [bp+Ch]
  char tmp42[1024]; // [sp+20h] [bp+10h] BYREF
  unsigned __int8 send_data[12]; // [sp+420h] [bp+410h] BYREF
  unsigned __int8 read_back_data[8]; // [sp+42Ch] [bp+41Ch]
  unsigned __int8 crc_data[4]; // [sp+434h] [bp+424h]
  int send_len; // [sp+438h] [bp+428h]
  unsigned __int8 length; // [sp+43Ch] [bp+42Ch]
  unsigned __int8 i; // [sp+43Dh] [bp+42Dh]
  unsigned __int16 crc; // [sp+43Eh] [bp+42Eh]
  _BYTE v19[4]; // [sp+440h] [bp+430h] BYREF

  which_chaina = which_chain;
  which_i2ca = which_i2c;
  length = 6;
  *(_WORD *)crc_data = 255;
  *(_DWORD *)read_back_data = 255;
  read_back_data[4] = 0;
  crc = 0;
  memset(send_data, 0, sizeof(send_data));
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 3) )
  {
    snprintf(tmp42, 0x400u, "\n--- %s\n", "write_data_to_PIC16F1704_flash");
    applog(4, tmp42, 0);
  }
  crc = buf_len + buf_len + length + 51;
  for ( i = 0; i < buf_len; ++i )
    crc += buf[i];
  crc_data[0] = HIBYTE(crc);
  crc_data[1] = crc;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(
      tmp42,
      0x400u,
      "--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n",
      "write_data_to_PIC16F1704_flash",
      crc_data[0],
      crc_data[1]);
    applog(2, tmp42, 0);
  }
  send_data[0] = 85;
  send_data[1] = -86;
  send_data[2] = length + buf_len;
  strcpy((char *)&send_data[3], "3");
  send_data[5] = buf_len;
  memcpy(&send_data[6], buf, buf_len);
  v19[buf_len - 26] = crc_data[0];
  v19[buf_len - 25] = crc_data[1];
  for ( i = 0; i < buf_len + 8; ++i )
    printf("%02x ", (unsigned __int8)v19[i - 32]);
  putchar(10);
  send_len = buf_len + length + 2;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i < send_len; ++i )
    write_pic(which_i2ca, which_chaina, v19[i - 32]);
  usleep(0x30D40u);
  for ( i = 0; i <= 4u; ++i )
  {
    v4 = i;
    read_back_data[v4] = read_pic(which_i2ca, which_chaina);
  }
  pthread_mutex_unlock(&i2c_mutex);
  usleep(0x30D40u);
  for ( i = 0; i <= 4u; ++i )
    printf("%02x ", (unsigned __int8)v19[i - 20]);
  putchar(10);
  if ( read_back_data[0] == 5 && read_back_data[1] == 51 && read_back_data[2] == 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "\n--- %s ok\n\n", "write_data_to_PIC16F1704_flash");
      applog(2, tmp42, 0);
    }
    return 1;
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      snprintf(
        tmp42,
        0x400u,
        "\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x\n\n",
        "write_data_to_PIC16F1704_flash",
        read_back_data[0],
        read_back_data[1],
        read_back_data[2]);
      applog(0, tmp42, 0);
    }
    return 0;
  }
}
