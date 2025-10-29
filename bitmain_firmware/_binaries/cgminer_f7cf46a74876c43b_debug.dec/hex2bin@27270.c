bool __fastcall hex2bin(unsigned __int8 *p, const char *hexstr, size_t len)
{
  unsigned int v4; // r3
  unsigned int v5; // r4
  _BOOL4 v6; // r0
  const char *v7; // r1
  const char *v8; // r4
  int v9; // r3
  char tmp42[4096]; // [sp+0h] [bp-1018h] BYREF

  if ( !*hexstr )
  {
    if ( !len )
    {
      LOBYTE(v6) = 1;
      return v6;
    }
    goto LABEL_23;
  }
  if ( !len )
  {
LABEL_23:
    LOBYTE(v6) = 0;
    return v6;
  }
  if ( hexstr[1] )
  {
    v4 = *(_DWORD *)&_func___12024[4 * *((unsigned __int8 *)hexstr + 1) + 108];
    v5 = *(_DWORD *)&_func___12024[4 * *(unsigned __int8 *)hexstr + 108];
    v6 = (v4 >> 31) | (v5 >> 31);
    if ( v6 )
    {
LABEL_11:
      if ( use_syslog || opt_log_output || opt_log_level > 2 )
      {
        strcpy(tmp42, "hex2bin scan failed");
        applog(3, tmp42, 0);
        LOBYTE(v6) = 0;
        return v6;
      }
    }
    else
    {
      v7 = hexstr + 4;
      while ( 1 )
      {
        --len;
        *p++ = v4 | (16 * v5);
        v8 = &_func___12024[4 * *((unsigned __int8 *)v7 - 2)];
        if ( !*(v7 - 2) )
          break;
        if ( !len )
          return v6;
        v9 = *((unsigned __int8 *)v7 - 1);
        v7 += 2;
        if ( !v9 )
          goto LABEL_16;
        v5 = *((_DWORD *)v8 + 27);
        v4 = *(_DWORD *)&_func___12024[4 * v9 + 108];
        if ( ((v5 | v4) & 0x80000000) != 0 )
          goto LABEL_11;
      }
      if ( !len )
      {
        LOBYTE(v6) = 1;
        return v6;
      }
    }
  }
  else
  {
LABEL_16:
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      strcpy(tmp42, "hex2bin str truncated");
      applog(3, tmp42, 0);
    }
  }
  LOBYTE(v6) = 0;
  return v6;
}
