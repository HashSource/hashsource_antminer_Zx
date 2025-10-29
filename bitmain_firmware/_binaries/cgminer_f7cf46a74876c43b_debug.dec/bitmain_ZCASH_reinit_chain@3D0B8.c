void *__fastcall bitmain_ZCASH_reinit_chain(void *usrdata)
{
  pthread_t v2; // r0
  unsigned int v3; // r4
  void *result; // r0
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "%s Begin\n", "bitmain_ZCASH_reinit_chain");
    applog(5, tmp42, 0);
  }
  v2 = pthread_self();
  pthread_detach(v2);
  pthread_mutex_lock(&reinit_mutex);
  v3 = *((unsigned __int8 *)usrdata + 4);
  reset_chain(*(bitmain_ZCASH_info **)usrdata, *((_BYTE *)usrdata + 4));
  software_set_address_chain(v3);
  cgsleep_ms(100);
  set_frequency_chain(v3, dev.freq[v3]);
  cgsleep_ms(100);
  set_core_timeout_chain(v3, (unsigned int)&loc_13880);
  cgsleep_ms(100);
  set_ticket_mask_chain(v3, default_ticket_mask_reg);
  cgsleep_ms(100);
  enable_read_temperature_from_asic_chain(v3);
  *((_BYTE *)&axi_fpga_addr + v3 + 652) = 1;
  sleep(1u);
  result = (void *)pthread_mutex_unlock(&reinit_mutex);
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "%s Done\n", "bitmain_ZCASH_reinit_chain");
    applog(5, tmp42, 0);
  }
  return result;
}
