int __fastcall write_data_to_PIC16F1704_flash(unsigned __int8 *buf, unsigned int offset, int buf_len)
{
  int v3; // r3
  __int16 v5; // r4
  __int16 v6; // r2
  size_t v7; // r2
  int v8; // r7
  unsigned __int8 *v9; // r5
  unsigned __int8 v10; // r4
  int v11; // r3
  unsigned __int8 *v12; // r4
  int result; // r0
  const char *v14; // r2
  const char *v15; // r2
  unsigned __int8 read_back_data[5]; // [sp+14h] [bp-1020h] BYREF
  char v17; // [sp+19h] [bp-101Bh] BYREF
  unsigned __int8 send_data[17]; // [sp+1Ch] [bp-1018h] BYREF
  char tmp42[4100]; // [sp+30h] [bp-1004h] BYREF

  v3 = 0;
  *(_DWORD *)&send_data[6] = 0;
  *(_DWORD *)read_back_data = 255;
  *(_DWORD *)&send_data[10] = 0;
  v5 = 2 * buf_len + 57;
  read_back_data[4] = 0;
  for ( *(_DWORD *)&send_data[13] = 0; v3 < buf_len; v5 += v6 )
  {
    v6 = buf[v3];
    v3 = (unsigned __int8)(v3 + 1);
  }
  send_data[4] = offset;
  send_data[2] = buf_len + 6;
  v7 = buf_len;
  send_data[5] = buf_len;
  v8 = buf_len + 8;
  send_data[3] = 51;
  v9 = &send_data[buf_len];
  *(_WORD *)send_data = -21931;
  memcpy(&send_data[6], buf, v7);
  v9[7] = v5;
  v9[6] = HIBYTE(v5);
  pthread_mutex_lock(&i2c_mutex);
  if ( v8 > 0 )
  {
    v10 = 0;
    v11 = 0;
    do
    {
      ++v10;
      i2c_write(send_data[v11] | (i2c_slave_addr << 16) | 0xA00000);
      v11 = v10;
    }
    while ( v10 < v8 );
  }
  v12 = read_back_data;
  usleep((__useconds_t)&loc_30D40);
  do
    *v12++ = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  while ( &v17 != (char *)v12 );
  pthread_mutex_unlock(&i2c_mutex);
  if ( read_back_data[0] == 5 && read_back_data[1] == 51 && (result = read_back_data[2], read_back_data[2] == 1) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v15) = -27212;
      HIWORD(v15) = (unsigned int)"d times" >> 16;
      snprintf(tmp42, 0x1000u, v15, "write_data_to_PIC16F1704_flash");
      applog(7, tmp42, 0);
      return 1;
    }
  }
  else if ( use_syslog || (result = opt_log_output) != 0 || opt_log_level > 2 )
  {
    LOWORD(v14) = -26956;
    HIWORD(v14) = (unsigned int)"_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n" >> 16;
    snprintf(
      tmp42,
      0x1000u,
      v14,
      "write_data_to_PIC16F1704_flash",
      read_back_data[0],
      read_back_data[1],
      read_back_data[2]);
    applog(3, tmp42, 0);
    return 0;
  }
  return result;
}
