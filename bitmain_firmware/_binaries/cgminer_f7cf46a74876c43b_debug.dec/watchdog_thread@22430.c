void *__fastcall __noreturn watchdog_thread(void *userdata)
{
  int v1; // r5
  _BOOL4 v2; // r3
  cgpu_info *devices; // r0
  cgpu_info *v4; // r4
  thr_info *v5; // r6
  alive status; // r1
  int v7; // r3
  _BOOL4 v8; // r3
  thr_info **v9; // r3
  thr_info **v10; // r1
  int v11; // t1
  int v12; // r4
  thr_info *thread; // r0
  cgsem_t *v14; // r5
  _BOOL4 v15; // r3
  int *v16; // r0
  int *v17; // r0
  timeval now; // [sp+30h] [bp-1014h] BYREF
  char dev_str[8]; // [sp+38h] [bp-100Ch] BYREF
  char tmp42[4100]; // [sp+40h] [bp-1004h] BYREF

  pthread_setcanceltype(1, 0);
  RenameThread("Watchdog");
  set_lowprio();
  cgtime(&rotate_tv);
LABEL_2:
  while ( 1 )
  {
    sleep(2u);
    discard_stale();
    hashmeter(-1, 0);
    cgtime(&now);
    if ( sched_paused )
      goto LABEL_92;
    if ( schedstart.enable || schedstop.enable )
    {
      if ( !should_run() )
      {
        if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
        {
          if ( !schedstart.enable )
            goto LABEL_86;
          goto LABEL_50;
        }
        snprintf(
          tmp42,
          0x1000u,
          "Pausing execution as per stop time %02d:%02d scheduled",
          schedstop.tm.tm_hour,
          schedstop.tm.tm_min);
        applog(4, tmp42, 0);
        if ( !schedstart.enable )
        {
LABEL_86:
          strcpy(tmp42, "Terminating execution as planned");
          applog(3, tmp42, 1);
          _quit(0, 1);
        }
        if ( use_syslog || opt_log_output )
        {
LABEL_60:
          snprintf(
            tmp42,
            0x1000u,
            "Will restart execution as scheduled at %02d:%02d",
            schedstart.tm.tm_hour,
            schedstart.tm.tm_min);
          applog(4, tmp42, 0);
        }
        else
        {
LABEL_50:
          if ( opt_log_level > 3 )
            goto LABEL_60;
        }
        sched_paused = 1;
        if ( pthread_rwlock_rdlock(&mining_thr_lock) )
        {
          v16 = _errno_location();
          snprintf(
            tmp42,
            0x1000u,
            "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
            *v16,
            "cgminer.c",
            "watchdog_thread",
            9721);
          goto LABEL_88;
        }
        if ( mining_threads > 0 )
        {
          v9 = mining_thr;
          v10 = &mining_thr[mining_threads];
          do
          {
            v11 = (int)*v9++;
            *(_BYTE *)(v11 + 60) = 1;
          }
          while ( v9 != v10 );
        }
        if ( pthread_rwlock_unlock(&mining_thr_lock) )
        {
          v17 = _errno_location();
          snprintf(
            tmp42,
            0x1000u,
            "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
            *v17,
            "cgminer.c",
            "watchdog_thread",
            9724);
LABEL_88:
          applog(3, tmp42, 1);
          _quit(1, 1);
        }
        selective_yield();
        goto LABEL_6;
      }
      if ( sched_paused )
      {
LABEL_92:
        if ( !schedstart.enable && !schedstop.enable || should_run() )
          break;
      }
    }
LABEL_6:
    if ( total_devices > 0 )
    {
      v1 = 0;
      while ( 1 )
      {
        devices = get_devices(v1);
        v4 = devices;
        v5 = *devices->thr;
        if ( v5 )
        {
          ((void (*)(void))devices->drv->get_stats)();
          snprintf(dev_str, 8u, "%s %d", v4->drv->name, v4->device_id);
          if ( !v5->getwork && v4->deven != dev_enable::DEV_DISABLED )
          {
            status = v4->status;
            v7 = now.tv_sec - v5->last.tv_sec;
            if ( status == alive::LIFE_WELL )
            {
              if ( v7 <= 120 )
                goto LABEL_20;
              v2 = use_syslog;
              v4->rolling = 0.0;
              v4->status = alive::LIFE_SICK;
              if ( v2 || opt_log_output || opt_log_level > 2 )
              {
                snprintf(tmp42, 0x1000u, "%s: Idle for more than 60 seconds, declaring SICK!", dev_str);
                applog(3, tmp42, 0);
              }
              cgtime(&v5->sick);
              dev_error(v4, dev_reason::REASON_DEV_SICK_IDLE_60);
              if ( !opt_restart )
                goto LABEL_20;
              if ( use_syslog || opt_log_output || opt_log_level > 2 )
              {
                snprintf(tmp42, 0x1000u, "%s: Attempting to restart", dev_str);
                applog(3, tmp42, 0);
              }
LABEL_18:
              if ( v4->deven != dev_enable::DEV_DISABLED )
                v4->drv->reinit_device(v4);
              goto LABEL_20;
            }
            if ( v7 > 119 )
            {
              if ( status == alive::LIFE_SICK )
              {
                if ( v7 <= 600 )
                {
                  if ( now.tv_sec - v5->sick.tv_sec > 60 )
                  {
                    cgtime(&v5->sick);
                    if ( opt_restart )
                      goto LABEL_18;
                  }
                }
                else
                {
                  v8 = use_syslog;
                  v4->status = alive::LIFE_DEAD;
                  if ( v8 || opt_log_output || opt_log_level > 2 )
                  {
                    snprintf(tmp42, 0x1000u, "%s: Not responded for more than 10 minutes, declaring DEAD!", dev_str);
                    applog(3, tmp42, 0);
                  }
                  cgtime(&v5->sick);
                  dev_error(v4, dev_reason::REASON_DEV_DEAD_IDLE_600);
                }
              }
              else if ( now.tv_sec - v5->sick.tv_sec > 60 && status == alive::LIFE_DEAD )
              {
                cgtime(&v5->sick);
                if ( opt_restart )
                  goto LABEL_18;
              }
            }
            else
            {
              if ( status != alive::LIFE_INIT && (use_syslog || opt_log_output || opt_log_level > 2) )
              {
                snprintf(tmp42, 0x1000u, "%s: Recovered, declaring WELL!", dev_str);
                applog(3, tmp42, 0);
              }
              v4->status = alive::LIFE_WELL;
              v4->device_last_well = time(0);
            }
          }
        }
LABEL_20:
        if ( total_devices <= ++v1 )
          goto LABEL_2;
      }
    }
  }
  if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "Restarting execution as per start time %02d:%02d scheduled",
      schedstart.tm.tm_hour,
      schedstart.tm.tm_min);
    applog(4, tmp42, 0);
    if ( !schedstop.enable )
      goto LABEL_68;
    if ( use_syslog || opt_log_output )
    {
LABEL_82:
      snprintf(
        tmp42,
        0x1000u,
        "Will pause execution as scheduled at %02d:%02d",
        schedstop.tm.tm_hour,
        schedstop.tm.tm_min);
      applog(4, tmp42, 0);
LABEL_68:
      v12 = 0;
      for ( sched_paused = 0; mining_threads > v12; ++v12 )
      {
        thread = get_thread(v12);
        v14 = (cgsem_t *)thread;
        if ( thread->cgpu->deven != dev_enable::DEV_DISABLED )
        {
          v15 = opt_debug;
          thread->pause = 0;
          if ( v15 && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            snprintf(tmp42, 0x1000u, "Pushing sem post to thread %d", thread->id);
            applog(7, tmp42, 0);
          }
          cgsem_post(v14 + 1, "cgminer.c", "watchdog_thread", 9746);
        }
      }
      goto LABEL_6;
    }
  }
  else if ( !schedstop.enable )
  {
    goto LABEL_68;
  }
  if ( opt_log_level <= 3 )
    goto LABEL_68;
  goto LABEL_82;
}
