int __cdecl pattern_test_mode2(runtime_base_t *runtime, int freq, int *nonce)
{
  int v3; // r3
  char tmp42[1024]; // [sp+14h] [bp+14h] BYREF
  int counter_limit; // [sp+414h] [bp+414h]
  int patten_check_interval; // [sp+418h] [bp+418h]
  int is_match; // [sp+41Ch] [bp+41Ch]
  int one_patten_bin_len; // [sp+420h] [bp+420h]
  int chainid; // [sp+424h] [bp+424h]
  int counter; // [sp+428h] [bp+428h]
  int which_patten; // [sp+42Ch] [bp+42Ch]
  int which_core; // [sp+430h] [bp+430h]
  int which_asic; // [sp+434h] [bp+434h]

  chainid = runtime->chain_id;
  clear_last_test_results();
  runtime->set_ticket_mask(runtime->chain_status[chainid].fd, app_conf->ticket_mask);
  usleep(0x186A0u);
  runtime->set_core_timeout(runtime->chain_status[chainid].fd, app_conf->core_timeout);
  usleep(0x186A0u);
  runtime->set_frequency(runtime->chain_status[chainid].fd, freq);
  usleep(0x186A0u);
  runtime->set_nonce_shift(runtime->chain_status[chainid].fd, 0, &runtime->nonce_shift);
  one_patten_bin_len = g_patten.sol_bin_len + g_patten.work_bin_len + g_patten.nonce_bin_len;
  g_patten.start = 1;
  sleep(1u);
  for ( which_asic = 0; g_patten.asic_num > which_asic; ++which_asic )
  {
    for ( which_core = 0; g_patten.core_num > which_core; ++which_core )
    {
      for ( which_patten = 0; g_patten.patten_num > which_patten; ++which_patten )
      {
        pthread_mutex_lock(&g_patten.patten_mutex);
        g_patten.cur_work = &g_patten.patten_start[one_patten_bin_len * which_core * g_patten.patten_num
                                                 + one_patten_bin_len
                                                 * g_patten.patten_num
                                                 * which_asic
                                                 * g_patten.core_num
                                                 + one_patten_bin_len * which_patten];
        g_patten.cur_asic = which_asic;
        g_patten.cur_core = which_core;
        g_patten.cur_patten = which_patten;
        pthread_mutex_unlock(&g_patten.patten_mutex);
        --g_patten.cur_work[g_patten.work_bin_len - 1];
        user_send_work(runtime, g_patten.cur_work, 1, 0);
        is_match = 0;
        patten_check_interval = 50;
        counter_limit = app_conf->slt_work_interval_ms / 50;
        counter = 0;
        do
        {
          usleep(1000 * patten_check_interval);
          pthread_mutex_lock(&g_patten.patten_mutex);
          is_match = g_patten.is_nonce_match[g_patten.cur_patten
                                           + g_patten.patten_num
                                           * (g_patten.core_num * g_patten.cur_asic + g_patten.cur_core)];
          pthread_mutex_unlock(&g_patten.patten_mutex);
          if ( is_match == 1 )
            break;
          v3 = counter++;
        }
        while ( v3 < counter_limit );
        if ( is_match != 1 )
        {
          if ( use_syslog || opt_log_output || opt_log_level > 1 )
          {
            snprintf(tmp42, 0x400u, "pattern id %d receive failed\n", which_patten);
            applog(2, tmp42, 0);
          }
          dump_str((void *)stderr, 0, g_patten.cur_work, g_patten.work_bin_len);
        }
      }
    }
  }
  g_patten.start = 0;
  *nonce = g_patten.recv_nonces;
  return 0;
}
