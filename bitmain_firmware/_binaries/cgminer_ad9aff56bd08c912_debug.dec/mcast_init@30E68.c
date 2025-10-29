void mcast_init()
{
  thr_info *v0; // r0
  void *(*v1)(void *); // r2
  int *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int *v10; // r6
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1
  int v16; // r2
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  v0 = (thr_info *)calloc(1u, 0x40u);
  if ( !v0 )
  {
    LOWORD(v10) = 23348;
    HIWORD(v10) = (unsigned int)"0s" >> 16;
    v11 = *v10;
    v12 = v10[1];
    v13 = v10[2];
    v14 = v10[3];
    v10 += 4;
    *(_DWORD *)tmp42 = v11;
    *(_DWORD *)&tmp42[4] = v12;
    *(_DWORD *)&tmp42[8] = v13;
    *(_DWORD *)&tmp42[12] = v14;
    v15 = v10[1];
    v16 = v10[2];
    *(_DWORD *)&tmp42[16] = *v10;
    *(_DWORD *)&tmp42[20] = v15;
    *(_WORD *)&tmp42[24] = v16;
    tmp42[26] = BYTE2(v16);
    applog(3, tmp42, 1);
    quit(1);
  }
  LOWORD(v1) = -12123;
  HIWORD(v1) = (unsigned int)&loc_2CF94 >> 16;
  if ( thr_info_create(v0, 0, v1, v0) )
  {
    LOWORD(v2) = 23376;
    HIWORD(v2) = (unsigned int)" Nostart" >> 16;
    v3 = *v2;
    v4 = v2[1];
    v5 = v2[2];
    v6 = v2[3];
    v2 += 4;
    *(_DWORD *)tmp42 = v3;
    *(_DWORD *)&tmp42[4] = v4;
    *(_DWORD *)&tmp42[8] = v5;
    *(_DWORD *)&tmp42[12] = v6;
    v7 = v2[1];
    v8 = v2[2];
    v9 = v2[3];
    *(_DWORD *)&tmp42[16] = *v2;
    *(_DWORD *)&tmp42[20] = v7;
    *(_DWORD *)&tmp42[24] = v8;
    *(_WORD *)&tmp42[28] = v9;
    tmp42[30] = BYTE2(v9);
    applog(3, tmp42, 1);
    quit(1);
  }
}
