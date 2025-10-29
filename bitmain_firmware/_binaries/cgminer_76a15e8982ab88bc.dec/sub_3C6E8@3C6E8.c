int __fastcall sub_3C6E8(char a1, __int16 a2, int a3, int a4)
{
  unsigned __int8 v6; // r4
  int i; // r0
  int v8; // r5
  int v9; // r4
  int v11; // r2
  int v12; // r3
  _BYTE v13[4]; // [sp+14h] [bp-1020h]
  unsigned __int8 v14; // [sp+18h] [bp-101Ch]
  char v15; // [sp+19h] [bp-101Bh]
  char v16; // [sp+1Ah] [bp-101Ah]
  char v17; // [sp+1Bh] [bp-1019h]
  char v18; // [sp+1Ch] [bp-1018h]
  int v19; // [sp+20h] [bp-1014h]
  int v20; // [sp+24h] [bp-1010h]
  int v21; // [sp+28h] [bp-100Ch]
  int v22; // [sp+2Ch] [bp-1008h]
  char s[4048]; // [sp+30h] [bp-1004h] BYREF

  v15 = a2;
  v13[1] = -86;
  v13[3] = 50;
  v14 = (2 * a1) | 1;
  v16 = a4;
  v20 = 0;
  v21 = 0;
  v6 = 0;
  v13[2] = 7;
  v19 = 255;
  v17 = (unsigned __int16)((unsigned __int8)a4 + a2 + v14 + 57) >> 8;
  v18 = a4 + a2 + v14 + 57;
  v22 = 0;
  v13[0] = 85;
  pthread_mutex_lock(&stru_75EE0);
  for ( i = 85; ; i = (unsigned __int8)v13[v6] )
  {
    sub_3C460(i);
    if ( ++v6 == 9 )
      break;
  }
  v8 = 0;
  sub_2A884();
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  if ( a4 + 4 < 0 )
  {
    pthread_mutex_unlock(&stru_75EE0);
    sleep(1u);
    goto LABEL_8;
  }
  LOBYTE(v9) = 0;
  do
  {
    v9 = (unsigned __int8)(v9 + 1);
    *((_BYTE *)&v19 + v8) = sub_3C478();
    v8 = v9;
  }
  while ( v9 <= a4 + 4 );
  v8 = BYTE1(v19);
  pthread_mutex_unlock(&stru_75EE0);
  sleep(1u);
  if ( v8 != 50 || BYTE2(v19) != 1 )
  {
LABEL_8:
    if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 4 )
      return -1;
    snprintf(
      s,
      0x1000u,
      "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x, read_back_data[3] = 0x%02x\n",
      "read_dc_dc",
      (unsigned __int8)v19,
      v8,
      BYTE2(v19),
      HIBYTE(v19));
    sub_385C8(5, s, 0);
    return -1;
  }
  if ( a4 > 0 )
  {
    v11 = 0;
    v12 = 0;
    do
    {
      *(_BYTE *)(a3 + v12) = *((_BYTE *)&v19 + v11 + 3);
      v12 = (unsigned __int8)(v12 + 1);
      v11 = v12;
    }
    while ( a4 > v12 );
  }
  return 0;
}
