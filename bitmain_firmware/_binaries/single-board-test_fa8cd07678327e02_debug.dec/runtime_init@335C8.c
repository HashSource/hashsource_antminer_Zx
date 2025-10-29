void __cdecl runtime_init(runtime_base_t *runtime)
{
  char tmp42[1024]; // [sp+Ch] [bp+Ch] BYREF
  int chainid; // [sp+40Ch] [bp+40Ch]

  work_list_init(runtime->nonce_verify_info.work_len);
  reg_list_init();
  chainid = runtime->chain_id;
  sleep(1u);
  pthread_create(&runtime->chain_status[chainid].p_dispatch, 0, (void *(*)(void *))handle_asic_response, runtime);
  pthread_create(&runtime->p_scanhash, 0, (void *(*)(void *))nonce_scanhash_loop, runtime);
  runtime->start_recv = 1;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "%s Done!\n", "runtime_init");
    applog(2, tmp42, 0);
  }
}
