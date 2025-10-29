void __fastcall calc_diff(work *work, double known)
{
  double v3; // d0
  pool *pool; // r4
  double *p_work_difficulty; // r6
  int v7; // r0
  double v8; // d8
  double min_diff; // d7
  double max_diff; // d7
  double v11; // d9
  unsigned __int64 v12; // r0
  double v13; // d8

  pool = work->pool;
  if ( v3 == 0.0 )
  {
    v11 = 65536.0;
    p_work_difficulty = &work->work_difficulty;
    v12 = *(_QWORD *)&work->target[24];
    if ( !opt_scrypt )
      v11 = 2.69595353e67;
    v13 = (double)*(unsigned __int64 *)work->target
        + (double)v12 * 6.27710174e57
        + (double)*(unsigned __int64 *)&work->target[16] * 3.40282367e38
        + (double)*(unsigned __int64 *)&work->target[8] * 1.84467441e19;
    if ( v13 != 0.0 )
      v11 = v11 / v13;
    *p_work_difficulty = v11;
  }
  else
  {
    p_work_difficulty = &work->work_difficulty;
    work->work_difficulty = v3;
  }
  v7 = target_zero_cal(work->target);
  v8 = (double)v7;
  *p_work_difficulty = (double)v7;
  pool->cgminer_pool_stats.last_diff = (double)v7;
  suffix_string(v7, work->pool->diff, 8u, 0);
  min_diff = pool->cgminer_pool_stats.min_diff;
  if ( v8 == min_diff )
  {
    ++pool->cgminer_pool_stats.min_diff_count;
    goto LABEL_5;
  }
  if ( v8 >= min_diff )
  {
    if ( min_diff != 0.0 )
    {
LABEL_5:
      max_diff = pool->cgminer_pool_stats.max_diff;
      if ( v8 != max_diff )
        goto LABEL_6;
LABEL_12:
      ++pool->cgminer_pool_stats.max_diff_count;
      return;
    }
    pool->cgminer_pool_stats.min_diff = v8;
    pool->cgminer_pool_stats.min_diff_count = 1;
  }
  else
  {
    pool->cgminer_pool_stats.min_diff = v8;
    pool->cgminer_pool_stats.min_diff_count = 1;
  }
  max_diff = pool->cgminer_pool_stats.max_diff;
  if ( v8 == max_diff )
    goto LABEL_12;
LABEL_6:
  if ( v8 > max_diff )
  {
    pool->cgminer_pool_stats.max_diff = v8;
    pool->cgminer_pool_stats.max_diff_count = 1;
  }
}
