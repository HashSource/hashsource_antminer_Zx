void __cdecl env_init(runtime_base_t *runtime)
{
  int chainid; // [sp+8h] [bp+8h]
  int sensorid; // [sp+Ch] [bp+Ch]

  strcpy(runtime->asic_name, app_conf->name);
  runtime->addr_interval = calc_asic_addr_interval(app_conf->asic_num);
  runtime->sensor_num = app_conf->sensor_num;
  for ( sensorid = 0; app_conf->sensor_num > sensorid; ++sensorid )
    runtime->sensor_pos[sensorid] = app_conf->sensor_pos[sensorid];
  runtime->chain_num = app_conf->comport_num;
  for ( chainid = 0; runtime->chain_num > chainid; ++chainid )
  {
    runtime->chain_status[chainid].comport = app_conf->comport[chainid];
    runtime->chain_status[chainid].design_asic_num = app_conf->asic_num;
  }
  runtime->baudrate = app_conf->baudrate;
  runtime->nonce_shift = 20;
  bm174x_init_asic(runtime);
  equihash_init_algo(runtime);
  equihash_miner_init(runtime);
}
