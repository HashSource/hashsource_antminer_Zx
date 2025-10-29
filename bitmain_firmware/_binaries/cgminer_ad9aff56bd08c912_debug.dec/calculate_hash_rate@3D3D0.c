void calculate_hash_rate()
{
  uint64_t *v0; // r9
  uint8_t *chain_exist; // r11
  int v2; // r4
  int v4; // r5
  _BOOL4 v5; // r7
  const char *v6; // r10
  int v7; // r6
  unsigned int v8; // r5
  unsigned int v9; // r3
  char *v10; // r2
  const char *v11; // r10
  unsigned int v12; // r6
  int i; // r5
  const char *v14; // r2
  unsigned int v15; // r3
  uint64_t tmp_rate; // [sp+10h] [bp-102Ch]
  uint64_t tmp_ratea; // [sp+10h] [bp-102Ch]
  uint64_t tmp_rt_rate_all_chain_low4; // [sp+1Ch] [bp-1020h]
  char tmp42[4100]; // [sp+38h] [bp-1004h] BYREF

  v0 = rate;
  chain_exist = dev.chain_exist;
  v2 = 0;
  tmp_rt_rate_all_chain_low4 = 0;
  do
  {
    while ( 1 )
    {
      if ( *chain_exist++ )
      {
        if ( g_HASH_RATE_reg_value_num[v2] )
        {
          if ( g_HASH_RATE_reg_value_num[v2] <= 2u )
          {
            for ( i = 0; i != 3; ++i )
            {
              if ( !g_HASH_RATE_reg_value_from_which_asic[v2][0] && !status_error )
              {
                LOWORD(v14) = -24400;
                if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                {
                  HIWORD(v14) = (unsigned int)"ne, avg freq %d max %d, reboot cgminer\n" >> 16;
                  snprintf(tmp42, 0x1000u, v14, "calculate_hash_rate", v2, i);
                  applog(7, tmp42, 0);
                }
              }
            }
            v15 = (unsigned __int8)(rate_error[v2] + 1);
            rate_error[v2] = v15;
            if ( v15 > 3 || status_error )
            {
              *v0 = 0;
              suffix_string_ZCASH(0, &displayed_rate[16 * v2], 0x10u, 6, 1);
            }
          }
          else
          {
            v4 = is_rt;
            v5 = opt_debug;
            if ( is_rt )
            {
              LOWORD(v6) = -24336;
              v7 = 0;
              tmp_rate = 0;
              do
              {
                v8 = g_HASH_RATE_reg_value[v2][v7] & 0x7FFFFFFF;
                tmp_rate += v8;
                if ( v5 && (use_syslog || opt_log_output || opt_log_level > 6) )
                {
                  HIWORD(v6) = (unsigned int)"%*.*f" >> 16;
                  snprintf(tmp42, 0x1000u, v6, "calculate_hash_rate", v2, v7, v8);
                  applog(7, tmp42, 0);
                  v5 = opt_debug;
                }
                ++v7;
              }
              while ( v7 != 3 );
              if ( v5 && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                snprintf(
                  tmp42,
                  0x1000u,
                  "%s: chain%d RT hash rate is %0.2fGHz/s",
                  "calculate_hash_rate",
                  v2,
                  (double)tmp_rate / 1000000.0);
                applog(7, tmp42, 0);
              }
              *v0 = 1000000 * tmp_rate;
              rate_error[v2] = 0;
              suffix_string_ZCASH(1000000 * tmp_rate, &displayed_rate[16 * v2], 0x10u, 6, 0);
            }
            else
            {
              LOWORD(v11) = -24248;
              tmp_ratea = 0;
              do
              {
                v12 = g_HASH_RATE_reg_value[v2][v4] & 0x7FFFFFFF;
                tmp_ratea += v12;
                if ( v5 && (use_syslog || opt_log_output || opt_log_level > 6) )
                {
                  HIWORD(v11) = (unsigned int)"TE_reg_value[%d][%d] = 0x%08x" >> 16;
                  snprintf(tmp42, 0x1000u, v11, "calculate_hash_rate", v2, v4, v12);
                  applog(7, tmp42, 0);
                  v5 = opt_debug;
                }
                ++v4;
              }
              while ( v4 != 3 );
              if ( v5 && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                snprintf(
                  tmp42,
                  0x1000u,
                  "%s: chain%d avg hash rate is %0.2fGHz/s",
                  "calculate_hash_rate",
                  v2,
                  (double)tmp_ratea / 1000000.0);
                applog(7, tmp42, 0);
              }
              rate_error[v2] = 0;
            }
          }
          tmp_rt_rate_all_chain_low4 += *v0;
          goto LABEL_19;
        }
        v9 = (unsigned __int8)(rate_error[v2] + 1);
        rate_error[v2] = v9;
        if ( v9 > 3 || status_error )
          break;
      }
LABEL_19:
      ++v2;
      ++v0;
      if ( v2 == 4 )
        goto LABEL_20;
    }
    v10 = &displayed_rate[16 * v2++];
    *v0 = 0;
    suffix_string_ZCASH(0, v10, 0x10u, 6, 1);
    ++v0;
  }
  while ( v2 != 4 );
LABEL_20:
  suffix_string_ZCASH(tmp_rt_rate_all_chain_low4, displayed_hash_rate, 0x10u, 6, 0);
}
