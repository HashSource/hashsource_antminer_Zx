void __cdecl bm174x_set_pt_result(int fd, int ptr_grp_num, int ptr_rd)
{
  base_type_t item; // [sp+14h] [bp+14h] BYREF
  bm174x_reg pt_result_reg; // [sp+1Ch] [bp+1Ch]

  *(_BYTE *)&pt_result_reg.chip_addr = *(_BYTE *)&pt_result_reg.chip_addr & 0xFE | ptr_rd & 1;
  *((_BYTE *)&pt_result_reg.chip_addr + 1) = *((_BYTE *)&pt_result_reg.chip_addr + 1) & 0xF0 | ptr_grp_num & 0xF;
  item.chip_addr = 0;
  item.all = 1;
  item.addr = 96;
  item.data = pt_result_reg.core_timeout.core_timeout;
  midd_ioctl(fd, 1u, &item);
}
