void __fastcall roll_work(work *work)
{
  _BOOL4 v2; // r5
  unsigned int v3; // r3
  int v4; // r0
  unsigned int v5; // r1
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
    strcpy(tmp42, "Successfully rolled work");
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
