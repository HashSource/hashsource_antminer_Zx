void __cdecl app_config_exit(app_config_t *conf)
{
  fclose(conf->dbg_fp);
  free(conf->comport);
  free(conf->sensor_pos);
  free(conf->bringup_autojh_freq);
  free(conf->bringup_autojh_volt);
  free(conf->slt_bin_rate);
  free(conf->pcba_level_rate);
  free(conf);
}
