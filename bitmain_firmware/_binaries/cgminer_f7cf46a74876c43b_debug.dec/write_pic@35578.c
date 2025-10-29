void __fastcall write_pic(unsigned __int8 data)
{
  i2c_write(data | (i2c_slave_addr << 16) | 0xA00000);
}
