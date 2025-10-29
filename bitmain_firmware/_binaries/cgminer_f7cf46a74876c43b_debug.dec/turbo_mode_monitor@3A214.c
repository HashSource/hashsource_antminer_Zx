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
  uint8_t *v9; // r9
  unsigned int v10; // r4
  int v11; // t1
  unsigned int *v12; // r5
  int v13; // r8
  unsigned __int8 v14; // r6
  uint32_t *v15; // r11
  int v16; // r3
  int *v17; // r7
  uint32_t v18; // r12
  freq_pll_str *v19; // r0
  int v20; // r2
  unsigned int v21; // r0
  freq_pll_str *v22; // r12
  int freq; // lr
  int v24; // r3
  unsigned int v25; // r2
  int v26; // t1
  unsigned int v27; // r2
  int v28; // r1
  uint8_t *v29; // r5
  int v30; // t1
  int v31; // r3
  int *v32; // r3
  int v33; // r4
  uint8_t *v34; // r10
  int v35; // t1
  int v36; // r8
  uint32_t *v37; // r6
  int *v38; // r5
  _BOOL4 v39; // r3
  int v40; // r7
  uint32_t v41; // r0
  uint32_t v42; // r2
  freq_pll_str *v43; // r2
  int v44; // r1
  int v45; // r3
  unsigned int v46; // r3
  pthread_cond_t *cond; // [sp+20h] [bp-10B4h]
  unsigned int v48; // [sp+30h] [bp-10A4h]
  int lower_times[4][3]; // [sp+40h] [bp-1094h] BYREF
  _BYTE s[48]; // [sp+70h] [bp-1064h] BYREF
  _DWORD v51[12]; // [sp+A0h] [bp-1034h] BYREF
  char tmp42[4100]; // [sp+D0h] [bp-1004h] BYREF

  memset(lower_times, 0, sizeof(lower_times));
  memset(s, 0, sizeof(s));
  chain_exist = dev.chain_exist;
  memset(v51, 0, sizeof(v51));
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
    v51[3 * v1] = 775;
    v5 = (char *)&g_scan_freq_info + 12 * v1++;
    v6 = *(_QWORD *)(v5 + 244);
    v7 = *((_DWORD *)v5 + 63);
    v8 = &v51[v4];
    v8[1] = 775;
    v8[2] = 775;
    *(_WORD *)(v3 + 593) = (__int16)(v6 + WORD2(v6) + v7) / 3;
  }
  while ( v1 != 4 );
LABEL_5:
  while ( !start_send[0] )
