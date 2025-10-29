void __fastcall set_address(const int which_chain, unsigned __int8 chip_addr)
{
  uint8_t v2; // r2
  unsigned __int8 v3; // r4
  unsigned int v4; // r0
  uint8_t cmd_buf[8]; // [sp+0h] [bp-8h] BYREF

  v3 = which_chain;
  *(_DWORD *)cmd_buf = 0;
  *(_DWORD *)&cmd_buf[3] = 0;
  v4 = bm1740_makeup_set_address_cmd(cmd_buf, chip_addr, v2);
  uart_send(v3, cmd_buf, v4);
}
