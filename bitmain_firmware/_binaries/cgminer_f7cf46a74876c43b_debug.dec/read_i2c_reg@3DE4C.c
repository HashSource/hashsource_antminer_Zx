void __fastcall read_i2c_reg(
        unsigned __int8 which_chain,
        unsigned __int8 which_sensor,
        uint8_t i2c_dev_addr,
        uint8_t i2c_reg_addr)
{
  unsigned int v4; // r9
  int v5; // r6
  int v6; // r7
  int v8; // r8
  int v9; // r4
  char *v10; // r8
  int v11; // r3
  uint32_t v12; // [sp+4h] [bp-1014h]
  uint8_t cmd_buf[11]; // [sp+Ch] [bp-100Ch] BYREF
  char tmp42[4096]; // [sp+18h] [bp-1000h] BYREF

  v4 = i2c_reg_addr;
  v5 = which_chain;
  *(_DWORD *)cmd_buf = 0;
  *(_DWORD *)&cmd_buf[4] = 0;
  v6 = which_sensor;
  *(_DWORD *)&cmd_buf[7] = 0;
  cgsleep_ms(50);
  if ( v4 < 2 )
  {
    v8 = v4;
  }
  else if ( v4 == 17 )
  {
    v8 = 2;
  }
  else
  {
    if ( v4 != 254 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 3 )
      {
        snprintf(tmp42, 0x1000u, "%s unknow reg_type %d\n", "read_i2c_reg", v4);
        applog(4, tmp42, 0);
      }
      return;
    }
    v8 = 3;
  }
  bm1740_makeup_set_config_cmd(
    cmd_buf,
    0,
    *((_BYTE *)&axi_fpga_addr + v6 + 800),
    0x20u,
    default_i2c_reg & 0xFE000000
  | 0x1000000
  | ((i2c_dev_addr & 0x7F) << 17)
  | (unsigned __int16)((unsigned __int8)v4 << 8),
    v12);
  uart_send(v5, cmd_buf, 0xBu);
  cgsleep_ms(200);
  v9 = 0;
  v10 = (char *)&(&(&axi_fpga_addr)[3 * v5])[v6] + v8;
  v10[3460] = 0;
  do
  {
    ++v9;
    cgsleep_ms(50);
    check_asic_reg(v5, *((_BYTE *)&axi_fpga_addr + v6 + 800), 0x20u, 0);
    if ( v9 == 3 )
      v11 = 0;
    else
      v11 = ((unsigned __int8)v10[3460] ^ 1) & 1;
  }
  while ( v11 );
}
