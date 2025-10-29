void __cdecl bm174x_set_nonce_shift(int fd, uint32_t nonce_shift, uint32_t *outer_shift)
{
  base_type_t item; // [sp+14h] [bp+14h] BYREF
  bm174x_reg nonce_shift_reg; // [sp+1Ch] [bp+1Ch]

  nonce_shift_reg.chip_addr = (bm174x_chip_addr)reg_value.nonce_shift;
  *(_BYTE *)&nonce_shift_reg.chip_addr = reg_value.nonce_shift & 0xE0 | nonce_shift & 0x1F;
  item.chip_addr = 0;
  item.all = 1;
  item.addr = 80;
  item.data = nonce_shift_reg.core_timeout.core_timeout;
  midd_ioctl(fd, 1u, &item);
  *outer_shift = nonce_shift;
}
