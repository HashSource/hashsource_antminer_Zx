void __cdecl V9_print_lcd_type(int type)
{
  if ( type == -1 )
  {
    write_lcd_no_memset(0, " hardware error ", 0x10u);
    write_lcd_no_memset(1u, "     check      ", 0x10u);
    write_lcd_no_memset(2u, " u2 u44 u16 u23 ", 0x10u);
    write_lcd_no_memset(3u, " u30            ", 0x10u);
  }
  else
  {
    V9_print_lcd();
  }
}
