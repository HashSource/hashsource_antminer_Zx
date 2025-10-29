void *__fastcall miner_thread(void *userdata)
{
  cgpu_info *v1; // r8
  device_drv *drv; // r7
  char threadname[16]; // [sp+0h] [bp-1010h] BYREF
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  v1 = (cgpu_info *)*((_DWORD *)userdata + 9);
  drv = v1->drv;
  snprintf(threadname, 0x10u, "%d/Miner", *(_DWORD *)userdata);
  RenameThread(threadname);
  thread_reportout((thr_info *)userdata);
  if ( ((int (__fastcall *)(void *))drv->thread_init)(userdata) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      strcpy(tmp42, "Waiting on sem in miner thread");
      applog(7, tmp42, 0);
    }
    cgsem_wait((cgsem_t *)userdata + 1, "cgminer.c", "miner_thread", 9147);
    v1->last_device_valid_work = time(0);
    drv->hash_work((thr_info *)userdata);
    drv->thread_shutdown((thr_info *)userdata);
    return 0;
  }
  else
  {
    dev_error(v1, dev_reason::REASON_THREAD_FAIL_INIT);
    return 0;
  }
}
