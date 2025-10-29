void __fastcall benchfile_dspwork(work *work, uint32_t nonce)
{
  int v2; // r2
  int v3; // r4
  int v4; // r3
  char buf[1024]; // [sp+8h] [bp-1400h] BYREF
  char tmp42[4096]; // [sp+408h] [bp-1000h] BYREF

  v2 = 4;
  v3 = 0;
  do
  {
    v4 = (unsigned __int8)nonce;
    --v2;
    nonce >>= 8;
    v3 = v4 + (v3 << 8);
  }
  while ( v2 );
  _bin2hex(buf, work->data, 0x80u);
  if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    snprintf(tmp42, 0x1000u, "BENCHFILE nonce %u=0x%08x for work=%s", v3, v3, buf);
    applog(3, tmp42, 0);
  }
}
