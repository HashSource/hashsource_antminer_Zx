void __fastcall chain_inactive(const int which_chain)
{
  uint32_t v1; // r1
  unsigned __int8 v2; // r4
  unsigned int v3; // r0
  uint8_t cmd_buf[8]; // [sp+0h] [bp-8h] BYREF

  v2 = which_chain;
  *(_DWORD *)cmd_buf = 0;
  *(_DWORD *)&cmd_buf[3] = 0;
  v3 = bm1740_makeup_chain_inactive_cmd(cmd_buf, v1);
  uart_send(v2, cmd_buf, v3);
}
