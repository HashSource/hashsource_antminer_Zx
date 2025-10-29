// Alternative name is 'send_result.isra.6'
void __fastcall send_result(io_data *io_data, int c, int isjson, int a4)
{
  const char *v7; // r11
  size_t v8; // r0
  size_t v9; // r2
  const char *v10; // r3
  signed int v11; // r5
  int v12; // r6
  int v13; // r3
  int v14; // r10
  _BOOL4 v15; // r3
  fd_set *p_tv_usec; // r3
  int v17; // r0
  ssize_t v18; // r0
  ssize_t v19; // r7
  int v20; // r0
  char *v21; // r0
  int count; // [sp+Ch] [bp-10A0h]
  int v23; // [sp+10h] [bp-109Ch]
  int tosend; // [sp+14h] [bp-1098h]
  timeval timeout; // [sp+20h] [bp-108Ch] BYREF
  fd_set wd; // [sp+28h] [bp-1084h] BYREF
  char tmp42[4100]; // [sp+A8h] [bp-1004h] BYREF

  v7 = (const char *)io_data;
  v8 = strlen((const char *)io_data);
  v9 = v8;
  if ( c )
  {
    v9 = v8 + 1;
    *(_WORD *)&v7[v8] = 93;
  }
  if ( a4 )
  {
    strcpy((char *)&v7[v9], ",\"id\":1}");
    v9 = strlen(v7);
  }
  tosend = v9 + 1;
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    v10 = &byte_59398;
    if ( v9 > 0xA )
      v10 = "...";
    snprintf(tmp42, 0x1000u, "API: send reply: (%d) '%.10s%s'", tosend, v7, v10);
    applog(7, tmp42, 0);
  }
  v11 = tosend;
  v12 = (isjson + 31) & (isjson >> 31);
  if ( isjson >= 0 )
    v12 = isjson;
  LOBYTE(v13) = isjson & 0x1F;
  if ( isjson <= 0 )
    v13 = -(-isjson & 0x1F);
  v14 = 0;
  count = 0;
  v23 = 1 << v13;
  while ( 1 )
  {
    v15 = count <= 4;
    if ( v11 <= 0 )
      v15 = 0;
    if ( !v15 )
      break;
    p_tv_usec = (fd_set *)&timeout.tv_usec;
    timeout.tv_sec = 0;
    timeout.tv_usec = 50000;
    do
    {
      p_tv_usec->fds_bits[1] = 0;
      p_tv_usec = (fd_set *)((char *)p_tv_usec + 4);
    }
    while ( &wd.fds_bits[31] != (__fd_mask *)p_tv_usec );
    wd.fds_bits[v12 >> 5] |= v23;
    v17 = select(isjson + 1, 0, &wd, 0, &timeout);
    if ( v17 <= 0 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 3 )
      {
        snprintf(tmp42, 0x1000u, "API: send select failed (%d)", v17);
        applog(4, tmp42, 0);
      }
      return;
    }
    v18 = send(isjson, v7, v11, 0);
    v19 = v18;
    ++v14;
    if ( v18 < 0 )
    {
      v20 = *_errno_location();
      if ( v20 != 11 )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 3 )
        {
          v21 = strerror(v20);
          snprintf(tmp42, 0x1000u, "API: send (%d:%d) failed: %s", tosend, tosend - v11, v21);
          applog(4, tmp42, 0);
        }
        return;
      }
LABEL_29:
      ++count;
    }
    else if ( v14 == 1 )
    {
      if ( v11 != v18 )
      {
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          snprintf(tmp42, 0x1000u, "API: sent %d of %d first go", v18, v11);
          applog(7, tmp42, 0);
        }
        goto LABEL_28;
      }
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        snprintf(tmp42, 0x1000u, "API: sent all of %d first go", v11);
        applog(7, tmp42, 0);
      }
LABEL_49:
      v11 -= v19;
      v7 += v19;
    }
    else if ( v11 == v18 )
    {
      if ( !opt_debug || !use_syslog && !opt_log_output && opt_log_level <= 6 )
        goto LABEL_49;
      snprintf(tmp42, 0x1000u, "API: sent all of remaining %d (sendc=%d)", v11, v14);
      v11 -= v19;
      applog(7, tmp42, 0);
      v7 += v19;
    }
    else
    {
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        snprintf(tmp42, 0x1000u, "API: sent %d of remaining %d (sendc=%d)", v18, v11, v14);
        applog(7, tmp42, 0);
      }
LABEL_28:
      v11 -= v19;
      v7 += v19;
      if ( !v19 )
        goto LABEL_29;
    }
  }
}
