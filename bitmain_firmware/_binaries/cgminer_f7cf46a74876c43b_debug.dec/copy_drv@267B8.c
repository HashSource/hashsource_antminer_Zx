device_drv *__fastcall copy_drv(device_drv *drv)
{
  device_drv *v2; // r0
  device_drv *v3; // r4
  const char *v5; // r1
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  v2 = (device_drv *)malloc(0x80u);
  if ( !v2 )
  {
    v5 = "original";
    if ( drv->copy )
      v5 = "copy";
    snprintf(tmp42, 0x1000u, "Failed to allocate device_drv copy of %s (%s)", drv->name, v5);
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  v3 = v2;
  memcpy(v2, drv, sizeof(device_drv));
  v3->copy = 1;
  return v3;
}
