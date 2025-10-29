void __fastcall hashmeter(int thr_id, uint64_t hashes_done)
{
  double v3; // d0
  __time_t tv_sec; // r6
  double v6; // d9
  int v7; // r6
  cgpu_info *cgpu; // r5
  double v9; // r0
  double v10; // r2
  double v11; // r0
  double v12; // r2
  double v13; // r0
  double v14; // r2
  double v15; // r0
  double v16; // r2
  double v17; // d10
  int v18; // r6
  int v19; // r6
  bool v20; // cc
  int v21; // r8
  unsigned __int64 v22; // r0
  int *v23; // r6
  double v24; // d8
  double v25; // r2
  double v26; // r0
  int v27; // r11
  __int64 v28; // r0
  int v29; // r6
  double v30; // d7
  thr_info *thread; // r0
  cgpu_info *v32; // r10
  double v33; // d8
  double v34; // r2
  double v35; // r0
  const char *v36; // r0
  const char *v37; // r2
  const char *v38; // r0
  double v39; // r0
  double v40; // r2
  double v41; // r0
  double v42; // r2
  double v43; // r0
  double v44; // r2
  double v45; // r0
  double v46; // r2
  double v47; // r0
  double v48; // r2
  int *v49; // r0
  const char *v50; // r2
  int v51; // r1
  int *v52; // r0
  int v53; // r1
  const char *v54; // r2
  int *v55; // r0
  int v56; // r3
  int v57; // r1
  int v58; // r4
  const char *v59; // r2
  int *v60; // r0
  int *v61; // r0
  int v62; // r3
  int v63; // r1
  int v64; // r4
  const char *v65; // r2
  int *v66; // r0
  int *v67; // r0
  int *v68; // r0
  double sigdigits; // [sp+0h] [bp-1064h]
  double sigdigitsb; // [sp+0h] [bp-1064h]
  double sigdigitsc; // [sp+0h] [bp-1064h]
  double sigdigitsd; // [sp+0h] [bp-1064h]
  double sigdigitse; // [sp+0h] [bp-1064h]
  double sigdigitsf; // [sp+0h] [bp-1064h]
  double sigdigitsg; // [sp+0h] [bp-1064h]
  double sigdigitsa; // [sp+0h] [bp-1064h]
  double v77; // [sp+8h] [bp-105Ch]
  double v78; // [sp+8h] [bp-105Ch]
  double v79; // [sp+8h] [bp-105Ch]
  double v80; // [sp+8h] [bp-105Ch]
  double v81; // [sp+8h] [bp-105Ch]
  double v82; // [sp+8h] [bp-105Ch]
  double v83; // [sp+8h] [bp-105Ch]
  double v84; // [sp+8h] [bp-105Ch]
  char displayed_hashes[16]; // [sp+20h] [bp-1044h] BYREF
  char displayed_rolling[16]; // [sp+30h] [bp-1034h] BYREF
  char displayed_r1[16]; // [sp+40h] [bp-1024h] BYREF
  char displayed_r5[16]; // [sp+50h] [bp-1014h] BYREF
  char displayed_r15[4100]; // [sp+60h] [bp-1004h] BYREF

  cgtime(&total_tv_end);
  tdiff(&total_tv_end, &tv_hashmeter);
  tv_sec = total_tv_end.tv_sec;
  v6 = v3;
  if ( opt_log_interval > total_tv_end.tv_sec - hashdisplay_t )
  {
    if ( thr_id < 0 )
      return;
    v27 = 0;
    copy_time(&tv_hashmeter, &total_tv_end);
  }
  else
  {
    hashdisplay_t = total_tv_end.tv_sec;
    copy_time(&tv_hashmeter, &total_tv_end);
    if ( thr_id < 0 )
    {
      v7 = pthread_mutex_lock(&hash_lock);
      if ( !v7 )
      {
        if ( mining_threads > 0 )
        {
          do
          {
            while ( 1 )
            {
              cgpu = get_thread(v7)->cgpu;
              tdiff(&total_tv_end, &cgpu->last_message_tv);
              copy_time(&cgpu->last_message_tv, &total_tv_end);
              if ( v3 > 0.0 )
                break;
              if ( mining_threads <= ++v7 )
                goto LABEL_9;
            }
            HIDWORD(v10) = opt_log_interval;
            LODWORD(v9) = &cgpu->rolling;
            decay_time_0(v9, v10, sigdigits, v77);
            LODWORD(v11) = &cgpu->rolling1;
            decay_time_0(v11, v12, sigdigitsb, v78);
            LODWORD(v13) = &cgpu->rolling5;
            decay_time_0(v13, v14, sigdigitsc, v79);
            LODWORD(v15) = &cgpu->rolling15;
            ++v7;
            v3 = 0.0;
            decay_time_0(v15, v16, sigdigitsd, v80);
          }
          while ( mining_threads > v7 );
        }
LABEL_9:
        if ( pthread_mutex_unlock(&hash_lock) )
        {
          v68 = _errno_location();
          LOWORD(v63) = -3136;
          v62 = *v68;
          HIWORD(v63) = (unsigned int)"iner" >> 16;
          v64 = 6776;
          goto LABEL_60;
        }
        selective_yield();
        if ( !pthread_mutex_lock(&hash_lock) )
        {
          v17 = (double)hashes_done;
          v18 = g_local_mhashes_index;
          total_mhashes_done = total_mhashes_done + (double)hashes_done;
          goto LABEL_12;
        }
LABEL_53:
        v49 = _errno_location();
        LOWORD(v50) = -968;
        LOWORD(v51) = -3136;
        HIWORD(v50) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
        HIWORD(v51) = (unsigned int)"iner" >> 16;
        snprintf(displayed_r15, 0x1000u, v50, *v49, v51, "hashmeter", 6779);
        goto LABEL_54;
      }
      v67 = _errno_location();
      LOWORD(v57) = -3136;
      v56 = *v67;
      HIWORD(v57) = (unsigned int)"iner" >> 16;
      v58 = 6763;
LABEL_57:
      LOWORD(v59) = -968;
      HIWORD(v59) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
      snprintf(displayed_r15, 0x1000u, v59, v56, v57, "hashmeter", v58);
      goto LABEL_54;
    }
    v27 = 1;
  }
  thread = get_thread(thr_id);
  v32 = thread->cgpu;
  copy_time(&thread->last, &total_tv_end);
  v32->device_last_well = tv_sec;
  tdiff(&total_tv_end, &v32->last_message_tv);
  v33 = v3;
  copy_time(&v32->last_message_tv, &total_tv_end);
  if ( pthread_mutex_lock(&hash_lock) )
  {
    v55 = _errno_location();
    LOWORD(v57) = -3136;
    v56 = *v55;
    HIWORD(v57) = (unsigned int)"iner" >> 16;
    v58 = 6737;
    goto LABEL_57;
  }
  v35 = (double)hashes_done;
  v17 = (double)hashes_done;
  v32->total_mhashes = v32->total_mhashes + (double)hashes_done;
  if ( v3 > 0.0 )
  {
    HIDWORD(v34) = opt_log_interval;
    LODWORD(v35) = &v32->rolling;
    decay_time_0(v35, v34, sigdigits, v77);
    LODWORD(v39) = &v32->rolling1;
    v3 = (double)hashes_done;
    decay_time_0(v39, v40, sigdigitse, v81);
    if ( v33 > 0.0 )
    {
      LODWORD(v41) = &v32->rolling5;
      decay_time_0(v41, v42, sigdigits, v77);
      LODWORD(v43) = &v32->rolling15;
      v3 = (double)hashes_done;
      decay_time_0(v43, v44, sigdigitsf, v82);
    }
  }
  if ( pthread_mutex_unlock(&hash_lock) )
  {
    v61 = _errno_location();
    LOWORD(v63) = -3136;
    v62 = *v61;
    HIWORD(v63) = (unsigned int)"iner" >> 16;
    v64 = 6743;
    goto LABEL_60;
  }
  selective_yield();
  get_statline(displayed_r15, 0x100u, v32);
  LOWORD(v36) = 3296;
  HIWORD(v36) = (unsigned int)"share submission lag time %d seconds" >> 16;
  printf(v36, displayed_r15);
  fflush((FILE *)stdout);
  if ( pthread_mutex_lock(&hash_lock) )
    goto LABEL_53;
  v18 = g_local_mhashes_index;
  total_mhashes_done = total_mhashes_done + v17;
  if ( v27 )
  {
LABEL_12:
    v19 = v18 + 1;
    v20 = v19 <= 11;
    v21 = 0;
    if ( v19 <= 11 )
      g_local_mhashes_index = v19;
    v22 = 0;
    v23 = (int *)g_local_mhashes_dones;
    if ( !v20 )
      g_local_mhashes_index = 0;
    do
    {
      v24 = *(double *)v23;
      v23 += 2;
      if ( v24 >= 0.0 )
      {
        ++v21;
        v22 = (unsigned __int64)((double)v22 + v24);
      }
    }
    while ( &g_local_mhashes_index != v23 );
    v25 = v17;
    if ( v21 )
      v25 = (double)(v22 / v21);
    HIDWORD(v26) = opt_log_interval;
    if ( (double)opt_log_interval > 0.0 )
    {
      LODWORD(v26) = &total_rolling;
      decay_time_0(v26, v25, sigdigits, v77);
      if ( v6 <= 0.0 )
        goto LABEL_23;
    }
    else if ( v6 <= 0.0 )
    {
LABEL_23:
      v27 = 1;
      v3 = total_rolling;
      v28 = llround();
      v29 = g_local_mhashes_index;
      v30 = 0.0;
      global_hashrate = 1000000 * v28;
      g_local_mhashes_dones[g_local_mhashes_index] = 0.0;
      goto LABEL_32;
    }
    LODWORD(v26) = &rolling1;
    decay_time_0(v26, v25, sigdigits, v77);
    LODWORD(v45) = &rolling5;
    decay_time_0(v45, v46, sigdigitsg, v83);
    if ( v6 > 0.0 )
    {
      LODWORD(v47) = &rolling15;
      decay_time_0(v47, v48, sigdigitsa, v84);
    }
    goto LABEL_23;
  }
  v29 = g_local_mhashes_index;
  v30 = g_local_mhashes_dones[g_local_mhashes_index];
LABEL_32:
  g_local_mhashes_dones[v29] = v30 + v17;
  tdiff(&total_tv_end, &total_tv_start);
  total_secs = v3;
  if ( v3 - last_total_secs > 86400.0 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      snprintf(displayed_r15, 0x1000u, "cgminer time error total_secs = %f last_total_secs = %f", v3, last_total_secs);
      applog(3, displayed_r15, 0);
    }
    if ( !pthread_mutex_unlock(&hash_lock) )
    {
      selective_yield();
      zero_stats();
      if ( !pthread_mutex_lock(&hash_lock) )
      {
        if ( !v27 )
          goto LABEL_39;
LABEL_43:
        suffix_string((unsigned __int64)(total_mhashes_done / total_secs * 1000000.0), displayed_hashes, 0x10u, 4);
        g_displayed_rolling = total_rolling / 1000.0;
        suffix_string((unsigned __int64)(total_rolling * 1000000.0), displayed_rolling, 0x10u, 4);
        suffix_string((unsigned __int64)(rolling1 * 1000000.0), displayed_r1, 0x10u, 4);
        suffix_string((unsigned __int64)(rolling5 * 1000000.0), displayed_r5, 0x10u, 4);
        suffix_string((unsigned __int64)(rolling15 * 1000000.0), displayed_r15, 0x10u, 4);
        LOWORD(v37) = 3368;
        HIWORD(v37) = (unsigned int)"or total_secs = %f last_total_secs = %f" >> 16;
        snprintf(
          statusline,
          0x100u,
          v37,
          opt_log_interval,
          displayed_rolling,
          displayed_r1,
          displayed_r5,
          displayed_r15,
          displayed_hashes);
        if ( !pthread_mutex_unlock(&hash_lock) )
        {
          selective_yield();
          LOWORD(v38) = 3296;
          HIWORD(v38) = (unsigned int)"share submission lag time %d seconds" >> 16;
          printf(v38, statusline);
          fflush((FILE *)stdout);
          return;
        }
        goto LABEL_55;
      }
      v60 = _errno_location();
      LOWORD(v57) = -3136;
      v56 = *v60;
      HIWORD(v57) = (unsigned int)"iner" >> 16;
      v58 = 6821;
      goto LABEL_57;
    }
    v66 = _errno_location();
    LOWORD(v63) = -3136;
    v62 = *v66;
    HIWORD(v63) = (unsigned int)"iner" >> 16;
    v64 = 6819;
LABEL_60:
    LOWORD(v65) = -920;
    HIWORD(v65) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(displayed_r15, 0x1000u, v65, v62, v63, "hashmeter", v64);
LABEL_54:
    applog(3, displayed_r15, 1);
    _quit(1, 1);
  }
  last_total_secs = v3;
  if ( v27 )
    goto LABEL_43;
LABEL_39:
  if ( pthread_mutex_unlock(&hash_lock) )
  {
LABEL_55:
    v52 = _errno_location();
    LOWORD(v53) = -3136;
    LOWORD(v54) = -920;
    HIWORD(v53) = (unsigned int)"iner" >> 16;
    HIWORD(v54) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(displayed_r15, 0x1000u, v54, *v52, v53, "hashmeter", 6850);
    goto LABEL_54;
  }
  selective_yield();
}
