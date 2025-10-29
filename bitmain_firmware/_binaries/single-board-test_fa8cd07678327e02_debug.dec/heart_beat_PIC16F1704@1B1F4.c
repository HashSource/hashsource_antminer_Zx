int __cdecl heart_beat_PIC16F1704(unsigned int which_chain, unsigned __int8 which_i2c)
{
  int v2; // r4
  unsigned __int8 which_chaina; // [sp+4h] [bp+4h]
  char tmp42[1024]; // [sp+8h] [bp+8h] BYREF
  unsigned __int8 send_data[6]; // [sp+408h] [bp+408h]
  unsigned __int8 read_back_data[6]; // [sp+410h] [bp+410h]
  unsigned __int8 crc_data[4]; // [sp+418h] [bp+418h]
  unsigned __int16 crc; // [sp+41Ch] [bp+41Ch]
  unsigned __int8 length; // [sp+41Eh] [bp+41Eh]
  unsigned __int8 i; // [sp+41Fh] [bp+41Fh]
  _BYTE v14[4]; // [sp+420h] [bp+420h] BYREF

  which_chaina = which_chain;
  length = 4;
  crc_data[0] = 0;
  *(_DWORD *)read_back_data = 255;
  *(_WORD *)&read_back_data[4] = 0;
  *(_DWORD *)send_data = 369404501;
  crc = 26;
  crc_data[1] = 26;
  send_data[4] = 0;
  send_data[5] = 26;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i <= 5u; ++i )
    write_pic(which_i2c, which_chaina, v14[i - 24]);
  usleep(0x186A0u);
  for ( i = 0; i <= 5u; ++i )
  {
    v2 = i;
    read_back_data[v2] = read_pic(which_i2c, which_chaina);
  }
  pthread_mutex_unlock(&i2c_mutex);
  if ( read_back_data[1] == 22 && read_back_data[2] == 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s ok\n\n", "heart_beat_PIC16F1704");
      applog(2, tmp42, 0);
    }
    return 1;
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "--- %s failed!\n\n", "heart_beat_PIC16F1704");
      applog(2, tmp42, 0);
    }
    return 0;
  }
}
