// Alternative name is 'mt_disable.isra.19'
void __fastcall mt_disable(thr_info *mythr, int thr_id, device_drv *drv)
{
  const char *v6; // r2
  _BOOL4 v7; // r3
  int *v8; // r6
  int v9; // r0
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r3
  const char *v16; // r1
  const char *v17; // r2
  char tmp42[4096]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    LOWORD(v6) = -2924;
    HIWORD(v6) = (unsigned int)"time set." >> 16;
    snprintf(tmp42, 0x1000u, v6, thr_id);
    applog(4, tmp42, 0);
  }
  v7 = opt_debug;
  mythr->cgpu->rolling = 0.0;
  if ( v7 && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v8) = -3168;
    HIWORD(v8) = (unsigned int)"s for share log" >> 16;
    v9 = *v8;
    v10 = v8[1];
    v11 = v8[2];
    v12 = v8[3];
    v8 += 4;
    *(_DWORD *)tmp42 = v9;
    *(_DWORD *)&tmp42[4] = v10;
    *(_DWORD *)&tmp42[8] = v11;
    *(_DWORD *)&tmp42[12] = v12;
    v13 = v8[1];
    v14 = v8[2];
    v15 = v8[3];
    *(_DWORD *)&tmp42[16] = *v8;
    *(_DWORD *)&tmp42[20] = v13;
    *(_DWORD *)&tmp42[24] = v14;
    *(_WORD *)&tmp42[28] = v15;
    tmp42[30] = BYTE2(v15);
    applog(7, tmp42, 0);
  }
  LOWORD(v16) = -3136;
  HIWORD(v16) = (unsigned int)"iner" >> 16;
  cgsem_wait(&mythr->sem, v16, "mt_disable", 8561);
  if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    LOWORD(v17) = -2896;
    HIWORD(v17) = (unsigned int)"t of range" >> 16;
    snprintf(tmp42, 0x1000u, v17, thr_id);
    applog(4, tmp42, 0);
  }
  ((void (__fastcall *)(thr_info *))drv->drv_id)(mythr);
}
