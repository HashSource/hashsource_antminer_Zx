void patten_info_init()
{
  memset(&g_patten, 0, sizeof(g_patten));
  g_patten.asic_num = app_conf->asic_num;
  g_patten.core_num = app_conf->core_num;
  g_patten.patten_num = app_conf->pattern_num;
  strcpy(g_patten.dir_root, "pattern");
  strcpy(g_patten.dir_algo, "zec-z15");
  strcpy(g_patten.dir_asic, "asic");
  strcpy(g_patten.file_core, "core");
  g_patten.work_bin_len = 140;
  g_patten.nonce_bin_len = 4;
  g_patten.sol_bin_len = 1344;
  g_patten.total_pattens = g_patten.patten_num * g_patten.core_num * g_patten.asic_num;
  g_patten.patten_start = (unsigned __int8 *)malloc(1488 * g_patten.patten_num * g_patten.core_num * g_patten.asic_num);
  if ( !g_patten.patten_start )
  {
    printf("%s[%d] malloc failed\n", "patten_info_init", 29);
    exit(1);
  }
  memset(g_patten.patten_start, 0, 1488 * g_patten.patten_num * g_patten.core_num * g_patten.asic_num);
  g_patten.is_nonce_match = (unsigned __int8 *)malloc(g_patten.patten_num * g_patten.core_num * g_patten.asic_num);
  if ( !g_patten.is_nonce_match )
  {
    printf("%s[%d] malloc failed\n", "patten_info_init", 35);
    exit(1);
  }
  memset(g_patten.is_nonce_match, 0, g_patten.patten_num * g_patten.core_num * g_patten.asic_num);
  g_patten.asic_recv_nonces = (int *)malloc(4 * g_patten.asic_num);
  if ( !g_patten.asic_recv_nonces )
  {
    printf("%s[%d] malloc failed\n", "patten_info_init", 41);
    exit(1);
  }
  memset(g_patten.asic_recv_nonces, 0, 4 * g_patten.asic_num);
  pthread_mutex_init(&g_patten.patten_mutex, 0);
}
