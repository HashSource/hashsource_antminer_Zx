int send_heart_beat_to_every_chain()
{
  int v0; // r6
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  pic_heart_beat = (thr_info *)calloc(1u, 0x40u);
  if ( thr_info_create(pic_heart_beat, 0, (void *(*)(void *))pic_heart_beat_func_new, pic_heart_beat) )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      snprintf(tmp42, 0x1000u, "%s: create thread error for pic_heart_beat_func", "send_heart_beat_to_every_chain");
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
