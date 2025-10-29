void *__fastcall bitmain_ZCASH_reinit_chain(void *usrdata)
{
  const char *v2; // r2
  pthread_t v3; // r0
  unsigned int v4; // r4
  void *result; // r0
  const char *v6; // r2
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v2) = -24432;
    HIWORD(v2) = (unsigned int)"chain%d %d %d %d\n" >> 16;
    snprintf(tmp42, 0x1000u, v2, "bitmain_ZCASH_reinit_chain");
    applog(5, tmp42, 0);
  }
  v3 = pthread_self();
  pthread_detach(v3);
  pthread_mutex_lock(&reinit_mutex);
  v4 = *((unsigned __int8 *)usrdata + 4);
  reset_chain(*(bitmain_ZCASH_info **)usrdata, *((_BYTE *)usrdata + 4));
  software_set_address_chain(v4);
  cgsleep_ms(100);
  set_frequency_chain(v4, dev.freq[v4]);
  cgsleep_ms(100);
  set_core_timeout_chain(v4, (unsigned int)&loc_13880);
  cgsleep_ms(100);
  set_ticket_mask_chain(v4, default_ticket_mask_reg);
  cgsleep_ms(100);
  enable_read_temperature_from_asic_chain(v4);
  *((_BYTE *)&axi_fpga_addr + v4 + 652) = 1;
  sleep(1u);
  result = (void *)pthread_mutex_unlock(&reinit_mutex);
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v6) = -24420;
    HIWORD(v6) = (unsigned int)"d %d\n" >> 16;
    snprintf(tmp42, 0x1000u, v6, "bitmain_ZCASH_reinit_chain");
    applog(5, tmp42, 0);
  }
  return result;
}
