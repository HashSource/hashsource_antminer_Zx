void __fastcall sharelog(const char *disposition, const work *work)
{
  int thr_id; // r6
  cgpu_info *cgpu; // r11
  pool *pool; // r10
  char *v6; // r8
  char *v7; // r7
  char *v8; // r9
  signed int v9; // r4
  size_t v10; // r4
  const char *v11; // r4
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3
  _DWORD *v16; // r4
  int v17; // r1
  int *v18; // r0
  int *v19; // r0
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
  v9 = snprintf(
         s,
         0x400u,
         "%lu,%s,%s,%s,%s%u,%u,%s,%s\n",
         t,
         disposition,
         v6,
         pool->rpc_url,
         cgpu->drv->name,
         cgpu->device_id,
         thr_id,
         v7,
         v8);
  free(v6);
  free(v7);
  free(v8);
  if ( v9 >= 1024 )
  {
    s[1023] = 0;
    goto LABEL_5;
  }
  if ( v9 >= 0 )
  {
LABEL_5:
    if ( pthread_mutex_lock(&sharelog_lock) )
    {
      v18 = _errno_location();
      snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", *v18, "cgminer.c", "sharelog", 673);
    }
    else
    {
      v10 = fwrite(s, v9, 1u, sharelog_file);
      fflush(sharelog_file);
      if ( !pthread_mutex_unlock(&sharelog_lock) )
      {
        selective_yield();
        if ( v10 != 1 && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          v11 = "sharelog fwrite error";
LABEL_12:
          v12 = *(_DWORD *)v11;
          v13 = *((_DWORD *)v11 + 1);
          v14 = *((_DWORD *)v11 + 2);
          v15 = *((_DWORD *)v11 + 3);
          v16 = v11 + 16;
          *(_DWORD *)tmp42 = v12;
          *(_DWORD *)&tmp42[4] = v13;
          *(_DWORD *)&tmp42[8] = v14;
          *(_DWORD *)&tmp42[12] = v15;
          v17 = v16[1];
          *(_DWORD *)&tmp42[16] = *v16;
          *(_WORD *)&tmp42[20] = v17;
          applog(3, tmp42, 0);
          return;
        }
        return;
      }
      v19 = _errno_location();
      snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v19, "cgminer.c", "sharelog", 676);
    }
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    v11 = "sharelog printf error";
    goto LABEL_12;
  }
}
