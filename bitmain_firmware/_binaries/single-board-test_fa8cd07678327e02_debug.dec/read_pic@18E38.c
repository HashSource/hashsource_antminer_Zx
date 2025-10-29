unsigned __int8 __cdecl read_pic(unsigned __int8 which_i2c, unsigned __int8 which_chain)
{
  return i2c_read((which_chain << 16) | (which_i2c << 26) | 0xA00000);
}
