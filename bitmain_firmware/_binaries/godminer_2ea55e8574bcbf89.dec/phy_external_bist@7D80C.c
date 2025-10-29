int __fastcall phy_external_bist(int a1, int a2, int a3, int a4)
{
  unsigned __int8 *v8; // r6
  unsigned __int8 *v9; // r5
  unsigned __int16 v10; // t1
  unsigned __int8 *v11; // r5
  unsigned __int8 v12; // t1
  _DWORD v14[7]; // [sp+38h] [bp-1084h] BYREF
  int v15; // [sp+54h] [bp-1068h]
  _DWORD v16[7]; // [sp+58h] [bp-1064h] BYREF
  int v17; // [sp+74h] [bp-1048h]
  _BYTE s[64]; // [sp+78h] [bp-1044h] BYREF
  char v19[4100]; // [sp+B8h] [bp-1004h] BYREF

  V_LOCK();
  V_INT((int)v14, "chain", *(int *)(a1 + 224));
  logfmt_raw(
    v19,
    0x1000u,
    0,
    v15,
    v14[0],
    v14[1],
    v14[2],
    v14[3],
    v14[4],
    v14[5],
    v14[6],
    v15,
    "%s start",
    "phy_external_bist");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/backend_eth_2280/backend_eth_phy_set.c",
    178,
    "phy_external_bist",
    17,
    1158,
    60,
    v19);
  memset(s, 0, sizeof(s));
  if ( a4 )
  {
    v8 = (unsigned __int8 *)(a3 - 1);
    v9 = (unsigned __int8 *)(a3 + (unsigned __int8)(a4 - 1));
    do
    {
      while ( 1 )
      {
        v10 = *++v8;
        if ( check_core_reg_with_expect_data_eth(a1, a2, v10, 64, 0xFF000100) )
          break;
        if ( v8 == v9 )
          goto LABEL_6;
      }
      V_LOCK();
      V_INT((int)v16, "chain", *(int *)(a1 + 224));
      logfmt_raw(
        v19,
        0x1000u,
        0,
        v17,
        v16[0],
        v16[1],
        v16[2],
        v16[3],
        v16[4],
        v16[5],
        v16[6],
        v17,
        "%s pcs lock failed!",
        "phy_external_bist");
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/backend_eth_2280/backend_eth_phy_set.c",
        178,
        "phy_external_bist",
        17,
        1298,
        100,
        v19);
    }
    while ( v8 != v9 );
LABEL_6:
    v11 = (unsigned __int8 *)(a3 - 1);
    do
    {
      v12 = *++v11;
      sub_75DB4(a1, v12, 133, 0xFFFF);
      sub_75DB4(a1, *v11, 134, 1342177279);
    }
    while ( v11 != v8 );
  }
  sub_75D70(a1, 132, -2147483647);
  sleep(0xAu);
  return 0;
}
