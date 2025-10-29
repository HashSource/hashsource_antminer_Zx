void __fastcall set_nonce_shift_chain(unsigned __int8 which_chain, int shift)
{
  uint32_t regaddr; // r5
  uint32_t shifta; // [sp+4h] [bp-1014h]
  uint8_t cmd[11]; // [sp+Ch] [bp-100Ch] BYREF
  char tmp42[4096]; // [sp+18h] [bp-1000h] BYREF

  *(_DWORD *)cmd = 0;
  *(_DWORD *)&cmd[4] = 0;
  *(_DWORD *)&cmd[7] = 0;
  regaddr = (unsigned __int8)shift << 27;
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "chainid%d %s: nonce shift = %08x", which_chain, "set_nonce_shift_chain", shift);
    applog(7, tmp42, 0);
  }
  default_nonce_shift_reg = regaddr;
  bm1740_makeup_set_config_cmd(cmd, 1u, 0, 0x50u, regaddr, shifta);
  uart_send(which_chain, cmd, 0xBu);
  cgsleep_ms(10);
}
