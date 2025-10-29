void __noreturn turbo_mode_monitor()
{
  uint8_t *chain_exist; // r7
  int v1; // r2
  int v2; // t1
  char *v3; // r0
  int v4; // r1
  char *v5; // r5
  __int64 v6; // kr00_8
  int v7; // r5
  _DWORD *v8; // r1
  int v9; // r2
  uint8_t *v10; // r9
  unsigned int v11; // r4
  int v12; // t1
  unsigned int *v13; // r5
  int v14; // r8
  unsigned __int8 v15; // r6
  uint32_t *v16; // r11
  int v17; // r3
  int *v18; // r7
  uint32_t v19; // r12
  freq_pll_str *v20; // r0
  int v21; // r2
  unsigned int v22; // r0
  freq_pll_str *v23; // r12
  int freq; // lr
  int v25; // r3
  unsigned int v26; // r2
  int v27; // t1
  unsigned int v28; // r2
  int *v29; // r5
  int v30; // r0
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r1
  int v35; // r2
  int v36; // r3
  int v37; // r1
  uint8_t *v38; // r5
  int v39; // t1
  int v40; // r3
  int *v41; // r3
  char *v42; // r2
  char *v43; // r1
  int v44; // r4
  uint8_t *v45; // r10
  int v46; // t1
  int v47; // r8
  uint32_t *v48; // r6
  int *v49; // r5
  _BOOL4 v50; // r3
  int v51; // r7
  uint32_t v52; // r0
  uint32_t v53; // r2
  freq_pll_str *v54; // r2
  int v55; // r1
  int v56; // r3
  unsigned int v57; // r3
  pthread_cond_t *cond; // [sp+20h] [bp-10B4h]
  char *format; // [sp+2Ch] [bp-10A8h]
  unsigned int v60; // [sp+30h] [bp-10A4h]
  int v61; // [sp+38h] [bp-109Ch]
  char *v62; // [sp+3Ch] [bp-1098h]
  int lower_times[4][3]; // [sp+40h] [bp-1094h] BYREF
  _BYTE s[48]; // [sp+70h] [bp-1064h] BYREF
  _DWORD v65[12]; // [sp+A0h] [bp-1034h] BYREF
  char tmp42[4096]; // [sp+D0h] [bp-1004h] BYREF

  memset(lower_times, 0, sizeof(lower_times));
  memset(s, 0, sizeof(s));
  chain_exist = dev.chain_exist;
  memset(v65, 0, sizeof(v65));
  v1 = 0;
  do
  {
    while ( 1 )
    {
      v2 = *chain_exist++;
      if ( v2 == 1 )
        break;
      if ( ++v1 == 4 )
        goto LABEL_5;
    }
    v3 = (char *)&dev + 2 * v1;
    v4 = 3 * v1;
    v65[3 * v1] = 775;
    v5 = (char *)&g_scan_freq_info + 12 * v1++;
    v6 = *(_QWORD *)(v5 + 244);
    v7 = *((_DWORD *)v5 + 63);
    v8 = &v65[v4];
    v8[1] = 775;
    v8[2] = 775;
    *(_WORD *)(v3 + 593) = (__int16)(v6 + WORD2(v6) + v7) / 3;
  }
  while ( v1 != 4 );
LABEL_5:
  LOWORD(v9) = 28216;
  HIWORD(v9) = (unsigned int)"s %s():%d" >> 16;
  v61 = v9;
  while ( !start_send[0] )
LABEL_12:
    cgsleep_ms(500);
  while ( 1 )
  {
    v10 = dev.chain_exist;
    v11 = 0;
    cond = 0;
    do
    {
      v12 = *v10++;
      if ( v12 == 1 )
      {
        v13 = &v65[v11 / 4];
        v14 = 0;
        v15 = ~(unsigned int)dev.chain_exist + (_BYTE)v10;
        v16 = g_scan_freq_info.each_asic_freq[v11 / 0xC];
        v18 = lower_times[v11 / 0xC + 4];
        v17 = *v18;
        if ( !*v18 )
        {
LABEL_14:
          v19 = *v16;
          if ( *v16 <= 0x306 || v19 == 775 )
          {
            v28 = *v16;
            *v13 = v19;
            set_freq_asic(v15, v14, v28);
          }
          else
          {
            v20 = freq_pll;
            v21 = 1;
            while ( 1 )
            {
              ++v21;
              ++v20;
              if ( v21 == 119 )
                break;
              if ( v20[1].freq == v19 )
              {
                v22 = *v13;
                if ( *v13 == 100 )
                  goto LABEL_25;
                goto LABEL_20;
              }
            }
            v22 = *v13;
            if ( *v13 == 100 )
              goto LABEL_34;
            v21 = -1;
LABEL_20:
            v23 = freq_pll;
            freq = 125;
            v17 = 1;
            while ( 1 )
            {
              ++v23;
              if ( freq == v22 )
              {
                v21 -= v17;
                goto LABEL_25;
              }
              if ( ++v17 == 119 )
                break;
              freq = v23[1].freq;
            }
            ++v21;
            v17 = -1;
LABEL_25:
            if ( v21 <= 1 )
LABEL_34:
              v25 = v17 + 1;
            else
              v25 = v17 + 2;
            v26 = *(_DWORD *)(v61 + 16 * v25 + 2004);
            *v13 = v26;
            v60 = v26;
            set_freq_asic(v15, v14, v26);
            if ( v60 != *v16 )
              goto LABEL_29;
          }
          *v18 = 1;
          goto LABEL_29;
        }
        while ( 1 )
        {
          cond = (pthread_cond_t *)((char *)cond + 1);
LABEL_29:
          ++v14;
          ++v13;
          ++v16;
          if ( v14 == 3 )
            break;
          v27 = v18[1];
          ++v18;
          v17 = v27;
          if ( !v27 )
            goto LABEL_14;
        }
      }
      v11 += 12;
    }
    while ( v11 != 48 );
    if ( 3 * dev.chain_num <= (int)cond )
      break;
    sleep(3u);
    if ( !start_send[0] )
      goto LABEL_12;
  }
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v29) = -26472;
    HIWORD(v29) = (unsigned int)"shift = %08x" >> 16;
    v30 = *v29;
    v31 = v29[1];
    v32 = v29[2];
    v33 = v29[3];
    v29 += 4;
    *(_DWORD *)tmp42 = v30;
    *(_DWORD *)&tmp42[4] = v31;
    *(_DWORD *)&tmp42[8] = v32;
    *(_DWORD *)&tmp42[12] = v33;
    v34 = v29[1];
    v35 = v29[2];
    v36 = v29[3];
    *(_DWORD *)&tmp42[16] = *v29;
    *(_DWORD *)&tmp42[20] = v34;
    *(_DWORD *)&tmp42[24] = v35;
    *(_WORD *)&tmp42[28] = v36;
    applog(5, tmp42, 0);
  }
  v37 = 0;
  v38 = dev.chain_exist;
  do
  {
    while ( 1 )
    {
      v39 = *v38++;
      if ( v39 == 1 )
        break;
      if ( ++v37 == 4 )
        goto LABEL_43;
    }
    v40 = 3 * v37++;
    v41 = &g_scan_freq_info.scan_freq_store_pos + v40;
    v41[1] = 0;
    v41[25] = 0;
    v41[49] = 815;
    v41[37] = 775;
    v41[2] = 0;
    v41[26] = 0;
    v41[50] = 815;
    v41[38] = 775;
    v41[3] = 0;
    v41[27] = 0;
    v41[51] = 815;
    v41[39] = 775;
  }
  while ( v37 != 4 );
