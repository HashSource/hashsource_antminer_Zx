void __fastcall tty_init_chain(uint8_t which_chain, bitmain_ZCASH_info *info)
{
  int v2; // r4
  _BOOL4 v3; // r3
  int v5; // r8
  int v6; // r6
  bitmian_ZCASH_info_with_index info_with_index; // [sp+8h] [bp-1028h] BYREF
  char tmp42[4096]; // [sp+10h] [bp-1020h] BYREF

  if ( dev.chain_exist[which_chain] )
  {
    v2 = which_chain;
    v3 = use_syslog;
    dev_info_0[which_chain].chainid = which_chain;
    if ( v3 || opt_log_output || opt_log_level > 4 )
    {
      snprintf(tmp42, 0x1000u, "%s chainid = %d", "tty_init_chain", which_chain);
      applog(5, tmp42, 0);
    }
    v5 = (__int16)v2 << 6;
    *((_BYTE *)&axi_fpga_addr + v2 + 776) = 1;
    if ( thr_info_create((thr_info *)((char *)info->uart_rx_t + v5), 0, get_asic_response, &dev_info_0[(__int16)v2]) )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 2 )
      {
        snprintf(tmp42, 0x1000u, "create rx read thread for chain %d failed", v2);
        goto LABEL_9;
      }
    }
    else if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      snprintf(tmp42, 0x1000u, "create rx read thread for chain %d ok", v2);
LABEL_9:
      applog(3, tmp42, 0);
    }
    cgsleep_ms(50);
    info_with_index.info = info;
    info_with_index.chain_index = v2;
    v6 = thr_info_create((thr_info *)((char *)info->uart_tx_t + v5), 0, ZCASH_fill_work, &info_with_index);
    cgsleep_ms(200);
    if ( v6 )
    {
      if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
        goto LABEL_22;
      snprintf(tmp42, 0x1000u, "create tx read thread for chain %d failed", v2);
    }
    else
    {
      if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
        goto LABEL_22;
      snprintf(tmp42, 0x1000u, "create tx read thread for chain %d ok", v2);
    }
    applog(3, tmp42, 0);
    if ( use_syslog || opt_log_output )
    {
LABEL_16:
      strcpy(tmp42, "open device over");
      applog(5, tmp42, 0);
LABEL_17:
      cgsleep_ms(10);
      return;
    }
LABEL_22:
    if ( opt_log_level <= 4 )
      goto LABEL_17;
    goto LABEL_16;
  }
}
