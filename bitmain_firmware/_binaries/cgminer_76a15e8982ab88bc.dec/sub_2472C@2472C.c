int __fastcall sub_2472C(int a1, int a2)
{
  _DWORD *v4; // r5
  time_t v5; // r8
  int v6; // r4
  time_t v7; // r0
  int v8; // r3
  int v9; // r8
  double v10; // d16
  double *v11; // r3
  int result; // r0
  int v13; // r2
  int v14; // r3
  int v15; // r3
  char v16[4100]; // [sp+0h] [bp-1004h] BYREF

  v4 = *(_DWORD **)(a1 + 36);
  sub_FB90(a1);
  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    strcpy(v16, "Popping work from get queue to get work");
    sub_385C8(7, v16, 0);
  }
  v5 = time(0);
  do
  {
    while ( 1 )
    {
      v6 = sub_18D24(1);
      if ( !sub_22A8C(v6, 0) )
        break;
      sub_158EC(v6);
      sub_1852C();
    }
  }
  while ( !v6 );
  v7 = time(0);
  v8 = (unsigned __int8)byte_75C49;
  v9 = v7 - v5;
  if ( v9 > 0 )
  {
    if ( byte_75C49 )
    {
      if ( byte_77B70 || byte_75C48 || dword_73504 > 6 )
      {
        snprintf(v16, 0x1000u, "Get work blocked for %d seconds", v9);
        sub_385C8(7, v16, 0);
        v8 = (unsigned __int8)byte_75C49;
      }
      else
      {
        v8 = 1;
      }
    }
    v4[58] += v9;
  }
  if ( v8 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(v16, 0x1000u, "Got work from get queue to get work for thread %d", a2);
    sub_385C8(7, v16, 0);
  }
  *(_DWORD *)(v6 + 1744) = a2;
  if ( byte_74149 )
  {
    v14 = v4[95] + v4[96];
    v4[95] = v14;
    if ( v14 > 0 )
    {
      if ( v14 > 15 )
      {
        v15 = v4[94] + 1;
        v4[96] = -1;
        if ( v15 > 15 )
          v15 = 0;
        v4[94] = v15;
        memcpy((void *)v6, &byte_74158[160 * v15], 0xA0u);
        goto LABEL_17;
      }
    }
    else
    {
      v4[96] = 1;
    }
    memcpy((void *)v6, &byte_74B58[160 * v14], 0xA0u);
  }
LABEL_17:
  sub_FB5C(a1);
  *(_BYTE *)(v6 + 1760) = 1;
  v10 = *(double *)(v4[1] + 104);
  v11 = (double *)(v6 + 1712);
  result = v6;
  if ( v10 > *(double *)(v6 + 1864) )
    v10 = *(double *)(v6 + 1864);
  *v11 = v10;
  v13 = v4[1];
  if ( v10 < *(double *)(v13 + 120) )
    v10 = *(double *)(v13 + 120);
  *v11 = v10;
  return result;
}
