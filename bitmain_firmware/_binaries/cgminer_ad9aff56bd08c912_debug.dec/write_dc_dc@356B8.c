int __fastcall write_dc_dc(uint8_t i2c_dev_addr, uint8_t reg, uint8_t *data, int len)
{
  int v4; // r1
  int v5; // r6
  int v6; // r0
  uint8_t v7; // r4
  uint8_t *v8; // r1
  unsigned int v9; // r2
  __int16 v10; // t1
  unsigned int v11; // r1
  unsigned __int8 v12; // r4
  int v13; // r6
  int v14; // r3
  uint8_t *v15; // r4
  const char *v17; // r2
  uint8_t read_back_data[16]; // [sp+10h] [bp-1024h] BYREF
  uint8_t send_data[16]; // [sp+20h] [bp-1014h] BYREF
  char tmp42[4100]; // [sp+30h] [bp-1004h] BYREF

  send_data[5] = reg;
  v4 = 0;
  v5 = len + 6;
  *(_WORD *)send_data = -21931;
  send_data[4] = 2 * i2c_dev_addr;
  send_data[3] = 50;
  send_data[2] = len + 6;
  *(_DWORD *)read_back_data = 255;
  memset(&read_back_data[4], 0, 12);
  memset(&send_data[6], 0, 10);
  if ( len > 0 )
  {
    v6 = 0;
    do
    {
      v7 = data[v4];
      v4 = (unsigned __int8)(v4 + 1);
      send_data[v6 + 6] = v7;
      v6 = v4;
    }
    while ( v4 < len );
  }
  if ( len < -3 )
  {
    LOBYTE(v9) = 0;
    LOBYTE(v11) = 0;
  }
  else
  {
    v8 = &send_data[1];
    LOWORD(v9) = 0;
    do
    {
      v10 = *++v8;
      v9 = (unsigned __int16)(v9 + v10);
    }
    while ( &send_data[len + 5] != v8 );
    v11 = v9 >> 8;
  }
  send_data[v5] = v11;
  v12 = 0;
  send_data[len + 7] = v9;
  pthread_mutex_lock(&i2c_mutex);
  v13 = (unsigned __int8)v5 + 1;
  v14 = 0;
  do
  {
    ++v12;
    i2c_write(send_data[v14] | (i2c_slave_addr << 16) | 0xA00000);
    v14 = v12;
  }
  while ( v12 <= v13 );
  v15 = read_back_data;
  usleep((__useconds_t)&loc_30D40);
  memset(read_back_data, 0, sizeof(read_back_data));
  do
    *v15++ = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  while ( &read_back_data[5] != v15 );
  pthread_mutex_unlock(&i2c_mutex);
  if ( read_back_data[1] == 50 && read_back_data[2] == 1 )
    return 0;
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
    return -1;
  LOWORD(v17) = -31012;
  HIWORD(v17) = (unsigned int)"uart%d always busy, break\n" >> 16;
  snprintf(
    tmp42,
    0x1000u,
    v17,
    "write_dc_dc",
    read_back_data[0],
    read_back_data[1],
    read_back_data[2],
    read_back_data[3]);
  applog(5, tmp42, 0);
  return -1;
}
