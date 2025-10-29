void __cdecl bm174x_set_baud(int fd, int baudrate)
{
  base_type_t item; // [sp+Ch] [bp+Ch] BYREF
  bm174x_reg reg_misc; // [sp+14h] [bp+14h]

  reg_misc.chip_addr = (bm174x_chip_addr)reg_value.misc_control;
  *((_BYTE *)&reg_misc.chip_addr + 1) = *((_BYTE *)&reg_misc.chip_addr + 1) & 0xE0 | get_bt8d_from_baud(baudrate) & 0x1F;
  item.chip_addr = 0;
  item.all = 1;
  item.addr = 28;
  item.data = reg_misc.core_timeout.core_timeout;
  reg_value.misc_control = reg_misc.core_timeout.core_timeout;
  midd_ioctl(fd, 1u, &item);
}
