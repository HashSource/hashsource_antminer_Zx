void __fastcall tty_init(bitmain_ZCASH_info *info)
{
  int *v2; // r2
  int v3; // r0
  int v4; // r1
  int v5; // r2
  int i; // r4
  uint8_t v7; // r0
  char tmp42[4096]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v2) = -26012;
    HIWORD(v2) = (unsigned int)"d for chain %d ok" >> 16;
    v3 = *v2;
    v4 = v2[1];
    v5 = v2[2];
    *(_DWORD *)tmp42 = v3;
    *(_DWORD *)&tmp42[4] = v4;
    tmp42[8] = v5;
    applog(5, tmp42, 0);
  }
  for ( i = 0; i != 4; ++i )
  {
    v7 = i;
    tty_init_chain(v7, info);
  }
  cgsleep_ms(10);
}
