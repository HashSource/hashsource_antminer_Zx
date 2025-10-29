int send_heart_beat_to_every_chain()
{
  int v0; // r6
  thr_info *v1; // r0
  void *(*v2)(void *); // r2
  const char *v3; // r2
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  v1 = (thr_info *)calloc(1u, 0x40u);
  LOWORD(v2) = 32365;
  HIWORD(v2) = (unsigned int)&loc_37D5C >> 16;
  pic_heart_beat = v1;
  if ( thr_info_create(v1, 0, v2, v1) )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      LOWORD(v3) = -27412;
      HIWORD(v3) = (unsigned int)"update_pic_app_program_new" >> 16;
      snprintf(tmp42, 0x1000u, v3, "send_heart_beat_to_every_chain");
      applog(3, tmp42, 0);
    }
    return -3;
  }
  else
  {
    pthread_detach(pic_heart_beat->pth);
    return v0;
  }
}
