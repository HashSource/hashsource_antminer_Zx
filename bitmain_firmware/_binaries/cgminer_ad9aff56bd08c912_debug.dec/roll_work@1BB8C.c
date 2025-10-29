void __fastcall roll_work(work *work)
{
  _BOOL4 v2; // r5
  unsigned int v3; // r3
  int v4; // r0
  unsigned int v5; // r1
  int *v6; // r6
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  char *ntime; // r5
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  v2 = opt_debug;
  v3 = bswap32(bswap32(*(_DWORD *)&work->data[68]) + 1);
  v4 = work->rolls + 1;
  v5 = local_work + 1;
  *(_DWORD *)&work->data[68] = v3;
  work->rolls = v4;
  work->nonce = 0;
  local_work = v5;
  if ( v2 && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v6) = -296;
    HIWORD(v6) = (unsigned int)"RROR ON UNLOCK! errno=%d in %s %s():%d" >> 16;
    v7 = *v6;
    v8 = v6[1];
    v9 = v6[2];
    v10 = v6[3];
    v6 += 4;
    *(_DWORD *)tmp42 = v7;
    *(_DWORD *)&tmp42[4] = v8;
    *(_DWORD *)&tmp42[8] = v9;
    *(_DWORD *)&tmp42[12] = v10;
    v11 = v6[1];
    v12 = v6[2];
    *(_DWORD *)&tmp42[16] = *v6;
    *(_DWORD *)&tmp42[20] = v11;
    tmp42[24] = v12;
    applog(7, tmp42, 0);
  }
  ntime = work->ntime;
  if ( ntime )
  {
    hex2bin((unsigned __int8 *)tmp42, work->ntime, 4u);
    *(_DWORD *)tmp42 = bswap32(bswap32(*(unsigned int *)tmp42) + 1);
    _bin2hex(ntime, (const unsigned __int8 *)tmp42, 4u);
  }
  work->id = total_work_inc();
}
