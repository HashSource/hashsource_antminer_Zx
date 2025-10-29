int __cdecl erase_PIC16F1704_app_flash(unsigned int which_i2c, unsigned __int8 which_chain)
{
  char tmp42[1024]; // [sp+10h] [bp+8h] BYREF
  unsigned int pic_flash_length; // [sp+410h] [bp+408h]
  unsigned __int8 end_addr_l; // [sp+414h] [bp+40Ch]
  unsigned __int8 end_addr_h; // [sp+415h] [bp+40Dh]
  unsigned __int8 start_addr_l; // [sp+416h] [bp+40Eh]
  unsigned __int8 start_addr_h; // [sp+417h] [bp+40Fh]
  unsigned int erase_loop; // [sp+418h] [bp+410h]
  unsigned int i; // [sp+41Ch] [bp+414h]

  i = 0;
  start_addr_h = 6;
  start_addr_l = 0;
  end_addr_h = 15;
  end_addr_l = 127;
  set_PIC16F1704_flash_pointer(which_i2c, which_chain, 6u, 0);
  pic_flash_length = 2432;
  erase_loop = 76;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "%s: erase_loop = %d\n", "erase_PIC16F1704_app_flash", erase_loop);
    applog(2, tmp42, 0);
  }
  for ( i = 0; i < erase_loop; ++i )
    erase_PIC16F1704_flash(which_i2c, which_chain);
  return 1;
}
