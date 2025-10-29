int __fastcall get_fake_regio_runtime(int a1)
{
  _DWORD *v3; // r0
  int (**v4)(); // r0
  int v5; // r7
  int *v6; // r0
  int v7; // r4
  __int64 v8; // r0

  if ( dword_185C94[a1] )
    return dword_185C94[a1];
  v3 = calloc(1u, 0x3C8u);
  v3[55] = a1;
  dword_185C94[a1] = v3;
  v4 = dev_ctrl((int)v3);
  ((void (__fastcall *)(int))v4[1])(a1);
  v5 = dword_185C94[a1];
  pthread_mutex_init((pthread_mutex_t *)(v5 + 848), 0);
  pthread_mutex_init((pthread_mutex_t *)(v5 + 872), 0);
  v6 = queue_new(1, 0);
  v7 = dword_185C94[a1];
  *(_DWORD *)(v5 + 824) = v6;
  LODWORD(v8) = set_chip_reg_base;
  HIDWORD(v8) = set_core_reg_base;
  *(_DWORD *)(v7 + 816) = *(_DWORD *)(v7 + 824);
  *(_DWORD *)(v7 + 232) = set_chipaddr_base;
  *(_QWORD *)(v7 + 240) = v8;
  *(_DWORD *)(v7 + 236) = set_inactive_base;
  *(_DWORD *)(v7 + 260) = sync_get_chip_reg_base;
  *(_DWORD *)(v7 + 268) = sync_get_core_reg_base;
  *(_BYTE *)(v7 + 228) = 1;
  return v7;
}
