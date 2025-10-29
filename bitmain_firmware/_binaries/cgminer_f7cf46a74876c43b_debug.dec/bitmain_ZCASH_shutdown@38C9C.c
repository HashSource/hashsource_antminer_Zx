void __fastcall bitmain_ZCASH_shutdown(thr_info *thr)
{
  every_chain_disable_PIC16F1704_dc_dc_new();
  reset_all_hash_board_low();
  cgsleep_ms(100);
  thr_info_cancel(check_miner_status_id);
  thr_info_cancel(check_fan_id);
  thr_info_cancel(read_hash_rate);
  thr_info_cancel(read_temp_id);
}
