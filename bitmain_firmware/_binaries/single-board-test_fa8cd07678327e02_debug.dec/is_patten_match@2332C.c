int __cdecl is_patten_match(int asic_index, uint8_t *nonce, uint8_t *sol)
{
  int sol_ret; // [sp+14h] [bp+14h]
  int nonce_ret; // [sp+18h] [bp+18h]
  int ret; // [sp+1Ch] [bp+1Ch]

  if ( g_patten.cur_asic == asic_index )
  {
    pthread_mutex_lock(&g_patten.patten_mutex);
    nonce_ret = memcmp(&g_patten.cur_work[g_patten.work_bin_len], nonce, g_patten.nonce_bin_len);
    sol_ret = memcmp(&g_patten.cur_work[g_patten.nonce_bin_len + g_patten.work_bin_len], sol, g_patten.sol_bin_len);
    if ( nonce_ret || sol_ret )
    {
      dump_str((void *)stderr, "Not Match Recv:", nonce, g_patten.nonce_bin_len);
      dump_str((void *)stderr, "Not Match Expect:", &g_patten.cur_work[g_patten.work_bin_len], g_patten.nonce_bin_len);
      ret = -1;
    }
    else
    {
      g_patten.is_nonce_match[g_patten.cur_patten
                            + g_patten.patten_num * (g_patten.core_num * g_patten.cur_asic + g_patten.cur_core)] = 1;
      g_patten.total_rate = (float)++g_patten.recv_nonces / (float)g_patten.total_pattens;
      ++g_patten.asic_recv_nonces[g_patten.cur_asic];
      ret = 0;
    }
    pthread_mutex_unlock(&g_patten.patten_mutex);
    return ret;
  }
  else
  {
    printf("asic is not match %d vs %d\n", asic_index, g_patten.cur_asic);
    return -1;
  }
}
