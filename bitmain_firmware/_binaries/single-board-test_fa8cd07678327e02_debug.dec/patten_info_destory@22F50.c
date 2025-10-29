void patten_info_destory()
{
  if ( g_patten.patten_start )
    free(g_patten.patten_start);
  if ( g_patten.is_nonce_match )
    free(g_patten.is_nonce_match);
  if ( g_patten.asic_recv_nonces )
    free(g_patten.asic_recv_nonces);
  pthread_mutex_destroy(&g_patten.patten_mutex);
}
