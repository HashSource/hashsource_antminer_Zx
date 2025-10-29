int __cdecl set_PIC16F1704_flash_pointer(
        unsigned int which_i2c,
        unsigned __int8 which_chain,
        unsigned __int8 flash_addr_h,
        unsigned __int8 flash_addr_l)
{
  __int16 v4; // r2
  int v5; // r4
  unsigned __int8 which_i2ca; // [sp+Ch] [bp+4h]
  char tmp42[1024]; // [sp+14h] [bp+Ch] BYREF
  unsigned __int8 send_data[8]; // [sp+414h] [bp+40Ch]
  unsigned __int8 read_back_data[4]; // [sp+41Ch] [bp+414h]
  unsigned __int8 crc_data[4]; // [sp+420h] [bp+418h]
  unsigned __int16 crc; // [sp+424h] [bp+41Ch]
  unsigned __int8 length; // [sp+426h] [bp+41Eh]
  unsigned __int8 i; // [sp+427h] [bp+41Fh]
  _BYTE v18[4]; // [sp+428h] [bp+420h] BYREF

  which_i2ca = which_i2c;
  length = 6;
  *(_WORD *)read_back_data = 255;
  *(_DWORD *)send_data = 17214037;
  v4 = flash_addr_h + 6;
  crc = flash_addr_l + v4 + 1;
  crc_data[0] = HIBYTE(crc);
  crc_data[1] = flash_addr_l + v4 + 1;
  send_data[4] = flash_addr_h;
  send_data[5] = flash_addr_l;
  send_data[6] = HIBYTE(crc);
  send_data[7] = crc_data[1];
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 7u; ++i )
    write_pic(which_i2ca, which_chain, v18[i - 20]);
  usleep(0x186A0u);
  for ( i = 0; i <= 1u; ++i )
  {
    v5 = i;
    read_back_data[v5] = read_pic(which_i2ca, which_chain);
  }
  pthread_mutex_unlock(&i2c_mutex);
  if ( read_back_data[0] == 1 && read_back_data[1] == 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s ok\n\n", "set_PIC16F1704_flash_pointer");
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
        "set_PIC16F1704_flash_pointer",
        read_back_data[0],
        read_back_data[1]);
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
