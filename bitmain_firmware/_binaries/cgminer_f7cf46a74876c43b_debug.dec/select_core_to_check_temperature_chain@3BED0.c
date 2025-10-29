void __fastcall select_core_to_check_temperature_chain(unsigned int which_chain, uint32_t analog_mux_reg_value)
{
  uint32_t regaddr; // r6
  unsigned __int8 *v4; // r4
  uint8_t v5; // t1
  uint32_t v6; // [sp+4h] [bp-1018h]
  uint8_t cmd[11]; // [sp+Ch] [bp-1010h] BYREF
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  *(_DWORD *)cmd = 0;
  *(_DWORD *)&cmd[4] = 0;
  regaddr = analog_mux_reg_value & 0xFFFFFFF8;
  *(_DWORD *)&cmd[7] = 0;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "%s: analog_mux_reg_value = %08x",
      "select_core_to_check_temperature_chain",
      analog_mux_reg_value);
    applog(5, tmp42, 0);
  }
  if ( dev.chain_exist[which_chain] == 1 )
  {
    v4 = TempChipAddr;
    do
    {
      v5 = *v4++;
      bm1740_makeup_set_config_cmd(cmd, 0, v5, 0x40u, regaddr, v6);
      uart_send(which_chain, cmd, 0xBu);
      cgsleep_ms(2);
    }
    while ( v4 != &TempChipAddr[3] );
  }
}
