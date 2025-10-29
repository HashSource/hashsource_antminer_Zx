void __fastcall get_reg_value(uint8_t regaddr)
{
  uint8_t v1; // r2
  uint8_t v2; // r3
  uint8_t *chain_exist; // r5
  uint32_t v4; // r7
  int v5; // r4
  int v6; // t1
  uint8_t cmd[12]; // [sp+0h] [bp-Ch] BYREF

  v2 = 0;
  chain_exist = dev.chain_exist;
  v4 = regaddr;
  LOBYTE(v5) = 0;
  *(_DWORD *)cmd = 0;
  *(_DWORD *)&cmd[3] = 0;
  do
  {
    v6 = *chain_exist++;
    if ( v6 == 1 )
    {
      bm1740_makeup_get_status_cmd_0(cmd, v4, v1, v2, cmd[0]);
      uart_send(v5, cmd, 7u);
      cgsleep_ms(200);
      check_asic_reg(v5, 0, v4, 1);
    }
    v5 = (unsigned __int8)(v5 + 1);
  }
  while ( v5 != 4 );
}
