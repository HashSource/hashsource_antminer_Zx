int __fastcall read_data_from_PIC16F1704_flash(unsigned __int8 *buf, unsigned __int8 offset, unsigned __int8 read_len)
{
  size_t v4; // r7
  unsigned __int8 *v6; // r4
  int i; // r3
  int v8; // t1
  signed int v9; // r4
  signed int v10; // r9
  signed int v11; // r10
  int v12; // r4
  int result; // r0
  __int16 v14; // r3
  signed int v15; // r2
  unsigned int v16; // r1
  const char *v17; // r2
  const char *v18; // r2
  unsigned __int8 send_data[8]; // [sp+8h] [bp-1030h] BYREF
  unsigned __int8 read_back_data[40]; // [sp+10h] [bp-1028h] BYREF
  char tmp42[4096]; // [sp+38h] [bp-1000h] BYREF

  v4 = read_len;
  memset(read_back_data, 0, sizeof(read_back_data));
  send_data[4] = offset;
  send_data[6] = (unsigned __int16)(v4 + 58) >> 8;
  v6 = &send_data[1];
  *(_DWORD *)send_data = 872852053;
  send_data[5] = v4;
  send_data[7] = v4 + 58;
  read_back_data[0] = -1;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 85; ; i = v8 )
  {
    i2c_write(i | 0xA00000 | (i2c_slave_addr << 16));
    if ( read_back_data == v6 )
      break;
    v8 = *v6++;
  }
  LOBYTE(v9) = 0;
  v10 = 0;
  v11 = v4 + 4;
  usleep((__useconds_t)&loc_30D40);
  do
  {
    v9 = (unsigned __int8)(v9 + 1);
    read_back_data[v10] = i2c_read((i2c_slave_addr << 16) | 0xA00000);
    v10 = v9;
  }
  while ( v9 <= v11 );
  v12 = read_back_data[1];
  pthread_mutex_unlock(&i2c_mutex);
  if ( v12 != 52 )
    return 0;
  v14 = read_back_data[0];
  if ( read_back_data[0] != v4 + 5 || read_back_data[2] != 1 )
    return 0;
  LOBYTE(v15) = 0;
  LOWORD(v16) = 0;
  while ( 1 )
  {
    v15 = (unsigned __int8)(v15 + 1);
    v16 = (unsigned __int16)(v14 + v16);
    if ( (int)(v4 + 2) < v15 )
      break;
    v14 = read_back_data[v15];
  }
  if ( read_back_data[v4 + 3] == v16 >> 8 && read_back_data[v11] == (unsigned __int8)v16 )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v18) = -27212;
      HIWORD(v18) = (unsigned int)"d times" >> 16;
      snprintf(tmp42, 0x1000u, v18, "read_data_from_PIC16F1704_flash");
      applog(7, tmp42, 0);
    }
    memcpy(buf, &read_back_data[3], v4);
    return 1;
  }
  else if ( use_syslog || (result = opt_log_output) != 0 || opt_log_level > 2 )
  {
    LOWORD(v17) = -27012;
    HIWORD(v17) = (unsigned int)"read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n" >> 16;
    snprintf(tmp42, 0x1000u, v17, "read_data_from_PIC16F1704_flash", v16);
    applog(3, tmp42, 0);
    return 0;
  }
  return result;
}
