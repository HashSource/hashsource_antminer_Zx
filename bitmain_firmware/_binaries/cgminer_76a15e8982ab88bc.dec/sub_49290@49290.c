void __fastcall sub_49290(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  int v13; // r4
  int v14; // r2
  int *v15; // r3
  unsigned int v16; // r12
  int v17; // t1
  int v18; // r1
  int v19; // r2
  int v20; // r3
  int v21; // [sp+0h] [bp-24h] BYREF
  int v22; // [sp+4h] [bp-20h]
  int v23; // [sp+8h] [bp-1Ch]
  int v24; // [sp+Ch] [bp-18h]
  __int64 v25; // [sp+10h] [bp-14h] BYREF
  int v26; // [sp+18h] [bp-Ch]
  int v27; // [sp+1Ch] [bp-8h] BYREF

  v13 = *(_DWORD *)(*(_DWORD *)(a1 + 36) + 20);
  *(_DWORD *)(v13 + 630) = a1;
  if ( pthread_mutex_init((pthread_mutex_t *)(v13 + 1146), 0) )
    sub_B800(7041);
  if ( pthread_mutex_init((pthread_mutex_t *)v13, 0) )
    sub_B800(7042);
  sub_3AD18((pthread_rwlock_t *)(v13 + 24));
  HIWORD(v23) = 0;
  v14 = 81;
  v27 = 4;
  BYTE2(v24) = dword_739B0;
  v15 = &v21;
  LOBYTE(v23) = ~(~(((2 * (byte_76A28 & 1)) | 1u) << 30) >> 30);
  v22 = 0;
  v26 = 0;
  v16 = 255;
  LOWORD(v25) = dword_739B8;
  v21 = 1572945;
  BYTE1(v23) = 7;
  LOWORD(v24) = 774;
  HIBYTE(v24) = 80;
  BYTE2(v25) = 7;
  strcpy((char *)&v25 + 3, "%\n\n");
  HIBYTE(v25) = 0;
  while ( 1 )
  {
    LOWORD(v16) = *(_WORD *)&aResetAllHashBo[2 * (v14 ^ (v16 >> 8)) + 424] ^ ((_WORD)v16 << 8);
    if ( v15 == (int *)((char *)&v27 + 1) )
      break;
    v17 = *((unsigned __int8 *)v15 + 1);
    v15 = (int *)((char *)v15 + 1);
    v14 = v17;
  }
  HIWORD(v27) = v16;
  v18 = v22;
  v19 = v23;
  v20 = v24;
  *(_DWORD *)(v13 + 1170) = v21;
  *(_DWORD *)(v13 + 1174) = v18;
  *(_DWORD *)(v13 + 1178) = v19;
  *(_DWORD *)(v13 + 1182) = v20;
  sub_493E0(v25, SHIDWORD(v25), v26, v27, a5, a6, a7, a8, a9, a10, a11, a12, a13);
}
