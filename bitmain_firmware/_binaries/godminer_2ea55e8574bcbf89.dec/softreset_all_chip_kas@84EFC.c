int __fastcall softreset_all_chip_kas(int a1)
{
  int v2; // r5
  unsigned int v3; // r0
  int (**v4)(); // r0
  int (**v5)(); // r0
  _DWORD v7[7]; // [sp+28h] [bp-1024h] BYREF
  int v8; // [sp+44h] [bp-1008h]
  int v9; // [sp+48h] [bp-1004h] BYREF
  int v10; // [sp+4Ch] [bp-1000h]
  int v11; // [sp+50h] [bp-FFCh]
  int v12; // [sp+54h] [bp-FF8h]
  int v13; // [sp+58h] [bp-FF4h]
  int v14; // [sp+5Ch] [bp-FF0h]
  int v15; // [sp+60h] [bp-FECh]
  int v16; // [sp+64h] [bp-FE8h]
  int v17; // [sp+68h] [bp-FE4h]
  int v18; // [sp+6Ch] [bp-FE0h]
  int v19; // [sp+70h] [bp-FDCh]
  int v20; // [sp+74h] [bp-FD8h]
  int v21; // [sp+78h] [bp-FD4h]
  __int16 v22; // [sp+7Ch] [bp-FD0h]

  V_LOCK();
  V_INT((int)v7, "chain", *(int *)(a1 + 224));
  v2 = 10;
  logfmt_raw((char *)&v9, 0x1000u, 0, v8, v7[0], v7[1], v7[2], v7[3], v7[4], v7[5], v7[6], v8, "softreset chain");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/backend_kas_2380/backend_kas_2380.c",
    175,
    "softreset_all_chip_kas",
    22,
    562,
    40,
    &v9);
  V_LOCK();
  logfmt_raw((char *)&v9, 0x1000u, 0, "software_reset %s %02x", "ChipSetting_software_reset_KAS_2380", 68);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/chip_setting.c",
    154,
    "ChipSetting_software_reset_KAS_2380",
    35,
    125,
    20,
    &v9);
  v11 = 4456449;
  v12 = 0;
  v9 = 3;
  v10 = 0;
  (*(void (__fastcall **)(int, int *))(a1 + 240))(a1, &v9);
  do
  {
    usleep((__useconds_t)&stru_1869C.st_value);
    v9 = 53520981;
    v10 = -1996423168;
    v11 = 1568885659;
    v12 = -2022340884;
    v13 = 739994112;
    v14 = 2023104256;
    v15 = 504402544;
    v16 = 232286627;
    v17 = 1496646687;
    v18 = 295890251;
    v19 = 1890778236;
    v20 = 60442;
    v21 = 0;
    v22 = 13171;
    v3 = pthread_mutex_lock((pthread_mutex_t *)(a1 + 896));
    do
    {
      v4 = dev_ctrl(v3);
      v3 = ((int (__fastcall *)(_DWORD))v4[17])(*(_DWORD *)(a1 + 220));
    }
    while ( v3 <= 0x35 );
    v5 = dev_ctrl(v3);
    ((void (__fastcall *)(_DWORD, int *, int))v5[13])(*(_DWORD *)(a1 + 220), &v9, 54);
    pthread_mutex_unlock((pthread_mutex_t *)(a1 + 896));
    --v2;
  }
  while ( v2 );
  sub_83C78(a1, 10, 0);
  sub_83F4C((int *)a1, 127);
  return 0;
}
