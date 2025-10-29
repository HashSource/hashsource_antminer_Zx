int __fastcall chip_speed_test(int a1, int a2)
{
  int v4; // r3
  int v5; // r0
  int v6; // lr
  _DWORD *v7; // r2
  unsigned int v8; // r8
  unsigned int v9; // r12
  unsigned int v10; // t1
  int v11; // r1
  int v12; // r8
  int v13; // r3
  int *v14; // r2
  int v15; // t1
  int *v17; // r5
  int v18; // r6
  int v19; // r9
  int v20; // t1
  float v21; // [sp+10h] [bp-1454h] BYREF
  int v22; // [sp+14h] [bp-1450h] BYREF
  unsigned __int8 v23; // [sp+1Ah] [bp-144Ah]
  _DWORD v24[16]; // [sp+20h] [bp-1444h] BYREF
  char v25[1024]; // [sp+60h] [bp-1404h] BYREF
  char v26[4100]; // [sp+460h] [bp-1004h] BYREF

  v21 = 0.0;
  (*(void (__fastcall **)(int, float *))(a1 + 144))(a1, &v21);
  v21 = v21 * 120.0;
  V_LOCK();
  logfmt_raw(v26, 0x1000u, 0, "qualify nonce count %f", v21);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/miner_monitor/update_miner_status/update_chip_status.c",
    197,
    "chip_speed_test",
    15,
    35,
    20,
    v26);
  get_miner_working_status((int)&v22);
  v4 = v23;
  if ( v23 )
  {
    V_LOCK();
    logfmt_raw(v26, 0x1000u, 0, "check lost connection to pool, keep the state of all chips!");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/miner_util/miner_monitor/update_miner_status/update_chip_status.c",
      197,
      "chip_speed_test",
      15,
      43,
      20,
      v26);
    return 0;
  }
  else
  {
    if ( *(int *)(a1 + 304) <= 0 )
    {
      if ( *(int *)(a1 + 492) >= 0 )
        return 0;
      strcpy(v25, "bad asic id:");
    }
    else
    {
      v5 = v23;
      v6 = v23;
      v7 = (_DWORD *)(*(_DWORD *)(a1 + 448) - 4);
      v8 = (unsigned int)v21;
      do
      {
        v10 = v7[1];
        ++v7;
        v9 = v10;
        v11 = v5 & 0xF;
        if ( v10 < v8 )
        {
          ++v5;
          if ( v9 )
            *(_DWORD *)(a2 + 4 * v4) = 3;
          else
            *(_DWORD *)(a2 + 4 * v4) = 2;
          v24[v11] = v4;
        }
        else
        {
          *(_DWORD *)(a2 + 4 * v4) = v6;
        }
        *v7 = v6;
        ++v4;
      }
      while ( *(_DWORD *)(a1 + 304) > v4 );
      if ( v5 >= 16 )
        v12 = 16;
      else
        v12 = v5;
      if ( *(_DWORD *)(a1 + 492) >= v5 )
      {
        if ( v5 > 0 )
        {
          v13 = 0;
          v14 = v24;
          do
          {
            ++v13;
            v15 = *v14++;
            *(_DWORD *)(a2 + 4 * v15) = 0;
          }
          while ( v12 > v13 );
        }
        return 0;
      }
      strcpy(v25, "bad asic id:");
      if ( v5 > 0 )
      {
        v17 = v24;
        v18 = 12;
        v19 = 0;
        do
        {
          ++v19;
          v20 = *v17++;
          v18 += snprintf(&v25[v18], 1024 - v18, "%03d ", v20);
        }
        while ( v12 > v19 );
      }
    }
    V_LOCK();
    logfmt_raw(v26, 0x1000u, 0, "%s", v25);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/miner_util/miner_monitor/update_miner_status/update_chip_status.c",
      197,
      "chip_speed_test",
      15,
      100,
      40,
      v26);
    return 0;
  }
}
