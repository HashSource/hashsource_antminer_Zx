device_drv *__fastcall copy_drv(device_drv *drv)
{
  device_drv *v2; // r0
  device_drv *v3; // r4
  int v5; // r2
  int v6; // r1
  const char *v7; // r2
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  v2 = (device_drv *)malloc(0x80u);
  if ( !v2 )
  {
    LOWORD(v5) = 5716;
    LOWORD(v6) = 5724;
    HIWORD(v6) = (unsigned int)" %s" >> 16;
    if ( drv->copy )
    {
      HIWORD(v5) = (unsigned int)"tum msg: %s" >> 16;
      v6 = v5;
    }
    LOWORD(v7) = 5736;
    HIWORD(v7) = (unsigned int)"o malloc userpass" >> 16;
    snprintf(tmp42, 0x1000u, v7, drv->name, v6);
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  v3 = v2;
  memcpy(v2, drv, sizeof(device_drv));
  v3->copy = 1;
  return v3;
}
