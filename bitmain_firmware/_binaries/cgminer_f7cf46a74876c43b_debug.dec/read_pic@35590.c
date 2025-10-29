int read_pic()
{
  return i2c_read((i2c_slave_addr << 16) | 0xA00000);
}
