// Alternative name is '__kill_work.part.37'
void _kill_work_0()
{
  int *v0; // r4
  int v1; // r0
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r1
  int *v6; // r6
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  void *v14; // r0
  int *v15; // r4
  int v16; // r0
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r1
  int v21; // r2
  void *v22; // r0
  int *v23; // r12
  int v24; // r0
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r4
  int v32; // r0
  thr_info *thread; // r0
  cgpu_info *cgpu; // r3
  void *v35; // r0
  int *v36; // r5
  int v37; // r0
  int v38; // r1
  int v39; // r2
  int v40; // r3
  int v41; // r1
  void *v42; // r0
  char tmp42[4096]; // [sp+0h] [bp-1004h] BYREF

  if ( opt_debug )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 6 )
    {
      LOWORD(v0) = 1000;
      HIWORD(v0) = (unsigned int)"ned only %.0f shares of %d requested." >> 16;
      v1 = *v0;
      v2 = v0[1];
      v3 = v0[2];
      v4 = v0[3];
      v0 += 4;
      *(_DWORD *)tmp42 = v1;
      *(_DWORD *)&tmp42[4] = v2;
      *(_DWORD *)&tmp42[8] = v3;
      *(_DWORD *)&tmp42[12] = v4;
      v5 = v0[1];
      *(_DWORD *)&tmp42[16] = *v0;
      *(_WORD *)&tmp42[20] = v5;
      applog(7, tmp42, 1);
      if ( !opt_debug )
        goto LABEL_8;
      if ( use_syslog )
      {
LABEL_7:
        LOWORD(v6) = 1024;
        HIWORD(v6) = (unsigned int)"%d requested." >> 16;
        v7 = *v6;
        v8 = v6[1];
        v9 = v6[2];
        v10 = v6[3];
        v6 += 4;
        *(_DWORD *)tmp42 = v7;
        *(_DWORD *)&tmp42[4] = v8;
        *(_DWORD *)&tmp42[8] = v9;
        *(_DWORD *)&tmp42[12] = v10;
        v11 = v6[1];
        v12 = v6[2];
        v13 = v6[3];
        *(_DWORD *)&tmp42[16] = *v6;
        *(_DWORD *)&tmp42[20] = v11;
        *(_DWORD *)&tmp42[24] = v12;
        tmp42[28] = v13;
        applog(7, tmp42, 1);
        goto LABEL_8;
      }
    }
    if ( opt_log_output || opt_log_level > 6 )
      goto LABEL_7;
  }
LABEL_8:
  LOWORD(v14) = 31689;
  HIWORD(v14) = (unsigned int)&loc_27AB8 >> 16;
  cg_completion_timeout(v14, &control_thr[watchpool_thr_id], 1000);
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v15) = 1056;
    HIWORD(v15) = (unsigned int)"ssage" >> 16;
    v16 = *v15;
    v17 = v15[1];
    v18 = v15[2];
    v19 = v15[3];
    v15 += 4;
    *(_DWORD *)tmp42 = v16;
    *(_DWORD *)&tmp42[4] = v17;
    *(_DWORD *)&tmp42[8] = v18;
    *(_DWORD *)&tmp42[12] = v19;
    v20 = v15[1];
    v21 = v15[2];
    *(_DWORD *)&tmp42[16] = *v15;
    *(_DWORD *)&tmp42[20] = v20;
    *(_DWORD *)&tmp42[24] = v21;
    applog(7, tmp42, 1);
  }
  LOWORD(v22) = 31689;
  HIWORD(v22) = (unsigned int)&loc_27AB8 >> 16;
  cg_completion_timeout(v22, &control_thr[watchdog_thr_id], 1000);
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v23) = 1084;
    HIWORD(v23) = (unsigned int)"l thread" >> 16;
    v24 = *v23;
    v25 = v23[1];
    v26 = v23[2];
    v27 = v23[3];
    v23 += 4;
    *(_DWORD *)tmp42 = v24;
    *(_DWORD *)&tmp42[4] = v25;
    *(_DWORD *)&tmp42[8] = v26;
    *(_DWORD *)&tmp42[12] = v27;
    v28 = v23[1];
    v29 = v23[2];
    v30 = v23[3];
    *(_DWORD *)&tmp42[16] = *v23;
    *(_DWORD *)&tmp42[20] = v28;
    *(_DWORD *)&tmp42[24] = v29;
    tmp42[28] = v30;
    applog(7, tmp42, 1);
  }
  if ( mining_threads > 0 )
  {
    v31 = 0;
    do
    {
      v32 = v31++;
      thread = get_thread(v32);
      if ( thread )
      {
        cgpu = thread->cgpu;
        if ( cgpu )
          cgpu->shutdown = 1;
      }
    }
    while ( v31 < mining_threads );
  }
  sleep(1u);
  LOWORD(v35) = -10823;
  HIWORD(v35) = ((unsigned int)&loc_1D562 + 7) >> 16;
  cg_completion_timeout(v35, 0, 3000);
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v36) = 1116;
    HIWORD(v36) = (unsigned int)" thread" >> 16;
    v37 = *v36;
    v38 = v36[1];
    v39 = v36[2];
    v40 = v36[3];
    v36 += 4;
    *(_DWORD *)tmp42 = v37;
    *(_DWORD *)&tmp42[4] = v38;
    *(_DWORD *)&tmp42[8] = v39;
    *(_DWORD *)&tmp42[12] = v40;
    v41 = v36[1];
    *(_DWORD *)&tmp42[16] = *v36;
    *(_WORD *)&tmp42[20] = v41;
    tmp42[22] = BYTE2(v41);
    applog(7, tmp42, 1);
  }
  LOWORD(v42) = 31689;
  HIWORD(v42) = (unsigned int)&loc_27AB8 >> 16;
  cg_completion_timeout(v42, &control_thr[api_thr_id], 1000);
}
