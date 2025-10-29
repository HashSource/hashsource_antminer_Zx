void *__fastcall miner_thread(void *userdata)
{
  cgpu_info *v1; // r8
  const char *v3; // r2
  device_drv *drv; // r7
  int *v5; // r6
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3
  const char *v13; // r2
  const char *v14; // r1
  char threadname[16]; // [sp+0h] [bp-1010h] BYREF
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  v1 = (cgpu_info *)*((_DWORD *)userdata + 9);
  LOWORD(v3) = -3180;
  HIWORD(v3) = (unsigned int)"ed to open %s for share log" >> 16;
  drv = v1->drv;
  snprintf(threadname, 0x10u, v3, *(_DWORD *)userdata);
  RenameThread(threadname);
  thread_reportout((thr_info *)userdata);
  if ( ((int (__fastcall *)(void *))drv->thread_init)(userdata) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v5) = -3168;
      HIWORD(v5) = (unsigned int)"s for share log" >> 16;
      v6 = *v5;
      v7 = v5[1];
      v8 = v5[2];
      v9 = v5[3];
      v5 += 4;
      *(_DWORD *)tmp42 = v6;
      *(_DWORD *)&tmp42[4] = v7;
      *(_DWORD *)&tmp42[8] = v8;
      *(_DWORD *)&tmp42[12] = v9;
      v10 = v5[1];
      v11 = v5[2];
      v12 = v5[3];
      *(_DWORD *)&tmp42[16] = *v5;
      *(_DWORD *)&tmp42[20] = v10;
      *(_DWORD *)&tmp42[24] = v11;
      *(_WORD *)&tmp42[28] = v12;
      tmp42[30] = BYTE2(v12);
      applog(7, tmp42, 0);
    }
    LOWORD(v13) = -15028;
    LOWORD(v14) = -3136;
    HIWORD(v13) = (unsigned int)&loc_4C524 >> 16;
    HIWORD(v14) = (unsigned int)"iner" >> 16;
    cgsem_wait((cgsem_t *)userdata + 1, v14, v13, 9147);
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
