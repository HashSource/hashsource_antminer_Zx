void start_http_thread()
{
  int v0; // r0
  pthread_t tid_ctrl; // [sp+0h] [bp-102Ch] BYREF
  pthread_attr_t tattr_ctrl; // [sp+4h] [bp-1028h] BYREF
  char tmp42[4100]; // [sp+28h] [bp-1004h] BYREF

  pthread_attr_init(&tattr_ctrl);
  pthread_attr_setstacksize(&tattr_ctrl, 0x200000u);
  v0 = pthread_create(&tid_ctrl, &tattr_ctrl, httpListenThread, 0);
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "httpListenThread start ret=%d", v0);
    applog(5, tmp42, 0);
  }
}
