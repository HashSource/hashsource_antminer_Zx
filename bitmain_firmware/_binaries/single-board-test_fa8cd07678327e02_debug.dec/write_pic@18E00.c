void __cdecl write_pic(unsigned __int8 which_i2c, unsigned __int8 which_chain, unsigned __int8 data)
{
  i2c_write(data | (which_i2c << 26) | 0xA00000 | (which_chain << 16));
}
