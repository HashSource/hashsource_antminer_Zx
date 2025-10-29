int __cdecl read_PIC16F1704_flash_pointer(
        unsigned int which_i2c,
        unsigned __int8 which_chain,
        unsigned __int8 *flash_addr_h,
        unsigned __int8 *flash_addr_l)
{
  int v4; // r4
  unsigned __int8 which_i2ca; // [sp+24h] [bp+Ch]
  char tmp42[1024]; // [sp+28h] [bp+10h] BYREF
  unsigned __int8 send_data[6]; // [sp+428h] [bp+410h]
  unsigned __int8 read_back_data[8]; // [sp+430h] [bp+418h]
  unsigned __int8 crc_data[4]; // [sp+438h] [bp+420h]
  unsigned __int16 crc; // [sp+43Ch] [bp+424h]
  unsigned __int8 length; // [sp+43Eh] [bp+426h]
  unsigned __int8 i; // [sp+43Fh] [bp+427h]
  _BYTE v18[4]; // [sp+440h] [bp+428h] BYREF

  which_i2ca = which_i2c;
  length = 4;
  crc_data[0] = 0;
  *(_DWORD *)read_back_data = 255;
  *(_WORD *)&read_back_data[4] = 0;
  *(_DWORD *)send_data = 134523477;
  crc = 12;
  crc_data[1] = 12;
  send_data[4] = 0;
  send_data[5] = 12;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 5u; ++i )
    write_pic(which_i2ca, which_chain, v18[i - 24]);
  usleep(0x186A0u);
  for ( i = 0; i <= 5u; ++i )
  {
    v4 = i;
    read_back_data[v4] = read_pic(which_i2ca, which_chain);
  }
  pthread_mutex_unlock(&i2c_mutex);
  if ( read_back_data[1] == 8 && read_back_data[0] == 6 )
  {
    crc = read_back_data[3] + read_back_data[2] + read_back_data[1] + read_back_data[0];
    if ( HIBYTE(crc) == read_back_data[4] && (unsigned __int8)crc == read_back_data[5] )
    {
      *flash_addr_h = read_back_data[2];
      *flash_addr_l = read_back_data[3];
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(
          tmp42,
          0x400u,
          "--- %s ok! flash_addr_h = 0x%02x, flash_addr_l = 0x%02x\n\n",
          "read_PIC16F1704_flash_pointer",
          *flash_addr_h,
          *flash_addr_l);
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
          "--- %s failed! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3]"
          " = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n"
          "\n",
          "read_PIC16F1704_flash_pointer",
          read_back_data[0],
          read_back_data[1],
          read_back_data[2],
          read_back_data[3],
          read_back_data[4],
          read_back_data[5]);
        applog(2, tmp42, 0);
      }
      return 0;
    }
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(
        tmp42,
        0x400u,
        "--- %s failed! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] ="
        " 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n"
        "\n",
        "read_PIC16F1704_flash_pointer",
        read_back_data[0],
        read_back_data[1],
        read_back_data[2],
        read_back_data[3],
        read_back_data[4],
        read_back_data[5]);
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
