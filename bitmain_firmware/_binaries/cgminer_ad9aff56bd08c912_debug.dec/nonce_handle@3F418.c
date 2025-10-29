int __fastcall nonce_handle(
        nonce_rb_format (*g_nonce)[1],
        uint8_t (*g_nonce_list)[1][16][91],
        uint8_t *str,
        int len,
        uint32_t chainid)
{
  unsigned __int8 v6; // r0
  int v7; // r4
  int v8; // r8
  const char *v10; // r2
  uint8_t *v11; // r6
  int v12; // r7
  int v13; // r7
  unsigned __int8 *v14; // r0
  int v15; // r12
  unsigned __int8 *v16; // r1
  unsigned int v17; // r2
  int v18; // t1
  int v19; // r0
  const char *v20; // r2
  const char *v21; // r2
  uint8_t *v22; // r0
  uint8_t *v23; // r1
  int v24; // r3
  uint8_t v25; // r2
  const char *v26; // r2
  uint8_t *v27; // r2
  int v28; // r7
  const char *v29; // r2
  uint8_t *v30; // r1
  int v31; // r7
  int v32; // r3
  int v33; // r7
  char *v34; // r7
  nonce_rb_format *v35; // r4
  nonce_rb_format *v36; // r5
  nonce_rb_format *v37; // r0
  uint32_t p_wr; // r3
  char *v39; // r2
  const char *v40; // r2
  const char *v41; // r2
  const char *v42; // r2
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  v6 = str[3] / dev.addrInterval;
  v7 = v6;
  if ( v6 <= 2u )
  {
    v11 = (*g_nonce_list)[v6][0];
    v12 = str[2] & 0xF;
    memcpy(&v11[91 * v12], str + 2, 0x5Bu);
    if ( v12 != 15 )
      return 1;
    LOWORD(v13) = 28216;
    v14 = v11 + 89;
    v15 = 0;
    while ( 1 )
    {
      v16 = v14 - 89;
      v17 = 0xFFFF;
      do
      {
        v18 = *v16++;
        HIWORD(v13) = (unsigned int)"s %s():%d" >> 16;
        v17 = (unsigned __int16)(*(_WORD *)(v13 + 2 * (v18 ^ (v17 >> 8)) + 100) ^ ((_WORD)v17 << 8));
      }
      while ( v16 != v14 );
      v19 = (unsigned __int16)(((_WORD)v17 << 8) | (v17 >> 8));
      if ( __PAIR64__((unsigned __int8)((unsigned __int16)(((_WORD)v17 << 8) | (v17 >> 8)) >> 8), BYTE1(v17)) != __PAIR64__(v16[1], *v16) )
        break;
      ++v15;
      v14 = v16 + 91;
      v8 = 0;
      if ( v15 == 16 )
      {
        v22 = v11;
        v23 = v11;
        v24 = 0;
        while ( 1 )
        {
          v25 = *v23;
          v23 += 91;
          if ( (v25 & 0xF) != v24 )
            break;
          if ( ++v24 == 16 )
          {
            v27 = v11;
            while ( 1 )
            {
              v28 = v27[92];
              v27 += 91;
              if ( v28 != v11[1] )
                break;
              if ( v11 + 1365 == v27 )
              {
                v30 = v11;
                while ( 1 )
                {
                  v31 = v30[93];
                  v30 += 91;
                  if ( v31 != v11[2] )
                    break;
                  if ( v27 == v30 )
                  {
                    v32 = v11[3];
                    while ( 1 )
                    {
                      v33 = v22[94];
                      v22 += 91;
                      if ( v33 != v32 )
                        break;
                      if ( v30 == v22 )
                      {
                        v34 = (char *)(v11 + 4);
                        v35 = &(*g_nonce)[v7];
                        v36 = v35;
                        do
                        {
                          v37 = v36;
                          v36 = (nonce_rb_format *)((char *)v36 + 85);
                          memcpy(v37, v34, 0x55u);
                          v34 += 91;
                        }
                        while ( v36 != (nonce_rb_format *)&v35->Nonce[1275] );
                        memcpy(v36, v11 + 1369, 0x45u);
                        *(_DWORD *)v35->chip_nonce = *(_DWORD *)(v11 + 1450);
                        v35->chip_addr = v11[1366];
                        v35->work_id = v11[1367];
                        v35->nonce_id = v11[1368];
                        v35->diff0 = v11[1441];
                        *(_DWORD *)v35->sha256 = *(_DWORD *)(v11 + 1442);
                        pthread_mutex_lock(&nonce_mutex);
                        p_wr = nonce_fifo.p_wr;
                        v39 = (char *)&nonce_fifo + 1357 * nonce_fifo.p_wr;
                        v39[1368] = chainid;
                        v39[1356] = v35->chip_addr;
                        v39[1357] = v35->work_id & 0x7F;
                        v39[1358] = v35->nonce_id;
                        v39[1359] = v35->diff0;
                        *(_DWORD *)nonce_fifo.nonce_buffer[p_wr].sha256 = *(_DWORD *)v35->sha256;
                        *(_DWORD *)nonce_fifo.nonce_buffer[p_wr].chip_nonce = *(_DWORD *)v35->chip_nonce;
                        memcpy(&nonce_fifo.nonce_buffer[p_wr], v35, 0x540u);
                        if ( nonce_fifo.p_wr > 0x62 )
                          nonce_fifo.p_wr = 0;
                        else
                          ++nonce_fifo.p_wr;
                        if ( nonce_fifo.nonce_num > 0x63 )
                        {
                          nonce_fifo.nonce_num = 100;
                          if ( use_syslog || opt_log_output || opt_log_level > 3 )
                          {
                            LOWORD(v40) = -22452;
                            HIWORD(v40) = (unsigned int)"ipid=%d\n" >> 16;
                            snprintf(tmp42, 0x1000u, v40, "nonce_handle");
                            applog(4, tmp42, 0);
                          }
                        }
                        else
                        {
                          ++nonce_fifo.nonce_num;
                        }
                        pthread_mutex_unlock(&nonce_mutex);
                        return v8;
                      }
                    }
                    if ( use_syslog || opt_log_output || opt_log_level > 2 )
                    {
                      LOWORD(v42) = -22536;
                      HIWORD(v42) = (unsigned int)"!= %02x\n" >> 16;
                      snprintf(tmp42, 0x1000u, v42, v32, v33, v7);
                      goto LABEL_17;
                    }
                    goto LABEL_19;
                  }
                }
                if ( use_syslog || opt_log_output || opt_log_level > 2 )
                {
                  LOWORD(v41) = -22572;
                  HIWORD(v41) = (unsigned int)"=%d\n" >> 16;
                  snprintf(tmp42, 0x1000u, v41);
                  goto LABEL_17;
                }
                goto LABEL_19;
              }
            }
            if ( use_syslog || opt_log_output || opt_log_level > 2 )
            {
              LOWORD(v29) = -22612;
              HIWORD(v29) = (unsigned int)"rc=%02x%02x\n" >> 16;
              snprintf(tmp42, 0x1000u, v29);
              goto LABEL_17;
            }
            goto LABEL_19;
          }
        }
        if ( use_syslog || opt_log_output || opt_log_level > 2 )
        {
          LOWORD(v26) = -22644;
          HIWORD(v26) = (unsigned int)"%s CRC error. cal-crc=%x, chip-crc=%02x%02x\n" >> 16;
          snprintf(tmp42, 0x1000u, v26);
          goto LABEL_17;
        }
        goto LABEL_19;
      }
    }
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      LOWORD(v20) = -22692;
      HIWORD(v20) = (unsigned int)"n_pwm : %d" >> 16;
      snprintf(tmp42, 0x1000u, v20, "bm1740_verify_nonce_integrality", v19, v11[91 * v15 + 89], v11[91 * v15 + 90]);
LABEL_17:
      applog(3, tmp42, 0);
      if ( use_syslog )
        goto LABEL_20;
    }
    if ( opt_log_output )
      goto LABEL_20;
LABEL_19:
    if ( opt_log_level <= 3 )
      return -1;
LABEL_20:
    LOWORD(v21) = -22488;
    HIWORD(v21) = (unsigned int)"nonceID is different %02x != %02x chipid=%d\n" >> 16;
    v8 = -1;
    ++total_error_16501;
    snprintf(tmp42, 0x1000u, v21);
    applog(4, tmp42, 0);
    return v8;
  }
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
    return -1;
  LOWORD(v10) = -22720;
  HIWORD(v10) = (unsigned int)"= %d us" >> 16;
  snprintf(tmp42, 0x1000u, v10, "nonce_handle", v6);
  applog(4, tmp42, 0);
  return -1;
}
