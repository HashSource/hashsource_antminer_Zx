void __fastcall set_ticket_mask_chain(unsigned __int8 which_chain, uint32_t ticket_mask)
{
  unsigned __int8 v3; // r6
  const char *v4; // r2
  uint32_t v5; // [sp+4h] [bp-1014h]
  uint8_t cmd[11]; // [sp+Ch] [bp-100Ch] BYREF
  char tmp42[4096]; // [sp+18h] [bp-1000h] BYREF

  *(_DWORD *)cmd = 0;
  *(_DWORD *)&cmd[4] = 0;
  v3 = ticket_mask;
  *(_DWORD *)&cmd[7] = 0;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v4) = -26304;
    HIWORD(v4) = (unsigned int)"%d]: cur freq %d, lower times %d\n" >> 16;
    v5 = ticket_mask;
    snprintf(tmp42, 0x1000u, v4, "set_ticket_mask_chain", which_chain);
    applog(5, tmp42, 0);
  }
  default_ticket_mask_reg = v3;
  bm1740_makeup_set_config_cmd(cmd, 1u, 0, 0x14u, v3, v5);
  uart_send(which_chain, cmd, 0xBu);
  cgsleep_ms(1);
}
