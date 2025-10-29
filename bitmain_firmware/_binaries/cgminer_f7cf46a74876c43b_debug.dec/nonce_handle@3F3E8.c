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
  uint8_t *v10; // r6
  int v11; // r7
  unsigned __int8 *v12; // r0
  int v13; // r12
  unsigned __int8 *v14; // r1
  unsigned int v15; // r2
  int v16; // t1
  uint32_t v17; // r3
  uint8_t *v18; // r0
  uint8_t *v19; // r1
  int v20; // r3
  uint8_t v21; // r2
  uint8_t *v22; // r2
  int v23; // r7
  uint8_t *v24; // r1
  int v25; // r7
  int v26; // r3
  int v27; // r7
  char *v28; // r7
  nonce_rb_format *v29; // r4
  nonce_rb_format *v30; // r5
  nonce_rb_format *v31; // r0
  uint32_t p_wr; // r3
  char *v33; // r2
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  v6 = str[3] / dev.addrInterval;
  v7 = v6;
  if ( v6 <= 2u )
  {
    v10 = (*g_nonce_list)[v6][0];
    v11 = str[2] & 0xF;
    memcpy(&v10[91 * v11], str + 2, 0x5Bu);
    if ( v11 != 15 )
      return 1;
    v12 = v10 + 89;
    v13 = 0;
    while ( 1 )
    {
      v14 = v12 - 89;
      v15 = 0xFFFF;
      do
      {
        v16 = *v14++;
        v15 = (unsigned __int16)(*(_WORD *)&_FUNCTION___15596[2 * (v16 ^ (v15 >> 8)) + 100] ^ ((_WORD)v15 << 8));
      }
      while ( v14 != v12 );
      if ( __PAIR64__((unsigned __int8)((unsigned __int16)(((_WORD)v15 << 8) | (v15 >> 8)) >> 8), BYTE1(v15)) != __PAIR64__(v14[1], *v14) )
        break;
      ++v13;
      v12 = v14 + 91;
      v8 = 0;
      if ( v13 == 16 )
      {
        v18 = v10;
        v19 = v10;
        v20 = 0;
        while ( 1 )
        {
          v21 = *v19;
          v19 += 91;
          if ( (v21 & 0xF) != v20 )
            break;
          if ( ++v20 == 16 )
          {
            v22 = v10;
            while ( 1 )
            {
              v23 = v22[92];
              v22 += 91;
              if ( v23 != v10[1] )
                break;
              if ( v10 + 1365 == v22 )
              {
                v24 = v10;
                while ( 1 )
                {
                  v25 = v24[93];
                  v24 += 91;
                  if ( v25 != v10[2] )
                    break;
                  if ( v22 == v24 )
                  {
                    v26 = v10[3];
                    while ( 1 )
                    {
                      v27 = v18[94];
                      v18 += 91;
                      if ( v27 != v26 )
                        break;
                      if ( v24 == v18 )
                      {
                        v28 = (char *)(v10 + 4);
                        v29 = &(*g_nonce)[v7];
                        v30 = v29;
                        do
                        {
                          v31 = v30;
                          v30 = (nonce_rb_format *)((char *)v30 + 85);
                          memcpy(v31, v28, 0x55u);
                          v28 += 91;
                        }
                        while ( v30 != (nonce_rb_format *)&v29->Nonce[1275] );
                        memcpy(v30, v10 + 1369, 0x45u);
                        *(_DWORD *)v29->chip_nonce = *(_DWORD *)(v10 + 1450);
                        v29->chip_addr = v10[1366];
                        v29->work_id = v10[1367];
                        v29->nonce_id = v10[1368];
                        v29->diff0 = v10[1441];
                        *(_DWORD *)v29->sha256 = *(_DWORD *)(v10 + 1442);
                        pthread_mutex_lock(&nonce_mutex);
                        p_wr = nonce_fifo.p_wr;
                        v33 = (char *)&nonce_fifo + 1357 * nonce_fifo.p_wr;
                        v33[1368] = chainid;
                        v33[1356] = v29->chip_addr;
                        v33[1357] = v29->work_id & 0x7F;
                        v33[1358] = v29->nonce_id;
                        v33[1359] = v29->diff0;
                        *(_DWORD *)nonce_fifo.nonce_buffer[p_wr].sha256 = *(_DWORD *)v29->sha256;
                        *(_DWORD *)nonce_fifo.nonce_buffer[p_wr].chip_nonce = *(_DWORD *)v29->chip_nonce;
                        memcpy(&nonce_fifo.nonce_buffer[p_wr], v29, 0x540u);
                        if ( nonce_fifo.p_wr > 0x62 )
                          nonce_fifo.p_wr = 0;
                        else
                          ++nonce_fifo.p_wr;
                        if ( nonce_fifo.nonce_num > 0x63 )
                        {
                          nonce_fifo.nonce_num = 100;
                          if ( use_syslog || opt_log_output || opt_log_level > 3 )
                          {
                            snprintf(tmp42, 0x1000u, "%s: nonce fifo full!!!", "nonce_handle");
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
                      snprintf(tmp42, 0x1000u, "nonceID is different %02x != %02x chipid=%d\n", v26, v27, v7);
                      goto LABEL_17;
                    }
                    goto LABEL_19;
                  }
                }
                if ( use_syslog || opt_log_output || opt_log_level > 2 )
                {
                  snprintf(tmp42, 0x1000u, "workID is different %02x != %02x\n");
                  goto LABEL_17;
                }
                goto LABEL_19;
              }
            }
            if ( use_syslog || opt_log_output || opt_log_level > 2 )
            {
              snprintf(tmp42, 0x1000u, "chip_addr is different %02x != %02x\n");
              goto LABEL_17;
            }
            goto LABEL_19;
          }
        }
        if ( use_syslog || opt_log_output || opt_log_level > 2 )
        {
          snprintf(tmp42, 0x1000u, "nonce is not continous i=%d\n", v20);
          goto LABEL_17;
        }
        goto LABEL_19;
      }
    }
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      snprintf(
        tmp42,
        0x1000u,
        "%s CRC error. cal-crc=%x, chip-crc=%02x%02x\n",
        "bm1740_verify_nonce_integrality",
        (unsigned __int16)((_WORD)v15 << 8) | (unsigned __int16)(v15 >> 8),
        v10[91 * v13 + 89],
        v10[91 * v13 + 90]);
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
    v17 = total_error_16509;
    v8 = -1;
    ++total_error_16509;
    snprintf(tmp42, 0x1000u, "receive a error nonce. total = %u", v17);
    applog(4, tmp42, 0);
    return v8;
  }
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
    return -1;
  snprintf(tmp42, 0x1000u, "%s chipid %d is not exist", "nonce_handle", v6);
  applog(4, tmp42, 0);
  return -1;
}
