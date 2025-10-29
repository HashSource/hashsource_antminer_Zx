int __fastcall top_init_kas(int *a1)
{
  int v2; // r7
  int v3; // r4
  int v4; // r0
  int v5; // r1
  char v6; // r3
  void (__fastcall *v7)(int *, int, int); // r3
  void *v8; // r0
  _DWORD v10[7]; // [sp+28h] [bp-1024h] BYREF
  int v11; // [sp+44h] [bp-1008h]
  char v12[4100]; // [sp+48h] [bp-1004h] BYREF

  V_LOCK();
  V_INT((int)v10, "chain", a1[56]);
  logfmt_raw(
    v12,
    0x1000u,
    0,
    v11,
    v10[0],
    v10[1],
    v10[2],
    v10[3],
    v10[4],
    v10[5],
    v10[6],
    v11,
    "%s start",
    "top_init_kas");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/backend_kas_2380/backend_kas_2380.c",
    175,
    "top_init_kas",
    12,
    866,
    60,
    v12);
  v2 = a1[76];
  v3 = a1[114];
  v4 = sub_12DBE0(256, (unsigned __int8)v2);
  if ( (_BYTE)v2 )
  {
    v5 = v3 - 1;
    v6 = 0;
    do
    {
      *(_BYTE *)++v5 = v6;
      v6 += v4;
    }
    while ( v5 != v3 - 1 + (unsigned __int8)v2 );
    v3 = a1[114];
    v2 = a1[76];
  }
  v7 = (void (__fastcall *)(int *, int, int))a1[58];
  a1[99] = v4;
  v7(a1, v3, v2);
  v8 = malloc(0x450u);
  sub_83D8C((int)a1, 0, v8);
  set_core_enable_kas((int)a1, 23130);
  sub_83F4C(a1, 127);
  set_work_len_kas((int)a1);
  set_nonce_len_kas((int)a1);
  set_nonce_count_zero_kas((int)a1);
  set_nonce_overflow_kas((int)a1, 0);
  sub_857B4(a1);
  return 0;
}
