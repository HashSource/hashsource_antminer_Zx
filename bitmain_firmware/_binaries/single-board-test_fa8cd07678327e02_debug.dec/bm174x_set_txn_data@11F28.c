void __cdecl bm174x_set_txn_data(int fd, uint32_t txn_data)
{
  base_type_t item; // [sp+8h] [bp+8h] BYREF

  item.chip_addr = 0;
  item.all = 1;
  item.addr = 88;
  item.data = txn_data;
  reg_value.txn_data = txn_data;
  midd_ioctl(fd, 1u, &item);
}
