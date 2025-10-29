int __fastcall sub_3C7E0(char a1, char a2, int a3, int a4)
{
  char v4; // r8
  int v5; // r0
  int v6; // r1
  char v7; // r12
  unsigned int v8; // r12
  unsigned int v9; // r2
  _BYTE *v10; // r2
  __int16 v11; // t1
  int v12; // r7
  char *v13; // r3
  int v14; // r3
  unsigned __int8 v15; // r4
  int *v16; // r4
  int v18; // [sp+Ch] [bp-1024h] BYREF
  int v19; // [sp+10h] [bp-1020h]
  int v20; // [sp+14h] [bp-101Ch] BYREF
  int v21; // [sp+18h] [bp-1018h]
  int v22; // [sp+1Ch] [bp-1014h]
  char v23; // [sp+20h] [bp-1010h]
  _BYTE v24[15]; // [sp+21h] [bp-100Fh] BYREF
  char v25[4048]; // [sp+30h] [bp-1000h] BYREF
  _DWORD savedregs[8]; // [sp+1030h] [bp+0h] BYREF

  v4 = 2 * a1;
  v5 = 0;
  memset(&v24[3], 0, 12);
  v24[4] = a2;
  v6 = (int)savedregs;
  v20 = 0;
  v19 = 255;
  v24[0] = -86;
  v21 = 0;
  v23 = 85;
  if ( a4 > 0 )
    v6 = 0;
  v24[3] = v4;
  v24[2] = 50;
  v24[1] = a4 + 6;
  v22 = 0;
  if ( a4 > 0 )
  {
    do
    {
      v7 = *(_BYTE *)(a3 + v6);
      v6 = (unsigned __int8)(v6 + 1);
      v24[v5 + 5] = v7;
      v5 = v6;
    }
    while ( a4 > v6 );
  }
  if ( a4 >= -3 )
  {
    LOWORD(v8) = 0;
    v10 = v24;
    do
    {
      v11 = (unsigned __int8)*++v10;
      v8 = (unsigned __int16)(v8 + v11);
    }
    while ( v10 != &v24[a4 + 4] );
    v9 = v8 >> 8;
  }
  else
  {
    LOBYTE(v8) = 0;
    LOBYTE(v9) = 0;
  }
  v12 = (unsigned __int8)(a4 + 6) + 1;
  v13 = &v25[a4];
  *(v13 - 10) = v9;
  *(v13 - 9) = v8;
  pthread_mutex_lock(&stru_790A0);
  v14 = 0;
  v15 = 0;
  do
  {
    sub_3C7B0((unsigned __int8)v24[v14 - 1]);
    v14 = ++v15;
  }
  while ( v15 <= v12 );
  v16 = (int *)((char *)&v18 + 3);
  usleep(0x30D40u);
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  do
  {
    *((_BYTE *)v16 + 1) = sub_3C7C8();
    v16 = (int *)((char *)v16 + 1);
  }
  while ( v16 != &v20 );
  pthread_mutex_unlock(&stru_790A0);
  if ( BYTE1(v19) == 50 && BYTE2(v19) == 1 )
    return 0;
  if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 4 )
    return -1;
  snprintf(
    v25,
    0x1000u,
    "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x, read_back_data[3] = 0x%02x\n\n",
    "write_dc_dc",
    (unsigned __int8)v19,
    BYTE1(v19),
    BYTE2(v19),
    HIBYTE(v19));
  sub_38730(5, v25, 0);
  return -1;
}
