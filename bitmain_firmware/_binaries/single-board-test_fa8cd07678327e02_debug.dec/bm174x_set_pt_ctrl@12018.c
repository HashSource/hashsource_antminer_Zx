void __cdecl bm174x_set_pt_ctrl(int fd, int pt_num, int pt_en)
{
  base_type_t item; // [sp+14h] [bp+14h] BYREF
  bm174x_reg pt_ctrl_reg; // [sp+1Ch] [bp+1Ch]

  *((_BYTE *)&pt_ctrl_reg.chip_addr + 1) = BYTE1(reg_value.pt_ctrl);
  *(_BYTE *)&pt_ctrl_reg.chip_addr = reg_value.pt_ctrl & 0xFE | pt_en & 1;
  *((_WORD *)&pt_ctrl_reg.hash_rate + 1) = HIWORD(reg_value.pt_ctrl) & 0xF800 | pt_num & 0x7FF;
  item.chip_addr = 0;
  item.all = 1;
  item.addr = 92;
  item.data = pt_ctrl_reg.core_timeout.core_timeout;
  midd_ioctl(fd, 1u, &item);
}
