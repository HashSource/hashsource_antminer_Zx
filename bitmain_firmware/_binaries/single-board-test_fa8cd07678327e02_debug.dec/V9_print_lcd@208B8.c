void V9_print_lcd()
{
  char level_str[20]; // [sp+8h] [bp+0h] BYREF
  char str[20]; // [sp+1Ch] [bp+14h] BYREF

  memset(str, 0, 17);
  show_result();
  sprintf(
    str,
    "Pattern %d %d %d   ",
    *g_patten.asic_recv_nonces,
    g_patten.asic_recv_nonces[1],
    g_patten.asic_recv_nonces[2]);
  write_lcd(0, str, 0x10u);
  if ( pattern_result <= 0 )
    write_lcd_no_memset(1u, "Pattern NG      ", 0x10u);
  else
    write_lcd_no_memset(1u, "Pattern OK      ", 0x10u);
  if ( read_temp_test_result <= 0 )
    write_lcd_no_memset(2u, "Sensor NG       ", 0x10u);
  else
    write_lcd_no_memset(2u, "Sensor OK       ", 0x10u);
  memset(level_str, 0, 17);
  sprintf(level_str, "    Level %d     ", pattern_level);
  write_lcd_no_memset(3u, level_str, 0x10u);
}
