bool __fastcall scanhash_scrypt(
        thr_info *thr,
        const unsigned __int8 *pmidstate,
        unsigned __int8 *pdata,
        unsigned __int8 *phash1,
        unsigned __int8 *phash,
        const unsigned __int8 *ptarget,
        uint32_t max_nonce,
        uint32_t *last_nonce,
        uint32_t n)
{
  unsigned __int8 *v11; // r1
  uint32_t *v12; // r2
  unsigned int v13; // r5
  unsigned int v15; // t1
  char *v16; // r9
  unsigned int v17; // r10
  bool v18; // r4
  uint32_t *v20; // r6
  uint32_t v21; // r0
  uint32_t v22; // r1
  uint32_t v23; // r2
  uint32_t v24; // r3
  uint32_t v25; // r0
  uint32_t v26; // r1
  uint32_t v27; // r2
  uint32_t v28; // r3
  uint32_t v29; // r1
  uint32_t v30; // r2
  uint32_t v31; // r3
  uint32_t data[20]; // [sp+0h] [bp-1050h] BYREF
  uint32_t ostate[8]; // [sp+50h] [bp-1000h] BYREF
  uint32_t v34; // [sp+70h] [bp-FE0h]
  uint32_t v35; // [sp+74h] [bp-FDCh]
  uint32_t v36; // [sp+78h] [bp-FD8h]
  __int16 v37; // [sp+7Ch] [bp-FD4h]
  char v38; // [sp+7Eh] [bp-FD2h]

  v11 = pdata - 4;
  v12 = &data[-1];
  v13 = *((_DWORD *)ptarget + 7);
  do
  {
    v15 = *((_DWORD *)v11 + 1);
    v11 += 4;
    v12[1] = bswap32(v15);
    ++v12;
  }
  while ( v12 != &data[18] );
  v16 = (char *)malloc(0x20200u);
  if ( v16 )
  {
    while ( 1 )
    {
      *((_DWORD *)pdata + 19) = ++n;
      v17 = bswap32(n);
      data[19] = v17;
      scrypt_1024_1_1_256_sp(data, v16, ostate);
      if ( v13 >= bswap32(ostate[7]) )
        break;
      if ( n >= max_nonce || thr->work_restart )
      {
        v18 = 0;
        *last_nonce = n;
        goto LABEL_8;
      }
    }
    *((_DWORD *)pdata + 19) = v17;
    v18 = 1;
    *last_nonce = n;
LABEL_8:
    free(v16);
  }
  else if ( use_syslog || (v18 = opt_log_output) || opt_log_level > 2 )
  {
    LOWORD(v20) = -2724;
    HIWORD(v20) = (unsigned int)"htarget %08lx diff1 %08lx hash %08lx" >> 16;
    v18 = 0;
    v21 = *v20;
    v22 = v20[1];
    v23 = v20[2];
    v24 = v20[3];
    v20 += 4;
    ostate[0] = v21;
    ostate[1] = v22;
    ostate[2] = v23;
    ostate[3] = v24;
    v25 = *v20;
    v26 = v20[1];
    v27 = v20[2];
    v28 = v20[3];
    v20 += 4;
    ostate[4] = v25;
    ostate[5] = v26;
    ostate[6] = v27;
    ostate[7] = v28;
    v29 = v20[1];
    v30 = v20[2];
    v31 = v20[3];
    v34 = *v20;
    v35 = v29;
    v36 = v30;
    v37 = v31;
    v38 = BYTE2(v31);
    applog(3, (const char *)ostate, 0);
  }
  return v18;
}
