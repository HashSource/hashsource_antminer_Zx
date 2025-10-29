int __fastcall read_PIC16F1704_flash_pointer_new(unsigned __int8 *flash_addr_h, unsigned __int8 *flash_addr_l)
{
  unsigned __int8 *v4; // r4
  int i; // r3
  int v6; // t1
  unsigned __int8 *v7; // r4
  int result; // r0
  int v9; // r1
  unsigned int v10; // r3
  unsigned __int8 read_back_data[6]; // [sp+20h] [bp-1010h] BYREF
  char v12; // [sp+26h] [bp-100Ah] BYREF
  unsigned __int8 send_data[6]; // [sp+28h] [bp-1008h] BYREF
  char tmp42[4096]; // [sp+30h] [bp-1000h] BYREF

  send_data[4] = 0;
  send_data[5] = 12;
  *(_DWORD *)read_back_data = 255;
  *(_WORD *)&read_back_data[4] = 0;
  v4 = send_data;
  *(_DWORD *)send_data = 134523477;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 85; ; i = v6 )
  {
    i2c_write(i | 0xA00000 | (i2c_slave_addr << 16));
    if ( &send_data[5] == v4 )
      break;
    v6 = *++v4;
  }
  v7 = read_back_data;
  usleep((__useconds_t)&loc_1869E + 2);
  do
    *v7++ = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  while ( &v12 != (char *)v7 );
  pthread_mutex_unlock(&i2c_mutex);
  if ( read_back_data[1] != 8 || read_back_data[0] != 6 )
  {
    if ( !use_syslog )
    {
      result = opt_log_output;
      if ( !opt_log_output && opt_log_level <= 2 )
        return result;
    }
    snprintf(
      tmp42,
      0x1000u,
      "%s chain %d failed! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3"
      "] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n"
      "\n",
      "read_PIC16F1704_flash_pointer_new",
      i2c_slave_addr,
      read_back_data[0],
      read_back_data[1],
      read_back_data[2],
      read_back_data[3],
      read_back_data[4],
      read_back_data[5]);
    goto LABEL_11;
  }
  v9 = read_back_data[3];
  v10 = read_back_data[2] + read_back_data[3] + 14;
  if ( read_back_data[4] != v10 >> 8 || read_back_data[5] != (unsigned __int8)v10 )
  {
    if ( !use_syslog )
    {
      result = opt_log_output;
      if ( !opt_log_output && opt_log_level <= 2 )
        return result;
    }
    snprintf(
      tmp42,
      0x1000u,
      "%s failed!!! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%"
      "x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n"
      "\n",
      "read_PIC16F1704_flash_pointer_new",
      6,
      8,
      read_back_data[2],
      read_back_data[3],
      read_back_data[4],
      read_back_data[5]);
LABEL_11:
    applog(3, tmp42, 0);
    return 0;
  }
  *flash_addr_h = read_back_data[2];
  *flash_addr_l = v9;
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
    return 1;
  snprintf(
    tmp42,
    0x1000u,
    "%s ok! flash_addr_h = 0x%02x, flash_addr_l = 0x%02x",
    "read_PIC16F1704_flash_pointer_new",
    *flash_addr_h,
    v9);
  applog(5, tmp42, 0);
  return 1;
}
