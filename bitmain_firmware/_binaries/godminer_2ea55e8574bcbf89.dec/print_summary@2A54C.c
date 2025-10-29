char *print_summary()
{
  double v0; // d0
  double v1; // d11
  double v2; // r0
  double v3; // d9
  double v4; // d8
  char *result; // r0
  _DWORD *v6; // r12
  int v7; // r0
  int v8; // r3
  int v9; // r6
  int v10; // r8
  int v11; // r5
  __int64 *v12; // r4
  __int64 *v13; // r5
  int v14; // r9
  __int64 v15; // t1
  __int64 v16; // r4
  int v17; // r1
  double v18; // d10
  double v19; // r0
  int v20; // r8
  unsigned int *v21; // r4
  unsigned int v22; // r5
  unsigned int v23; // r6
  int v24; // r1
  double v25; // d8
  double v26; // r0
  int v27; // [sp+4h] [bp-2078h]
  int v28; // [sp+18h] [bp-2064h]
  char *v29; // [sp+1Ch] [bp-2060h]
  int v30; // [sp+1Ch] [bp-2060h]
  int v31; // [sp+20h] [bp-205Ch]
  int i; // [sp+2Ch] [bp-2050h]
  int v33; // [sp+3Ch] [bp-2040h] BYREF
  float v34[14]; // [sp+40h] [bp-203Ch] BYREF
  char v35[4040]; // [sp+78h] [bp-2004h] BYREF
  char v36[4100]; // [sp+1078h] [bp-1004h] BYREF

  read_system_status_from_monitor((int)v34);
  v1 = v34[6] / 1000.0 / 1000.0 / 1000.0;
  get_miner_elapsed_time();
  LODWORD(v2) = sub_12E1AC(total_accepted);
  v3 = v2 / v0 * 60.0;
  v4 = (total_diff_accepted + total_diff_rejected + total_diff_stale) / v0 * 60.0;
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Summary of runtime statistics:");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2148,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Runtime: %d hrs : %d mins : %d secs", (int)v0 / 3600, (int)v0 % 3600 / 60, (int)v0 % 60);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2149,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Average hashrate: %.1f Ghash/s", v1);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2150,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Total got job from pools: %lld", total_getworks, dword_186204);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2151,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Total generated local work  %d", local_work);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2152,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Solved blocks: %d", dword_173078);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2153,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Share submissions: %lld", total_accepted + *(_QWORD *)&total_rejected);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2154,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Accepted shares: %lld", total_accepted);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2155,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Rejected shares: %lld", total_rejected, dword_18621C);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2156,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Accepted difficulty shares: %1.f", total_diff_accepted);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2157,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Rejected difficulty shares: %1.f", total_diff_rejected);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2158,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Total Hardware errors %llu", v34[12], v34[13]);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2159,
    80,
    v36);
  if ( total_accepted || *(_QWORD *)&total_rejected )
  {
    V_LOCK();
    v16 = *(_QWORD *)&total_rejected;
    LODWORD(v18) = sub_12E1AC(100LL * *(_QWORD *)&total_rejected);
    HIDWORD(v18) = v17;
    LODWORD(v19) = sub_12E1AC(v16 + total_accepted);
    logfmt_raw(v36, 0x1000u, 0, "Reject ratio: %.1f%%", v18 / v19);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/api_new.c",
      141,
      "print_summary",
      13,
      2162,
      80,
      v36);
  }
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Utility (accepted shares / min): %.2f/min", v3);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2164,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Work Utility (diff1 shares solved / min): %.2f/min", v4);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2165,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Stale submissions discarded due to new blocks: %lld", total_stale, dword_1861CC);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2166,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Unable to get work from server occasions: %d", total_go);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2167,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Submitting work remotely delay occasions: %d", total_ro);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2168,
    80,
    v36);
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "New blocks detected on network: %d", new_blocks);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2169,
    80,
    v36);
  if ( total_pools > 0 )
  {
    V_LOCK();
    logfmt_raw(v36, 0x1000u, 0, "Summary of pool statistics:");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/api_new.c",
      141,
      "print_summary",
      13,
      2173,
      80,
      v36);
    if ( total_pools > 0 )
    {
      v30 = 0;
      do
      {
        v20 = *(_DWORD *)(pools + 4 * v30);
        V_LOCK();
        v21 = (unsigned int *)(v20 + 1936);
        logfmt_raw(v36, 0x1000u, 0, "Pool: %s", *(_DWORD *)(v20 + 12));
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/api_new.c",
          141,
          "print_summary",
          13,
          2178,
          80,
          v36);
        V_LOCK();
        logfmt_raw(v36, 0x1000u, 0, "User: %s", *(_DWORD *)(v20 + 16));
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/api_new.c",
          141,
          "print_summary",
          13,
          2179,
          80,
          v36);
        V_LOCK();
        logfmt_raw(v36, 0x1000u, 0, "Share submissions: %lld", *(_QWORD *)(v20 + 1928) + *(_QWORD *)(v20 + 1936));
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/api_new.c",
          141,
          "print_summary",
          13,
          2180,
          80,
          v36);
        V_LOCK();
        logfmt_raw(v36, 0x1000u, 0, "Accepted shares: %lld", *(_DWORD *)(v20 + 1928), *(_DWORD *)(v20 + 1932));
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/api_new.c",
          141,
          "print_summary",
          13,
          2181,
          80,
          v36);
        V_LOCK();
        logfmt_raw(v36, 0x1000u, 0, "Rejected shares: %lld", *(_DWORD *)(v20 + 1936), *(_DWORD *)(v20 + 1940));
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/api_new.c",
          141,
          "print_summary",
          13,
          2182,
          80,
          v36);
        V_LOCK();
        v20 += 1968;
        logfmt_raw(v36, 0x1000u, 0, "Accepted difficulty shares: %1.f", *(_DWORD *)(v20 - 8), *(_DWORD *)(v20 - 4));
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/api_new.c",
          141,
          "print_summary",
          13,
          2183,
          80,
          v36);
        V_LOCK();
        logfmt_raw(v36, 0x1000u, 0, "Rejected difficulty shares: %1.f", *(_DWORD *)v20, *(_DWORD *)(v20 + 4));
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/api_new.c",
          141,
          "print_summary",
          13,
          2184,
          80,
          v36);
        if ( *((_QWORD *)v21 - 1) || *(_QWORD *)v21 )
        {
          V_LOCK();
          v22 = *v21;
          v23 = v21[1];
          LODWORD(v25) = sub_12E1AC(100LL * *(_QWORD *)v21);
          HIDWORD(v25) = v24;
          LODWORD(v26) = sub_12E1AC(__PAIR64__(v23, v22) + *((_QWORD *)v21 - 1));
          logfmt_raw(v36, 0x1000u, 0, "Reject ratio: %.1f%%", v25 / v26);
          V_UNLOCK();
          zlog(
            g_zc,
            "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmi"
            "ner-origin_godminer-new/api_new.c",
            141,
            "print_summary",
            13,
            2187,
            80,
            v36);
        }
        ++v30;
      }
      while ( total_pools > v30 );
    }
  }
  V_LOCK();
  logfmt_raw(v36, 0x1000u, 0, "Summary of per device statistics:");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "print_summary",
    13,
    2192,
    80,
    v36);
  v33 = 0;
  result = (char *)get_all_created_runtime(&v33);
  if ( v33 > 0 )
  {
    v29 = result - 4;
    for ( i = 0; i < v33; ++i )
    {
      v6 = (_DWORD *)*((_DWORD *)v29 + 1);
      v29 += 4;
      v7 = snprintf(
             v35,
             0x1000u,
             "chain %d device %d wc %llu nc %llu detail: ",
             v6[56],
             v6[55],
             v27,
             v6[102],
             v6[103],
             v6[104],
             v6[105]);
      v8 = *(_DWORD *)v29;
      v9 = v7;
      v31 = *(_DWORD *)(*(_DWORD *)v29 + 304);
      if ( v31 > 0 )
      {
        v10 = 0;
        v28 = 0;
        while ( 1 )
        {
          v11 = *(_DWORD *)(v8 + 424);
          v12 = (__int64 *)(v11 + v10);
          v10 += 48;
          v13 = (__int64 *)(v11 + v10);
          ++v28;
          v14 = snprintf(&v35[v9], 4096 - v9, "%d:") + v9;
          do
          {
            v15 = *v12++;
            v14 += snprintf(&v35[v14], 4096 - v14, " %llu", v15);
          }
          while ( v13 != v12 );
          v9 = v14 + 2;
          snprintf(&v35[v14], 4096 - v14, " /");
          if ( v28 == v31 )
            break;
          v8 = *(_DWORD *)v29;
        }
      }
      V_LOCK();
      logfmt_raw(v36, 0x1000u, 0, "%s", v35);
      V_UNLOCK();
      result = (char *)zlog(
                         g_zc,
                         "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/releas"
                         "e/build/godminer-origin_godminer-new/api_new.c",
                         141,
                         "print_summary",
                         13,
                         2212,
                         80,
                         v36);
    }
  }
  return result;
}
