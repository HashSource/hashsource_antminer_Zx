int __fastcall sub_A2C20(int a1, int *a2)
{
  _DWORD *v3; // r8
  int v4; // r7
  int v5; // r3
  int v6; // r0
  int v7; // r2
  _DWORD *v8; // r11
  int v9; // r5
  int v10; // r3
  int v11; // r0
  int v12; // r2
  float *v13; // r0
  int *v14; // r2
  float *v15; // r12
  int v16; // r1
  float v17; // s12
  float v18; // s14
  float v19; // s15
  int v21; // [sp+40h] [bp-10DCh]
  int *v22; // [sp+40h] [bp-10DCh]
  int v24; // [sp+48h] [bp-10D4h]
  int *v25; // [sp+48h] [bp-10D4h]
  _DWORD *v26; // [sp+4Ch] [bp-10D0h]
  int v27; // [sp+50h] [bp-10CCh] BYREF
  int v28; // [sp+54h] [bp-10C8h] BYREF
  _DWORD v29[7]; // [sp+58h] [bp-10C4h] BYREF
  int v30; // [sp+74h] [bp-10A8h]
  _DWORD v31[7]; // [sp+78h] [bp-10A4h] BYREF
  int v32; // [sp+94h] [bp-1088h]
  _DWORD v33[7]; // [sp+98h] [bp-1084h] BYREF
  int v34; // [sp+B4h] [bp-1068h]
  _DWORD v35[7]; // [sp+B8h] [bp-1064h] BYREF
  int v36; // [sp+D4h] [bp-1048h]
  _DWORD v37[7]; // [sp+D8h] [bp-1044h] BYREF
  int v38; // [sp+F4h] [bp-1028h]
  _DWORD v39[7]; // [sp+F8h] [bp-1024h] BYREF
  int v40; // [sp+114h] [bp-1008h]
  char v41[4100]; // [sp+118h] [bp-1004h] BYREF

  v24 = *(_DWORD *)(a1 + 364);
  if ( v24 > 0 )
  {
    v3 = *(_DWORD **)(a1 + 356);
    v21 = 0;
    v26 = v3;
    do
    {
      v4 = 5;
      do
      {
        (*(void (__fastcall **)(int, int *, int *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(a1 + 152))(
          a1,
          &v28,
          &v27,
          *v3,
          v3[1],
          v3[2],
          v3[3],
          v3[4],
          v3[5]);
        if ( v27 )
        {
          v5 = v28;
          if ( v28 >= -63 )
            goto LABEL_9;
          V_LOCK();
          V_INT((int)v31, "chain", *(int *)(a1 + 224));
          logfmt_raw(
            v41,
            0x1000u,
            0,
            v32,
            v31[0],
            v31[1],
            v31[2],
            v31[3],
            v31[4],
            v31[5],
            v31[6],
            v32,
            "sensor[%d] invalid temp, retry",
            *v3);
          V_UNLOCK();
          v6 = g_zc;
          v7 = 481;
        }
        else
        {
          V_LOCK();
          V_INT((int)v29, "chain", *(int *)(a1 + 224));
          logfmt_raw(
            v41,
            0x1000u,
            0,
            v30,
            v29[0],
            v29[1],
            v29[2],
            v29[3],
            v29[4],
            v29[5],
            v29[6],
            v30,
            "sensor[%d] read lost, retry",
            *v3);
          V_UNLOCK();
          v6 = g_zc;
          v7 = 479;
        }
        zlog(
          v6,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/backend/backend_zec_1746/backend_zec_1746.c",
          175,
          "read_temperature_zec_1746",
          25,
          v7,
          20,
          v41);
        usleep((__useconds_t)sub_30D40);
        --v4;
      }
      while ( v4 );
      v28 = -64;
      V_LOCK();
      V_INT((int)v33, "chain", *(int *)(a1 + 224));
      logfmt_raw(
        v41,
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
        "read sensor[%d] local temp failed after retry %d times",
        *v3,
        5);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/backend_zec_1746/backend_zec_1746.c",
        175,
        "read_temperature_zec_1746",
        25,
        489,
        100,
        v41);
      v5 = v28;
LABEL_9:
      v3 += 6;
      a2[2 * v21++] = v5;
    }
    while ( v24 != v21 );
    v8 = v26;
    v25 = &a2[2 * v24];
    v22 = a2;
    do
    {
      v9 = 5;
      do
      {
        (*(void (__fastcall **)(int, int *, int *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(a1 + 156))(
          a1,
          &v28,
          &v27,
          *v8,
          v8[1],
          v8[2],
          v8[3],
          v8[4],
          v8[5]);
        if ( v27 )
        {
          v10 = v28;
          if ( v28 >= -63 )
            goto LABEL_17;
          V_LOCK();
          V_INT((int)v37, "chain", *(int *)(a1 + 224));
          logfmt_raw(
            v41,
            0x1000u,
            0,
            v38,
            v37[0],
            v37[1],
            v37[2],
            v37[3],
            v37[4],
            v37[5],
            v37[6],
            v38,
            "sensor[%d] invalid temp, retry",
            *v8);
          V_UNLOCK();
          v11 = g_zc;
          v12 = 503;
        }
        else
        {
          V_LOCK();
          V_INT((int)v35, "chain", *(int *)(a1 + 224));
          logfmt_raw(
            v41,
            0x1000u,
            0,
            v36,
            v35[0],
            v35[1],
            v35[2],
            v35[3],
            v35[4],
            v35[5],
            v35[6],
            v36,
            "sensor[%d] read lost, retry",
            *v8);
          V_UNLOCK();
          v11 = g_zc;
          v12 = 501;
        }
        zlog(
          v11,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/backend/backend_zec_1746/backend_zec_1746.c",
          175,
          "read_temperature_zec_1746",
          25,
          v12,
          20,
          v41);
        usleep((__useconds_t)sub_30D40);
        --v9;
      }
      while ( v9 );
      v28 = -64;
      V_LOCK();
      V_INT((int)v39, "chain", *(int *)(a1 + 224));
      logfmt_raw(
        v41,
        0x1000u,
        0,
        v40,
        v39[0],
        v39[1],
        v39[2],
        v39[3],
        v39[4],
        v39[5],
        v39[6],
        v40,
        "read sensor[%d] remote temp failed after retry %d times",
        *v8,
        5);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/backend_zec_1746/backend_zec_1746.c",
        175,
        "read_temperature_zec_1746",
        25,
        511,
        100,
        v41);
      v10 = v28;
LABEL_17:
      v8 += 6;
      v22[1] = v10;
      v22 += 2;
    }
    while ( v25 != v22 );
  }
  v13 = (float *)&unk_15156C;
  v14 = a2;
  v15 = (float *)&unk_151584;
  do
  {
    if ( *v14 != -64 )
    {
      v16 = v14[1];
      if ( v16 != -64 )
      {
        v17 = 0.0;
        v18 = (float)(*v15 + (float)((float)*v14 * *v13)) + (float)*v14;
        v19 = (float)v16 - v18;
        if ( (float)(v19 * v19) < 100.0 )
          v17 = v19 * -0.01 * v19 + 1.0;
        v14[1] = (int)((float)(v18 + (float)(v17 * v19)) + 0.5);
      }
    }
    v14 += 2;
    ++v13;
    ++v15;
  }
  while ( v14 != a2 + 12 );
  return 0;
}
