void __fastcall check_chain_asic_number(unsigned __int8 which_chain, bool whether_update_asic_num)
{
  if ( dev.chain_exist[which_chain] )
  {
    *((_BYTE *)&axi_fpga_addr + which_chain + 3456) = whether_update_asic_num;
    check_asic_reg(which_chain, 0, 0, 1);
  }
}
