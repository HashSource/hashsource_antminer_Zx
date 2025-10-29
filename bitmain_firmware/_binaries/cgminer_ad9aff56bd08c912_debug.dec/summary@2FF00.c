void __fastcall summary(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r9
  char *v7; // r1
  const char *v8; // r2
  int v9; // r3
  double v10; // d7
  double v11; // d9
  char *v12; // r1
  api_data *v13; // r0
  char *v14; // r1
  api_data *v15; // r0
  char *v16; // r1
  api_data *v17; // r0
  char *v18; // r1
  api_data *v19; // r0
  char *v20; // r1
  api_data *v21; // r0
  char *v22; // r1
  api_data *v23; // r0
  char *v24; // r1
  api_data *v25; // r0
  char *v26; // r1
  api_data *v27; // r0
  char *v28; // r1
  api_data *v29; // r0
  char *v30; // r1
  api_data *v31; // r0
  char *v32; // r1
  api_data *v33; // r0
  char *v34; // r1
  api_data *v35; // r0
  char *v36; // r1
  api_data *v37; // r0
  char *v38; // r1
  api_data *v39; // r0
  char *v40; // r1
  api_data *v41; // r0
  char *v42; // r1
  api_data *v43; // r0
  char *v44; // r1
  api_data *v45; // r0
  char *v46; // r1
  api_data *v47; // r0
  char *v48; // r1
  api_data *v49; // r0
  char *v50; // r1
  api_data *v51; // r0
  char *v52; // r1
  api_data *v53; // r0
  int64_t v54; // r10
  double v55; // d7
  char *v56; // r1
  api_data *v57; // r4
  double v58; // d7
  char *v59; // r1
  api_data *v60; // r0
  double v61; // d7
  double v62; // d5
  char *v63; // r1
  api_data *v64; // r0
  double v65; // d7
  double v66; // d5
  char *v67; // r1
  api_data *v68; // r0
  char *v69; // r1
  api_data *v70; // r4
  const char *v71; // r2
  int v72; // r3
  time_t v73; // r0
  int v74; // r4
  int v75; // r0
  int v76; // r10
  int v77; // r10
  int v78; // r4
  time_t v79; // r0
  double v80; // d5
  int v81; // r0
  int v82; // r3
  const char *v83; // r1
  const char *v84; // r1
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
  LOWORD(v7) = 22476;
  HIWORD(v7) = (unsigned int)"" >> 16;
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
    v73 = time(0);
    srand(v73);
    if ( *cert_devname == 122 && cert_devname[1] == 57 && !cert_devname[2] )
    {
      v74 = 14 * rt_chain_num;
    }
    else
    {
      LOWORD(v84) = 22488;
      v78 = 4;
      HIWORD(v84) = (unsigned int)"[" >> 16;
      v77 = 14;
      if ( strcmp(cert_devname, v84) )
      {
LABEL_31:
        v79 = time(0);
        srand(v79);
        v80 = (double)(rand() % 99) / 100.0;
        rt_hashrate_total = (double)v77 + v80;
        utility = (double)v78 + v80;
        ghs = (double)v77 + v80;
        v81 = rand();
        v82 = v81 & 3;
        if ( v81 <= 0 )
          v82 = -(-v81 & 3);
        LOWORD(v83) = 21516;
        HIWORD(v83) = (unsigned int)"remaining %d (sendc=%d)" >> 16;
        work_utility = (double)(v82 + 100) + 0.27;
        sprintf(displayed_hash_rate, v83, (double)v77 + v80 + 0.79);
        goto LABEL_7;
      }
      v74 = 3 * rt_chain_num + 1;
    }
    v75 = rand();
    v76 = v75 & 1;
    if ( v75 < 0 )
      v76 = -v76;
    v77 = v76 + v74;
    v78 = v77 % 5;
    goto LABEL_31;
  }
