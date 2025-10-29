int __fastcall scrypt_test(unsigned __int8 *pdata, const unsigned __int8 *ptarget, uint32_t nonce)
{
  unsigned __int8 *v3; // r0
  unsigned int v4; // r5
  uint32_t *v5; // r1
  unsigned int v6; // t1
  unsigned int v7; // r4
  char scratchpad[131596]; // [sp+8h] [bp-20208h] BYREF
  uint32_t *input; // [sp+20214h] [bp+4h]
  uint32_t ohash[8]; // [sp+20218h] [bp+8h] BYREF
  uint32_t data[20]; // [sp+20238h] [bp+28h] BYREF
  char tmp42[4096]; // [sp+20288h] [bp+78h] BYREF

  v3 = pdata - 4;
  v4 = *((_DWORD *)ptarget + 7);
  v5 = &ohash[7];
  do
  {
    v6 = *((_DWORD *)v3 + 1);
    v3 += 4;
    v5[1] = bswap32(v6);
    ++v5;
  }
  while ( v5 != &data[18] );
  input = data;
  data[19] = bswap32(nonce);
  scrypt_1024_1_1_256_sp(data, scratchpad, ohash);
  v7 = bswap32(ohash[7]);
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "htarget %08lx diff1 %08lx hash %08lx", v4, 0xFFFF, v7);
    applog(7, tmp42, 0);
  }
  if ( v7 >= 0x10000 )
    return -1;
  else
    return v4 >= v7;
}
