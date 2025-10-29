int __cdecl cgpu_init(runtime_base_t *runtime)
{
  char tmp42[1024]; // [sp+Ch] [bp+Ch] BYREF
  int ret; // [sp+40Ch] [bp+40Ch]

  ret = 0;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "--- %s\n", "cgpu_init");
    applog(2, tmp42, 0);
  }
  memset(&cgpu, 0, sizeof(cgpu));
  ret = open_lcd();
  if ( ret <= 0 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "!!! %s: open lcd driver error\n", "cgpu_init");
      applog(2, tmp42, 0);
    }
    goto LCD_ERR;
  }
  memset(lcd_output, 32, sizeof(lcd_output));
  write(cgpu.lcd_fd, lcd_output, 0x40u);
  ret = open_key();
  if ( ret <= 0 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "!!! %s: open start key error\n", "cgpu_init");
      applog(2, tmp42, 0);
    }
    goto START_KEY_ERR;
  }
  ret = open_red_led();
  if ( ret <= 0 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "!!! %s: open red led error\n", "cgpu_init");
      applog(2, tmp42, 0);
    }
    goto RED_LED_ERR;
  }
  ret = open_green_led();
  if ( ret <= 0 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "!!! %s: open green led error\n", "cgpu_init");
      applog(2, tmp42, 0);
    }
    goto GREEN_LED_ERR;
  }
  ret = bitmain_axi_init();
  if ( ret < 0 )
  {
    bitmain_axi_close();
GREEN_LED_ERR:
    close_green_led();
RED_LED_ERR:
    close_red_led();
START_KEY_ERR:
    close_key();
LCD_ERR:
    close_lcd();
    return -1;
  }
  cgpu.runtime = runtime;
  patten_info_init();
  patten_load("/mnt/card/");
  return 0;
}
