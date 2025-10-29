int __cdecl write_data_into_PIC16F1704_flash(unsigned int which_i2c, unsigned __int8 which_chain)
{
  int v2; // r4
  unsigned __int8 which_i2ca; // [sp+Ch] [bp+4h]
  char tmp42[1024]; // [sp+14h] [bp+Ch] BYREF
  unsigned __int8 send_data[6]; // [sp+414h] [bp+40Ch]
  unsigned __int8 read_back_data[4]; // [sp+41Ch] [bp+414h]
  unsigned __int8 crc_data[4]; // [sp+420h] [bp+418h]
  unsigned __int16 crc; // [sp+424h] [bp+41Ch]
  unsigned __int8 length; // [sp+426h] [bp+41Eh]
  unsigned __int8 i; // [sp+427h] [bp+41Fh]
  _BYTE v14[4]; // [sp+428h] [bp+420h] BYREF

  which_i2ca = which_i2c;
  length = 4;
  crc_data[0] = 0;
  *(_WORD *)read_back_data = 255;
  *(_DWORD *)send_data = 84191829;
  crc = 9;
  crc_data[1] = 9;
  send_data[4] = 0;
  send_data[5] = 9;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 5u; ++i )
    write_pic(which_i2ca, which_chain, v14[i - 20]);
  usleep(0x30D40u);
  for ( i = 0; i <= 1u; ++i )
  {
    v2 = i;
    read_back_data[v2] = read_pic(which_i2ca, which_chain);
  }
  pthread_mutex_unlock(&i2c_mutex);
  usleep(0x30D40u);
  if ( read_back_data[0] == 5 && read_back_data[1] == 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s ok\n\n", "write_data_into_PIC16F1704_flash");
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
        "write_data_into_PIC16F1704_flash",
        read_back_data[0],
        read_back_data[1]);
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
