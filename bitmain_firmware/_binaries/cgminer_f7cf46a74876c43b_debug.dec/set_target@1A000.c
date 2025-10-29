void __fastcall set_target(unsigned __int8 *dest_target, double diff)
{
  double v3; // d0
  double v5; // d7
  double v6; // d8
  double v7; // d8
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  char *v14; // r6
  unsigned __int8 target[32]; // [sp+0h] [bp-1020h] BYREF
  char tmp42[4096]; // [sp+20h] [bp-1000h] BYREF

  if ( v3 == 0.0 )
  {
    if ( use_syslog || opt_log_output || (v3 = 1.0, opt_log_level > 2) )
    {
      strcpy(tmp42, "Diff zero passed to set_target");
      applog(3, tmp42, 0);
      v3 = 1.0;
    }
  }
  v5 = 2.69595353e67;
  if ( opt_scrypt )
    v5 = 1.7668201e72;
  *(_QWORD *)&target[24] = (unsigned __int64)(v5 / v3 * 1.59309191e-58);
  v6 = v5 / v3 - (double)*(unsigned __int64 *)&target[24] * 6.27710174e57;
  *(_QWORD *)&target[16] = (unsigned __int64)(v6 * 2.93873588e-39);
  v7 = v6 - (double)*(unsigned __int64 *)&target[16] * 3.40282367e38;
  *(_QWORD *)&target[8] = (unsigned __int64)(v7 * 5.42101086e-20);
  *(_QWORD *)target = (unsigned __int64)(v7 - (double)*(unsigned __int64 *)&target[8] * 1.84467441e19);
  if ( opt_debug )
  {
    v14 = bin2hex(target, 0x20u);
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "Generated target %s", v14);
      applog(7, tmp42, 0);
    }
    free(v14);
  }
  v8 = *(_DWORD *)&target[4];
  v9 = *(_DWORD *)&target[8];
  v10 = *(_DWORD *)&target[12];
  *(_DWORD *)dest_target = *(_DWORD *)target;
  *((_DWORD *)dest_target + 1) = v8;
  *((_DWORD *)dest_target + 2) = v9;
  *((_DWORD *)dest_target + 3) = v10;
  v11 = *(_DWORD *)&target[20];
  v12 = *(_DWORD *)&target[24];
  v13 = *(_DWORD *)&target[28];
  *((_DWORD *)dest_target + 4) = *(_DWORD *)&target[16];
  *((_DWORD *)dest_target + 5) = v11;
  *((_DWORD *)dest_target + 6) = v12;
  *((_DWORD *)dest_target + 7) = v13;
}
