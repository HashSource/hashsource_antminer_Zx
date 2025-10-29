void __cdecl set_fan_speed(unsigned int speed)
{
  write_axi_fpga(0x21u, speed);
}
