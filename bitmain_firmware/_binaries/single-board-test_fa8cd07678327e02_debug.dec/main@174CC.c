int __fastcall main(int argc, const char **argv, const char **envp)
{
  char tmp42[1024]; // [sp+0h] [bp+0h] BYREF
  char command[64]; // [sp+400h] [bp+400h] BYREF
  runtime_base_t *runtime; // [sp+440h] [bp+440h]
  int ret; // [sp+444h] [bp+444h]

  memset(command, 0, sizeof(command));
  app_conf = app_config_init("/mnt/card/Config.ini");
  runtime = (runtime_base_t *)calloc(0xB94u, 1u);
  env_init(runtime);
  if ( !app_conf )
    return -1;
  if ( cgpu_init(runtime) < 0 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      strcpy(tmp42, "cgpu init failed\n");
      applog(2, tmp42, 0);
    }
    return -1;
  }
  display_arguments();
  fan_control(2u);
  while ( 1 )
  {
    memset(command, 0, sizeof(command));
    if ( strcmp(app_conf->pcba_repeat_ctrl, "keyboard") )
      break;
    ret = _isoc99_fscanf(stdin, "%s", command);
LABEL_18:
    if ( ret > 0 && command[0] == 48 )
      singleBoardTest_Z15_BM1746();
    usleep(0x186A0u);
  }
  if ( !strcmp(app_conf->pcba_repeat_ctrl, "button") )
  {
    ret = v9_key_read(command, 64);
    goto LABEL_18;
  }
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    strcpy(tmp42, "please assign ctrl type: keyboard or button\n");
    applog(2, tmp42, 0);
  }
  free(runtime);
  app_config_exit(app_conf);
  cgpu_exit();
  return 0;
}
