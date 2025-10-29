int __fastcall write_hash_ID_PIC16F1704_new(unsigned __int8 *buf)
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
  int v10; // r4
  int v11; // r6
  bool v12; // zf
  int result; // r0
  char v14; // [sp+13h] [bp-1015h] BYREF
  unsigned __int8 send_data[18]; // [sp+14h] [bp-1014h] BYREF
  char tmp42[4096]; // [sp+28h] [bp-1000h] BYREF

  v1 = buf - 1;
  v2 = buf + 11;
  v3 = v1;
  v4 = 34;
  memset(&send_data[4], 0, 12);
  do
  {
    v5 = *++v3;
    v4 += v5;
  }
  while ( v2 != v3 );
  v6 = &send_data[3];
  *(_DWORD *)send_data = 303082069;
  do
  {
    v7 = *++v1;
    *++v6 = v7;
  }
  while ( v1 != v3 );
  send_data[16] = HIBYTE(v4);
  v8 = (unsigned __int8 *)&v14;
  send_data[17] = v4;
  pthread_mutex_lock(&i2c_mutex);
  do
  {
    v9 = *++v8;
    i2c_write(v9 | (i2c_slave_addr << 16) | 0xA00000);
  }
  while ( &send_data[17] != v8 );
  usleep(0x30D40u);
  v10 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  v11 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  pthread_mutex_unlock(&i2c_mutex);
  usleep(0x30D40u);
  v12 = v11 == 1;
  if ( v11 == 1 )
    v12 = v10 == 18;
  if ( v12 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      snprintf(tmp42, 0x1000u, "%s ok", "write_hash_ID_PIC16F1704_new");
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
    snprintf(
      tmp42,
      0x1000u,
      "%s chain %d failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
      "write_hash_ID_PIC16F1704_new",
      i2c_slave_addr,
      v10,
      v11);
    applog(3, tmp42, 0);
    return 0;
  }
  return result;
}
