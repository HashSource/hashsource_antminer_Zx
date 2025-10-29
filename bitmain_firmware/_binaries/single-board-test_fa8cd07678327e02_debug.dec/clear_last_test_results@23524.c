void clear_last_test_results()
{
  memset(g_patten.is_nonce_match, 0, g_patten.patten_num * g_patten.core_num * g_patten.asic_num);
  memset(g_patten.asic_recv_nonces, 0, 4 * g_patten.asic_num);
  g_patten.recv_nonces = 0;
  g_patten.total_rate = 0.0;
}
