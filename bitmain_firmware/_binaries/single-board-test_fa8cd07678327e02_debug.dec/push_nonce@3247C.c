void __cdecl push_nonce(nonce_rb_format *nonce_item)
{
  char tmp42[1024]; // [sp+8h] [bp+8h] BYREF

  pthread_mutex_lock(&nonce_mutex);
  memcpy(&nonce_fifo.nonce_buffer[nonce_fifo.p_wr], nonce_item, sizeof(nonce_fifo.nonce_buffer[nonce_fifo.p_wr]));
  if ( nonce_fifo.p_wr >= 0x1FE )
    nonce_fifo.p_wr = 0;
  else
    ++nonce_fifo.p_wr;
  if ( nonce_fifo.nonce_num > 0x1FE )
  {
    nonce_fifo.nonce_num = 511;
    if ( use_syslog || opt_log_output || opt_log_level > 0 )
    {
      snprintf(tmp42, 0x400u, "%s: nonce fifo full!!!\n", "push_nonce");
      applog(1, tmp42, 0);
    }
  }
  else
  {
    ++nonce_fifo.nonce_num;
  }
  pthread_mutex_unlock(&nonce_mutex);
}
