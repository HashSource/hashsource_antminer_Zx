void __cdecl equihash_miner_start(runtime_base_t *runtime)
{
  char tmp42[1024]; // [sp+8h] [bp+8h] BYREF

  if ( pthread_create(&p_miner, 0, (void *(*)(void *))mining_mode, runtime) )
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      strcpy(tmp42, "create mining mode thread failed\n");
      applog(0, tmp42, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level >= 0 )
  {
    strcpy(tmp42, "create mining mode thread successed\n");
    applog(0, tmp42, 0);
  }
}
