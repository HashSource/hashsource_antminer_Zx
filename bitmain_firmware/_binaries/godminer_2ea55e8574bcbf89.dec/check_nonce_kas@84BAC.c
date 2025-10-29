int __fastcall check_nonce_kas(int a1, int a2)
{
  unsigned int v2; // r3
  int v5; // r1
  int v6; // r8
  char *v7; // r3
  char *v8; // r2
  unsigned int v9; // r5
  int v10; // r1
  int v11; // t1
  unsigned int v12; // r0
  unsigned int v13; // r6
  unsigned __int8 *v14; // r2
  int v15; // r12
  int v16; // r3
  int v17; // r12
  unsigned int v18; // r0
  unsigned int v19; // t1
  unsigned int v20; // t1
  bool v21; // cc
  int v23; // r2
  int v24; // r0
  int v25; // r1
  _DWORD v26[7]; // [sp+30h] [bp-10A0h] BYREF
  int v27; // [sp+4Ch] [bp-1084h]
  _DWORD v28[7]; // [sp+50h] [bp-1080h] BYREF
  int v29; // [sp+6Ch] [bp-1064h]
  _DWORD v30[7]; // [sp+70h] [bp-1060h] BYREF
  int v31; // [sp+8Ch] [bp-1044h] BYREF
  char v32; // [sp+AFh] [bp-1021h] BYREF
  _DWORD v33[7]; // [sp+B0h] [bp-1020h] BYREF
  int v34; // [sp+CCh] [bp-1004h]
  char v35[4096]; // [sp+D0h] [bp-1000h] BYREF

  v2 = *(unsigned __int8 *)(a2 + 17);
  v5 = *(unsigned __int8 *)(a2 + 16);
  if ( v2 <= 0x23 )
  {
    V_LOCK();
    V_INT((int)v33, "chain", *(int *)(a1 + 224));
    logfmt_raw(
      v35,
      0x1000u,
      0,
      v34,
      v33[0],
      v33[1],
      v33[2],
      v33[3],
      v33[4],
      v33[5],
      v33[6],
      v34,
      "ans diff %d TICKET_MASK_KAS_2380 %d",
      *(unsigned __int8 *)(a2 + 17),
      36);
    V_UNLOCK();
    v23 = 462;
    v24 = g_zc;
    LOWORD(v25) = (unsigned __int16)"/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot"
                                    "/tmp/release/build/godminer-origin_godminer-new/backend/backend_kas_2380/backend_kas_2380.c";
LABEL_13:
    HIWORD(v25) = (unsigned int)"/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp"
                                "/release/build/godminer-origin_godminer-new/backend/backend_kas_2380/backend_kas_2380.c" >> 16;
    zlog(v24, v25, 175, "check_nonce_kas", 15, v23, 20, v35);
    return 2;
  }
  v6 = *(_DWORD *)(a1 + 784);
  v7 = (char *)&v31 + 3;
  v8 = v35;
  v9 = *(unsigned __int8 *)(v6 + v5 + 0x2000);
  do
  {
    v11 = (unsigned __int8)*++v7;
    v10 = v11;
    *--v8 = v11;
  }
  while ( v7 != &v32 );
  v12 = target_to_diff_kas((int)v33, v10, (int)v8);
  v13 = v12;
  if ( v12 <= 0x23 )
  {
    V_LOCK();
    V_INT((int)v26, "chain", *(int *)(a1 + 224));
    logfmt_raw(
      v35,
      0x1000u,
      0,
      v27,
      v26[0],
      v26[1],
      v26[2],
      v26[3],
      v26[4],
      v26[5],
      v26[6],
      v27,
      "hw error calculate diff %d ans diff %d TICKET_MASK_KAS_2380 %d",
      v13,
      *(unsigned __int8 *)(a2 + 17),
      36);
    V_UNLOCK();
    v24 = g_zc;
    v23 = 508;
    LOWORD(v25) = -6072;
    goto LABEL_13;
  }
  if ( v9 > v12 )
  {
LABEL_11:
    V_LOCK();
    V_INT((int)v28, "chain", *(int *)(a1 + 224));
    logfmt_raw(
      v35,
      0x1000u,
      0,
      v29,
      v28[0],
      v28[1],
      v28[2],
      v28[3],
      v28[4],
      v28[5],
      v28[6],
      v29,
      "hw diff (%d<%d) not reach pool",
      v13,
      v9);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/backend_kas_2380/backend_kas_2380.c",
      175,
      "check_nonce_kas",
      15,
      528,
      20,
      v35);
    return 1;
  }
  else
  {
    v14 = (unsigned __int8 *)v33;
    v15 = v6 + 32 * (*(unsigned __int8 *)(a2 + 16) + 260);
    v16 = v15 - 1;
    v17 = v15 + 31;
    do
    {
      v19 = *v14++;
      v18 = v19;
      v20 = *(unsigned __int8 *)++v16;
      v21 = v18 > v20;
      if ( v18 < v20 )
        break;
      if ( v21 )
        goto LABEL_11;
    }
    while ( v17 != v16 );
    V_LOCK();
    V_INT((int)v30, "chain", *(int *)(a1 + 224));
    logfmt_raw(
      v35,
      0x1000u,
      0,
      v31,
      v30[0],
      v30[1],
      v30[2],
      v30[3],
      v30[4],
      v30[5],
      v30[6],
      v31,
      "Verification passed! diff %d expected_diff %d ",
      v13,
      v9);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/backend_kas_2380/backend_kas_2380.c",
      175,
      "check_nonce_kas",
      15,
      531,
      20,
      v35);
    return 0;
  }
}
