void calculate_hash_rate()
{
  uint64_t *v0; // r9
  uint8_t *chain_exist; // r11
  int v2; // r4
  int v4; // r5
  _BOOL4 v5; // r7
  int v6; // r6
  unsigned int v7; // r5
  unsigned int v8; // r3
  char *v9; // r2
  unsigned int v10; // r6
  int i; // r5
  unsigned int v12; // r3
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
              if ( !g_HASH_RATE_reg_value_from_which_asic[v2][0]
                && !status_error
                && opt_debug
                && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                snprintf(
                  tmp42,
                  0x1000u,
                  "%s: Chain%d ASIC%d didn't send back HASH_RATE register value",
                  "calculate_hash_rate",
                  v2,
                  i);
                applog(7, tmp42, 0);
              }
            }
            v12 = (unsigned __int8)(rate_error[v2] + 1);
            rate_error[v2] = v12;
            if ( v12 > 3 || status_error )
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
              v6 = 0;
              tmp_rate = 0;
              do
              {
                v7 = g_HASH_RATE_reg_value[v2][v6] & 0x7FFFFFFF;
                tmp_rate += v7;
                if ( v5 && (use_syslog || opt_log_output || opt_log_level > 6) )
                {
                  snprintf(
                    tmp42,
                    0x1000u,
                    "%s: RT g_HASH_RATE_reg_value[%d][%d] = 0x%08x",
                    "calculate_hash_rate",
                    v2,
                    v6,
                    v7);
                  applog(7, tmp42, 0);
                  v5 = opt_debug;
                }
                ++v6;
              }
              while ( v6 != 3 );
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
              tmp_ratea = 0;
              do
              {
                v10 = g_HASH_RATE_reg_value[v2][v4] & 0x7FFFFFFF;
                tmp_ratea += v10;
                if ( v5 && (use_syslog || opt_log_output || opt_log_level > 6) )
                {
                  snprintf(
                    tmp42,
                    0x1000u,
                    "%s: avg g_HASH_RATE_reg_value[%d][%d] = 0x%08x",
                    "calculate_hash_rate",
                    v2,
                    v4,
                    v10);
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
        v8 = (unsigned __int8)(rate_error[v2] + 1);
        rate_error[v2] = v8;
        if ( v8 > 3 || status_error )
          break;
      }
LABEL_19:
      ++v2;
      ++v0;
      if ( v2 == 4 )
        goto LABEL_20;
    }
    v9 = &displayed_rate[16 * v2++];
    *v0 = 0;
    suffix_string_ZCASH(0, v9, 0x10u, 6, 1);
    ++v0;
  }
  while ( v2 != 4 );
LABEL_20:
  suffix_string_ZCASH(tmp_rt_rate_all_chain_low4, displayed_hash_rate, 0x10u, 6, 0);
}
