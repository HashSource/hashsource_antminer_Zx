void mcast_init()
{
  thr_info *v0; // r0
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  v0 = (thr_info *)calloc(1u, 0x40u);
  if ( !v0 )
  {
    strcpy(tmp42, "Failed to calloc mcast thr");
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( thr_info_create(v0, 0, mcast_thread, v0) )
  {
    strcpy(tmp42, "API mcast thread create failed");
    applog(3, tmp42, 1);
    quit(1);
  }
}
