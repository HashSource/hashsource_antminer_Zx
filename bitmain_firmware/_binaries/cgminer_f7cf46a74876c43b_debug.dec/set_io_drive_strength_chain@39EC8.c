void __fastcall set_io_drive_strength_chain(unsigned __int8 which_chain)
{
  uint32_t regaddr; // r4
  uint32_t regdata; // [sp+4h] [bp-1018h]
  uint8_t cmd[11]; // [sp+Ch] [bp-1010h] BYREF
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  regaddr = default_io_drive_strength_reg & 0xFFFF0FFF | 0x3000;
  default_io_drive_strength_reg = regaddr;
  *(_DWORD *)cmd = 0;
  *(_DWORD *)&cmd[4] = 0;
  *(_DWORD *)&cmd[7] = 0;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "chainid%d %s: IO drive = %08x", which_chain, "set_io_drive_strength_chain", regaddr);
    applog(5, tmp42, 0);
  }
  bm1740_makeup_set_config_cmd(cmd, 1u, 0, 0x30u, regaddr, regdata);
  uart_send(which_chain, cmd, 0xBu);
  cgsleep_ms(1);
}
