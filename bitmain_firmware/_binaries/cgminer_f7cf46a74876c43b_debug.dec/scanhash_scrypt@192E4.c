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
  uint32_t data[20]; // [sp+0h] [bp-1050h] BYREF
  uint32_t ostate[1024]; // [sp+50h] [bp-1000h] BYREF

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
    v18 = 0;
    strcpy((char *)ostate, "Failed to malloc scratchbuf in scanhash_scrypt");
    applog(3, (const char *)ostate, 0);
  }
  return v18;
}
