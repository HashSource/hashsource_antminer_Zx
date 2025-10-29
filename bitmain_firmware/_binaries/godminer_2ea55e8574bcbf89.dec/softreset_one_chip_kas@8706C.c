int __fastcall softreset_one_chip_kas(int *a1, int a2)
{
  int v4; // r3
  void (__fastcall *v5)(int *, int *); // r2
  int v6; // r3
  void (__fastcall *v7)(int *, int *); // r2
  _DWORD v9[7]; // [sp+28h] [bp-1020h] BYREF
  int v10; // [sp+44h] [bp-1004h]
  int v11; // [sp+48h] [bp-1000h] BYREF
  int v12; // [sp+4Ch] [bp-FFCh]
  int v13; // [sp+50h] [bp-FF8h]
  int v14; // [sp+54h] [bp-FF4h]

  V_LOCK();
  V_INT((int)v9, "chain", a1[56]);
  logfmt_raw(
    (char *)&v11,
    0x1000u,
    0,
    v10,
    v9[0],
    v9[1],
    v9[2],
    v9[3],
    v9[4],
    v9[5],
    v9[6],
    v10,
    "softreset chip addr %d",
    a2);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/backend_kas_2380/backend_kas_2380.c",
    175,
    "softreset_one_chip_kas",
    22,
    596,
    40,
    &v11);
  v4 = a1[81];
  v13 = 4456448;
  v14 = 0;
  v12 = 0;
  v11 = 3;
  v5 = (void (__fastcall *)(int *, int *))a1[60];
  BYTE1(v13) = v4 * a2;
  v5(a1, &v11);
  v6 = a1[81];
  v13 = 655360;
  v14 = 255;
  v12 = 0;
  v11 = 0;
  v7 = (void (__fastcall *)(int *, int *))a1[61];
  BYTE1(v13) = v6 * a2;
  v7(a1, &v11);
  usleep((__useconds_t)&stru_1387C.st_value);
  sub_83F4C(a1, 36);
  sub_84074((int)a1, 0, 0, a2);
  return 0;
}
