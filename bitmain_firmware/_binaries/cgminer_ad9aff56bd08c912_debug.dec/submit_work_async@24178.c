void __fastcall submit_work_async(work *work)
{
  int *v1; // r4
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r4
  pool *pool; // r5
  cgpu_info *cgpu; // r6
  int64_t v14; // kr08_8
  double v15; // d6
  double work_difficulty; // d5
  double v17; // d7
  const char *v18; // r2
  _BOOL4 v19; // r2
  _BOOL4 v20; // r2
  const char *v21; // r2
  int *v22; // r5
  int v23; // r0
  int v24; // r1
  int v25; // r2
  int v26; // r3
  int v27; // r0
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r5
  int *v32; // r6
  int v33; // r0
  int v34; // r1
  int v35; // r2
  int v36; // r3
  int v37; // r0
  int v38; // r1
  int v39; // r2
  int v40; // r3
  int v41; // r6
  void *(*v42)(void *); // r2
  int *v43; // r4
  int v44; // r0
  int v45; // r1
  int v46; // r2
  int v47; // r3
  int v48; // r0
  int v49; // r1
  int v50; // r2
  int v51; // r3
  int v52; // r4
  const char *v53; // r2
  _BOOL4 stratum; // r3
  const char *v55; // r2
  const char *v56; // r0
  double diff_stale; // d6
  double v58; // d7
  double v59; // d5
  int *v60; // r0
  int v61; // r3
  int v62; // r1
  int v63; // r4
  const char *v64; // r2
  int *v65; // r0
  int v66; // r3
  int v67; // r1
  int v68; // r4
  const char *v69; // r2
  const char *v70; // r2
  int *v71; // r0
  int *v72; // r0
  pthread_t submit_thread; // [sp+14h] [bp-1008h] BYREF
  char tmp42[4096]; // [sp+18h] [bp-1004h] BYREF

  if ( !*(_DWORD *)&work->data[76] )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      LOWORD(v1) = 4496;
      HIWORD(v1) = (unsigned int)"Pushing work from pool %d to hash queue" >> 16;
      v2 = *v1;
      v3 = v1[1];
      v4 = v1[2];
      v5 = v1[3];
      v1 += 4;
      *(_DWORD *)tmp42 = v2;
      *(_DWORD *)&tmp42[4] = v3;
      *(_DWORD *)&tmp42[8] = v4;
      *(_DWORD *)&tmp42[12] = v5;
      v6 = *v1;
      v7 = v1[1];
      v8 = v1[2];
      v9 = v1[3];
      v10 = v1[4];
      *(_DWORD *)&tmp42[16] = v6;
      *(_DWORD *)&tmp42[20] = v7;
      *(_DWORD *)&tmp42[24] = v8;
      *(_DWORD *)&tmp42[28] = v9;
      tmp42[32] = v10;
      applog(4, tmp42, 0);
    }
    return;
  }
  pool = work->pool;
  cgtime(&work->tv_work_found);
  if ( opt_benchmark )
  {
    cgpu = get_thread(work->thr_id)->cgpu;
    if ( !pthread_mutex_lock(&stats_lock) )
    {
      v14 = total_accepted;
      ++cgpu->accepted;
      total_accepted = v14 + 1;
      v15 = total_diff_accepted;
      ++pool->accepted;
      cgpu->diff_accepted = cgpu->diff_accepted + work->work_difficulty;
      work_difficulty = work->work_difficulty;
      v17 = pool->diff_accepted + work_difficulty;
      total_diff_accepted = v15 + work_difficulty;
      pool->diff_accepted = v17;
      if ( !pthread_mutex_unlock(&stats_lock) )
      {
        selective_yield();
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          LOWORD(v18) = 4532;
          HIWORD(v18) = (unsigned int)"eue" >> 16;
          snprintf(tmp42, 0x1000u, v18, cgpu->drv->name, cgpu->device_id, *(_DWORD *)&work->data[76]);
          applog(7, tmp42, 0);
        }
        return;
      }
      v65 = _errno_location();
      LOWORD(v67) = -3136;
      v66 = *v65;
      HIWORD(v67) = (unsigned int)"iner" >> 16;
      v68 = 8243;
      goto LABEL_65;
    }
    v60 = _errno_location();
    LOWORD(v62) = -3136;
    v61 = *v60;
    HIWORD(v62) = (unsigned int)"iner" >> 16;
    v63 = 8236;
LABEL_62:
    LOWORD(v64) = -968;
    HIWORD(v64) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v64, v61, v62, "submit_work_async", v63);
    goto LABEL_63;
  }
  if ( !stale_work(work, 1) )
  {
    v19 = opt_debug;
    goto LABEL_17;
  }
  if ( !opt_submit_stale )
  {
    if ( !pool->submit_old )
    {
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v55) = 4696;
        HIWORD(v55) = (unsigned int)"detected, submitting as pool requested" >> 16;
        snprintf(tmp42, 0x1000u, v55, pool->pool_no);
        applog(7, tmp42, 0);
      }
      LOWORD(v56) = 4740;
      HIWORD(v56) = (unsigned int)" %d stale share detected, discarding" >> 16;
      sharelog(v56, work);
      if ( pthread_mutex_lock(&stats_lock) )
      {
        v71 = _errno_location();
        LOWORD(v62) = -3136;
        v61 = *v71;
        HIWORD(v62) = (unsigned int)"iner" >> 16;
        v63 = 8261;
        goto LABEL_62;
      }
      diff_stale = pool->diff_stale;
      v58 = total_diff_stale;
      ++pool->stale_shares;
      v59 = work->work_difficulty;
      ++total_stale;
      pool->diff_stale = diff_stale + v59;
      total_diff_stale = v58 + v59;
      if ( pthread_mutex_unlock(&stats_lock) )
      {
        v72 = _errno_location();
        LOWORD(v67) = -3136;
        v66 = *v72;
        HIWORD(v67) = (unsigned int)"iner" >> 16;
        v68 = 8266;
LABEL_65:
        LOWORD(v69) = -920;
        HIWORD(v69) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
        snprintf(tmp42, 0x1000u, v69, v66, v67, "submit_work_async", v68);
LABEL_63:
        applog(3, tmp42, 1);
        _quit(1, 1);
      }
      selective_yield();