LABEL_11:
    cgsleep_ms(500);
  while ( 1 )
  {
    v9 = dev.chain_exist;
    v10 = 0;
    cond = 0;
    do
    {
      v11 = *v9++;
      if ( v11 == 1 )
      {
        v12 = &v51[v10 / 4];
        v13 = 0;
        v14 = ~(unsigned int)dev.chain_exist + (_BYTE)v9;
        v15 = g_scan_freq_info.each_asic_freq[v10 / 0xC];
        v17 = lower_times[v10 / 0xC + 4];
        v16 = *v17;
        if ( !*v17 )
        {
LABEL_13:
          v18 = *v15;
          if ( *v15 <= 0x306 || v18 == 775 )
          {
            v27 = *v15;
            *v12 = v18;
            set_freq_asic(v14, v13, v27);
          }
          else
          {
            v19 = freq_pll;
            v20 = 1;
            while ( 1 )
            {
              ++v20;
              ++v19;
              if ( v20 == 119 )
                break;
              if ( v19[1].freq == v18 )
              {
                v21 = *v12;
                if ( *v12 == 100 )
                  goto LABEL_24;
                goto LABEL_19;
              }
            }
            v21 = *v12;
            if ( *v12 == 100 )
              goto LABEL_33;
            v20 = -1;
LABEL_19:
            v22 = freq_pll;
            freq = 125;
            v16 = 1;
            while ( 1 )
            {
              ++v22;
              if ( freq == v21 )
              {
                v20 -= v16;
                goto LABEL_24;
              }
              if ( ++v16 == 119 )
                break;
              freq = v22[1].freq;
            }
            ++v20;
            v16 = -1;
LABEL_24:
            if ( v20 <= 1 )
LABEL_33:
              v24 = v16 + 1;
            else
              v24 = v16 + 2;
            v25 = *(_DWORD *)&_FUNCTION___15596[16 * v24 + 2004];
            *v12 = v25;
            v48 = v25;
            set_freq_asic(v14, v13, v25);
            if ( v48 != *v15 )
              goto LABEL_28;
          }
          *v17 = 1;
          goto LABEL_28;
        }
        while ( 1 )
        {
          cond = (pthread_cond_t *)((char *)cond + 1);
LABEL_28:
          ++v13;
          ++v12;
          ++v15;
          if ( v13 == 3 )
            break;
          v26 = v17[1];
          ++v17;
          v16 = v26;
          if ( !v26 )
            goto LABEL_13;
        }
      }
      v10 += 12;
    }
    while ( v10 != 48 );
    if ( 3 * dev.chain_num <= (int)cond )
      break;
    sleep(3u);
    if ( !start_send[0] )
      goto LABEL_11;
  }
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    strcpy(tmp42, "All asics arrive target freq\n");
    applog(5, tmp42, 0);
  }
  v28 = 0;
  v29 = dev.chain_exist;
  do
  {
    while ( 1 )
    {
      v30 = *v29++;
      if ( v30 == 1 )
        break;
      if ( ++v28 == 4 )
        goto LABEL_42;
    }
    v31 = 3 * v28++;
    v32 = &g_scan_freq_info.scan_freq_store_pos + v31;
    v32[1] = 0;
    v32[25] = 0;
    v32[49] = 815;
    v32[37] = 775;
    v32[2] = 0;
    v32[26] = 0;
    v32[50] = 815;
    v32[38] = 775;
    v32[3] = 0;
    v32[27] = 0;
    v32[51] = 815;
    v32[39] = 775;
  }
  while ( v28 != 4 );
  while ( 1 )
  {
    do
    {
LABEL_42:
      sleep(1u);
      pthread_mutex_lock(&each_chain_err_asic_mutex);
      pthread_cond_wait(&each_chain_err_asic_cond, &each_chain_err_asic_mutex);
      pthread_mutex_unlock(&each_chain_err_asic_mutex);
      v33 = status_error;
    }
    while ( status_error );
    v34 = &dev.chain_exist[1];
    if ( dev.chain_exist[0] == 1 )
    {
LABEL_46:
      v36 = 0;
      v37 = g_scan_freq_info.each_asic_invalid_nonce_each_2min[v33];
      v38 = lower_times[v33];
      if ( v37[24] != 1 )
      {
        *v38 = 0;
        goto LABEL_49;
      }
LABEL_52:
      v39 = use_syslog;
      v40 = *v38 + 1;
      *v38 = v40;
      if ( v39 || opt_log_output || opt_log_level > 4 )
      {
        snprintf(tmp42, 0x1000u, "low freq[%d-%d]: cur freq %d, lower times %d\n", v33, v36, v37[60], v40);
        applog(5, tmp42, 0);
      }
      if ( v40 > 3 )
      {
        v41 = v37[60];
        v42 = v37[36];
        if ( v41 > v42 )
        {
          *v38 = 0;
          if ( use_syslog || opt_log_output || opt_log_level > 4 )
          {
            snprintf(
              tmp42,
              0x1000u,
              "low freq[%d-%d]: cur freq %d, [%d, %d], invalid nonce %d, ox status %d\n",
              v33,
              v36,
              v41,
              v42,
              v37[48],
              *v37,
              v37[24]);
            applog(5, tmp42, 0);
            v41 = v37[60];
          }
          if ( v41 == 100 )
          {
LABEL_74:
            v46 = 0;
          }
          else
          {
            v43 = freq_pll;
            v44 = 125;
            v45 = 1;
            while ( 1 )
            {
              ++v43;
              if ( v41 == v44 )
                break;
              if ( ++v45 == 119 )
                goto LABEL_74;
              v44 = v43[1].freq;
            }
            v46 = *(_DWORD *)&_FUNCTION___15596[16 * v45 + 1988];
          }
          v37[60] = v46;
          set_freq_asic(v33, v36, v46);
        }
      }
LABEL_49:
      while ( 1 )
      {
        ++v36;
        ++v37;
        ++v38;
        if ( v36 == 3 )
          break;
        if ( v37[24] == 1 )
          goto LABEL_52;
        *v38 = 0;
      }
    }
    while ( ++v33 != 4 )
    {
      v35 = *v34++;
      if ( v35 == 1 )
        goto LABEL_46;
    }
  }
}
