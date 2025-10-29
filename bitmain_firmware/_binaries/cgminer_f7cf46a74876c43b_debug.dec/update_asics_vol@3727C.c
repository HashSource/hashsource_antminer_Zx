void __fastcall update_asics_vol(int vol)
{
  uint8_t *chain_exist; // r5
  int i; // r4
  int v4; // t1
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "isl set voltage to %d\n", vol);
    applog(5, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  for ( i = 0; i != 4; ++i )
  {
    v4 = *chain_exist++;
    if ( v4 == 1 )
    {
      update_asic_vol(i, 0, vol);
      update_asic_vol(i, 1, vol);
      update_asic_vol(i, 2, vol);
    }
  }
}
