void __fastcall reset_chain(bitmain_ZCASH_info *info, uint8_t chain)
{
  int v3; // r5
  const char *v4; // r2
  char *v5; // r3
  const char *v6; // r2
  const char *v7; // r2
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  v3 = chain;
  if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    LOWORD(v4) = -25040;
    HIWORD(v4) = (unsigned int)"d\n" >> 16;
    snprintf(tmp42, 0x1000u, v4, "reset_chain", chain);
    applog(4, tmp42, 0);
  }
  pthread_mutex_lock(&iic_mutex);
  i2c_slave_addr = v3;
  disable_PIC16F1704_dc_dc_new();
  pthread_mutex_unlock(&iic_mutex);
  v5 = (char *)&axi_fpga_addr + v3;
  v5[652] = 0;
  v5[776] = 0;
  v5[668] = 1;
  thr_info_join(&info->uart_tx_t[v3]);
  thr_info_join(&info->uart_rx_t[v3]);
  send_heart = 0;
  pthread_mutex_lock(&iic_mutex);
  i2c_slave_addr = v3;
  reset_PIC16F1704_pic_new();
  cgsleep_ms(1000);
  jump_from_loader_to_app_PIC16F1704_new();
  cgsleep_ms(1000);
  pthread_mutex_unlock(&iic_mutex);
  send_heart = 1;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v6) = 3828;
    HIWORD(v6) = (unsigned int)"d:%02d" >> 16;
    snprintf(tmp42, 0x1000u, v6, "reset_hash_board_low", v3);
    applog(5, tmp42, 0);
  }
  axi_fpga_addr[13] = 1 << v3;
  cgsleep_ms(100);
  pthread_mutex_lock(&iic_mutex);
  i2c_slave_addr = v3;
  enable_PIC16F1704_dc_dc_new();
  pthread_mutex_unlock(&iic_mutex);
  sleep(1u);
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v7) = 3828;
    HIWORD(v7) = (unsigned int)"d:%02d" >> 16;
    snprintf(tmp42, 0x1000u, v7, "reset_hash_board_high", v3);
    applog(5, tmp42, 0);
  }
  axi_fpga_addr[13] = 0;
  *((_BYTE *)&axi_fpga_addr + v3 + 668) = 0;
  tty_init_chain(v3, info);
  set_fpga_baud(0x1Au);
  cgsleep_ms(100);
  set_baud_chain(v3, 0);
  cgsleep_ms(1000);
  set_fpga_baud(0);
  cgsleep_ms(100);
}
