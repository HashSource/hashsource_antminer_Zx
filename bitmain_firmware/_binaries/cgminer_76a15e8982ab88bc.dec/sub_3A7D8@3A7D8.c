void sub_3A7D8()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r4
  void *v2; // r0
  char v3[4100]; // [sp+0h] [bp-1004h] BYREF

  v0 = calloc(1u, 0x188u);
  v1 = v0;
  if ( !v0 )
    _assert_fail("cgpu", "driver-btm-zcash.c", 0x1B6Fu, "bitmain_ZCASH_detect");
  v0[37] = 1;
  v0[1] = &unk_73908;
  v0[8] = 0;
  v2 = calloc(0x4B4u, 1u);
  v1[5] = v2;
  if ( !v2 )
  {
    strcpy(v3, "Failed to calloc cgpu_info data");
    sub_385C8(3, v3, 1);
    sub_16BE0(1);
  }
  if ( !sub_27F60(v1) )
    _assert_fail("add_cgpu(cgpu)", "driver-btm-zcash.c", 0x1B77u, "bitmain_ZCASH_detect");
  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(v3, 0x1000u, "%s detect new device", "bitmain_ZCASH_detect");
    sub_385C8(7, v3, 0);
  }
}
