void __noreturn scan_freq_handle()
{
  scan_freq_status *v0; // r2
  uint8_t *chain_exist; // r4
  int v2; // t1
  scan_freq_status *v3; // r3
  int v4; // r0
  int v5; // r9
  int v6; // r5
  uint8_t *v7; // r8
  int v8; // t1
  scan_freq_status *v9; // r4
  int v10; // r10
  int v11; // r7
  int v12; // r5
  int v13; // r3
  int v14; // r6
  uint32_t *v15; // r4
  int v16; // r12
  uint32_t v17; // r1
  uint32_t v18; // r0
  freq_pll_str *v19; // r2
  int freq; // r7
  int v21; // r3
  freq_pll_str *v22; // r1
  int v23; // r7
  int v24; // r2
  int v25; // r2
  int v26; // r0
  int v27; // r2
  unsigned int v28; // r2
  _BOOL4 v29; // r3
  const char *v30; // r3
  uint32_t v31; // r7
  freq_pll_str *v32; // r3
  int v33; // r0
  int v34; // r2
  int v35; // r2
  uint32_t v36; // lr
  freq_pll_str *v37; // r1
  int v38; // r0
  int v39; // r3
  uint32_t v40; // r12
  uint8_t *v41; // [sp+24h] [bp-1040h]
  uint32_t v42; // [sp+38h] [bp-102Ch]
  char tmp42[4100]; // [sp+60h] [bp-1004h] BYREF

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
        v5 = 0;
        while ( 1 )
        {
          while ( 1 )
          {
            do
            {
              ++v5;
              sleep(1u);
              pthread_mutex_lock(&each_chain_err_asic_mutex);
              pthread_cond_wait(&each_chain_err_asic_cond, &each_chain_err_asic_mutex);
              pthread_mutex_unlock(&each_chain_err_asic_mutex);
              v6 = status_error;
            }
            while ( status_error );
            if ( v5 != 1 )
              break;
            if ( use_syslog || opt_log_output || opt_log_level > 4 )
            {
              strcpy(tmp42, "ignore first 2 minutes\n");
              applog(5, tmp42, 0);
            }
          }
          v7 = dev.chain_exist;
          do
          {
            v8 = *v7++;
            if ( v8 == 1 )
            {
              v14 = 0;
              v15 = g_scan_freq_info.each_asic_invalid_nonce_each_2min[v6];
              v16 = v15[24];
              v17 = v15[60];
              if ( v16 )
                goto LABEL_48;
LABEL_24:
              if ( *v15 <= 0x19 )
              {
                v18 = v15[48];
                if ( v18 != v17 )
                {
                  v15[36] = v17;
                  if ( v17 == 100 )
                  {
                    if ( v18 != 100 )
                    {
                      v21 = v16;
                      goto LABEL_32;
                    }
                    v25 = v16;
                    v21 = v16;
                  }
                  else
                  {
                    v19 = freq_pll;
                    freq = 125;
                    v21 = 1;
                    while ( 1 )
                    {
                      ++v19;
                      if ( v17 == freq )
                      {
                        if ( v18 != 100 )
                          goto LABEL_32;
                        v24 = 0;
                        goto LABEL_36;
                      }
                      if ( ++v21 == 119 )
                        break;
                      freq = v19[1].freq;
                    }
                    v21 = -1;
                    if ( v18 == 100 )
                    {
LABEL_70:
                      v27 = v21 + 1;
                      v26 = 1;
LABEL_38:
                      v28 = *(_DWORD *)&_FUNCTION___15596[16 * v27 + 2004];
                      v29 = opt_debug;
                      v15[60] = v28;
                      if ( v29 && (use_syslog || opt_log_output || opt_log_level > 6) )
                      {
                        v30 = "down";
                        if ( v26 == 1 )
                          v30 = "up";
                        snprintf(
                          tmp42,
                          0x1000u,
                          "%s freq[%d-%d]: cur freq %d, [%d, %d], invalid nonce %d, ox status %d\n",
                          v30,
                          v6,
                          v14,
                          v28,
                          v15[36],
                          v15[48],
                          *v15,
                          v16);
                        applog(7, tmp42, 0);
                        v28 = v15[60];
                      }
                      set_freq_asic(v6, v14, v28);
                      goto LABEL_46;
                    }
LABEL_32:
                    v22 = freq_pll;
                    v23 = 125;
                    v24 = 1;
                    while ( 1 )
                    {
                      ++v22;
                      if ( v18 == v23 )
                        goto LABEL_36;
                      if ( ++v24 == 119 )
                        break;
                      v23 = v22[1].freq;
                    }
                    v24 = -1;
LABEL_36:
                    v25 = v24 - v21;
                    if ( v25 == 1 )
                      goto LABEL_70;
                  }
                  v26 = 1;
                  v27 = v21 + v25 / 2;
                  goto LABEL_38;
                }
                goto LABEL_85;
              }
              while ( 1 )
              {
LABEL_48:
                v31 = v15[36];
                if ( v17 != v31 )
                {
                  if ( v17 == 100 )
                  {
                    if ( v31 != 100 )
                    {
                      v35 = -1;
                      v36 = 0;
                      goto LABEL_55;
                    }
                    v39 = 0;
                    v35 = -1;
                    v36 = 0;
                    goto LABEL_62;
                  }
                  v32 = freq_pll;
                  v33 = 125;
                  v34 = 1;
                  while ( 1 )
                  {
                    ++v32;
                    if ( v17 == v33 )
                    {
                      v35 = v34 - 1;
                      v36 = *(_DWORD *)&_FUNCTION___15596[16 * v35 + 2004];
                      if ( v31 == 100 )
                      {
                        v39 = 0;
                      }
                      else
                      {
LABEL_55:
                        v37 = freq_pll;
                        v38 = 125;
                        v39 = 1;
                        while ( 1 )
                        {
                          ++v37;
                          if ( v38 == v31 )
                          {
                            v35 -= v39;
                            goto LABEL_60;
                          }
                          if ( ++v39 == 119 )
                            break;
                          v38 = v37[1].freq;
                        }
                        ++v35;
                        v39 = -1;
                      }
LABEL_60:
                      if ( v35 != 1 )
                        goto LABEL_62;
                      v27 = v39 + 1;
                      goto LABEL_63;
                    }
                    if ( ++v34 == 119 )
                      break;
                    v33 = v32[1].freq;
                  }
                  if ( v31 != 100 )
                  {
                    v35 = -2;
                    v36 = 0;
                    goto LABEL_55;
                  }
                  v39 = 0;
                  v35 = -2;
                  v36 = 0;
LABEL_62:
                  v27 = v39 + v35 / 2;
LABEL_63:
                  v26 = -1;
                  v15[48] = v36;
                  goto LABEL_38;
                }
LABEL_85:
                v15[72] = 1;
LABEL_46:
                ++v14;
                ++v15;
                if ( v14 == 3 )
                  break;
                v16 = v15[24];
                v17 = v15[60];
                if ( !v16 )
                  goto LABEL_24;
              }
            }
            ++v6;
          }
          while ( v6 != 4 );
          v9 = &g_scan_freq_info;
          v10 = 0;
          v11 = 0;
          v12 = 0;
          v41 = dev.chain_exist;
          do
          {
            v13 = *v41++;
            if ( v13 == 1 )
            {
              v40 = v9->each_asic_freq[0][2];
              v42 = v9->each_asic_freq[0][1];
              v10 += v9->each_asic_freq[0][0] + v42 + v40;
              v11 += v9->is_asic_scan_freq_done[0][0]
                   + v9->is_asic_scan_freq_done[0][1]
                   + v9->is_asic_scan_freq_done[0][2];
              if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                snprintf(tmp42, 0x1000u, "chain%d %d %d %d\n", v12, v9->each_asic_freq[0][0], v42, v40);
                applog(7, tmp42, 0);
              }
            }
            ++v12;
            v9 = (scan_freq_status *)((char *)v9 + 12);
          }
          while ( v12 != 4 );
          if ( 3 * dev.chain_num == v11 )
          {
            scan_freq_save_freq();
            if ( use_syslog || opt_log_output || opt_log_level > 4 )
            {
              snprintf(tmp42, 0x1000u, "scan freq done, avg freq %d max %d, reboot cgminer\n", v10 / v11, 815);
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
