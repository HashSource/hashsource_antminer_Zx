void __fastcall tty_init_chain(uint8_t which_chain, bitmain_ZCASH_info *info)
{
  int v2; // r4
  _BOOL4 v3; // r3
  int v5; // r8
  void *(*v6)(void *); // r2
  const char *v7; // r2
  void *(*v8)(void *); // r2
  int v9; // r6
  const char *v10; // r2
  int *v11; // r4
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r4
  const char *v17; // r2
  const char *v18; // r2
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
    LOWORD(v6) = -1231;
    *((_BYTE *)&axi_fpga_addr + v2 + 776) = 1;
    HIWORD(v6) = (unsigned int)&loc_3FB00 >> 16;
    if ( thr_info_create((thr_info *)((char *)info->uart_rx_t + v5), 0, v6, &dev_info_0[(__int16)v2]) )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 2 )
      {
        LOWORD(v17) = -26200;
        HIWORD(v17) = (unsigned int)"%d\n" >> 16;
        snprintf(tmp42, 0x1000u, v17, v2);
        goto LABEL_9;
      }
    }
    else if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      LOWORD(v7) = -26156;
      HIWORD(v7) = (unsigned int)" = 0x%08x" >> 16;
      snprintf(tmp42, 0x1000u, v7, v2);
LABEL_9:
      applog(3, tmp42, 0);
    }
    cgsleep_ms(50);
    LOWORD(v8) = 21205;
    HIWORD(v8) = (unsigned int)&loc_351C4 >> 16;
    info_with_index.info = info;
    info_with_index.chain_index = v2;
    v9 = thr_info_create((thr_info *)((char *)info->uart_tx_t + v5), 0, v8, &info_with_index);
    cgsleep_ms(200);
    if ( v9 )
    {
      if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
        goto LABEL_22;
      LOWORD(v18) = -26116;
      HIWORD(v18) = (unsigned int)"ero %d" >> 16;
      snprintf(tmp42, 0x1000u, v18, v2);
    }
    else
    {
      if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
        goto LABEL_22;
      LOWORD(v10) = -26072;
      HIWORD(v10) = (unsigned int)"te rx read thread for chain %d failed" >> 16;
      snprintf(tmp42, 0x1000u, v10, v2);
    }
    applog(3, tmp42, 0);
    if ( use_syslog || opt_log_output )
    {
LABEL_16:
      LOWORD(v11) = -26032;
      HIWORD(v11) = (unsigned int)"create rx read thread for chain %d ok" >> 16;
      v12 = *v11;
      v13 = v11[1];
      v14 = v11[2];
      v15 = v11[3];
      v16 = v11[4];
      *(_DWORD *)tmp42 = v12;
      *(_DWORD *)&tmp42[4] = v13;
      *(_DWORD *)&tmp42[8] = v14;
      *(_DWORD *)&tmp42[12] = v15;
      tmp42[16] = v16;
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
