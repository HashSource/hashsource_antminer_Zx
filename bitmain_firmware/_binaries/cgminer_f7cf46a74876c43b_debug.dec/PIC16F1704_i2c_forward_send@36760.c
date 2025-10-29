int __fastcall PIC16F1704_i2c_forward_send(uint8_t dev_addr, int rw_flag, uint8_t reg_addr, int len, uint8_t *data)
{
  uint8_t v7; // r4
  int v8; // r4
  __int16 v9; // r3
  int v10; // r6
  int v11; // r2
  uint8_t *v12; // r1
  int v13; // r5
  __int16 v14; // t1
  uint8_t *v15; // r10
  int v16; // r6
  int v17; // r3
  int v18; // r4
  int v19; // t1
  uint8_t *v20; // r7
  int v21; // r6
  int v22; // r0
  _BOOL4 v23; // r5
  int v24; // r3
  uint8_t *v25; // r2
  __int16 v26; // t1
  int v28; // [sp+Ch] [bp-1050h]
  int v30; // [sp+18h] [bp-1044h]
  int v31; // [sp+1Ch] [bp-1040h]
  uint8_t recv_data[12]; // [sp+2Ch] [bp-1030h] BYREF
  uint8_t send_data[32]; // [sp+38h] [bp-1024h] BYREF
  char tmp42[4100]; // [sp+58h] [bp-1004h] BYREF

  v7 = rw_flag | (2 * dev_addr);
  memset(&send_data[2], 0, 0x1Eu);
  send_data[5] = reg_addr;
  send_data[4] = v7;
  *(_WORD *)send_data = -21931;
  send_data[3] = 38;
  memset(recv_data, 0, sizeof(recv_data));
  if ( rw_flag )
  {
    v8 = 8;
    v9 = 7;
    v10 = 5;
    v31 = 7;
    send_data[6] = len;
    send_data[2] = 7;
LABEL_3:
    v11 = 0;
    v12 = &send_data[2];
    LOWORD(v13) = 0;
    while ( 1 )
    {
      ++v11;
      v13 = (unsigned __int16)(v13 + v9);
      if ( v10 <= v11 )
        break;
      v14 = *++v12;
      v9 = v14;
    }
    send_data[v31] = BYTE1(v13);
    send_data[v8] = v13;
    pthread_mutex_lock(&i2c_mutex);
    if ( v8 < 0 )
      goto LABEL_13;
    goto LABEL_7;
  }
  v10 = len + 4;
  memcpy(&send_data[6], data, len);
  v9 = (unsigned __int8)(len + 6);
  v8 = len + 7;
  v31 = len + 6;
  send_data[2] = len + 6;
  if ( len + 4 > 0 )
    goto LABEL_3;
  send_data[len + 6] = rw_flag;
  send_data[v8] = rw_flag;
  pthread_mutex_lock(&i2c_mutex);
  if ( v8 < 0 )
  {
    usleep(0x30D40u);
    goto LABEL_30;
  }
  v13 = rw_flag;
LABEL_7:
  v15 = send_data;
  v16 = 0;
  v28 = v8 + 1;
  do
  {
    v17 = v16++;
    v19 = *v15++;
    v18 = v19;
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      snprintf(tmp42, 0x1000u, "write pic i2c[%d] %02x\n", v17, v18);
      applog(5, tmp42, 0);
    }
    i2c_write(v18 | (i2c_slave_addr << 16) | 0xA00000);
  }
  while ( v16 != v28 );
LABEL_13:
  usleep(0x30D40u);
  if ( rw_flag != 1 )
  {
LABEL_30:
    pthread_mutex_unlock(&i2c_mutex);
    return 0;
  }
  if ( len >= -4 )
  {
    v20 = recv_data;
    v21 = 0;
    v30 = v13;
    do
    {
      v22 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
      v23 = use_syslog;
      v24 = v21++;
      *v20++ = v22;
      if ( v23 || opt_log_output || opt_log_level > 4 )
      {
        snprintf(tmp42, 0x1000u, "read pic i2c[%d] %02x\n", v24, v22);
        applog(5, tmp42, 0);
      }
    }
    while ( v21 != len + 5 );
    v13 = v30;
  }
  if ( len >= -2 )
  {
    v25 = recv_data;
    do
    {
      v26 = *v25++;
      v13 = (unsigned __int16)(v13 + v26);
    }
    while ( v25 != &recv_data[len + 3] );
  }
  if ( *(unsigned __int16 *)&recv_data[len + 3] == v13 )
  {
    if ( recv_data[0] == v31 && recv_data[1] == 38 && recv_data[2] == 1 )
    {
      memcpy(data, &recv_data[3], len);
      goto LABEL_30;
    }
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      snprintf(tmp42, 0x1000u, "pic read failed %d %d %d\n", *data, data[1], data[2]);
      applog(5, tmp42, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "crc failed 0x%x\n", v13);
    applog(5, tmp42, 0);
  }
  pthread_mutex_unlock(&i2c_mutex);
  return -1;
}