LABEL_7:
  LOWORD(v12) = 22288;
  HIWORD(v12) = (unsigned int)"" >> 16;
  v13 = api_add_data_full(0, v12, api_data_type::API_ELAPSED, &total_secs, 1);
  LOWORD(v14) = 22320;
  HIWORD(v14) = (unsigned int)"ime" >> 16;
  v15 = api_add_data_full(v13, v14, api_data_type::API_STRING, displayed_hash_rate, 0);
  LOWORD(v16) = 22328;
  HIWORD(v16) = (unsigned int)"" >> 16;
  v17 = api_add_data_full(v15, v16, api_data_type::API_MHS, &ghs, 0);
  LOWORD(v18) = 22496;
  HIWORD(v18) = (unsigned int)"," >> 16;
  v19 = api_add_data_full(v17, v18, api_data_type::API_UINT, &found_blocks, 1);
  LOWORD(v20) = 22512;
  HIWORD(v20) = (unsigned int)" Method" >> 16;
  v21 = api_add_data_full(v19, v20, api_data_type::API_INT64, &total_getworks, 1);
  LOWORD(v22) = 20400;
  HIWORD(v22) = (unsigned int)&_func___12699.__data.__nusers >> 16;
  v23 = api_add_data_full(v21, v22, api_data_type::API_INT64, &total_accepted, 1);
  LOWORD(v24) = 22524;
  HIWORD(v24) = (unsigned int)"ent Block Time" >> 16;
  v25 = api_add_data_full(v23, v24, api_data_type::API_INT64, &total_rejected, 1);
  LOWORD(v26) = 22536;
  HIWORD(v26) = (unsigned int)"me" >> 16;
  v27 = api_add_data_full(v25, v26, api_data_type::API_INT, &hw_errors, 1);
  LOWORD(v28) = 22552;
  HIWORD(v28) = (unsigned int)"k Hash" >> 16;
  v29 = api_add_data_full(v27, v28, api_data_type::API_UTILITY, &utility, 0);
  LOWORD(v30) = 22560;
  HIWORD(v30) = (unsigned int)"LP" >> 16;
  v31 = api_add_data_full(v29, v30, api_data_type::API_INT64, &total_discarded, 1);
  LOWORD(v32) = 22572;
  HIWORD(v32) = (unsigned int)"Difficulty" >> 16;
  v33 = api_add_data_full(v31, v32, api_data_type::API_INT64, &total_stale, 1);
  LOWORD(v34) = 22580;
  HIWORD(v34) = (unsigned int)"ty" >> 16;
  v35 = api_add_data_full(v33, v34, api_data_type::API_UINT, &total_go, 1);
  LOWORD(v36) = 22596;
  HIWORD(v36) = (unsigned int)"" >> 16;
  v37 = api_add_data_full(v35, v36, api_data_type::API_UINT, &local_work, 1);
  LOWORD(v38) = 22608;
  HIWORD(v38) = (unsigned int)"" >> 16;
  v39 = api_add_data_full(v37, v38, api_data_type::API_UINT, &total_ro, 1);
  LOWORD(v40) = 22624;
  HIWORD(v40) = (unsigned int)"d Blocks" >> 16;
  v41 = api_add_data_full(v39, v40, api_data_type::API_UINT, &new_blocks, 1);
  LOWORD(v42) = 22640;
  HIWORD(v42) = (unsigned int)"orks" >> 16;
  v43 = api_add_data_full(v41, v42, api_data_type::API_MHTOTAL, &total_mhashes_done, 1);
  LOWORD(v44) = 22652;
  HIWORD(v44) = (unsigned int)"cted" >> 16;
  v45 = api_add_data_full(v43, v44, api_data_type::API_UTILITY, &work_utility, 0);
  LOWORD(v46) = 22668;
  HIWORD(v46) = (unsigned int)" Errors" >> 16;
  v47 = api_add_data_full(v45, v46, api_data_type::API_DIFF, &total_diff_accepted, 1);
  LOWORD(v48) = 22688;
  HIWORD(v48) = (unsigned int)"arded" >> 16;
  v49 = api_add_data_full(v47, v48, api_data_type::API_DIFF, &total_diff_rejected, 1);
  LOWORD(v50) = 22708;
  HIWORD(v50) = (unsigned int)"Failures" >> 16;
  v51 = api_add_data_full(v49, v50, api_data_type::API_DIFF, &total_diff_stale, 1);
  LOWORD(v52) = 22728;
  HIWORD(v52) = (unsigned int)"rk" >> 16;
  v53 = api_add_data_full(v51, v52, api_data_type::API_UINT64, &best_diff, 1);
  v54 = total_diff1 + hw_errors;
  if ( v54 )
    v55 = (double)hw_errors / (double)v54;
  else
    v55 = 0.0;
  LOWORD(v56) = 22740;
  hwp = v55;
  HIWORD(v56) = (unsigned int)"ailures" >> 16;
  v57 = api_add_data_full(v53, v56, api_data_type::API_PERCENT, &hwp, 0);
  if ( total_diff1 )
    v58 = total_diff_rejected / (double)total_diff1;
  else
    v58 = 0.0;
  LOWORD(v59) = 22760;
  rejp = v58;
  HIWORD(v59) = (unsigned int)"ks" >> 16;
  v60 = api_add_data_full(v57, v59, api_data_type::API_PERCENT, &rejp, 0);
  v61 = total_diff_rejected + total_diff_accepted + total_diff_stale;
  if ( v61 == 0.0 )
    v62 = 0.0;
  else
    v62 = total_diff_rejected / v61;
  LOWORD(v63) = 22780;
  prejp = v62;
  HIWORD(v63) = (unsigned int)" Utility" >> 16;
  v64 = api_add_data_full(v60, v63, api_data_type::API_PERCENT, &prejp, 0);
  v65 = total_diff_accepted + total_diff_rejected + total_diff_stale;
  if ( v65 == 0.0 )
    v66 = 0.0;
  else
    v66 = total_diff_stale / v65;
  LOWORD(v67) = 22796;
  stalep = v66;
  HIWORD(v67) = (unsigned int)"iculty Accepted" >> 16;
  v68 = api_add_data_full(v64, v67, api_data_type::API_PERCENT, &stalep, 0);
  LOWORD(v69) = 22808;
  HIWORD(v69) = (unsigned int)"ted" >> 16;
  v70 = api_add_data_full(v68, v69, api_data_type::API_TIME, &last_getwork, 0);
  if ( pthread_mutex_unlock(&hash_lock) )
    mutex_unlock_noyield_1((pthread_mutex_t *)&_func___11888, (const char *)0xB2E, v71, v72);
  selective_yield();
  print_data(io_data, v70, v5, 0);
  if ( v5 && io_open )
    io_data->close = 1;
}
