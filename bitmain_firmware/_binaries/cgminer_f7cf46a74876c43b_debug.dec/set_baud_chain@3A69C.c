void __fastcall set_baud_chain(unsigned __int8 which_chain, unsigned int bt8d)
{
  uint32_t v3; // [sp+4h] [bp-14h]
  uint8_t cmd[12]; // [sp+Ch] [bp-Ch] BYREF

  memset(cmd, 0, 11);
  default_misc_reg = default_misc_reg & 0xFFFFE0FF | ((bt8d & 0x1F) << 8) | 4;
  bm1740_makeup_set_config_cmd(cmd, 1u, 0, 0x1Cu, default_misc_reg, v3);
  uart_send(which_chain, cmd, 0xBu);
  cgsleep_ms(1);
}
