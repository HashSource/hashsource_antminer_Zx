void start_http_thread()
{
  void *(*v0)(void *); // r2
  int v1; // r0
  const char *v2; // r2
  pthread_t tid_ctrl; // [sp+0h] [bp-102Ch] BYREF
  pthread_attr_t tattr_ctrl; // [sp+4h] [bp-1028h] BYREF
  char tmp42[4100]; // [sp+28h] [bp-1004h] BYREF

  pthread_attr_init(&tattr_ctrl);
  pthread_attr_setstacksize(&tattr_ctrl, 0x200000u);
  LOWORD(v0) = 31213;
  HIWORD(v0) = ((unsigned int)&loc_479BA + 3) >> 16;
  v1 = pthread_create(&tid_ctrl, &tattr_ctrl, v0, 0);
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v2) = -20488;
    HIWORD(v2) = (unsigned int)" on 6060 ..." >> 16;
    snprintf(tmp42, 0x1000u, v2, v1);
    applog(5, tmp42, 0);
  }
}
