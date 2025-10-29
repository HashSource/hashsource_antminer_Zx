bool __fastcall fulltest(const unsigned __int8 *hash, const unsigned __int8 *target)
{
  const unsigned __int8 *v2; // r3
  const unsigned __int8 *v3; // r2
  unsigned int v4; // r5
  unsigned int v5; // t1
  unsigned int v6; // t1
  bool v7; // cf
  _BOOL4 v8; // r5
  __int64 v10; // kr00_8
  unsigned int v11; // r6
  unsigned int v12; // r2
  __int64 v13; // kr08_8
  __int64 v14; // r6
  unsigned int v15; // r2
  unsigned int v16; // r3
  unsigned int v17; // r2
  unsigned int v18; // r3
  unsigned int v19; // r12
  __int64 v20; // kr10_8
  char *v21; // r7
  char *v22; // r0
  char *v23; // r6
  const char *v24; // r3
  const char *v25; // r2
  unsigned __int8 hash_swap[32]; // [sp+8h] [bp-1044h] BYREF
  unsigned __int8 target_swap[32]; // [sp+28h] [bp-1024h] BYREF
  char tmp42[4100]; // [sp+48h] [bp-1004h] BYREF

  v2 = hash + 32;
  v3 = target + 32;
  while ( 1 )
  {
    v5 = *((_DWORD *)v2 - 1);
    v2 -= 4;
    v4 = v5;
    v6 = *((_DWORD *)v3 - 1);
    v3 -= 4;
    v7 = v4 >= v6;
    if ( v4 > v6 )
      break;
    if ( !v7 || hash == v2 )
    {
      v8 = 1;
      goto LABEL_7;
    }
  }
  v8 = 0;
LABEL_7:
  if ( !opt_debug )
    return v8;
  v10 = *((_QWORD *)hash + 3);
  v11 = *((_DWORD *)hash + 5);
  *(_DWORD *)hash_swap = bswap32(HIDWORD(v10));
  v12 = *((_DWORD *)hash + 4);
  *(_DWORD *)&hash_swap[4] = bswap32(v10);
  *(_DWORD *)&hash_swap[8] = bswap32(v11);
  v13 = *((_QWORD *)hash + 1);
  *(_DWORD *)&hash_swap[12] = bswap32(v12);
  v14 = *(_QWORD *)hash;
  v15 = *((_DWORD *)target + 7);
  *(_DWORD *)&hash_swap[20] = bswap32(v13);
  v16 = *((_DWORD *)target + 6);
  *(_DWORD *)&hash_swap[24] = bswap32(HIDWORD(v14));
  *(_DWORD *)&hash_swap[28] = bswap32(v14);
  LODWORD(v14) = *((_DWORD *)target + 5);
  HIDWORD(v14) = bswap32(v16);
  *(_DWORD *)target_swap = bswap32(v15);
  v17 = *((_DWORD *)target + 3);
  v18 = bswap32(v14);
  LODWORD(v14) = *((_DWORD *)target + 4);
  *(_DWORD *)&hash_swap[16] = bswap32(HIDWORD(v13));
  *(_DWORD *)&target_swap[4] = HIDWORD(v14);
  v19 = bswap32(v14);
  *(_DWORD *)&target_swap[8] = v18;
  LODWORD(v14) = *((_DWORD *)target + 2);
  v20 = *(_QWORD *)target;
  *(_DWORD *)&target_swap[12] = v19;
  *(_DWORD *)&target_swap[16] = bswap32(v17);
  *(_DWORD *)&target_swap[24] = bswap32(HIDWORD(v20));
  *(_DWORD *)&target_swap[28] = bswap32(v20);
  *(_DWORD *)&target_swap[20] = bswap32(v14);
  v21 = bin2hex(hash_swap, 0x20u);
  v22 = bin2hex(target_swap, 0x20u);
  v23 = v22;
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v24) = 16204;
    HIWORD(v24) = (unsigned int)" failed" >> 16;
    if ( !v8 )
      v24 = "no (false positive; hash > target)";
    LOWORD(v25) = 16264;
    HIWORD(v25) = (unsigned int)"Pool %d extranonce set to %s" >> 16;
    snprintf(tmp42, 0x1000u, v25, v21, v22, v24);
    applog(7, tmp42, 0);
  }
  free(v21);
  free(v23);
  return v8;
}
