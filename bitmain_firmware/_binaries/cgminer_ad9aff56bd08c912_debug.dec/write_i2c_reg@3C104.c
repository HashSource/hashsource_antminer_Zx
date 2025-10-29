void __fastcall write_i2c_reg(
        unsigned __int8 which_chain,
        unsigned __int8 which_sensor,
        uint8_t i2c_dev_addr,
        uint8_t i2c_reg_addr,
        uint8_t i2c_reg_data)
{
  uint8_t v6; // r1
  uint32_t v7; // [sp+4h] [bp-18h]
  uint8_t cmd_buf[11]; // [sp+Ch] [bp-10h] BYREF

  v6 = *((_BYTE *)&axi_fpga_addr + which_sensor + 800);
  *(_DWORD *)cmd_buf = 0;
  *(_DWORD *)&cmd_buf[4] = 0;
  *(_DWORD *)&cmd_buf[7] = 0;
  bm1740_makeup_set_config_cmd(
    cmd_buf,
    0,
    v6,
    0x20u,
    default_i2c_reg & 0xFE010000
  | 0x1000000
  | ((i2c_dev_addr & 0x7F) << 17)
  | (i2c_reg_addr << 8)
  | i2c_reg_data
  | 0x10000,
    v7);
  uart_send(which_chain, cmd_buf, 0xBu);
  cgsleep_ms(50);
}
