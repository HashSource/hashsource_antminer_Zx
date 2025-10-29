void __fastcall tty_init(bitmain_ZCASH_info *info)
{
  int i; // r4
  uint8_t v3; // r0
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    strcpy(tmp42, "tty_init");
    applog(5, tmp42, 0);
  }
  for ( i = 0; i != 4; ++i )
  {
    v3 = i;
    tty_init_chain(v3, info);
  }
  cgsleep_ms(10);
}
