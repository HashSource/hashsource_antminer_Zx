int __fastcall packet_2_nonce_kas(int a1, int a2, int a3, _BYTE *a4, _DWORD *a5, signed int *a6, _DWORD *a7)
{
  int v11; // r0
  char v12; // r3
  int v14; // r6
  int v15; // r9
  int v16; // r2
  int v17; // r3
  int *v18; // r0
  int v19; // r1
  int v20; // r0
  int *v21; // r3
  int v22; // r1
  int v23; // r1
  int v24; // r3
  signed int v25; // r0
  int v26; // r3
  int v27; // r1
  int v28; // r2
  int v29; // r0
  signed int v30; // r1
  int v31; // r2
  _DWORD v32[7]; // [sp+30h] [bp-1024h] BYREF
  int v33; // [sp+4Ch] [bp-1008h]
  char v34[4080]; // [sp+50h] [bp-1004h] BYREF

  v11 = BM_CRC5((_BYTE *)(a2 + 2), 91);
  v12 = *(_BYTE *)(a2 + 13);
  if ( (v12 & 0x80) == 0 )
    return 10;
  v14 = v12 & 0x1F;
  v15 = v11;
  if ( v11 == v14 || !*(_BYTE *)(a1 + 230) )
  {
    v16 = *(unsigned __int8 *)(a2 + 12);
    v17 = *(_DWORD *)(a1 + 784);
    if ( (v16 & 0x80) != 0 )
    {
      V_LOCK();
      logfmt_raw(v34, 0x1000u, 0, "chip respond wrong work id ,err");
      V_UNLOCK();
      v31 = 286;
    }
    else
    {
      v18 = (int *)(v17 + 8 * v16);
      v19 = *v18;
      v20 = v18[1];
      *(_DWORD *)a3 = v19;
      *(_DWORD *)(a3 + 4) = v20;
      *a7 = v19;
      if ( v19 != -1 )
      {
        v21 = (int *)(v17 + 8 * (v16 + 128));
        v22 = *(_DWORD *)(a2 + 7);
        *(_DWORD *)(a3 + 26) = *(_DWORD *)(a2 + 3);
        *(_DWORD *)(a3 + 30) = v22;
        v23 = *v21;
        v24 = v21[1];
        *(_DWORD *)(a3 + 18) = v23;
        *(_DWORD *)(a3 + 22) = v24;
        LOBYTE(v24) = *(_BYTE *)(a2 + 11);
        *(_BYTE *)(a3 + 16) = v16;
        *(_BYTE *)(a3 + 17) = v24;
        v25 = (unsigned int)*(unsigned __int8 *)(a2 + 6) / *(_DWORD *)(a1 + 396);
        if ( v25 >= *(_DWORD *)(a1 + 304) )
        {
          v29 = rand();
          sub_12DE74(v29, *(_DWORD *)(a1 + 304));
          v25 = v30;
        }
        *a6 = v25;
        *(_DWORD *)(a3 + 8) = v25;
        *(_DWORD *)(a3 + 12) = *(_BYTE *)(a2 + 10) & 0x7F;
        v26 = *(_DWORD *)(a3 + 30);
        *a5 = *(_DWORD *)(a3 + 26);
        a5[1] = v26;
        *a4 = 1;
        return 0;
      }
      V_LOCK();
      logfmt_raw(v34, 0x1000u, 0, "chip respond wrong work id ,err");
      V_UNLOCK();
      v31 = 293;
    }
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/backend_kas_2380/backend_kas_2380.c",
      175,
      "packet_2_nonce_kas",
      18,
      v31,
      20,
      v34);
    return 12;
  }
  v27 = *(_DWORD *)(a1 + 224);
  v28 = dword_18511C[v27];
  dword_18511C[v27] = v28 + 1;
  if ( v28 <= 9 )
  {
    V_LOCK();
    V_INT((int)v32, "chain", *(int *)(a1 + 224));
    logfmt_raw(
      v34,
      0x1000u,
      0,
      v33,
      v32[0],
      v32[1],
      v32[2],
      v32[3],
      v32[4],
      v32[5],
      v32[6],
      v33,
      "chip id %2d, get nonce crc error calc value %04x expected value %04x",
      0,
      v15,
      v14);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/backend_kas_2380/backend_kas_2380.c",
      175,
      "packet_2_nonce_kas",
      18,
      277,
      40,
      v34);
  }
  return 11;
}
