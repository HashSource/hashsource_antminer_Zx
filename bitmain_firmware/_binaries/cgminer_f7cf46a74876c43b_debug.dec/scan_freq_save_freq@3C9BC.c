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
  FILE *v13; // r8
  uint8_t *v14; // r6
  int i; // r5
  int v16; // t1
  uint32_t *v17; // r9
  int v18; // r7
  uint32_t v19; // t1
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
  v13 = fopen("/config/chips_freq.config", "w+");
  if ( v13 )
  {
    v14 = dev.chain_exist;
    for ( i = 0; i != 4; ++i )
    {
      v16 = *v14++;
      if ( v16 == 1 )
      {
        v17 = &g_scan_freq_info.each_asic_max_freq[i + 3][2];
        v18 = 3;
        do
        {
          v19 = v17[1];
          ++v17;
          fprintf(v13, "%d ", v19);
          --v18;
        }
        while ( v18 );
      }
    }
    fclose(v13);
    return 0;
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "%s open %s failed\n", "scan_freq_save_freq", "/config/chips_freq.config");
    applog(5, tmp42, 0);
    return -1;
  }
  else
  {
    return -1;
  }
}
