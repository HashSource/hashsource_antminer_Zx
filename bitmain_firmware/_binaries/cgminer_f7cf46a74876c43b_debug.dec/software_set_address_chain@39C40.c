void __fastcall software_set_address_chain(unsigned int which_chain)
{
  int v2; // r4
  unsigned __int8 v3; // r1
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "%s chainID%d asics %d addrInterval %d",
      "software_set_address_chain",
      which_chain,
      dev.chain_asic_num[which_chain],
      dev.addrInterval);
    applog(5, tmp42, 0);
  }
  v2 = 0;
  chain_inactive(which_chain);
  cgsleep_ms(50);
  do
  {
    v3 = dev.addrInterval * v2++;
    set_address(which_chain, v3);
    cgsleep_ms(50);
  }
  while ( v2 != 3 );
}
