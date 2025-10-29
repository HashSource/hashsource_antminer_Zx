_DWORD *sub_1A520()
{
  _DWORD *v0; // r4
  char v2[4096]; // [sp+0h] [bp-1000h] BYREF

  v0 = calloc(1u, 0x7B0u);
  if ( !v0 )
  {
    strcpy(v2, "Failed to calloc work in make_work");
    sub_385C8(3, v2, 1);
    sub_16BE0(1);
  }
  v0[457] = sub_1A334();
  return v0;
}
