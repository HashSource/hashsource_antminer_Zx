void __cdecl bm174x_set_vmount(int fd, int vmount)
{
  base_type_t item; // [sp+Ch] [bp+Ch] BYREF
  bm174x_reg vmount_reg; // [sp+14h] [bp+14h]

  vmount_reg.chip_addr = (bm174x_chip_addr)reg_value.analog_mux_control;
  *(_BYTE *)&vmount_reg.chip_addr = reg_value.analog_mux_control & 0xF8 | vmount & 7;
  item.chip_addr = 0;
  item.all = 1;
  item.addr = 64;
  item.data = vmount_reg.core_timeout.core_timeout;
  reg_value.analog_mux_control = vmount_reg.core_timeout.core_timeout;
  midd_ioctl(fd, 1u, &item);
}
