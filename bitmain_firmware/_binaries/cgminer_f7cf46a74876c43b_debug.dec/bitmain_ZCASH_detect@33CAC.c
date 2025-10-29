void bitmain_ZCASH_detect()
{
  cgpu_info *v0; // r0
  cgpu_info *v1; // r4
  void *v2; // r0
  char v3[4100]; // [sp+0h] [bp-1004h] BYREF

  v0 = (cgpu_info *)calloc(1u, 0x188u);
  if ( !v0 )
    _assert_fail("cgpu", "driver-btm-zcash.c", 0x1D65u, "bitmain_ZCASH_detect");
  v1 = v0;
  v0->drv = &bitmainZCASH_drv;
  v0->deven = dev_enable::DEV_ENABLED;
  v0->threads = 1;
  v2 = calloc(0x4B4u, 1u);
  v1->device_data = v2;
  if ( !v2 )
  {
    strcpy(v3, "Failed to calloc cgpu_info data");
    applog(3, v3, 1);
    quit(1);
  }
  if ( !add_cgpu(v1) )
    _assert_fail("add_cgpu(cgpu)", "driver-btm-zcash.c", 0x1D6Du, "bitmain_ZCASH_detect");
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(v3, 0x1000u, "%s detect new device", "bitmain_ZCASH_detect");
    applog(7, v3, 0);
  }
}