LABEL_37:
      clean_work(work);
      sub_12000(work);
      return;
    }
    if ( opt_debug )
    {
      if ( !use_syslog && !opt_log_output && opt_log_level <= 6 )
        goto LABEL_26;
      LOWORD(v70) = 4636;
      HIWORD(v70) = (unsigned int)"detected, submitting as user requested" >> 16;
      snprintf(tmp42, 0x1000u, v70, pool->pool_no);
      goto LABEL_50;
    }
LABEL_51:
    stratum = work->stratum;
    work->stale = 1;
    if ( stratum )
      goto LABEL_31;
    goto LABEL_43;
  }
  if ( !opt_debug )
    goto LABEL_51;
  if ( !use_syslog && !opt_log_output && opt_log_level <= 6 )
  {
LABEL_26:
    v20 = work->stratum;
    work->stale = 1;
    if ( v20 )
    {
LABEL_27:
      if ( use_syslog || opt_log_output || opt_log_level > 6 )
      {
        LOWORD(v21) = 4748;
        HIWORD(v21) = (unsigned int)"e share detected, discarding" >> 16;
        snprintf(tmp42, 0x1000u, v21, pool->pool_no);
        applog(7, tmp42, 0);
      }
      goto LABEL_31;
    }
LABEL_39:
    if ( use_syslog || opt_log_output || opt_log_level > 6 )
    {
      LOWORD(v32) = 4824;
      HIWORD(v32) = (unsigned int)"e" >> 16;
      v33 = *v32;
      v34 = v32[1];
      v35 = v32[2];
      v36 = v32[3];
      v32 += 4;
      *(_DWORD *)tmp42 = v33;
      *(_DWORD *)&tmp42[4] = v34;
      *(_DWORD *)&tmp42[8] = v35;
      *(_DWORD *)&tmp42[12] = v36;
      v37 = *v32;
      v38 = v32[1];
      v39 = v32[2];
      v40 = v32[3];
      v41 = v32[4];
      *(_DWORD *)&tmp42[16] = v37;
      *(_DWORD *)&tmp42[20] = v38;
      *(_DWORD *)&tmp42[24] = v39;
      *(_DWORD *)&tmp42[28] = v40;
      *(_WORD *)&tmp42[32] = v41;
      tmp42[34] = BYTE2(v41);
      applog(7, tmp42, 0);
    }
    goto LABEL_43;
  }
  LOWORD(v53) = 4576;
  HIWORD(v53) = (unsigned int)"pted %s %d benchmark share nonce %08x" >> 16;
  snprintf(tmp42, 0x1000u, v53, pool->pool_no);
LABEL_50:
  applog(7, tmp42, 0);
  v19 = opt_debug;
  work->stale = 1;
LABEL_17:
  if ( work->stratum )
  {
    if ( v19 )
      goto LABEL_27;
LABEL_31:
    if ( tq_push(pool->stratum_q, work) )
      return;
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v22) = 4788;
      HIWORD(v22) = (unsigned int)"Pushing pool %d work to stratum queue" >> 16;
      v23 = *v22;
      v24 = v22[1];
      v25 = v22[2];
      v26 = v22[3];
      v22 += 4;
      *(_DWORD *)tmp42 = v23;
      *(_DWORD *)&tmp42[4] = v24;
      *(_DWORD *)&tmp42[8] = v25;
      *(_DWORD *)&tmp42[12] = v26;
      v27 = *v22;
      v28 = v22[1];
      v29 = v22[2];
      v30 = v22[3];
      v31 = v22[4];
      *(_DWORD *)&tmp42[16] = v27;
      *(_DWORD *)&tmp42[20] = v28;
      *(_DWORD *)&tmp42[24] = v29;
      *(_DWORD *)&tmp42[28] = v30;
      *(_WORD *)&tmp42[32] = v31;
      applog(7, tmp42, 0);
    }
    goto LABEL_37;
  }
  if ( v19 )
    goto LABEL_39;
LABEL_43:
  LOWORD(v42) = 27505;
  HIWORD(v42) = ((unsigned int)&loc_16B1A + 7) >> 16;
  if ( pthread_create(&submit_thread, 0, v42, work) )
  {
    LOWORD(v43) = 4860;
    HIWORD(v43) = (unsigned int)"l" >> 16;
    v44 = *v43;
    v45 = v43[1];
    v46 = v43[2];
    v47 = v43[3];
    v43 += 4;
    *(_DWORD *)tmp42 = v44;
    *(_DWORD *)&tmp42[4] = v45;
    *(_DWORD *)&tmp42[8] = v46;
    *(_DWORD *)&tmp42[12] = v47;
    v48 = *v43;
    v49 = v43[1];
    v50 = v43[2];
    v51 = v43[3];
    v52 = v43[4];
    *(_DWORD *)&tmp42[16] = v48;
    *(_DWORD *)&tmp42[20] = v49;
    *(_DWORD *)&tmp42[24] = v50;
    *(_DWORD *)&tmp42[28] = v51;
    *(_DWORD *)&tmp42[32] = v52;
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
}
