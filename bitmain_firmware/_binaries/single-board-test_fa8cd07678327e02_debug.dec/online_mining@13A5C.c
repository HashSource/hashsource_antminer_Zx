void __cdecl online_mining(runtime_base_t *runtime)
{
  int chainid; // [sp+Ch] [bp+Ch]

  chainid = runtime->chain_id;
  runtime->set_ticket_mask(runtime->chain_status[chainid].fd, app_conf->ticket_mask);
  usleep(0x186A0u);
  runtime->set_core_timeout(runtime->chain_status[chainid].fd, app_conf->core_timeout);
  usleep(0x186A0u);
  runtime->set_frequency(runtime->chain_status[chainid].fd, app_conf->bringup_freq);
  usleep(0x186A0u);
  runtime->set_nonce_shift(runtime->chain_status[chainid].fd, 0, &runtime->nonce_shift);
  usleep(0x186A0u);
  equihash_miner_start(runtime);
  equihash_miner_join();
}
