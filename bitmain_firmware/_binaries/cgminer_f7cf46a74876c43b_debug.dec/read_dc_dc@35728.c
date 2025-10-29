// local variable allocation has failed, the output may be wrong!
int __fastcall read_dc_dc(uint8_t i2c_dev_addr, uint8_t reg, uint8_t *value, int len)
{
  int v4; // r10
  char v5; // r4
  __int16 v7; // r0
  __int16 v9; // r3
  int *v10; // r4
  int i; // r3
  int v12; // t1
  int v13; // r4
  int v15; // r3
  int v16; // r2
  int v17; // [sp+14h] [bp-101Ch] BYREF
  char v18; // [sp+18h] [bp-1018h]
  uint8_t rega; // [sp+19h] [bp-1017h]
  char v20; // [sp+1Ah] [bp-1016h]
  char v21; // [sp+1Bh] [bp-1015h]
  char v22; // [sp+1Ch] [bp-1014h] BYREF
  uint8_t read_back_data[16]; // [sp+20h] [bp-1010h] BYREF
  char tmp42[4096]; // [sp+30h] [bp-1000h] BYREF

  v5 = len;
  v7 = (unsigned __int8)(2 * i2c_dev_addr) | 1;
  rega = reg;
  v9 = v7 + 57 + reg + (unsigned __int8)len;
  v18 = v7;
  v22 = v9;
  v20 = v5;
  v21 = HIBYTE(v9);
  v10 = &v17;
  v17 = 839363157;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 85; ; i = v12 )
  {
    i2c_write(i | 0xA00000 | (i2c_slave_addr << 16));
    if ( v10 == (int *)&v22 )
      break;
    v12 = *((unsigned __int8 *)v10 + 1);
    v10 = (int *)((char *)v10 + 1);
  }
  v13 = 0;
  cgsleep_ms(200);
  *(_DWORD *)&read_back_data[4] = 0;
  if ( len + 4 >= 0 )
    v4 = 0;
  *(_DWORD *)read_back_data = 0;
  *(_DWORD *)&read_back_data[8] = 0;
  *(_DWORD *)&read_back_data[12] = 0;
  if ( len + 4 < 0 )
  {
    pthread_mutex_unlock(&i2c_mutex);
LABEL_9:
    if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
      return -1;
    snprintf(
      tmp42,
      0x1000u,
      "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x, read_back_data[3] = 0x%02x\n",
      "read_dc_dc",
      read_back_data[0],
      v13,
      read_back_data[2],
      read_back_data[3]);
    applog(5, tmp42, 0);
    return -1;
  }
  do
  {
    v13 = (unsigned __int8)(v13 + 1);
    read_back_data[v4] = i2c_read((i2c_slave_addr << 16) | 0xA00000);
    v4 = v13;
  }
  while ( v13 <= len + 4 );
  v13 = read_back_data[1];
  pthread_mutex_unlock(&i2c_mutex);
  if ( v13 != 50 || read_back_data[2] != 1 )
    goto LABEL_9;
  if ( len > 0 )
  {
    v15 = 0;
    v16 = 0;
    do
    {
      value[v15] = read_back_data[v16 + 3];
      v15 = (unsigned __int8)(v15 + 1);
      v16 = v15;
    }
    while ( v15 < len );
  }
  return 0;
}
