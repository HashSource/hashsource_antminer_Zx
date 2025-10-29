// Alternative name is 'send_result.isra.6'
void __fastcall send_result(io_data *io_data, int c, int isjson, int a4)
{
  const char *v7; // r11
  size_t v8; // r0
  size_t v9; // r2
  int *v10; // r3
  const char *v11; // r4
  int v12; // r0
  int v13; // r1
  char *v14; // r3
  const char *v15; // r2
  signed int v16; // r5
  int v17; // r6
  int v18; // r3
  int v19; // r10
  _BOOL4 v20; // r3
  fd_set *p_tv_usec; // r3
  int v22; // r0
  ssize_t v23; // r0
  ssize_t v24; // r7
  const char *v25; // r2
  int v26; // r0
  char *v27; // r0
  const char *v28; // r2
  const char *v29; // r2
  _WORD *v30; // r3
  const char *v31; // r2
  const char *v32; // r2
  const char *v33; // r2
  int count; // [sp+Ch] [bp-10A0h]
  int v35; // [sp+10h] [bp-109Ch]
  int tosend; // [sp+14h] [bp-1098h]
  timeval timeout; // [sp+20h] [bp-108Ch] BYREF
  fd_set wd; // [sp+28h] [bp-1084h] BYREF
  char tmp42[4100]; // [sp+A8h] [bp-1004h] BYREF

  v7 = (const char *)io_data;
  v8 = strlen((const char *)io_data);
  v9 = v8;
  if ( c )
  {
    LOWORD(v30) = -25844;
    v9 = v8 + 1;
    HIWORD(v30) = (unsigned int)"echo %d > /sys/class/gpio/gpio%d/value" >> 16;
    *(_WORD *)&v7[v8] = *v30;
  }
  if ( a4 )
  {
    LOWORD(v10) = 21116;
    v11 = &v7[v9];
    HIWORD(v10) = (unsigned int)"eply failed (%s) (%d)" >> 16;
    v12 = *v10;
    v13 = v10[1];
    LOBYTE(v10) = *((_BYTE *)v10 + 8);
    *(_DWORD *)&v7[v9] = v12;
    *((_DWORD *)v11 + 1) = v13;
    *((_BYTE *)v11 + 8) = (_BYTE)v10;
    v9 = strlen(v7);
  }
  tosend = v9 + 1;
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v14) = -27628;
    HIWORD(v14) = (unsigned int)"c.txt" >> 16;
    if ( v9 > 0xA )
      v14 = "...";
    LOWORD(v15) = 21172;
    HIWORD(v15) = (unsigned int)"ded (%d) (%d)" >> 16;
    snprintf(tmp42, 0x1000u, v15, tosend, v7, v14);
    applog(7, tmp42, 0);
  }
  v16 = tosend;
  v17 = (isjson + 31) & (isjson >> 31);
  if ( isjson >= 0 )
    v17 = isjson;
  LOBYTE(v18) = isjson & 0x1F;
  if ( isjson <= 0 )
    v18 = -(-isjson & 0x1F);
  v19 = 0;
  count = 0;
  v35 = 1 << v18;
  while ( 1 )
  {
    v20 = count <= 4;
    if ( v16 <= 0 )
      v20 = 0;
    if ( !v20 )
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
    wd.fds_bits[v17 >> 5] |= v35;
    v22 = select(isjson + 1, 0, &wd, 0, &timeout);
    if ( v22 <= 0 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 3 )
      {
        LOWORD(v33) = 21204;
        HIWORD(v33) = (unsigned int)"t was no good" >> 16;
        snprintf(tmp42, 0x1000u, v33, v22);
        applog(4, tmp42, 0);
      }
      return;
    }
    v23 = send(isjson, v7, v16, 0);
    v24 = v23;
    ++v19;
    if ( v23 < 0 )
    {
      v26 = *_errno_location();
      if ( v26 != 11 )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 3 )
        {
          v27 = strerror(v26);
          LOWORD(v28) = 21236;
          HIWORD(v28) = (unsigned int)"cast" >> 16;
          snprintf(tmp42, 0x1000u, v28, tosend, tosend - v16, v27);
          applog(4, tmp42, 0);
        }
        return;
      }
LABEL_29:
      ++count;
    }
    else if ( v19 == 1 )
    {
      if ( v16 != v23 )
      {
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          LOWORD(v29) = 21300;
          HIWORD(v29) = (unsigned int)"API: send reply: (%d) '%.10s%s'" >> 16;
          snprintf(tmp42, 0x1000u, v29, v23, v16);
          applog(7, tmp42, 0);
        }
        goto LABEL_28;
      }
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v31) = 21268;
        HIWORD(v31) = (unsigned int)"%d tot=%d ext=%d in %s %s():%d" >> 16;
        snprintf(tmp42, 0x1000u, v31, v16);
        applog(7, tmp42, 0);
      }
LABEL_49:
      v16 -= v24;
      v7 += v24;
    }
    else if ( v16 == v23 )
    {
      if ( !opt_debug || !use_syslog && !opt_log_output && opt_log_level <= 6 )
        goto LABEL_49;
      LOWORD(v32) = 21328;
      HIWORD(v32) = (unsigned int)"%s'" >> 16;
      snprintf(tmp42, 0x1000u, v32, v16, v19);
      v16 -= v24;
      applog(7, tmp42, 0);
      v7 += v24;
    }
    else
    {
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v25) = 21372;
        HIWORD(v25) = (unsigned int)"d (%d:%d) failed: %s" >> 16;
        snprintf(tmp42, 0x1000u, v25, v23, v16, v19);
        applog(7, tmp42, 0);
      }
LABEL_28:
      v16 -= v24;
      v7 += v24;
      if ( !v24 )
        goto LABEL_29;
    }
  }
}
