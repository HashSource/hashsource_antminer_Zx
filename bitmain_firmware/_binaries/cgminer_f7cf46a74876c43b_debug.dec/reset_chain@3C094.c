void __fastcall reset_chain(bitmain_ZCASH_info *info, uint8_t chain)
{
  int v3; // r5
  char *v4; // r3
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  v3 = chain;
  if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    snprintf(tmp42, 0x1000u, "%s chainid %d", "reset_chain", chain);
    applog(4, tmp42, 0);
  }
  pthread_mutex_lock(&iic_mutex);
  i2c_slave_addr = v3;
  disable_PIC16F1704_dc_dc_new();
  pthread_mutex_unlock(&iic_mutex);
  v4 = (char *)&axi_fpga_addr + v3;
  v4[652] = 0;
  v4[776] = 0;
  v4[668] = 1;
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
    snprintf(tmp42, 0x1000u, "%s %d", "reset_hash_board_low", v3);
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
    snprintf(tmp42, 0x1000u, "%s %d", "reset_hash_board_high", v3);
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
