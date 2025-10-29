// Alternative name is 'bm1740_makeup_get_status_cmd.constprop.20'
int __fastcall bm1740_makeup_get_status_cmd_0(
        uint8_t *str,
        uint32_t str_len,
        uint8_t all,
        uint8_t chip_addr,
        uint8_t regaddr)
{
  return bm1740_makeup_get_status_cmd(str, 1u, 0, str_len, regaddr);
}
