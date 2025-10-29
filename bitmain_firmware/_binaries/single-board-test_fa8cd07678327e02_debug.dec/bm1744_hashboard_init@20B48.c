int bm1744_hashboard_init()
{
  char tmp42[1024]; // [sp+Ch] [bp+4h] BYREF
  runtime_base_t *runtime; // [sp+40Ch] [bp+404h]

  runtime = cgpu.runtime;
  fan_control(5u);
  check_asic_num(runtime);
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(
      tmp42,
      0x400u,
      "%s: Check ASIC number: chain %d has %d asic\n",
      "bm1744_hashboard_init",
      runtime->chain_id,
      runtime->chain_status[runtime->chain_id].real_asic_num);
    applog(2, tmp42, 0);
  }
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(
      tmp42,
      0x400u,
      "%s: Expect ASIC number: %d\n",
      "bm1744_hashboard_init",
      runtime->chain_status[runtime->chain_id].design_asic_num);
    applog(2, tmp42, 0);
  }
  if ( runtime->chain_status[runtime->chain_id].real_asic_num == runtime->chain_status[runtime->chain_id].design_asic_num )
  {
    if ( app_conf->pcba_only_find_asic )
    {
      write_lcd(0, "Find all ASIC!  ", 0x10u);
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        strcpy(tmp42, "Find all ASIC\n");
        applog(2, tmp42, 0);
      }
      return 1;
    }
    else
    {
      set_asic_address(runtime, gChain);
      user_i2c_enable(cgpu.runtime, gChain);
      runtime->set_core_timeout(runtime->chain_status[gChain].fd, app_conf->core_timeout);
      usleep(0x2710u);
      runtime->set_ticket_mask(runtime->chain_status[gChain].fd, app_conf->ticket_mask);
      usleep(0x2710u);
      runtime->set_frequency(runtime->chain_status[gChain].fd, app_conf->pcba_freq);
      usleep(0x2710u);
      runtime->set_nonce_shift(runtime->chain_status[gChain].fd, 0, &runtime->nonce_shift);
      usleep(0x2710u);
      puts("re read asic address:");
      runtime->read_register(runtime->chain_status[runtime->chain_id].fd, 1, 0, 0);
      return 0;
    }
  }
  else
  {
    memset(lcd_output, 32, sizeof(lcd_output));
    write_lcd(0, "Not enough ASIC!", 0x10u);
    sprintf(&lcd_output[16], "%d ASIC", runtime->chain_status[runtime->chain_id].real_asic_num);
    write_lcd_no_memset(1u, &lcd_output[16], 0x10u);
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      strcpy(tmp42, "Not enough ASIC!\n");
      applog(0, tmp42, 0);
    }
    return -1;
  }
}
