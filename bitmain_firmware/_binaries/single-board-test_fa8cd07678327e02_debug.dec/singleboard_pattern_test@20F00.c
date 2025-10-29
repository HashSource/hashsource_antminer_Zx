void singleboard_pattern_test()
{
  int v0; // r3
  int v1; // r3
  char tmp42[1024]; // [sp+0h] [bp+0h] BYREF
  int offset; // [sp+400h] [bp+400h]
  int is_match; // [sp+404h] [bp+404h]
  int counter_limit; // [sp+408h] [bp+408h]
  int patten_check_interval; // [sp+40Ch] [bp+40Ch]
  int one_patten_bin_len; // [sp+410h] [bp+410h]
  int counter; // [sp+414h] [bp+414h]
  int which_patten; // [sp+418h] [bp+418h]
  int which_core; // [sp+41Ch] [bp+41Ch]
  int which_asic; // [sp+420h] [bp+420h]
  int i; // [sp+424h] [bp+424h]

  one_patten_bin_len = g_patten.sol_bin_len + g_patten.work_bin_len + g_patten.nonce_bin_len;
  g_patten.start = 1;
  sleep(1u);
  fan_control(5u);
  for ( which_asic = 0; g_patten.asic_num > which_asic; ++which_asic )
  {
    for ( which_core = 0; g_patten.core_num > which_core; ++which_core )
    {
      for ( which_patten = 0; g_patten.patten_num > which_patten; ++which_patten )
      {
        if ( hardware_exception )
        {
          if ( use_syslog || opt_log_output || opt_log_level > 0 )
          {
            snprintf(tmp42, 0x400u, "%s hardware error\n", "singleboard_pattern_test");
            applog(1, tmp42, 0);
          }
          which_patten = g_patten.patten_num;
          which_core = g_patten.core_num;
          which_asic = g_patten.asic_num;
        }
        else
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
          user_send_work(cgpu.runtime, g_patten.cur_work, 1, 0);
          patten_check_interval = 50000;
          counter_limit = app_conf->send_pattern_timeout / 50000;
          counter = 0;
          is_match = 0;
          do
          {
            usleep(patten_check_interval);
            pthread_mutex_lock(&g_patten.patten_mutex);
            is_match = g_patten.is_nonce_match[g_patten.cur_patten
                                             + g_patten.patten_num
                                             * (g_patten.core_num * g_patten.cur_asic + g_patten.cur_core)];
            pthread_mutex_unlock(&g_patten.patten_mutex);
            if ( is_match == 1 )
              break;
            v0 = counter++;
          }
          while ( v0 < counter_limit );
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
  }
  g_patten.start = 0;
  sleep(1u);
  for ( which_asic = 0; g_patten.asic_num > which_asic; ++which_asic )
  {
    printf("ASIC %d result:\n", which_asic);
    offset = g_patten.patten_num * which_asic * g_patten.core_num;
    for ( i = 0; g_patten.patten_num * g_patten.core_num > i; ++i )
    {
      if ( g_patten.is_nonce_match[i + offset] )
        v1 = 79;
      else
        v1 = 88;
      printf("%c ", v1);
      if ( i % 10 == 9 )
        putchar(10);
    }
    putchar(10);
  }
}
