void __fastcall enable_read_temperature_from_asic_chain(unsigned int which_chain)
{
  int v1; // r1
  uint32_t regaddr; // r4
  unsigned __int8 v3; // r6
  const char *v4; // r2
  unsigned __int8 *v5; // r5
  uint8_t v6; // t1
  uint32_t v7; // [sp+4h] [bp-1018h]
  uint8_t cmd[11]; // [sp+Ch] [bp-1010h] BYREF
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  v1 = dev.chain_exist[which_chain];
  *(_DWORD *)&cmd[4] = 0;
  regaddr = default_misc_reg | 0x4060;
  *(_DWORD *)&cmd[7] = 0;
  default_misc_reg |= 0x4060u;
  *(_DWORD *)cmd = 0;
  if ( v1 == 1 )
  {
    v3 = which_chain;
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      LOWORD(v4) = -25104;
      HIWORD(v4) = (unsigned int)"ue" >> 16;
      v7 = which_chain;
      snprintf(tmp42, 0x1000u, v4, "enable_read_temperature_from_asic_chain", regaddr);
      applog(5, tmp42, 0);
    }
    v5 = TempChipAddr;
    do
    {
      v6 = *v5++;
      bm1740_makeup_set_config_cmd(cmd, 0, v6, 0x1Cu, regaddr, v7);
      uart_send(v3, cmd, 0xBu);
      cgsleep_ms(50);
    }
    while ( v5 != &TempChipAddr[3] );
  }
}
