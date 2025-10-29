void __cdecl bm174x_reg_handle(uint8_t *str, int len, uint8_t chainid)
{
  char tmp42[1024]; // [sp+1Ch] [bp+14h] BYREF
  reg_list_item_t new_item; // [sp+41Ch] [bp+414h]
  uint8_t crc5; // [sp+42Bh] [bp+423h]
  reg_respond *reg; // [sp+42Ch] [bp+424h]
  reg_list_item_t v8; // 0:r0.12

  reg = (reg_respond *)str;
  crc5 = CRC5_v1(str + 2, 8 * (len - 3) + 3);
  if ( crc5 == (*((_BYTE *)reg + 8) & 0x1F) )
  {
    new_item.age = 3;
    new_item.chainid = chainid;
    new_item.chip_addr = reg->chip_addr;
    new_item.reg_addr = reg->reg_addr;
    *(_QWORD *)&v8.chainid = __PAIR64__(_byteswap_ulong(*(_DWORD *)reg->reg_data), *(unsigned int *)&new_item.chainid);
    v8.age = 3;
    add_reg_item(v8);
  }
  else if ( use_syslog || opt_log_output || opt_log_level >= 0 )
  {
    snprintf(tmp42, 0x400u, "%s CRC error crc = %02x\n", "bm174x_reg_handle", crc5);
    applog(0, tmp42, 0);
  }
}
