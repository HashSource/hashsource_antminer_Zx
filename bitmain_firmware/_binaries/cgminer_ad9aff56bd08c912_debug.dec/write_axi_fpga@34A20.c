void __fastcall write_axi_fpga(unsigned int address, unsigned int data)
{
  axi_fpga_addr[address] = data;
}
