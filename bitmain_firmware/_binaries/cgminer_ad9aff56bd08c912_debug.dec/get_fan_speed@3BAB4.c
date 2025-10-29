int __fastcall get_fan_speed(unsigned __int8 *fan_id, unsigned int *fan_speed)
{
  int v2; // r3

  v2 = axi_fpga_addr[1];
  *fan_speed = (unsigned __int8)v2;
  *fan_id = BYTE1(v2) & 7;
  return v2;
}
