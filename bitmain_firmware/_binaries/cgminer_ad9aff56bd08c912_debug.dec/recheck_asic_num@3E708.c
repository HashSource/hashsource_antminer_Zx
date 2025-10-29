void __fastcall recheck_asic_num(bitmain_ZCASH_info *info, uint8_t chain)
{
  int v2; // r5
  const char *v4; // r2
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  v2 = chain;
  pthread_mutex_lock(&reinit_mutex);
  reset_chain(info, v2);
  pthread_mutex_unlock(&reinit_mutex);
  clear_register_value_buf();
  cgsleep_ms(100);
  if ( dev.chain_exist[v2] )
  {
    *((_BYTE *)&axi_fpga_addr + v2 + 3456) = 1;
    check_asic_reg(v2, 0, 0, 1);
  }
  cgsleep_ms(200);
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v4) = -23180;
    HIWORD(v4) = (unsigned int)"ll sensor's temperature, close PIC and need reboot!!!" >> 16;
    snprintf(tmp42, 0x1000u, v4, "recheck_asic_num");
    applog(5, tmp42, 0);
  }
}
