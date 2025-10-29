void __fastcall check_every_chain_asic_number(bool whether_update_asic_num)
{
  uint8_t *chain_exist; // r5
  int i; // r4
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    strcpy(tmp42, "check_every_chain_asic_number");
    applog(5, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  for ( i = 0; i != 4; ++i )
  {
    if ( *chain_exist++ )
    {
      update_asic_num[i] = whether_update_asic_num;
      check_asic_reg(i, 0, 0, 1);
    }
    cgsleep_ms(100);
  }
}
