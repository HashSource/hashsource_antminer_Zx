int __fastcall sub_244C4(int a1, int a2)
{
  _DWORD *v4; // r5
  time_t v5; // r8
  int v6; // r4
  time_t v7; // r0
  int v8; // r3
  int v9; // r8
  double v10; // d17
  double v11; // d16
  int result; // r0
  int v13; // r3
  int v14; // r3
  int v15; // r3
  char v16[2052]; // [sp+0h] [bp-804h] BYREF

  v4 = *(_DWORD **)(a1 + 36);
  sub_F808(a1);
  if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
  {
    strcpy(v16, "Popping work from get queue to get work");
    sub_38438(7, v16, 0);
  }
  v5 = time(0);
  do
  {
    while ( 1 )
    {
      v6 = sub_17A14(1);
      if ( !sub_2282C(v6, 0) )
        break;
      sub_154EC(v6);
      sub_17ED8();
    }
  }
  while ( !v6 );
  v7 = time(0);
  v8 = (unsigned __int8)byte_630C1;
  v9 = v7 - v5;
  if ( v9 > 0 )
  {
    if ( byte_630C1 )
    {
      if ( byte_632F0 || byte_630C0 || dword_60964 > 6 )
      {
        snprintf(v16, 0x800u, "Get work blocked for %d seconds", v9);
        sub_38438(7, v16, 0);
        v8 = (unsigned __int8)byte_630C1;
      }
      else
      {
        v8 = 1;
      }
    }
    v4[58] += v9;
  }
  if ( v8 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
  {
    snprintf(v16, 0x800u, "Got work from get queue to get work for thread %d", a2);
    sub_38438(7, v16, 0);
  }
  *(_DWORD *)(v6 + 256) = a2;
  if ( byte_615C9 )
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
        memcpy((void *)v6, &byte_615D8[160 * v15], 0xA0u);
        goto LABEL_17;
      }
    }
    else
    {
      v4[96] = 1;
    }
    memcpy((void *)v6, &byte_61FD8[160 * v14], 0xA0u);
  }
LABEL_17:
  sub_F7D4(a1);
  v10 = *(double *)(v6 + 376);
  *(_BYTE *)(v6 + 272) = 1;
  v11 = *(double *)(v4[1] + 104);
  result = v6;
  if ( v11 > v10 )
    v11 = v10;
  *(double *)(v6 + 224) = v11;
  v13 = v4[1];
  if ( v11 < *(double *)(v13 + 120) )
    v11 = *(double *)(v13 + 120);
  *(double *)(v6 + 224) = v11;
  return result;
}
