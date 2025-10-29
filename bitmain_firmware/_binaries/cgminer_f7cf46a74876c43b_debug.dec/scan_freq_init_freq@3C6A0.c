void scan_freq_init_freq()
{
  uint8_t *chain_exist; // r6
  int v1; // r1
  uint8_t *v2; // r3
  int v3; // t1
  int i; // r4
  int v5; // t1
  int *v6; // r5
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r5
  const char *v12; // r5
  int v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int *v17; // r5
  int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r12
  uint32_t *v26; // r5
  unsigned __int8 *v27; // r9
  int v28; // t1
  int v29; // r8
  uint32_t v30; // r6
  int v31; // r4
  FILE *v32; // r8
  uint8_t *v33; // r7
  int v34; // t1
  int v35; // r5
  _DWORD *v36; // r6
  uint8_t *v37; // [sp+1Ch] [bp-1030h]
  unsigned __int8 freq_table[4][9]; // [sp+24h] [bp-1028h] BYREF
  char tmp42[4096]; // [sp+48h] [bp-1004h] BYREF

  memset(freq_table, 0, 12);
  every_chain_get_pic_version();
  g_scan_freq_info.scan_freq_store_pos = every_chain_read_pic_freq_data(freq_table);
  if ( g_scan_freq_info.scan_freq_store_pos > 0 )
  {
    chain_exist = dev.chain_exist;
    v1 = 0;
    v2 = dev.chain_exist;
    while ( 1 )
    {
      v3 = *v2++;
      if ( v3 == 1 && freq_table[v1][0] != 78 )
        break;
      if ( ++v1 == 4 )
      {
        for ( i = 0; i != 4; ++i )
        {
          v5 = *chain_exist++;
          if ( v5 == 1 )
          {
            v37 = chain_exist;
            v25 = 0;
            v26 = g_scan_freq_info.each_asic_freq[i];
            v27 = &freq_table[i][1];
            do
            {
              v28 = *v27++;
              v29 = v25 + 1;
              v30 = *(_DWORD *)&_FUNCTION___15596[16 * v28 + 2004];
              if ( use_syslog || opt_log_output || opt_log_level > 4 )
              {
                snprintf(tmp42, 0x1000u, "pic read chain%d asic%d freq %d\n", i, v25, v30);
                applog(5, tmp42, 0);
              }
              v25 = v29;
              if ( v30 - 775 > 0x32 )
                *v26 = 800;
              ++v26;
              if ( v30 - 775 <= 0x32 )
                *(v26 - 1) = v30;
            }
            while ( v29 != 3 );
            chain_exist = v37;
          }
        }
        if ( use_syslog || opt_log_output || opt_log_level > 4 )
        {
          v6 = (int *)&unk_59E9C;
          goto LABEL_11;
        }
        goto LABEL_12;
      }
    }
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      v12 = "1 Goto scan mode and find the best frequency\n";
      goto LABEL_17;
    }
    goto LABEL_18;
  }
  v31 = access("/config/chips_freq.config", 0);
  if ( !v31 )
  {
    v32 = fopen("/config/chips_freq.config", "r");
    if ( v32 )
    {
      v33 = dev.chain_exist;
      do
      {
        v34 = *v33++;
        if ( v34 == 1 )
        {
          v35 = 0;
          v36 = (uint32_t *)((char *)g_scan_freq_info.each_asic_freq[0] + v31);
          do
          {
            *(_DWORD *)tmp42 = 0;
            fscanf(v32, "%d", tmp42);
            if ( (unsigned int)(*(_DWORD *)tmp42 - 775) <= 0x32 )
            {
              if ( *(_DWORD *)tmp42 == 775 )
                *v36 = 775;
              else
                *v36 = *(_DWORD *)tmp42;
            }
            else
            {
              *v36 = 800;
            }
            ++v35;
            ++v36;
          }
          while ( v35 != 3 );
        }
        v31 += 12;
      }
      while ( v31 != 48 );
      fclose(v32);
    }
    else
    {
      if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
      {
LABEL_45:
        if ( opt_log_level <= 4 )
        {
LABEL_12:
          create_bitmain_turbo_mode_monitor_pthread();
          return;
        }
LABEL_46:
        v6 = (int *)&unk_59F0C;
LABEL_11:
        v7 = *v6;
        v8 = v6[1];
        v9 = v6[2];
        v10 = v6[3];
        v11 = v6[4];
        *(_DWORD *)tmp42 = v7;
        *(_DWORD *)&tmp42[4] = v8;
        *(_DWORD *)&tmp42[8] = v9;
        *(_DWORD *)&tmp42[12] = v10;
        *(_WORD *)&tmp42[16] = v11;
        tmp42[18] = BYTE2(v11);
        applog(5, tmp42, 0);
        goto LABEL_12;
      }
      snprintf(tmp42, 0x1000u, "open %s failed\n", "/config/chips_freq.config");
      applog(5, tmp42, 0);
    }
    if ( use_syslog || opt_log_output )
      goto LABEL_46;
    goto LABEL_45;
  }
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    v12 = "2 Goto scan mode and find the best frequency\n";
LABEL_17:
    v13 = *(_DWORD *)v12;
    v14 = *((_DWORD *)v12 + 1);
    v15 = *((_DWORD *)v12 + 2);
    v16 = *((_DWORD *)v12 + 3);
    v17 = (int *)(v12 + 16);
    *(_DWORD *)tmp42 = v13;
    *(_DWORD *)&tmp42[4] = v14;
    *(_DWORD *)&tmp42[8] = v15;
    *(_DWORD *)&tmp42[12] = v16;
    v18 = *v17;
    v19 = v17[1];
    v20 = v17[2];
    v21 = v17[3];
    v17 += 4;
    *(_DWORD *)&tmp42[16] = v18;
    *(_DWORD *)&tmp42[20] = v19;
    *(_DWORD *)&tmp42[24] = v20;
    *(_DWORD *)&tmp42[28] = v21;
    v22 = v17[1];
    v23 = v17[2];
    v24 = v17[3];
    *(_DWORD *)&tmp42[32] = *v17;
    *(_DWORD *)&tmp42[36] = v22;
    *(_DWORD *)&tmp42[40] = v23;
    *(_WORD *)&tmp42[44] = v24;
    applog(5, tmp42, 0);
  }
LABEL_18:
  create_bitmain_scan_freq_pthread();
}
