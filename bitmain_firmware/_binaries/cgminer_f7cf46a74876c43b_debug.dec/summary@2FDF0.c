void __fastcall summary(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r9
  char *v7; // r1
  const char *v8; // r2
  int v9; // r3
  double v10; // d7
  double v11; // d9
  api_data *v12; // r0
  api_data *v13; // r0
  api_data *v14; // r0
  api_data *v15; // r0
  api_data *v16; // r0
  api_data *v17; // r0
  api_data *v18; // r0
  api_data *v19; // r0
  api_data *v20; // r0
  api_data *v21; // r0
  api_data *v22; // r0
  api_data *v23; // r0
  api_data *v24; // r0
  api_data *v25; // r0
  api_data *v26; // r0
  api_data *v27; // r0
  api_data *v28; // r0
  api_data *v29; // r0
  api_data *v30; // r0
  api_data *v31; // r0
  api_data *v32; // r0
  int64_t v33; // r10
  double v34; // d7
  api_data *v35; // r4
  double v36; // d7
  api_data *v37; // r0
  double v38; // d7
  double v39; // d5
  api_data *v40; // r0
  double v41; // d7
  double v42; // d5
  api_data *v43; // r0
  api_data *v44; // r4
  const char *v45; // r2
  int v46; // r3
  time_t v47; // r0
  int v48; // r4
  int v49; // r0
  int v50; // r10
  int v51; // r10
  int v52; // r4
  time_t v53; // r0
  double v54; // d5
  int v55; // r0
  int v56; // r3
  _BOOL4 io_open; // [sp+8h] [bp-44h]
  double utility; // [sp+10h] [bp-3Ch] BYREF
  double ghs; // [sp+18h] [bp-34h] BYREF
  double work_utility; // [sp+20h] [bp-2Ch] BYREF
  double hwp; // [sp+28h] [bp-24h] BYREF
  double rejp; // [sp+30h] [bp-1Ch] BYREF
  double prejp; // [sp+38h] [bp-14h] BYREF
  double stalep; // [sp+40h] [bp-Ch] BYREF

  v5 = isjson;
  message(io_data, 11, 0, 0, isjson);
  v7 = "SUMMARY,";
  if ( v5 )
    v7 = ",\"SUMMARY\":[";
  io_open = io_add(io_data, v7);
  if ( pthread_mutex_lock(&hash_lock) )
    mutex_lock_1((pthread_mutex_t *)&_func___11888, (const char *)0xAE9, v8, v9);
  total_diff1 = (__int64)(total_diff_accepted + total_diff_rejected + total_diff_stale);
  v10 = (double)total_accepted;
  if ( total_secs == 0.0 )
  {
    v11 = 1.0;
  }
  else
  {
    v10 = (double)total_accepted / total_secs;
    v11 = total_secs;
  }
  utility = v10 * 60.0;
  ghs = total_mhashes_done / total_secs;
  work_utility = (double)(__int64)(total_diff_accepted + total_diff_rejected + total_diff_stale) / v11 * 60.0;
  if ( certification_firmware )
  {
    v47 = time(0);
    srand(v47);
    if ( *cert_devname == 122 && cert_devname[1] == 57 && !cert_devname[2] )
    {
      v48 = 14 * rt_chain_num;
    }
    else
    {
      v52 = 4;
      v51 = 14;
      if ( strcmp(cert_devname, "z9-mini") )
      {
LABEL_31:
        v53 = time(0);
        srand(v53);
        v54 = (double)(rand() % 99) / 100.0;
        rt_hashrate_total = (double)v51 + v54;
        utility = (double)v52 + v54;
        ghs = (double)v51 + v54;
        v55 = rand();
        v56 = v55 & 3;
        if ( v55 <= 0 )
          v56 = -(-v55 & 3);
        work_utility = (double)(v56 + 100) + 0.27;
        sprintf(displayed_hash_rate, "%f", (double)v51 + v54 + 0.79);
        goto LABEL_7;
      }
      v48 = 3 * rt_chain_num + 1;
    }
    v49 = rand();
    v50 = v49 & 1;
    if ( v49 < 0 )
      v50 = -v50;
    v51 = v50 + v48;
    v52 = v51 % 5;
    goto LABEL_31;
  }
LABEL_7:
  v12 = api_add_data_full(0, "Elapsed", api_data_type::API_ELAPSED, &total_secs, 1);
  v13 = api_add_data_full(v12, "GHS 5s", api_data_type::API_STRING, displayed_hash_rate, 0);
  v14 = api_add_data_full(v13, "GHS av", api_data_type::API_MHS, &ghs, 0);
  v15 = api_add_data_full(v14, "Found Blocks", api_data_type::API_UINT, &found_blocks, 1);
  v16 = api_add_data_full(v15, "Getworks", api_data_type::API_INT64, &total_getworks, 1);
  v17 = api_add_data_full(v16, "Accepted", api_data_type::API_INT64, &total_accepted, 1);
  v18 = api_add_data_full(v17, "Rejected", api_data_type::API_INT64, &total_rejected, 1);
  v19 = api_add_data_full(v18, "Hardware Errors", api_data_type::API_INT, &hw_errors, 1);
  v20 = api_add_data_full(v19, "Utility", api_data_type::API_UTILITY, &utility, 0);
  v21 = api_add_data_full(v20, "Discarded", api_data_type::API_INT64, &total_discarded, 1);
  v22 = api_add_data_full(v21, "Stale", api_data_type::API_INT64, &total_stale, 1);
  v23 = api_add_data_full(v22, "Get Failures", api_data_type::API_UINT, &total_go, 1);
  v24 = api_add_data_full(v23, "Local Work", api_data_type::API_UINT, &local_work, 1);
  v25 = api_add_data_full(v24, "Remote Failures", api_data_type::API_UINT, &total_ro, 1);
  v26 = api_add_data_full(v25, "Network Blocks", api_data_type::API_UINT, &new_blocks, 1);
  v27 = api_add_data_full(v26, "Total MH", api_data_type::API_MHTOTAL, &total_mhashes_done, 1);
  v28 = api_add_data_full(v27, "Work Utility", api_data_type::API_UTILITY, &work_utility, 0);
  v29 = api_add_data_full(v28, "Difficulty Accepted", api_data_type::API_DIFF, &total_diff_accepted, 1);
  v30 = api_add_data_full(v29, "Difficulty Rejected", api_data_type::API_DIFF, &total_diff_rejected, 1);
  v31 = api_add_data_full(v30, "Difficulty Stale", api_data_type::API_DIFF, &total_diff_stale, 1);
  v32 = api_add_data_full(v31, "Best Share", api_data_type::API_UINT64, &best_diff, 1);
  v33 = total_diff1 + hw_errors;
  if ( v33 )
    v34 = (double)hw_errors / (double)v33;
  else
    v34 = 0.0;
  hwp = v34;
  v35 = api_add_data_full(v32, "Device Hardware%", api_data_type::API_PERCENT, &hwp, 0);
  if ( total_diff1 )
    v36 = total_diff_rejected / (double)total_diff1;
  else
    v36 = 0.0;
  rejp = v36;
  v37 = api_add_data_full(v35, "Device Rejected%", api_data_type::API_PERCENT, &rejp, 0);
  v38 = total_diff_rejected + total_diff_accepted + total_diff_stale;
  if ( v38 == 0.0 )
    v39 = 0.0;
  else
    v39 = total_diff_rejected / v38;
  prejp = v39;
  v40 = api_add_data_full(v37, "Pool Rejected%", api_data_type::API_PERCENT, &prejp, 0);
  v41 = total_diff_accepted + total_diff_rejected + total_diff_stale;
  if ( v41 == 0.0 )
    v42 = 0.0;
  else
    v42 = total_diff_stale / v41;
  stalep = v42;
  v43 = api_add_data_full(v40, "Pool Stale%", api_data_type::API_PERCENT, &stalep, 0);
  v44 = api_add_data_full(v43, "Last getwork", api_data_type::API_TIME, &last_getwork, 0);
  if ( pthread_mutex_unlock(&hash_lock) )
    mutex_unlock_noyield_1((pthread_mutex_t *)&_func___11888, (const char *)0xB2E, v45, v46);
  selective_yield();
  print_data(io_data, v44, v5, 0);
  if ( v5 && io_open )
    io_data->close = 1;
}
