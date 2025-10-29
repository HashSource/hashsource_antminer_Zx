void *__fastcall __noreturn watchdog_thread(void *userdata)
{
  const char *v1; // r0
  const char *v2; // r8
  int v3; // r5
  _BOOL4 v4; // r3
  const char *v5; // r2
  const char *v6; // r2
  cgpu_info *devices; // r0
  cgpu_info *v8; // r4
  thr_info *v9; // r6
  alive status; // r1
  int v11; // r3
  const char *v12; // r2
  _BOOL4 v13; // r3
  const char *v14; // r2
  thr_info **v15; // r3
  thr_info **v16; // r1
  int v17; // t1
  const char *v18; // r2
  int v19; // r4
  const char *v20; // r6
  thr_info *thread; // r0
  cgsem_t *v22; // r5
  _BOOL4 v23; // r3
  const char *v24; // r2
  const char *v25; // r2
  int *v26; // r4
  int v27; // r0
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r0
  int v32; // r1
  int v33; // r2
  int v34; // r3
  int v35; // r4
  int *v36; // r0
  int v37; // r3
  const char *v38; // r2
  int *v39; // r0
  int v40; // r3
  const char *v41; // r2
  timeval now; // [sp+30h] [bp-1014h] BYREF
  char dev_str[8]; // [sp+38h] [bp-100Ch] BYREF
  char tmp42[4096]; // [sp+40h] [bp-1004h] BYREF

  pthread_setcanceltype(1, 0);
  LOWORD(v1) = 3532;
  HIWORD(v1) = (unsigned int)"Driver %s working diff changed to %.0f" >> 16;
  RenameThread(v1);
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
      goto LABEL_93;
    if ( schedstart.enable || schedstop.enable )
    {
      if ( !should_run() )
      {
        if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
        {
          if ( !schedstart.enable )
            goto LABEL_87;
          goto LABEL_50;
        }
        LOWORD(v18) = 3544;
        HIWORD(v18) = (unsigned int)"rking diff changed to %.0f" >> 16;
        snprintf(tmp42, 0x1000u, v18, schedstop.tm.tm_hour, schedstop.tm.tm_min);
        applog(4, tmp42, 0);
        if ( !schedstart.enable )
        {
LABEL_87:
          LOWORD(v26) = 3600;
          HIWORD(v26) = (unsigned int)"n as per stop time %02d:%02d scheduled" >> 16;
          v27 = *v26;
          v28 = v26[1];
          v29 = v26[2];
          v30 = v26[3];
          v26 += 4;
          *(_DWORD *)tmp42 = v27;
          *(_DWORD *)&tmp42[4] = v28;
          *(_DWORD *)&tmp42[8] = v29;
          *(_DWORD *)&tmp42[12] = v30;
          v31 = *v26;
          v32 = v26[1];
          v33 = v26[2];
          v34 = v26[3];
          v35 = v26[4];
          *(_DWORD *)&tmp42[16] = v31;
          *(_DWORD *)&tmp42[20] = v32;
          *(_DWORD *)&tmp42[24] = v33;
          *(_DWORD *)&tmp42[28] = v34;
          tmp42[32] = v35;
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
          v36 = _errno_location();
          LOWORD(v37) = -3136;
          HIWORD(v37) = (unsigned int)"iner" >> 16;
          LOWORD(v38) = -232;
          HIWORD(v38) = (unsigned int)"" >> 16;
          snprintf(tmp42, 0x1000u, v38, *v36, v37, "watchdog_thread", 9721);
          goto LABEL_89;
        }
        if ( mining_threads > 0 )
        {
          v15 = mining_thr;
          v16 = &mining_thr[mining_threads];
          do
          {
            v17 = (int)*v15++;
            *(_BYTE *)(v17 + 60) = 1;
          }
          while ( v15 != v16 );
        }
        if ( pthread_rwlock_unlock(&mining_thr_lock) )
        {
          v39 = _errno_location();
          LOWORD(v40) = -3136;
          HIWORD(v40) = (unsigned int)"iner" >> 16;
          LOWORD(v41) = -348;
          HIWORD(v41) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
          snprintf(tmp42, 0x1000u, v41, *v39, v40, "watchdog_thread", 9724);
LABEL_89:
          applog(3, tmp42, 1);
          _quit(1, 1);
        }
        selective_yield();
        goto LABEL_6;
      }
      if ( sched_paused )
      {
LABEL_93:
        if ( !schedstart.enable && !schedstop.enable || should_run() )
          break;
      }
    }
LABEL_6:
    if ( total_devices > 0 )
    {
      LOWORD(v2) = 3828;
      v3 = 0;
      while ( 1 )
      {
        devices = get_devices(v3);
        v8 = devices;
        v9 = *devices->thr;
        if ( v9 )
        {
          ((void (*)(void))devices->drv->get_stats)();
          HIWORD(v2) = (unsigned int)"d:%02d" >> 16;
          snprintf(dev_str, 8u, v2, v8->drv->name, v8->device_id);
          if ( !v9->getwork && v8->deven != dev_enable::DEV_DISABLED )
          {
            status = v8->status;
            v11 = now.tv_sec - v9->last.tv_sec;
            if ( status == alive::LIFE_WELL )
            {
              if ( v11 <= 120 )
                goto LABEL_20;
              v4 = use_syslog;
              v8->rolling = 0.0;
              v8->status = alive::LIFE_SICK;
              if ( v4 || opt_log_output || opt_log_level > 2 )
              {
                LOWORD(v5) = 3868;
                HIWORD(v5) = (unsigned int)"%s %d" >> 16;
                snprintf(tmp42, 0x1000u, v5, dev_str);
                applog(3, tmp42, 0);
              }
              cgtime(&v9->sick);
              dev_error(v8, dev_reason::REASON_DEV_SICK_IDLE_60);
              if ( !opt_restart )
                goto LABEL_20;
              if ( use_syslog || opt_log_output || opt_log_level > 2 )
              {
                LOWORD(v6) = 3920;
                HIWORD(v6) = (unsigned int)" more than 60 seconds, declaring SICK!" >> 16;
                snprintf(tmp42, 0x1000u, v6, dev_str);
                applog(3, tmp42, 0);
              }
LABEL_18:
              if ( v8->deven != dev_enable::DEV_DISABLED )
                v8->drv->reinit_device(v8);
              goto LABEL_20;
            }
            if ( v11 > 119 )
            {
              if ( status == alive::LIFE_SICK )
              {
                if ( v11 <= 600 )
                {
                  if ( now.tv_sec - v9->sick.tv_sec > 60 )
                  {
                    cgtime(&v9->sick);
                    if ( opt_restart )
                      goto LABEL_18;
                  }
                }
                else
                {
                  v13 = use_syslog;
                  v8->status = alive::LIFE_DEAD;
                  if ( v13 || opt_log_output || opt_log_level > 2 )
                  {
                    LOWORD(v14) = 3948;
                    HIWORD(v14) = (unsigned int)"ring SICK!" >> 16;
                    snprintf(tmp42, 0x1000u, v14, dev_str);
                    applog(3, tmp42, 0);
                  }
                  cgtime(&v9->sick);
                  dev_error(v8, dev_reason::REASON_DEV_DEAD_IDLE_600);
                }
              }
              else if ( now.tv_sec - v9->sick.tv_sec > 60 && status == alive::LIFE_DEAD )
              {
                cgtime(&v9->sick);
                if ( opt_restart )
                  goto LABEL_18;
              }
            }
            else
            {
              if ( status != alive::LIFE_INIT && (use_syslog || opt_log_output || opt_log_level > 2) )
              {
                LOWORD(v12) = 3836;
                HIWORD(v12) = (unsigned int)"Pushing sem post to thread %d" >> 16;
                snprintf(tmp42, 0x1000u, v12, dev_str);
                applog(3, tmp42, 0);
              }
              v8->status = alive::LIFE_WELL;
              v8->device_last_well = time(0);
            }
          }
        }
LABEL_20:
        if ( total_devices <= ++v3 )
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
LABEL_83:
      LOWORD(v25) = 3748;
      HIWORD(v25) = (unsigned int)" as per start time %02d:%02d scheduled" >> 16;
      snprintf(tmp42, 0x1000u, v25, schedstop.tm.tm_hour, schedstop.tm.tm_min);
      applog(4, tmp42, 0);
LABEL_68:
      v19 = 0;
      sched_paused = 0;
      if ( mining_threads > 0 )
      {
        LOWORD(v20) = -3136;
        do
        {
          thread = get_thread(v19);
          v22 = (cgsem_t *)thread;
          if ( thread->cgpu->deven != dev_enable::DEV_DISABLED )
          {
            v23 = opt_debug;
            thread->pause = 0;
            if ( v23 && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              LOWORD(v24) = 3796;
              HIWORD(v24) = (unsigned int)"se execution as scheduled at %02d:%02d" >> 16;
              snprintf(tmp42, 0x1000u, v24, thread->id);
              applog(7, tmp42, 0);
            }
            HIWORD(v20) = (unsigned int)"iner" >> 16;
            cgsem_post(v22 + 1, v20, "watchdog_thread", 9746);
          }
          ++v19;
        }
        while ( mining_threads > v19 );
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
  goto LABEL_83;
}
