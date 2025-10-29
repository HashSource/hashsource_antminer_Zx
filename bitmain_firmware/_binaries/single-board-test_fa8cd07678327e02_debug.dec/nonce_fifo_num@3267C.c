void __cdecl nonce_fifo_num(int *num)
{
  pthread_mutex_lock(&nonce_mutex);
  *num = nonce_fifo.nonce_num;
  pthread_mutex_unlock(&nonce_mutex);
}
