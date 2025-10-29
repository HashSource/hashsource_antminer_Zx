void scan_freq_init_freq()
{
  uint8_t *chain_exist; // r6
  int v1; // r1
  uint8_t *v2; // r3
  int v3; // t1
  int v4; // r10
  int i; // r4
  int v6; // t1
  int *v7; // r5
  int v8; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r5
  const char *v13; // r5
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int *v18; // r5
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r1
  int v24; // r2
  int v25; // r3
  int v26; // r12
  uint32_t *v27; // r5
  unsigned __int8 *v28; // r9
  int v29; // t1
  int v30; // r8
  uint32_t v31; // r6
  const char *v32; // r0
  int v33; // r4
  const char *v34; // r1
  const char *v35; // r0
  FILE *v36; // r8
  uint8_t *v37; // r7
  int v38; // t1
  int v39; // r5
  _DWORD *v40; // r6
  int v41; // r3
  const char *v42; // r2
  uint8_t *v43; // [sp+1Ch] [bp-1030h]
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
        LOWORD(v4) = 28216;
        for ( i = 0; i != 4; ++i )
        {
          v6 = *chain_exist++;
          if ( v6 == 1 )
          {
            v43 = chain_exist;
            v26 = 0;
            v27 = g_scan_freq_info.each_asic_freq[i];
            v28 = &freq_table[i][1];
            do
            {
              v29 = *v28++;
              v30 = v26 + 1;
              HIWORD(v4) = (unsigned int)"s %s():%d" >> 16;
              v31 = *(_DWORD *)(v4 + 16 * v29 + 2004);
              if ( use_syslog || opt_log_output || opt_log_level > 4 )
              {
                snprintf(tmp42, 0x1000u, "pic read chain%d asic%d freq %d\n", i, v26, v31);
                applog(5, tmp42, 0);
              }
              v26 = v30;
              if ( v31 - 775 > 0x32 )
                *v27 = 800;
              ++v27;
              if ( v31 - 775 <= 0x32 )
                *(v27 - 1) = v31;
            }
            while ( v30 != 3 );
            chain_exist = v43;
          }
        }
        if ( use_syslog || opt_log_output || opt_log_level > 4 )
        {
          v7 = (int *)&unk_59F18;
          goto LABEL_11;
        }
        goto LABEL_12;
      }
    }
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      v13 = "1 Goto scan mode and find the best frequency\n";
      goto LABEL_17;
    }
    goto LABEL_18;
  }
  LOWORD(v32) = -24788;
  HIWORD(v32) = (unsigned int)"adopt file mode\n" >> 16;
  v33 = access(v32, 0);
  if ( !v33 )
  {
    LOWORD(v34) = -23732;
    LOWORD(v35) = -24788;
    HIWORD(v34) = (unsigned int)"d has %d ASIC" >> 16;
    HIWORD(v35) = (unsigned int)"adopt file mode\n" >> 16;
    v36 = fopen(v35, v34);
    if ( v36 )
    {
      v37 = dev.chain_exist;
      do
      {
        v38 = *v37++;
        if ( v38 == 1 )
        {
          v39 = 0;
          v40 = (uint32_t *)((char *)g_scan_freq_info.each_asic_freq[0] + v33);
          do
          {
            *(_DWORD *)tmp42 = 0;
            fscanf(v36, "%d", tmp42);
            if ( (unsigned int)(*(_DWORD *)tmp42 - 775) <= 0x32 )
            {
              if ( *(_DWORD *)tmp42 == 775 )
                *v40 = 775;
              else
                *v40 = *(_DWORD *)tmp42;
            }
            else
            {
              *v40 = 800;
            }
            ++v39;
            ++v40;
          }
          while ( v39 != 3 );
        }
        v33 += 12;
      }
      while ( v33 != 48 );
      fclose(v36);
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
        v7 = (int *)&unk_59F88;
LABEL_11:
        v8 = *v7;
        v9 = v7[1];
        v10 = v7[2];
        v11 = v7[3];
        v12 = v7[4];
        *(_DWORD *)tmp42 = v8;
        *(_DWORD *)&tmp42[4] = v9;
        *(_DWORD *)&tmp42[8] = v10;
        *(_DWORD *)&tmp42[12] = v11;
        *(_WORD *)&tmp42[16] = v12;
        tmp42[18] = BYTE2(v12);
        applog(5, tmp42, 0);
        goto LABEL_12;
      }
      LOWORD(v41) = -24788;
      LOWORD(v42) = -24712;
      HIWORD(v41) = (unsigned int)"adopt file mode\n" >> 16;
      HIWORD(v42) = (unsigned int)" chain%d asic%d freq %d\n" >> 16;
      snprintf(tmp42, 0x1000u, v42, v41);
      applog(5, tmp42, 0);
    }
    if ( use_syslog || opt_log_output )
      goto LABEL_46;
    goto LABEL_45;
  }
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    v13 = "2 Goto scan mode and find the best frequency\n";
LABEL_17:
    v14 = *(_DWORD *)v13;
    v15 = *((_DWORD *)v13 + 1);
    v16 = *((_DWORD *)v13 + 2);
    v17 = *((_DWORD *)v13 + 3);
    v18 = (int *)(v13 + 16);
    *(_DWORD *)tmp42 = v14;
    *(_DWORD *)&tmp42[4] = v15;
    *(_DWORD *)&tmp42[8] = v16;
    *(_DWORD *)&tmp42[12] = v17;
    v19 = *v18;
    v20 = v18[1];
    v21 = v18[2];
    v22 = v18[3];
    v18 += 4;
    *(_DWORD *)&tmp42[16] = v19;
    *(_DWORD *)&tmp42[20] = v20;
    *(_DWORD *)&tmp42[24] = v21;
    *(_DWORD *)&tmp42[28] = v22;
    v23 = v18[1];
    v24 = v18[2];
    v25 = v18[3];
    *(_DWORD *)&tmp42[32] = *v18;
    *(_DWORD *)&tmp42[36] = v23;
    *(_DWORD *)&tmp42[40] = v24;
    *(_WORD *)&tmp42[44] = v25;
    applog(5, tmp42, 0);
  }
LABEL_18:
  create_bitmain_scan_freq_pthread();
}
