void clear_nonce_fifo()
{
  pthread_mutex_lock(&nonce_mutex);
  nonce_fifo.p_wr = 0;
  nonce_fifo.p_rd = 0;
  nonce_fifo.nonce_num = 0;
  clear_uart_rx_fifo(0);
  clear_uart_rx_fifo(1u);
  clear_uart_rx_fifo(2u);
  clear_uart_rx_fifo(3u);
  j_pthread_mutex_unlock(&nonce_mutex);
}
