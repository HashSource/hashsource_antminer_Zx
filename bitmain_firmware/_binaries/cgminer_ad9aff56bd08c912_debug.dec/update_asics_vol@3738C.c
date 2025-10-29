void __fastcall update_asics_vol(int vol)
{
  const char *v2; // r2
  uint8_t *chain_exist; // r5
  int i; // r4
  int v5; // t1
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v2) = -29104;
    HIWORD(v2) = (unsigned int)"e %d\n" >> 16;
    snprintf(tmp42, 0x1000u, v2, vol);
    applog(5, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  for ( i = 0; i != 4; ++i )
  {
    v5 = *chain_exist++;
    if ( v5 == 1 )
    {
      update_asic_vol(i, 0, vol);
      update_asic_vol(i, 1, vol);
      update_asic_vol(i, 2, vol);
    }
  }
}
