void __fastcall set_txn_data_chain(unsigned __int8 which_chain, int txn_shalow, int txn_zero)
{
  char v4; // r8
  char v5; // r7
  uint32_t regdata; // [sp+4h] [bp-101Ch]
  uint8_t cmd[11]; // [sp+14h] [bp-100Ch] BYREF
  char tmp42[4096]; // [sp+20h] [bp-1000h] BYREF

  v4 = txn_shalow;
  *(_DWORD *)cmd = 0;
  *(_DWORD *)&cmd[4] = 0;
  v5 = txn_zero;
  *(_DWORD *)&cmd[7] = 0;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "chainID%d %s txndata %d txnzero %d",
      which_chain,
      "set_txn_data_chain",
      txn_shalow,
      txn_zero);
    applog(5, tmp42, 0);
  }
  default_txn_data = (2 * (v4 & 1)) | v5 & 1;
  bm1740_makeup_set_config_cmd(cmd, 1u, 0, 0x58u, default_txn_data, regdata);
  uart_send(which_chain, cmd, 0xBu);
  cgsleep_ms(1);
}
