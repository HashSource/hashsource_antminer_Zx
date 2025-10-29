int __fastcall write_temperature_offset_PIC16F1704_new(unsigned __int8 *buf)
{
  unsigned __int8 *v1; // r1
  unsigned __int8 *v2; // r0
  unsigned __int8 *v3; // r2
  __int16 v4; // r3
  __int16 v5; // t1
  unsigned __int8 *v6; // r0
  unsigned __int8 v7; // t1
  unsigned __int8 *v8; // r4
  int v9; // t1
  __int64 v10; // r4
  int result; // r0
  const char *v12; // r2
  const char *v13; // r2
  char v14; // [sp+7h] [bp-1011h] BYREF
  unsigned __int8 send_data[14]; // [sp+8h] [bp-1010h] BYREF
  char tmp42[4096]; // [sp+18h] [bp-1000h] BYREF

  v1 = buf - 1;
  v2 = buf + 7;
  v3 = v1;
  v4 = 46;
  *(_DWORD *)&send_data[4] = 0;
  *(_DWORD *)&send_data[8] = 0;
  do
  {
    v5 = *++v3;
    v4 += v5;
  }
  while ( v2 != v3 );
  v6 = &send_data[4];
  *(_DWORD *)send_data = 571255381;
  do
  {
    v7 = *++v1;
    *v6++ = v7;
  }
  while ( v1 != v3 );
  send_data[12] = HIBYTE(v4);
  v8 = (unsigned __int8 *)&v14;
  send_data[13] = v4;
  pthread_mutex_lock(&i2c_mutex);
  do
  {
    v9 = *++v8;
    i2c_write(v9 | (i2c_slave_addr << 16) | 0xA00000);
  }
  while ( &send_data[13] != v8 );
  usleep(0x30D40u);
  LODWORD(v10) = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  HIDWORD(v10) = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  pthread_mutex_unlock(&i2c_mutex);
  usleep(0x30D40u);
  if ( v10 == 0x100000022LL )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      LOWORD(v13) = -30676;
      HIWORD(v13) = (unsigned int)"a[2] = 0x%02x, read_back_data[3] = 0x%02x\n" >> 16;
      snprintf(tmp42, 0x1000u, v13, "write_temperature_offset_PIC16F1704_new");
      applog(5, tmp42, 0);
      return 1;
    }
    else
    {
      return 1;
    }
  }
  else if ( use_syslog || (result = opt_log_output) != 0 || opt_log_level > 2 )
  {
    LOWORD(v12) = -28188;
    HIWORD(v12) = (unsigned int)"k_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x\n" >> 16;
    snprintf(
      tmp42,
      0x1000u,
      v12,
      "write_temperature_offset_PIC16F1704_new",
      v10,
      *(_DWORD *)send_data,
      *(_DWORD *)&send_data[4],
      *(_DWORD *)&send_data[8]);
    applog(3, tmp42, 0);
    return 0;
  }
  return result;
}