LABEL_43:
  LOWORD(v42) = -26392;
  LOWORD(v43) = -26440;
  HIWORD(v42) = (unsigned int)"chainid%d %s freq=%d" >> 16;
  HIWORD(v43) = (unsigned int)" drive = %08x" >> 16;
  v62 = v42;
  format = v43;
  while ( 1 )
  {
    do
    {
      sleep(1u);
      pthread_mutex_lock(&each_chain_err_asic_mutex);
      pthread_cond_wait(&each_chain_err_asic_cond, &each_chain_err_asic_mutex);
      pthread_mutex_unlock(&each_chain_err_asic_mutex);
      v44 = status_error;
    }
    while ( status_error );
    v45 = &dev.chain_exist[1];
    if ( dev.chain_exist[0] == 1 )
    {
LABEL_48:
      v47 = 0;
      v48 = g_scan_freq_info.each_asic_invalid_nonce_each_2min[v44];
      v49 = lower_times[v44];
      if ( v48[24] != 1 )
      {
        *v49 = 0;
        goto LABEL_51;
      }
LABEL_54:
      v50 = use_syslog;
      v51 = *v49 + 1;
      *v49 = v51;
      if ( v50 || opt_log_output || opt_log_level > 4 )
      {
        snprintf(tmp42, 0x1000u, format, v44, v47, v48[60], v51);
        applog(5, tmp42, 0);
      }
      if ( v51 > 3 )
      {
        v52 = v48[60];
        v53 = v48[36];
        if ( v52 > v53 )
        {
          *v49 = 0;
          if ( use_syslog || opt_log_output || opt_log_level > 4 )
          {
            snprintf(tmp42, 0x1000u, v62, v44, v47, v52, v53, v48[48], *v48, v48[24]);
            applog(5, tmp42, 0);
            v52 = v48[60];
          }
          if ( v52 == 100 )
          {
LABEL_76:
            v57 = 0;
          }
          else
          {
            v54 = freq_pll;
            v55 = 125;
            v56 = 1;
            while ( 1 )
            {
              ++v54;
              if ( v52 == v55 )
                break;
              if ( ++v56 == 119 )
                goto LABEL_76;
              v55 = v54[1].freq;
            }
            v57 = *(_DWORD *)(v61 + 16 * v56 + 1988);
          }
          v48[60] = v57;
          set_freq_asic(v44, v47, v57);
        }
      }
LABEL_51:
      while ( 1 )
      {
        ++v47;
        ++v48;
        ++v49;
        if ( v47 == 3 )
          break;
        if ( v48[24] == 1 )
          goto LABEL_54;
        *v49 = 0;
      }
    }
    while ( ++v44 != 4 )
    {
      v46 = *v45++;
      if ( v46 == 1 )
        goto LABEL_48;
    }
  }
}
