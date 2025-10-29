int __fastcall work_2_packet_kas(int a1, int a2, _BYTE *a3, _DWORD *a4)
{
  int v6; // r4
  int v7; // r3
  int v8; // lr
  int v9; // r0
  int *v10; // r12
  _DWORD *v11; // r2
  double v12; // d7
  _BYTE *v13; // r1
  int *v14; // r3
  int v15; // t1
  int v16; // r10
  int v17; // r9
  int v18; // r8
  int v19; // r8
  int v20; // r10
  int v21; // r9
  int v22; // r8
  int v23; // lr
  _DWORD *v24; // r0
  int v25; // r8
  int v26; // lr
  int v27; // r0
  int v28; // r2
  int *v29; // r3
  int v30; // r4
  int v31; // lr
  int v32; // r12
  int v33; // r1
  int v34; // r2
  char v35; // r2
  __int16 v36; // r0
  int result; // r0
  void *v38; // r0
  int v39; // [sp+14h] [bp-1010h]
  int v40; // [sp+14h] [bp-1010h]
  int *v42; // [sp+1Ch] [bp-1008h]
  char v43[4100]; // [sp+20h] [bp-1004h] BYREF

  if ( dword_185128 )
  {
    v6 = *(_DWORD *)(a1 + 784);
    if ( v6 )
      goto LABEL_3;
LABEL_14:
    V_LOCK();
    logfmt_raw(v43, 0x1000u, v6, "id_map is null", "work_2_packet_kas");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/backend_kas_2380/backend_kas_2380.c",
      175,
      "work_2_packet_kas",
      17,
      203,
      0x14u,
      v43);
    return 3;
  }
  v40 = a2;
  v38 = malloc(0x450u);
  v6 = *(_DWORD *)(a1 + 784);
  dword_185128 = (int)v38;
  a2 = v40;
  if ( !v6 )
    goto LABEL_14;
LABEL_3:
  *a3 = 85;
  a3[1] = -86;
  v7 = a2;
  a3[2] = 48;
  v8 = a2;
  v9 = *(unsigned __int8 *)(v6 + 12416);
  v39 = v6 + 12288;
  v10 = (int *)(a2 + 16);
  v42 = (int *)(a2 + 16);
  *(_DWORD *)(v6 + 8 * v9) = *(_DWORD *)a2;
  *(_DWORD *)(v6 + 8 * v9 + 4) = *(_DWORD *)(a2 + 4);
  v11 = (_DWORD *)(v6 + 32 * (v9 + 260));
  v12 = *(double *)(a2 + 192);
  v13 = a3 + 4;
  *(_BYTE *)(v6 + v9 + 0x2000) = (unsigned int)v12;
  v15 = *(_DWORD *)(v7 + 64);
  v14 = (int *)(v7 + 64);
  v16 = v14[1];
  v17 = v14[2];
  v18 = v14[3];
  *v11 = v15;
  v11[1] = v16;
  v11[2] = v17;
  v11[3] = v18;
  v19 = v14[7];
  v20 = v14[5];
  v21 = v14[6];
  v11[4] = v14[4];
  v11[5] = v20;
  v11[6] = v21;
  v11[7] = v19;
  v22 = *(_DWORD *)(v8 + 8);
  v23 = *(_DWORD *)(v8 + 12);
  v24 = (_DWORD *)(v6 + 8 * (*(unsigned __int8 *)(v6 + 12416) + 128));
  *v24 = v22;
  v24[1] = v23;
  do
  {
    v25 = *v10;
    v10 += 4;
    v26 = *(v10 - 3);
    v13 += 16;
    v27 = *(v10 - 2);
    v28 = *(v10 - 1);
    *((_DWORD *)v13 - 4) = v25;
    *((_DWORD *)v13 - 3) = v26;
    *((_DWORD *)v13 - 2) = v27;
    *((_DWORD *)v13 - 1) = v28;
  }
  while ( v10 != v14 );
  v29 = v42;
  v30 = v6 + 48 * *(unsigned __int8 *)(v6 + 12416) + 2048;
  do
  {
    v31 = *v29;
    v29 += 4;
    v32 = *(v29 - 3);
    v30 += 16;
    v33 = *(v29 - 2);
    v34 = *(v29 - 1);
    *(_DWORD *)(v30 - 16) = v31;
    *(_DWORD *)(v30 - 12) = v32;
    *(_DWORD *)(v30 - 8) = v33;
    *(_DWORD *)(v30 - 4) = v34;
  }
  while ( v29 != v42 + 12 );
  v35 = *(_BYTE *)(v39 + 128);
  a3[3] = v35;
  *(_BYTE *)(v39 + 128) = (v35 + 1) & 0x7F;
  if ( ((v35 + 1) & 0x7F) == 0 )
    sub_83D8C(a1, 60, (void *)dword_185128);
  v36 = BM_CRC16(a3 + 2, 50);
  a3[53] = v36;
  a3[52] = HIBYTE(v36);
  result = *(unsigned __int8 *)(a1 + 229);
  *a4 = 54;
  if ( result )
  {
    result = *(unsigned __int8 *)(a1 + 230);
    if ( *(_BYTE *)(a1 + 230) )
    {
      sub_83F4C((int *)a1, 36);
      set_misc_control_kas(a1);
      result = 0;
      *(_BYTE *)(a1 + 229) = 0;
    }
  }
  return result;
}
