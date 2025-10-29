api_data *__fastcall bitmain_api_stats(cgpu_info *cgpu)
{
  uint32_t *v1; // r5
  api_data *v2; // r0
  api_data *v3; // r0
  int v4; // r4
  api_data *v5; // r6
  api_data *v6; // r0
  api_data *v7; // r5
  int i; // r4
  int v9; // r4
  api_data *v10; // r0
  api_data *v11; // r4
  int64_t v12; // r0
  int32x2_t v13; // d8
  double v14; // d7
  api_data *v15; // r0
  int v16; // r5
  api_data *v17; // r4
  char *v18; // r6
  int v19; // r5
  api_data *v20; // r0
  int j; // r5
  int k; // r6
  int v23; // r2
  char *v24; // r6
  int v25; // r5
  api_data *result; // r0
  double rateideal; // [sp+10h] [bp-101Ch] BYREF
  char chain_freq[16]; // [sp+18h] [bp-1014h] BYREF
  char chain_rate[4100]; // [sp+28h] [bp-1004h] BYREF

  rateideal = 320000.0;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(chain_rate, 0x1000u, "rateideal = %f\n", rateideal);
    applog(5, chain_rate, 0);
  }
  v1 = (_DWORD *)(&dev + 489);
  v2 = api_add_mhs(0, "total_rateideal", &rateideal, 0);
  v3 = api_add_uint8(v2, "miner_count", &dev.chain_num, 0);
  v4 = 0;
  v5 = api_add_uint8(v3, "fan_num", &dev.fan_num, 0);
  do
  {
    sprintf(chain_rate, "fan%d", ++v4);
    v6 = api_add_uint32(v5, chain_rate, v1++, 0);
    v5 = v6;
  }
  while ( v4 != 6 );
  v7 = api_add_uint8(v6, "temp_num", &dev.chain_num, 0);
  for ( i = 0; i != 4; v7 = api_add_int16(v7, chain_rate, &dev.pfd[5].events + 2 * i, 0) )
    sprintf(chain_rate, "temp%d", ++i);
  v9 = 0;
  do
  {
    sprintf(chain_rate, "temp2_%d", ++v9);
    v10 = api_add_int16(v7, chain_rate, (int16_t *)&dev.max_local_temp[v9 + 3], 0);
    v7 = v10;
  }
  while ( v9 != 4 );
  v11 = api_add_uint32(v10, "temp_max", (uint32_t *)&dev.temp_top1, 0);
  total_diff1 = (__int64)(total_diff_accepted + total_diff_rejected + total_diff_stale);
  v12 = total_diff1 + hw_errors;
  if ( v12 )
  {
    v13.n64_u32[0] = hw_errors;
    v13.n64_u32[1] = hw_errors;
    v14 = vcvt_n_f64_s32(v13, 8u) / (double)v12;
  }
  else
  {
    v14 = 0.0;
  }
  hwp = v14;
  v15 = api_add_percent(v11, "Device Hardware%", &hwp, 1);
  v16 = 0;
  v17 = api_add_int(v15, "no_matching_work", &hw_errors, 1);
  do
  {
    sprintf(chain_rate, "chain_acn%d", ++v16);
    v17 = api_add_uint8(v17, chain_rate, (uint8_t *)&dev.temp[3] + v16 + 3, 0);
  }
  while ( v16 != 4 );
  v18 = (_BYTE *)(&dev + 355);
  v19 = 0;
  do
  {
    sprintf(chain_rate, "chain_acs%d", ++v19);
    v20 = api_add_string(v17, chain_rate, v18, 0);
    v18 += 19;
    v17 = v20;
  }
  while ( v19 != 4 );
  for ( j = 0; j != 4; v17 = api_add_uint32(v17, chain_rate, (uint32_t *)&dev.whether_read_out_temp[j + 3][3], 0) )
    sprintf(chain_rate, "chain_hw%d", ++j);
  for ( k = 0; k != 4; v17 = api_add_uint16(v17, chain_freq, (uint16_t *)&dev.frequency_t[2 * k + 8], 0) )
  {
    memset(chain_freq, 0, sizeof(chain_freq));
    memset(chain_rate, 0, 16);
    sprintf(chain_freq, "frequency%d", k + 1);
    v23 = dev.freq[k++];
    sprintf(chain_rate, "%u", v23);
  }
  v24 = displayed_rate;
  v25 = 0;
  do
  {
    sprintf(chain_rate, "chain_rate%d", ++v25);
    if ( certification_firmware )
      sprintf(v24, "%2.2f", rt_hashrate_total / (double)rt_chain_num);
    result = api_add_string(v17, chain_rate, v24, 0);
    v24 += 16;
    v17 = result;
  }
  while ( v25 != 4 );
  return result;
}
