void __cdecl pop_nonce(nonce_rb_format *nonce_tmp)
{
  pthread_mutex_lock(&nonce_mutex);
  --nonce_fifo.nonce_num;
  memcpy(nonce_tmp, &nonce_fifo.nonce_buffer[nonce_fifo.p_rd], sizeof(nonce_rb_format));
  if ( nonce_fifo.p_rd >= 0x1FE )
    nonce_fifo.p_rd = 0;
  else
    ++nonce_fifo.p_rd;
  pthread_mutex_unlock(&nonce_mutex);
}
