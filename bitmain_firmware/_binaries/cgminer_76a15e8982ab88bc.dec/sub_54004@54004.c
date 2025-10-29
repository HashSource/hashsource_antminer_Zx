_BYTE *__fastcall sub_54004(int a1, _BYTE *a2)
{
  __int64 v2; // d16
  __int64 v5; // r4
  char v6; // r3
  int v7; // r7
  int v8; // r2
  int v9; // r3
  _BYTE *result; // r0
  _BYTE *v11; // r2
  int v12; // r3
  int v13; // r1

  v2 = *(_QWORD *)(a1 + 32);
  v5 = vshld_n_s64(v2, 3u);
  v6 = (v2 & 0x3F) + 1;
  *(_BYTE *)(a1 + (v2 & 0x3F) + 40) = 0x80;
  if ( (v2 & 0x3F) != 0x37 )
  {
    do
    {
      while ( 1 )
      {
        v7 = v6 & 0x3F;
        v6 = v7 + 1;
        if ( v7 )
          break;
        sub_53CA0((unsigned __int8 *)a1);
        *(_BYTE *)(a1 + 40) = v7;
        v6 = 1;
      }
      *(_BYTE *)(a1 + v7 + 40) = 0;
    }
    while ( v7 != 55 );
  }
  v8 = a1;
  v9 = 56;
  do
  {
    ++v9;
    *(_BYTE *)(v8 + 96) = HIBYTE(v5);
    v5 <<= 8;
    ++v8;
  }
  while ( v9 != 64 );
  sub_53CA0((unsigned __int8 *)a1);
  result = a2 + 32;
  v11 = a2;
  v12 = 0;
  do
  {
    a2[v12] = HIBYTE(*(_DWORD *)(a1 + v12));
    v11[1] = BYTE2(*(_DWORD *)(a1 + v12));
    v11[2] = BYTE1(*(_DWORD *)(a1 + v12));
    v13 = *(_DWORD *)(a1 + v12);
    v12 += 4;
    v11[3] = v13;
    v11 += 4;
  }
  while ( result != v11 );
  *(_QWORD *)(a1 + 32) = 0;
  *(_DWORD *)a1 = 1779033703;
  *(_DWORD *)(a1 + 4) = -1150833019;
  *(_DWORD *)(a1 + 8) = 1013904242;
  *(_DWORD *)(a1 + 12) = -1521486534;
  *(_DWORD *)(a1 + 16) = 1359893119;
  *(_DWORD *)(a1 + 20) = -1694144372;
  *(_DWORD *)(a1 + 24) = 528734635;
  *(_DWORD *)(a1 + 28) = 1541459225;
  return result;
}
