void __fastcall select_core_to_check_temperature_chain(unsigned int which_chain, uint32_t analog_mux_reg_value)
{
  uint32_t regaddr; // r6
  const char *v4; // r2
  unsigned __int8 *v5; // r4
  uint8_t v6; // t1
  uint32_t v7; // [sp+4h] [bp-1018h]
  uint8_t cmd[11]; // [sp+Ch] [bp-1010h] BYREF
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  *(_DWORD *)cmd = 0;
  *(_DWORD *)&cmd[4] = 0;
  regaddr = analog_mux_reg_value & 0xFFFFFFF8;
  *(_DWORD *)&cmd[7] = 0;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v4) = -25072;
    HIWORD(v4) = (unsigned int)"o955/value" >> 16;
    snprintf(tmp42, 0x1000u, v4, "select_core_to_check_temperature_chain", analog_mux_reg_value);
    applog(5, tmp42, 0);
  }
  if ( dev.chain_exist[which_chain] == 1 )
  {
    v5 = TempChipAddr;
    do
    {
      v6 = *v5++;
      bm1740_makeup_set_config_cmd(cmd, 0, v6, 0x40u, regaddr, v7);
      uart_send(which_chain, cmd, 0xBu);
      cgsleep_ms(2);
    }
    while ( v5 != &TempChipAddr[3] );
  }
}
