void __fastcall sharelog(const char *disposition, const work *work)
{
  int thr_id; // r6
  cgpu_info *cgpu; // r11
  pool *pool; // r10
  char *v6; // r8
  char *v7; // r7
  char *v8; // r9
  const char *v9; // r2
  signed int v10; // r4
  size_t v11; // r4
  const char *v12; // r4
  int v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // r3
  _DWORD *v17; // r4
  int v18; // r1
  int *v19; // r0
  const char *v20; // r2
  int v21; // r1
  int *v22; // r0
  int v23; // r1
  const char *v24; // r2
  __time_t t; // [sp+24h] [bp-1408h]
  char s[1024]; // [sp+28h] [bp-1404h] BYREF
  char tmp42[4096]; // [sp+428h] [bp-1004h] BYREF

  if ( !sharelog_file )
    return;
  thr_id = work->thr_id;
  cgpu = get_thread(thr_id)->cgpu;
  pool = work->pool;
  t = work->tv_work_found.tv_sec;
  v6 = bin2hex(work->target, 0x20u);
  v7 = bin2hex(work->hash, 0x20u);
  v8 = bin2hex(work->data, 0x80u);
  LOWORD(v9) = 2256;
  HIWORD(v9) = (unsigned int)"Work available from pools, resuming." >> 16;
  v10 = snprintf(s, 0x400u, v9, t, disposition, v6, pool->rpc_url, cgpu->drv->name, cgpu->device_id, thr_id, v7, v8);
  free(v6);
  free(v7);
  free(v8);
  if ( v10 >= 1024 )
  {
    s[1023] = 0;
    goto LABEL_5;
  }
  if ( v10 >= 0 )
  {
LABEL_5:
    if ( pthread_mutex_lock(&sharelog_lock) )
    {
      v19 = _errno_location();
      LOWORD(v20) = -968;
      LOWORD(v21) = -3136;
      HIWORD(v20) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
      HIWORD(v21) = (unsigned int)"iner" >> 16;
      snprintf(tmp42, 0x1000u, v20, *v19, v21, "sharelog", 673);
    }
    else
    {
      v11 = fwrite(s, v10, 1u, sharelog_file);
      fflush(sharelog_file);
      if ( !pthread_mutex_unlock(&sharelog_lock) )
      {
        selective_yield();
        if ( v11 != 1 && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          v12 = "sharelog fwrite error";
LABEL_12:
          v13 = *(_DWORD *)v12;
          v14 = *((_DWORD *)v12 + 1);
          v15 = *((_DWORD *)v12 + 2);
          v16 = *((_DWORD *)v12 + 3);
          v17 = v12 + 16;
          *(_DWORD *)tmp42 = v13;
          *(_DWORD *)&tmp42[4] = v14;
          *(_DWORD *)&tmp42[8] = v15;
          *(_DWORD *)&tmp42[12] = v16;
          v18 = v17[1];
          *(_DWORD *)&tmp42[16] = *v17;
          *(_WORD *)&tmp42[20] = v18;
          applog(3, tmp42, 0);
          return;
        }
        return;
      }
      v22 = _errno_location();
      LOWORD(v23) = -3136;
      LOWORD(v24) = -920;
      HIWORD(v23) = (unsigned int)"iner" >> 16;
      HIWORD(v24) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v24, *v22, v23, "sharelog", 676);
    }
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    v12 = "sharelog printf error";
    goto LABEL_12;
  }
}
