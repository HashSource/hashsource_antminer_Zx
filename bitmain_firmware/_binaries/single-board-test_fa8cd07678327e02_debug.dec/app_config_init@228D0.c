app_config_t *__cdecl app_config_init(char *config_filename)
{
  FILE *v2; // r0
  char tmp42[1024]; // [sp+Ch] [bp+Ch] BYREF
  char dbg_fname[32]; // [sp+40Ch] [bp+40Ch] BYREF
  app_config_t *app_conf; // [sp+42Ch] [bp+42Ch]

  app_conf = (app_config_t *)calloc(0x128u, 1u);
  if ( app_config_handle(app_conf, config_filename) < 0 )
    return 0;
  memset(dbg_fname, 0, sizeof(dbg_fname));
  sprintf(dbg_fname, "%s.log", app_conf->name);
  v2 = fopen(dbg_fname, "w+");
  app_conf->dbg_fp = v2;
  if ( app_conf->dbg_fp )
    return app_conf;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "open %s file error\n", dbg_fname);
    applog(2, tmp42, 0);
  }
  return 0;
}
