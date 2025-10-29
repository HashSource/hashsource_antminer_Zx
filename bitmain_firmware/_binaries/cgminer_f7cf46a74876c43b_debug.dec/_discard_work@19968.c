void __fastcall discard_work(work *work)
{
  pool *pool; // r3
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( work->clone || work->rolls || work->mined )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      strcpy(tmp42, "Discarded cloned or rolled work");
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
