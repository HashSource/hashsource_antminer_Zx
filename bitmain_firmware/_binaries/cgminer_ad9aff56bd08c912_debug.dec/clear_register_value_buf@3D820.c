void clear_register_value_buf()
{
  pthread_mutex_lock(&reg_mutex);
  reg_fifo.p_wr = 0;
  reg_fifo.p_rd = 0;
  reg_fifo.reg_value_num = 0;
  j_pthread_mutex_unlock(&reg_mutex);
}
