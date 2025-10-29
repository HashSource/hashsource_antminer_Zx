_DWORD *__fastcall update_hashrate(int a1, int a2, _DWORD *a3)
{
  int v5; // r7
  __int64 v6; // r2
  int v7; // r9
  float *v8; // r8
  float v9; // s16
  int v10; // r7
  int v11; // lr
  int v12; // r7
  __int64 v13; // kr00_8
  __int64 *v14; // r2
  __int64 v15; // t1
  int v17; // r4
  int v18; // r3
  int v19; // r2
  double v20; // d6
  float v21; // s17
  float *v22; // r10
  unsigned int v23; // r12
  int v24; // lr
  __int64 v25; // r0
  __int64 v26; // kr08_8
  float v27; // s17
  int v28; // r0
  char v29; // r1
  int v30; // r3
  __int64 v31; // r0
  float v32; // s17
  int v34; // [sp+38h] [bp-1044h]
  int v35; // [sp+3Ch] [bp-1040h]
  __int64 v36; // [sp+40h] [bp-103Ch]
  _BYTE v37[4]; // [sp+4Ch] [bp-1030h] BYREF
  __int64 v38; // [sp+50h] [bp-102Ch] BYREF
  __int64 v39; // [sp+58h] [bp-1024h] BYREF
  double v40; // [sp+60h] [bp-101Ch] BYREF
  _BYTE v41[12]; // [sp+6Ch] [bp-1010h] BYREF
  char v42[4100]; // [sp+78h] [bp-1004h] BYREF

  (*(void (__fastcall **)(int, __int64 *))(a1 + 132))(a1, &v38);
  (*(void (__fastcall **)(int, __int64 *))(a1 + 140))(a1, &v39);
  (*(void (__fastcall **)(int, double *, _BYTE *))(a1 + 136))(a1, &v40, v37);
  v5 = *(_DWORD *)(a1 + 220);
  v6 = v39;
  *(_QWORD *)(a2 + 48) = v38;
  *(_QWORD *)(a2 + 56) = v6;
  if ( v5 <= 16 )
  {
    v7 = 16 * v5;
    if ( !byte_1795A8[v5] )
    {
      clock_gettime(1, (struct timespec *)&byte_1795A8[v7 + 16]);
      clock_gettime(1, (struct timespec *)&byte_1795A8[v7 + 272]);
      clock_gettime(1, (struct timespec *)&byte_1795A8[v7 + 528]);
      *((_QWORD *)&unk_1798B8 + v5) = 0;
      byte_1795A8[v5] = 1;
    }
    if ( !byte_179938 )
      byte_179938 = 1;
    clock_gettime(1, (struct timespec *)&byte_1795A8[v7 + 24]);
    v8 = &flt_179940[724 * v5];
    v9 = (float)(1000LL * (*(_DWORD *)&byte_1795A8[v7 + 24] - *(_DWORD *)&byte_1795A8[v7 + 16])
               + (*(_DWORD *)&byte_1795A8[v7 + 28] - *(_DWORD *)&byte_1795A8[v7 + 20]) / 1000000)
       / 1000.0;
    if ( v9 >= 5.0 )
    {
      v34 = *(_DWORD *)(a1 + 416);
      v36 = *(_QWORD *)(a1 + 416) - *((_QWORD *)&unk_1798B8 + v5);
      v35 = *(_DWORD *)(a1 + 420);
      get_miner_working_status((int)v41);
      if ( v41[6] || v41[0] )
      {
        v21 = 0.0;
      }
      else
      {
        v28 = *(_DWORD *)(a1 + 400);
        v29 = 32 - v28;
        v30 = 1 << (v28 - 32);
        LODWORD(v31) = 1 << v28;
        HIDWORD(v31) = v30 | (1u >> v29);
        v32 = COERCE_FLOAT(sub_12E398(v31));
        v21 = v32 * (float)(COERCE_FLOAT(sub_12E398(v36)) / v9);
      }
      V_LOCK();
      logfmt_raw(
        v42,
        0x1000u,
        0,
        "[HashRate] time_passed_sec: %.2f, nc %llu, new %llu, %.2f H/s",
        v9,
        v34,
        v35,
        v36,
        v21);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/miner_util/miner_monitor/update_miner_status/update_hashrate.c",
        194,
        "update_hashrate",
        15,
        125,
        20,
        v42);
      clock_gettime(1, (struct timespec *)&byte_1795A8[v7 + 16]);
      v22 = &flt_179940[724 * v5];
      *((_DWORD *)&unk_1798B8 + 2 * v5) = v34;
      v23 = *((_DWORD *)v22 + 723);
      *((_DWORD *)&unk_1798B8 + 2 * v5 + 1) = v35;
      v24 = *((_DWORD *)v22 + 720) + 1;
      *(float *)&v25 = v22[722];
      HIDWORD(v25) = v23;
      flt_179940[724 * v5 + *((_DWORD *)v22 + 720)] = v21;
      v26 = __PAIR64__(v23, v25) + 1;
      *((_DWORD *)v22 + 720) = v24 % 720;
      v27 = v21 + (float)(COERCE_FLOAT(sub_12E398(v25)) * *(float *)(a2 + 44));
      *(float *)(a2 + 44) = v27 / COERCE_FLOAT(sub_12E398(v26));
      *((_QWORD *)v22 + 361) = v26;
    }
    sub_5A608((int)v8);
    *(float *)(a2 + 32) = 5.0;
    sub_5A608((int)v8);
    *(_DWORD *)(a2 + 36) = 1114636288;
    sub_5A608((int)v8);
    v10 = *(_DWORD *)(a1 + 304);
    *(_DWORD *)(a2 + 40) = 1155596288;
    if ( v10 <= 0 )
    {
      v13 = 0;
    }
    else
    {
      v11 = *(_DWORD *)(a1 + 424) + 16;
      v12 = v11 + 48 * v10;
      v13 = 0;
      do
      {
        v14 = (__int64 *)v11;
        do
        {
          v15 = *v14++;
          v13 += v15;
        }
        while ( (__int64 *)(v11 + 32) != v14 );
        v11 += 48;
      }
      while ( v12 != v11 );
    }
    *(_QWORD *)(a2 + 80) = v13;
    clock_gettime(1, (struct timespec *)&byte_1795A8[v7 + 280]);
    if ( (float)((float)(1000LL * (*(_DWORD *)&byte_1795A8[v7 + 280] - *(_DWORD *)&byte_1795A8[v7 + 272])
                       + (*(_DWORD *)&byte_1795A8[v7 + 284] - *(_DWORD *)&byte_1795A8[v7 + 276]) / 1000000)
               / 1000.0) >= 900.0 )
    {
      sub_5A608((int)v8);
      v17 = *(_DWORD *)(a2 + 200);
      if ( v17 > 23 )
      {
        memcpy((void *)(a2 + 104), (const void *)(a2 + 108), 0x5Cu);
        *(_DWORD *)(a2 + 196) = 1147207680;
      }
      else
      {
        *(_DWORD *)(a2 + 4 * v17 + 104) = 1147207680;
      }
      v18 = *(_DWORD *)(a2 + 208);
      v19 = *(_DWORD *)(a2 + 212);
      v20 = v40 * 0.97;
      *(_DWORD *)(a2 + 200) = v17 + 1;
      *(_DWORD *)(a2 + 208) = v18 + 1;
      *(_DWORD *)(a2 + 212) = __CFADD__(v18, 1) + v19;
      if ( v20 >= 900.0 )
        *a3 |= 1u;
      clock_gettime(1, (struct timespec *)&byte_1795A8[v7 + 272]);
    }
  }
  return a3;
}
