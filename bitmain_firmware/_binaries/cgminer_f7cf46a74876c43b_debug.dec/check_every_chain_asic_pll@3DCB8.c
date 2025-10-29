void check_every_chain_asic_pll()
{
  uint8_t *chain_exist; // r5
  int v1; // r4
  int v2; // t1
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    strcpy(tmp42, "check_every_chain_asic_pll");
    applog(5, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  LOBYTE(v1) = 0;
  do
  {
    v2 = *chain_exist++;
    if ( v2 == 1 )
    {
      check_asic_reg(v1, 0, 0xCu, 1);
      cgsleep_ms(100);
    }
    v1 = (unsigned __int8)(v1 + 1);
  }
  while ( v1 != 4 );
}
