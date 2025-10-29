void __fastcall discard_work(work *work)
{
  pool *pool; // r3
  int *v3; // r4
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r2
  int v10; // r3
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( work->clone || work->rolls || work->mined )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v3) = -2428;
      HIWORD(v3) = (unsigned int)"t %s" >> 16;
      v4 = *v3;
      v5 = v3[1];
      v6 = v3[2];
      v7 = v3[3];
      v3 += 4;
      *(_DWORD *)tmp42 = v4;
      *(_DWORD *)&tmp42[4] = v5;
      *(_DWORD *)&tmp42[8] = v6;
      *(_DWORD *)&tmp42[12] = v7;
      v8 = v3[1];
      v9 = v3[2];
      v10 = v3[3];
      *(_DWORD *)&tmp42[16] = *v3;
      *(_DWORD *)&tmp42[20] = v8;
      *(_DWORD *)&tmp42[24] = v9;
      *(_DWORD *)&tmp42[28] = v10;
      applog(7, tmp42, 0);
    }
  }
  else
  {
    pool = work->pool;
    if ( pool )
    {
      ++pool->discarded_work;
      --work->pool->quota_used;
      --work->pool->works;
    }
    ++total_discarded;
  }
  clean_work(work);
  sub_12000(work);
}
