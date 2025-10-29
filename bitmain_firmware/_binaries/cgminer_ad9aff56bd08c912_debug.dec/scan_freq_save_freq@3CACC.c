int scan_freq_save_freq()
{
  uint8_t *chain_exist; // r7
  int v1; // r4
  int v2; // t1
  int v4; // r6
  uint32_t *v5; // r5
  unsigned __int8 *v6; // r8
  int v7; // r0
  int v8; // t1
  freq_pll_str *v9; // r2
  int freq; // r1
  int v11; // r3
  int v12; // t1
  const char *v13; // r1
  const char *v14; // r0
  FILE *v15; // r8
  uint8_t *v16; // r6
  const char *v17; // r10
  int i; // r5
  int v19; // t1
  uint32_t *v20; // r9
  int v21; // r7
  uint32_t v22; // t1
  int v23; // r3
  const char *v24; // r2
  unsigned __int8 buf[4][9]; // [sp+1Ch] [bp-1028h] BYREF
  char tmp42[4100]; // [sp+40h] [bp-1004h] BYREF

  if ( g_scan_freq_info.scan_freq_store_pos > 0 )
  {
    chain_exist = dev.chain_exist;
    v1 = 0;
    memset(buf, 0, sizeof(buf));
    while ( 1 )
    {
      v2 = *chain_exist++;
      if ( v2 != 1 )
        goto LABEL_4;
      v4 = 0;
      v5 = g_scan_freq_info.each_asic_freq[v1];
      v6 = buf[v1];
      *v6 = 78;
      do
      {
        if ( use_syslog || opt_log_output || opt_log_level > 4 )
        {
          snprintf(tmp42, 0x1000u, "pic write chain%d asic%d freq %d\n", v1, v4, *v5);
          applog(5, tmp42, 0);
          v12 = *v5++;
          v7 = v12;
          if ( v12 == 100 )
          {
LABEL_18:
            LOBYTE(v11) = 0;
            goto LABEL_15;
          }
        }
        else
        {
          v8 = *v5++;
          v7 = v8;
          if ( v8 == 100 )
            goto LABEL_18;
        }
        v9 = freq_pll;
        freq = 125;
        v11 = 1;
        while ( 1 )
        {
          ++v9;
          if ( v7 == freq )
            break;
          if ( ++v11 == 119 )
          {
            LOBYTE(v11) = -1;
            break;
          }
          freq = v9[1].freq;
        }
LABEL_15:
        ++v4;
        *++v6 = v11;
      }
      while ( v4 != 3 );
      xxtea_encode((uint32_t *)&buf[v1][1], 2, sec_key[v1]);
LABEL_4:
      if ( ++v1 == 4 )
      {
        every_chain_write_freq_to_pic(buf);
        return 0;
      }
    }
  }
  LOWORD(v13) = -24640;
  LOWORD(v14) = -24788;
  HIWORD(v13) = (unsigned int)"g" >> 16;
  HIWORD(v14) = (unsigned int)"adopt file mode\n" >> 16;
  v15 = fopen(v14, v13);
  if ( v15 )
  {
    v16 = dev.chain_exist;
    LOWORD(v17) = -24616;
    for ( i = 0; i != 4; ++i )
    {
      v19 = *v16++;
      if ( v19 == 1 )
      {
        v20 = &g_scan_freq_info.each_asic_max_freq[i + 3][2];
        v21 = 3;
        do
        {
          v22 = v20[1];
          ++v20;
          HIWORD(v17) = (unsigned int)" find the best frequency\n" >> 16;
          fprintf(v15, v17, v22);
          --v21;
        }
        while ( v21 );
      }
    }
    fclose(v15);
    return 0;
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v23) = -24788;
    LOWORD(v24) = -24636;
    HIWORD(v23) = (unsigned int)"adopt file mode\n" >> 16;
    HIWORD(v24) = (unsigned int)"2 Goto scan mode and find the best frequency\n" >> 16;
    snprintf(tmp42, 0x1000u, v24, "scan_freq_save_freq", v23);
    applog(5, tmp42, 0);
    return -1;
  }
  else
  {
    return -1;
  }
}
