api_data *__fastcall bitmain_api_stats(cgpu_info *cgpu)
{
  uint32_t *v1; // r5
  char *v2; // r1
  api_data *v3; // r0
  char *v4; // r1
  api_data *v5; // r0
  char *v6; // r1
  const char *v7; // r7
  int v8; // r4
  api_data *v9; // r6
  api_data *v10; // r0
  char *v11; // r1
  const char *v12; // r6
  api_data *v13; // r5
  int i; // r4
  const char *v15; // r6
  int v16; // r4
  api_data *v17; // r0
  char *v18; // r1
  api_data *v19; // r4
  int64_t v20; // r0
  int32x2_t v21; // d8
  double v22; // d7
  char *v23; // r1
  const char *v24; // r6
  api_data *v25; // r0
  char *v26; // r1
  int v27; // r5
  api_data *v28; // r4
  char *v29; // r6
  int v30; // r5
  api_data *v31; // r0
  const char *v32; // r6
  int j; // r5
  int v34; // r6
  const char *v35; // r10
  const char *v36; // r9
  int v37; // r2
  char *v38; // r6
  const char *v39; // r7
  const char *v40; // r9
  int v41; // r5
  api_data *result; // r0
  double rateideal; // [sp+10h] [bp-101Ch] BYREF
  char chain_freq[16]; // [sp+18h] [bp-1014h] BYREF
  char chain_rate[4100]; // [sp+28h] [bp-1004h] BYREF

  rateideal = 200000.0;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(chain_rate, 0x1000u, "rateideal = %f\n", rateideal);
    applog(5, chain_rate, 0);
  }
  v1 = (_DWORD *)(&dev + 489);
  LOWORD(v2) = -32304;
  HIWORD(v2) = (unsigned int)"grality" >> 16;
  v3 = api_add_mhs(0, v2, &rateideal, 0);
  LOWORD(v4) = -32288;
  HIWORD(v4) = (unsigned int)"ndle" >> 16;
  v5 = api_add_uint8(v3, v4, &dev.chain_num, 0);
  LOWORD(v6) = -32276;
  HIWORD(v6) = (unsigned int)"andle" >> 16;
  LOWORD(v7) = -32268;
  v8 = 0;
  v9 = api_add_uint8(v5, v6, &dev.fan_num, 0);
  do
  {
    ++v8;
    HIWORD(v7) = (unsigned int)"reg_handle" >> 16;
    sprintf(chain_rate, v7, v8);
    v10 = api_add_uint32(v9, chain_rate, v1++, 0);
    v9 = v10;
  }
  while ( v8 != 6 );
  LOWORD(v11) = -32260;
  HIWORD(v11) = (unsigned int)"le" >> 16;
  LOWORD(v12) = -32248;
  v13 = api_add_uint8(v10, v11, &dev.chain_num, 0);
  for ( i = 0; i != 4; v13 = api_add_int16(v13, chain_rate, &dev.pfd[5].events + 2 * i, 0) )
  {
    ++i;
    HIWORD(v12) = (unsigned int)"le" >> 16;
    sprintf(chain_rate, v12, i);
  }
  LOWORD(v15) = -32240;
  v16 = 0;
  do
  {
    ++v16;
    HIWORD(v15) = (unsigned int)"asic_response" >> 16;
    sprintf(chain_rate, v15, v16);
    v17 = api_add_int16(v13, chain_rate, (int16_t *)&dev.max_local_temp[v16 + 3], 0);
    v13 = v17;
  }
  while ( v16 != 4 );
  LOWORD(v18) = -32228;
  HIWORD(v18) = (unsigned int)"e" >> 16;
  v19 = api_add_uint32(v17, v18, (uint32_t *)&dev.temp_top1, 0);
  total_diff1 = (__int64)(total_diff_accepted + total_diff_rejected + total_diff_stale);
  v20 = total_diff1 + hw_errors;
  if ( v20 )
  {
    v21.n64_u32[0] = hw_errors;
    v21.n64_u32[1] = hw_errors;
    v22 = vcvt_n_f64_s32(v21, 8u) / (double)v20;
  }
  else
  {
    v22 = 0.0;
  }
  LOWORD(v23) = 22740;
  hwp = v22;
  HIWORD(v23) = (unsigned int)"ailures" >> 16;
  LOWORD(v24) = -32196;
  v25 = api_add_percent(v19, v23, &hwp, 1);
  LOWORD(v26) = -32216;
  HIWORD(v26) = (unsigned int)&default_chip_freq >> 16;
  v27 = 0;
  v28 = api_add_int(v25, v26, &hw_errors, 1);
  do
  {
    ++v27;
    HIWORD(v24) = (unsigned int)"rateideal = %f\n" >> 16;
    sprintf(chain_rate, v24, v27);
    v28 = api_add_uint8(v28, chain_rate, (uint8_t *)&dev.temp[3] + v27 + 3, 0);
  }
  while ( v27 != 4 );
  v29 = (_BYTE *)(&dev + 355);
  v30 = 0;
  do
  {
    sprintf(chain_rate, "chain_acs%d", ++v30);
    v31 = api_add_string(v28, chain_rate, v29, 0);
    v29 += 19;
    v28 = v31;
  }
  while ( v30 != 4 );
  LOWORD(v32) = -32172;
  for ( j = 0; j != 4; v28 = api_add_uint32(v28, chain_rate, (uint32_t *)&dev.whether_read_out_temp[j + 3][3], 0) )
  {
    ++j;
    HIWORD(v32) = (unsigned int)"teideal" >> 16;
    sprintf(chain_rate, v32, j);
  }
  v34 = 0;
  LOWORD(v35) = -32160;
  LOWORD(v36) = 21504;
  do
  {
    HIWORD(v35) = (unsigned int)"r_count" >> 16;
    memset(chain_freq, 0, sizeof(chain_freq));
    memset(chain_rate, 0, 16);
    sprintf(chain_freq, v35, v34 + 1);
    HIWORD(v36) = (unsigned int)" sent %d of remaining %d (sendc=%d)" >> 16;
    v37 = dev.freq[v34++];
    sprintf(chain_rate, v36, v37);
    v28 = api_add_uint16(v28, chain_freq, (uint16_t *)&dev.frequency_t[2 * v34 + 8], 0);
  }
  while ( v34 != 4 );
  v38 = displayed_rate;
  LOWORD(v39) = -32148;
  LOWORD(v40) = -32132;
  v41 = 0;
  do
  {
    ++v41;
    HIWORD(v39) = (unsigned int)"num" >> 16;
    sprintf(chain_rate, v39, v41);
    if ( certification_firmware )
    {
      HIWORD(v40) = (unsigned int)"_num" >> 16;
      sprintf(v38, v40, rt_hashrate_total / (double)rt_chain_num);
    }
    result = api_add_string(v28, chain_rate, v38, 0);
    v38 += 16;
    v28 = result;
  }
  while ( v41 != 4 );
  return result;
}
