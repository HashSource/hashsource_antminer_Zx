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
  const char *v15; // r3
  const char *v16; // r7
  uint8_t *v17; // r10
  int v18; // r6
  int v19; // r3
  int v20; // r4
  int v21; // t1
  const char *v22; // r10
  uint8_t *v23; // r7
  int v24; // r6
  int v25; // r0
  _BOOL4 v26; // r5
  int v27; // r3
  uint8_t *v28; // r2
  __int16 v29; // t1
  const char *v31; // r2
  const char *v32; // r2
  int v33; // [sp+Ch] [bp-1050h]
  int v35; // [sp+18h] [bp-1044h]
  int v36; // [sp+1Ch] [bp-1040h]
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
    v36 = 7;
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
    send_data[v36] = BYTE1(v13);
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
  v36 = len + 6;
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
  LOWORD(v15) = -29588;
  HIWORD(v15) = (unsigned int)" %d failed!" >> 16;
  v16 = v15;
  v17 = send_data;
  v18 = 0;
  v33 = v8 + 1;
  do
  {
    v19 = v18++;
    v21 = *v17++;
    v20 = v21;
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      snprintf(tmp42, 0x1000u, v16, v19, v20);
      applog(5, tmp42, 0);
    }
    i2c_write(v20 | (i2c_slave_addr << 16) | 0xA00000);
  }
  while ( v18 != v33 );
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
    LOWORD(v22) = -29564;
    v23 = recv_data;
    v24 = 0;
    v35 = v13;
    do
    {
      v25 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
      v26 = use_syslog;
      v27 = v24++;
      *v23++ = v25;
      if ( v26 || opt_log_output || opt_log_level > 4 )
      {
        HIWORD(v22) = (unsigned int)"rc = 0x%04x\n\n" >> 16;
        snprintf(tmp42, 0x1000u, v22, v27, v25);
        applog(5, tmp42, 0);
      }
    }
    while ( v24 != len + 5 );
    v13 = v35;
  }
  if ( len >= -2 )
  {
    v28 = recv_data;
    do
    {
      v29 = *v28++;
      v13 = (unsigned __int16)(v13 + v29);
    }
    while ( v28 != &recv_data[len + 3] );
  }
  if ( *(unsigned __int16 *)&recv_data[len + 3] == v13 )
  {
    if ( recv_data[0] == v36 && recv_data[1] == 38 && recv_data[2] == 1 )
    {
      memcpy(data, &recv_data[3], len);
      goto LABEL_30;
    }
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      LOWORD(v31) = -29520;
      HIWORD(v31) = (unsigned int)"read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x" >> 16;
      snprintf(tmp42, 0x1000u, v31, *data, data[1], data[2]);
      applog(5, tmp42, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v32) = -29540;
    HIWORD(v32) = (unsigned int)"%s chain %d failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x" >> 16;
    snprintf(tmp42, 0x1000u, v32, v13);
    applog(5, tmp42, 0);
  }
  pthread_mutex_unlock(&i2c_mutex);
  return -1;
}
