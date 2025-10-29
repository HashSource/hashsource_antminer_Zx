void __fastcall software_set_address_chain(unsigned int which_chain)
{
  const char *v2; // r2
  int v3; // r4
  unsigned __int8 v4; // r1
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v2) = -26692;
    HIWORD(v2) = (unsigned int)"n %u voltage %u" >> 16;
    snprintf(
      tmp42,
      0x1000u,
      v2,
      "software_set_address_chain",
      which_chain,
      dev.chain_asic_num[which_chain],
      dev.addrInterval);
    applog(5, tmp42, 0);
  }
  v3 = 0;
  chain_inactive(which_chain);
  cgsleep_ms(50);
  do
  {
    v4 = dev.addrInterval * v3++;
    set_address(which_chain, v4);
    cgsleep_ms(50);
  }
  while ( v3 != 3 );
}
