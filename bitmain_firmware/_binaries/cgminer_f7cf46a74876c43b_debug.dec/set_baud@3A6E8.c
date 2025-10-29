void __fastcall set_baud(unsigned int bt8d)
{
  unsigned __int8 v1; // r7
  uint8_t *chain_exist; // r5
  int v4; // r4
  int v5; // t1
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  v1 = bt8d;
  dev.baud = bt8d;
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "%s: bt8d = %d", "set_baud", bt8d);
    applog(7, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  LOBYTE(v4) = 0;
  do
  {
    v5 = *chain_exist++;
    if ( v5 == 1 )
      set_baud_chain(v4, bt8d);
    v4 = (unsigned __int8)(v4 + 1);
  }
  while ( v4 != 4 );
  sleep(1u);
  set_fpga_baud(v1);
  cgsleep_ms(10);
}
