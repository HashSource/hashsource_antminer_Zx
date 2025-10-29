void __fastcall set_baud(unsigned int bt8d)
{
  unsigned __int8 v1; // r7
  const char *v3; // r2
  uint8_t *chain_exist; // r5
  int v5; // r4
  int v6; // t1
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  v1 = bt8d;
  dev.baud = bt8d;
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v3) = -26320;
    HIWORD(v3) = (unsigned int)"\n" >> 16;
    snprintf(tmp42, 0x1000u, v3, "set_baud", bt8d);
    applog(7, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  LOBYTE(v5) = 0;
  do
  {
    v6 = *chain_exist++;
    if ( v6 == 1 )
      set_baud_chain(v5, bt8d);
    v5 = (unsigned __int8)(v5 + 1);
  }
  while ( v5 != 4 );
  sleep(1u);
  set_fpga_baud(v1);
  cgsleep_ms(10);
}
