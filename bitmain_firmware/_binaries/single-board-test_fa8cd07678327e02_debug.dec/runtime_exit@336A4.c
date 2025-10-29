void __cdecl runtime_exit(runtime_base_t *runtime)
{
  char tmp42[1024]; // [sp+Ch] [bp+Ch] BYREF
  int chainid; // [sp+40Ch] [bp+40Ch]

  runtime->start_recv = 0;
  chainid = runtime->chain_id;
  usleep((__useconds_t)&buf_7545[4072]);
  pthread_cancel(runtime->p_scanhash);
  pthread_join(runtime->p_scanhash, 0);
  pthread_cancel(runtime->chain_status[chainid].p_dispatch);
  pthread_join(runtime->chain_status[chainid].p_dispatch, 0);
  reg_list_exit();
  work_list_exit();
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "%s Done!\n", "runtime_exit");
    applog(2, tmp42, 0);
  }
}
