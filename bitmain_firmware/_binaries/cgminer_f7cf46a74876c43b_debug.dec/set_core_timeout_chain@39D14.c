void __fastcall set_core_timeout_chain(unsigned __int8 which_chain, unsigned int timeout)
{
  uint32_t regdata; // [sp+4h] [bp-1018h]
  uint8_t cmd[11]; // [sp+Ch] [bp-1010h] BYREF
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  *(_DWORD *)cmd = 0;
  *(_DWORD *)&cmd[4] = 0;
  *(_DWORD *)&cmd[7] = 0;
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "chainid%d %s: core timeout = %08x", which_chain, "set_core_timeout_chain", timeout);
    applog(7, tmp42, 0);
  }
  default_core_timeout_reg = timeout;
  bm1740_makeup_set_config_cmd(cmd, 1u, 0, 0x28u, timeout, regdata);
  uart_send(which_chain, cmd, 0xBu);
  cgsleep_ms(1);
}
