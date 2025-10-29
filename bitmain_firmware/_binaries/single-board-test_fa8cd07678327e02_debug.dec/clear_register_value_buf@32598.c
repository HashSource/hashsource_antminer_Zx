void clear_register_value_buf()
{
  pthread_mutex_lock(&nonce_mutex);
  nonce_fifo.p_wr = 0;
  nonce_fifo.p_rd = 0;
  nonce_fifo.nonce_num = 0;
  pthread_mutex_unlock(&nonce_mutex);
}
