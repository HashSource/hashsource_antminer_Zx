int __fastcall sub_4A598(int a1)
{
  int v1; // r4
  int v2; // r2
  int *v3; // r3
  unsigned int v4; // r12
  int v5; // t1
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v13; // [sp+0h] [bp-24h] BYREF
  int v14; // [sp+4h] [bp-20h]
  int v15; // [sp+8h] [bp-1Ch]
  int v16; // [sp+Ch] [bp-18h]
  __int64 v17; // [sp+10h] [bp-14h] BYREF
  int v18; // [sp+18h] [bp-Ch]
  int v19; // [sp+1Ch] [bp-8h] BYREF

  v1 = *(_DWORD *)(*(_DWORD *)(a1 + 36) + 20);
  *(_DWORD *)(v1 + 630) = a1;
  if ( pthread_mutex_init((pthread_mutex_t *)(v1 + 1146), 0) )
    sub_B8B8(7498);
  if ( pthread_mutex_init((pthread_mutex_t *)v1, 0) )
    sub_B8B8(7499);
  sub_3AF0C((pthread_rwlock_t *)(v1 + 24));
  HIWORD(v15) = 0;
  v2 = 81;
  v19 = 4;
  BYTE2(v16) = dword_76B78;
  v3 = &v13;
  LOBYTE(v15) = ~(~(((2 * (byte_79BF8 & 1)) | 1u) << 30) >> 30);
  v14 = 0;
  v18 = 0;
  v4 = 255;
  LOWORD(v17) = dword_76B7C;
  v13 = 1572945;
  BYTE1(v15) = 7;
  LOWORD(v16) = 774;
  HIBYTE(v16) = 80;
  BYTE2(v17) = 7;
  strcpy((char *)&v17 + 3, "%\n\n");
  HIBYTE(v17) = 0;
  while ( 1 )
  {
    LOWORD(v4) = *(_WORD *)&aResetAllHashBo[2 * (v2 ^ (v4 >> 8)) + 404] ^ ((_WORD)v4 << 8);
    if ( v3 == (int *)((char *)&v19 + 1) )
      break;
    v5 = *((unsigned __int8 *)v3 + 1);
    v3 = (int *)((char *)v3 + 1);
    v2 = v5;
  }
  HIWORD(v19) = v4;
  v6 = v14;
  v7 = v15;
  v8 = v16;
  *(_DWORD *)(v1 + 1170) = v13;
  *(_DWORD *)(v1 + 1174) = v6;
  *(_DWORD *)(v1 + 1178) = v7;
  *(_DWORD *)(v1 + 1182) = v8;
  v9 = HIDWORD(v17);
  v10 = v18;
  v11 = v19;
  *(_DWORD *)(v1 + 1186) = v17;
  *(_DWORD *)(v1 + 1190) = v9;
  *(_DWORD *)(v1 + 1194) = v10;
  *(_DWORD *)(v1 + 1198) = v11;
  sub_49CC8(v1);
  return 1;
}
