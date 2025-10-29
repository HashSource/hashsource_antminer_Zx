int __fastcall dhash_start_kas(int a1)
{
  int v2; // r3
  int result; // r0
  _DWORD v4[7]; // [sp+28h] [bp-1024h] BYREF
  int v5; // [sp+44h] [bp-1008h]
  char v6[4100]; // [sp+48h] [bp-1004h] BYREF

  V_LOCK();
  V_INT((int)v4, "chain", *(int *)(a1 + 224));
  logfmt_raw(v6, 0x1000u, 0, v5, v4[0], v4[1], v4[2], v4[3], v4[4], v4[5], v4[6], v5, "%s start", "dhash_start_kas");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/backend_kas_2380/backend_kas_2380.c",
    175,
    "dhash_start_kas",
    15,
    363,
    40,
    v6);
  v2 = *(unsigned __int8 *)(a1 + 428);
  result = 0;
  *(_BYTE *)(a1 + 229) = 1;
  if ( !v2 )
    *(_DWORD *)(a1 + 432) = (int)*(float *)(a1 + 924);
  return result;
}
