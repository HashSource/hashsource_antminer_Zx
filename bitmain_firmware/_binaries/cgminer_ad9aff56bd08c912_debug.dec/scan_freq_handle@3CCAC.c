void __noreturn scan_freq_handle()
{
  scan_freq_status *v0; // r2
  uint8_t *chain_exist; // r4
  int v2; // t1
  scan_freq_status *v3; // r3
  int v4; // r0
  const char *v5; // r3
  int v6; // r4
  const char *v7; // r2
  int v8; // r9
  int v9; // r5
  uint8_t *v10; // r8
  int v11; // t1
  scan_freq_status *v12; // r4
  int v13; // r10
  const char *v14; // r8
  int v15; // r7
  int v16; // r5
  int v17; // r3
  const char *v18; // r2
  int v19; // r6
  uint32_t *v20; // r4
  int v21; // r12
  uint32_t v22; // r1
  uint32_t v23; // r0
  freq_pll_str *v24; // r2
  int freq; // r7
  int v26; // r3
  freq_pll_str *v27; // r1
  int v28; // r7
  int v29; // r2
  int v30; // r2
  int v31; // r0
  int v32; // r2
  unsigned int v33; // r2
  _BOOL4 v34; // r3
  const char *v35; // r3
  uint32_t v36; // r7
  freq_pll_str *v37; // r3
  int v38; // r0
  int v39; // r2
  int v40; // r2
  uint32_t v41; // lr
  freq_pll_str *v42; // r1
  int v43; // r0
  int v44; // r3
  uint32_t v45; // r12
  int *v46; // r4
  int v47; // r0
  int v48; // r1
  int v49; // r2
  int v50; // r3
  int v51; // r1
  uint8_t *v52; // [sp+24h] [bp-1040h]
  int v53; // [sp+2Ch] [bp-1038h]
  uint32_t v54; // [sp+38h] [bp-102Ch]
  const char *v55; // [sp+54h] [bp-1010h]
  const char *v56; // [sp+58h] [bp-100Ch]
  char tmp42[4096]; // [sp+60h] [bp-1004h] BYREF

  set_frequency(0x320u);
  v0 = &g_scan_freq_info;
  chain_exist = dev.chain_exist;
  while ( 1 )
  {
    v2 = *chain_exist++;
    if ( v2 == 1 )
    {
      v3 = v0;
      v4 = 3;
      do
      {
        --v4;
        v3->each_asic_invalid_nonce_each_2min[0][0] = 0;
        v3 = (scan_freq_status *)((char *)v3 + 4);
        v3->each_asic_valid_nonce_each_2min[3][2] = 0;
        v3->each_asic_max_freq[3][2] = 800;
        v3->each_asic_min_freq[3][2] = 815;
        v3->each_asic_ox_status[3][2] = 775;
        v3->each_asic_freq[3][2] = 0;
      }
      while ( v4 );
      v0 = (scan_freq_status *)((char *)v0 + 12);
      if ( v0 == (scan_freq_status *)&g_scan_freq_info.each_asic_invalid_nonce_each_2min[3][2] )
      {
LABEL_7:
        LOWORD(v5) = -24608;
        HIWORD(v5) = (unsigned int)"e best frequency\n" >> 16;
        v55 = v5;
        LOWORD(v6) = 28216;
        LOWORD(v7) = -24612;
        v8 = 0;
        HIWORD(v6) = (unsigned int)"s %s():%d" >> 16;
        HIWORD(v7) = (unsigned int)"d the best frequency\n" >> 16;
        v53 = v6;
        v56 = v7;
        while ( 1 )
        {
          while ( 1 )
          {
            do
            {
              ++v8;
              sleep(1u);
              pthread_mutex_lock(&each_chain_err_asic_mutex);
              pthread_cond_wait(&each_chain_err_asic_cond, &each_chain_err_asic_mutex);
              pthread_mutex_unlock(&each_chain_err_asic_mutex);
              v9 = status_error;
            }
            while ( status_error );
            if ( v8 != 1 )
              break;
            if ( use_syslog || opt_log_output || opt_log_level > 4 )
            {
              LOWORD(v46) = -24600;
              HIWORD(v46) = (unsigned int)"requency\n" >> 16;
              v47 = *v46;
              v48 = v46[1];
              v49 = v46[2];
              v50 = v46[3];
              v46 += 4;
              *(_DWORD *)tmp42 = v47;
              *(_DWORD *)&tmp42[4] = v48;
              *(_DWORD *)&tmp42[8] = v49;
              *(_DWORD *)&tmp42[12] = v50;
              v51 = v46[1];
              *(_DWORD *)&tmp42[16] = *v46;
              *(_DWORD *)&tmp42[20] = v51;
              applog(5, tmp42, 0);
            }
          }
          v10 = dev.chain_exist;
          do
          {
            v11 = *v10++;
            if ( v11 == 1 )
            {
              v19 = 0;
              v20 = g_scan_freq_info.each_asic_invalid_nonce_each_2min[v9];
              v21 = v20[24];
              v22 = v20[60];
              if ( v21 )
                goto LABEL_48;
LABEL_24:
              if ( *v20 <= 0x19 )
              {
                v23 = v20[48];
                if ( v23 != v22 )
                {
                  v20[36] = v22;
                  if ( v22 == 100 )
                  {
                    if ( v23 != 100 )
                    {
                      v26 = v21;
                      goto LABEL_32;
                    }
                    v30 = v21;
                    v26 = v21;
                  }
                  else
                  {
                    v24 = freq_pll;
                    freq = 125;
                    v26 = 1;
                    while ( 1 )
                    {
                      ++v24;
                      if ( v22 == freq )
                      {
                        if ( v23 != 100 )
                          goto LABEL_32;
                        v29 = 0;
                        goto LABEL_36;
                      }
                      if ( ++v26 == 119 )
                        break;
                      freq = v24[1].freq;
                    }
                    v26 = -1;
                    if ( v23 == 100 )
                    {
LABEL_70:
                      v32 = v26 + 1;
                      v31 = 1;
LABEL_38:
                      v33 = *(_DWORD *)(v53 + 16 * v32 + 2004);
                      v34 = opt_debug;
                      v20[60] = v33;
                      if ( v34 && (use_syslog || opt_log_output || opt_log_level > 6) )
                      {
                        v35 = v55;
                        if ( v31 == 1 )
                          v35 = v56;
                        snprintf(
                          tmp42,
                          0x1000u,
                          "%s freq[%d-%d]: cur freq %d, [%d, %d], invalid nonce %d, ox status %d\n",
                          v35,
                          v9,
                          v19,
                          v33,
                          v20[36],
                          v20[48],
                          *v20,
                          v21);
                        applog(7, tmp42, 0);
                        v33 = v20[60];
                      }
                      set_freq_asic(v9, v19, v33);
                      goto LABEL_46;
                    }
LABEL_32:
                    v27 = freq_pll;
                    v28 = 125;
                    v29 = 1;
                    while ( 1 )
                    {
                      ++v27;
                      if ( v23 == v28 )
                        goto LABEL_36;
                      if ( ++v29 == 119 )
                        break;
                      v28 = v27[1].freq;
                    }
                    v29 = -1;
LABEL_36:
                    v30 = v29 - v26;
                    if ( v30 == 1 )
                      goto LABEL_70;
                  }
                  v31 = 1;
                  v32 = v26 + v30 / 2;
                  goto LABEL_38;
                }
                goto LABEL_85;
              }
              while ( 1 )
              {
LABEL_48:
                v36 = v20[36];
                if ( v22 != v36 )
                {
                  if ( v22 == 100 )
                  {
                    if ( v36 != 100 )
                    {
                      v40 = -1;
                      v41 = 0;
                      goto LABEL_55;
                    }
                    v44 = 0;
                    v40 = -1;
                    v41 = 0;
                    goto LABEL_62;
                  }
                  v37 = freq_pll;
                  v38 = 125;
                  v39 = 1;
                  while ( 1 )
                  {
                    ++v37;
                    if ( v22 == v38 )
                    {
                      v40 = v39 - 1;
                      v41 = *(_DWORD *)(v53 + 16 * v40 + 2004);
                      if ( v36 == 100 )
                      {
                        v44 = 0;
                      }
                      else
                      {
LABEL_55:
                        v42 = freq_pll;
                        v43 = 125;
                        v44 = 1;
                        while ( 1 )
                        {
                          ++v42;
                          if ( v43 == v36 )
                          {
                            v40 -= v44;
                            goto LABEL_60;
                          }
                          if ( ++v44 == 119 )
                            break;
                          v43 = v42[1].freq;
                        }
                        ++v40;
                        v44 = -1;
                      }
LABEL_60:
                      if ( v40 != 1 )
                        goto LABEL_62;
                      v32 = v44 + 1;
                      goto LABEL_63;
                    }
                    if ( ++v39 == 119 )
                      break;
                    v38 = v37[1].freq;
                  }
                  if ( v36 != 100 )
                  {
                    v40 = -2;
                    v41 = 0;
                    goto LABEL_55;
                  }
                  v44 = 0;
                  v40 = -2;
                  v41 = 0;
LABEL_62:
                  v32 = v44 + v40 / 2;
LABEL_63:
                  v31 = -1;
                  v20[48] = v41;
                  goto LABEL_38;
                }
LABEL_85:
                v20[72] = 1;
LABEL_46:
                ++v19;
                ++v20;
                if ( v19 == 3 )
                  break;
                v21 = v20[24];
                v22 = v20[60];
                if ( !v21 )
                  goto LABEL_24;
              }
            }
            ++v9;
          }
          while ( v9 != 4 );
          v12 = &g_scan_freq_info;
          v13 = 0;
          LOWORD(v14) = -24504;
          v15 = 0;
          v16 = 0;
          v52 = dev.chain_exist;
          do
          {
            v17 = *v52++;
            if ( v17 == 1 )
            {
              v45 = v12->each_asic_freq[0][2];
              v54 = v12->each_asic_freq[0][1];
              v13 += v12->each_asic_freq[0][0] + v54 + v45;
              v15 += v12->is_asic_scan_freq_done[0][0]
                   + v12->is_asic_scan_freq_done[0][1]
                   + v12->is_asic_scan_freq_done[0][2];
              if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                HIWORD(v14) = (unsigned int)"%s failed\n" >> 16;
                snprintf(tmp42, 0x1000u, v14, v16, v12->each_asic_freq[0][0], v54, v45);
                applog(7, tmp42, 0);
              }
            }
            ++v16;
            v12 = (scan_freq_status *)((char *)v12 + 12);
          }
          while ( v16 != 4 );
          if ( 3 * dev.chain_num == v15 )
          {
            scan_freq_save_freq();
            if ( use_syslog || opt_log_output || opt_log_level > 4 )
            {
              LOWORD(v18) = -24484;
              HIWORD(v18) = (unsigned int)"down" >> 16;
              snprintf(tmp42, 0x1000u, v18, v13 / v15, 815);
              applog(5, tmp42, 0);
            }
            system("/etc/init.d/cgminer.sh restart > /dev/null 2>&1 &");
          }
        }
      }
    }
    else
    {
      v0 = (scan_freq_status *)((char *)v0 + 12);
      if ( v0 == (scan_freq_status *)&g_scan_freq_info.each_asic_invalid_nonce_each_2min[3][2] )
        goto LABEL_7;
    }
  }
}
