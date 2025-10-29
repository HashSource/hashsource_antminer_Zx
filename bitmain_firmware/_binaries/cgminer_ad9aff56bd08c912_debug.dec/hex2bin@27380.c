bool __fastcall hex2bin(unsigned __int8 *p, const char *hexstr, size_t len)
{
  int v4; // r5
  unsigned int v5; // r3
  unsigned int v6; // r4
  _BOOL4 v7; // r0
  const char *v8; // r1
  int v9; // r4
  int v10; // r3
  int *v11; // r4
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r4
  int *v17; // r4
  int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r1
  char tmp42[4096]; // [sp+0h] [bp-1018h] BYREF

  if ( !*hexstr )
  {
    if ( !len )
    {
      LOBYTE(v7) = 1;
      return v7;
    }
    goto LABEL_23;
  }
  if ( !len )
  {
LABEL_23:
    LOBYTE(v7) = 0;
    return v7;
  }
  if ( hexstr[1] )
  {
    LOWORD(v4) = 13056;
    HIWORD(v4) = (unsigned int)"0.0" >> 16;
    v5 = *(_DWORD *)(v4 + 4 * *((unsigned __int8 *)hexstr + 1) + 108);
    v6 = *(_DWORD *)(v4 + 4 * *(unsigned __int8 *)hexstr + 108);
    v7 = (v5 >> 31) | (v6 >> 31);
    if ( v7 )
    {
LABEL_11:
      if ( use_syslog || opt_log_output || opt_log_level > 2 )
      {
        LOWORD(v11) = 16064;
        HIWORD(v11) = (unsigned int)"o sem_post errno=%d cgsem=0x%p in %s %s():%d" >> 16;
        v12 = *v11;
        v13 = v11[1];
        v14 = v11[2];
        v15 = v11[3];
        v16 = v11[4];
        *(_DWORD *)tmp42 = v12;
        *(_DWORD *)&tmp42[4] = v13;
        *(_DWORD *)&tmp42[8] = v14;
        *(_DWORD *)&tmp42[12] = v15;
        *(_DWORD *)&tmp42[16] = v16;
        applog(3, tmp42, 0);
        LOBYTE(v7) = 0;
        return v7;
      }
    }
    else
    {
      v8 = hexstr + 4;
      while ( 1 )
      {
        --len;
        *p++ = v5 | (16 * v6);
        v9 = v4 + 4 * *((unsigned __int8 *)v8 - 2);
        if ( !*(v8 - 2) )
          break;
        if ( !len )
          return v7;
        v10 = *((unsigned __int8 *)v8 - 1);
        v8 += 2;
        if ( !v10 )
          goto LABEL_16;
        v6 = *(_DWORD *)(v9 + 108);
        v5 = *(_DWORD *)(v4 + 4 * v10 + 108);
        if ( ((v6 | v5) & 0x80000000) != 0 )
          goto LABEL_11;
      }
      if ( !len )
      {
        LOBYTE(v7) = 1;
        return v7;
      }
    }
  }
  else
  {
LABEL_16:
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      LOWORD(v17) = 16040;
      HIWORD(v17) = (unsigned int)"SOCKS4 server" >> 16;
      v18 = *v17;
      v19 = v17[1];
      v20 = v17[2];
      v21 = v17[3];
      v17 += 4;
      *(_DWORD *)tmp42 = v18;
      *(_DWORD *)&tmp42[4] = v19;
      *(_DWORD *)&tmp42[8] = v20;
      *(_DWORD *)&tmp42[12] = v21;
      v22 = v17[1];
      *(_DWORD *)&tmp42[16] = *v17;
      *(_WORD *)&tmp42[20] = v22;
      applog(3, tmp42, 0);
    }
  }
  LOBYTE(v7) = 0;
  return v7;
}
