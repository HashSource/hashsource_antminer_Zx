const char *__fastcall sub_389F0(const char **a1, const char *a2, const char *a3, int a4)
{
  const char *result; // r0
  const char *v6; // r3
  const char *v7; // r2
  const char *v8; // r6
  char *v9; // r0
  const char *v10; // r1
  const char *v11; // r0
  _DWORD *v12; // r0
  _DWORD *v13; // r5
  const char *v14; // lr
  int v15; // r1
  const char *v16; // r0
  _DWORD *v17; // r3
  int v18; // r2
  int v19; // r1
  char *v20; // r3
  int v21; // r2
  char *v22; // r0
  const char *v23; // r1
  const char *v24; // r0
  char s[4096]; // [sp+20h] [bp-1000h] BYREF

  result = (const char *)*((unsigned __int8 *)a1 + 4);
  if ( result )
  {
    snprintf(
      s,
      0x1000u,
      "List %s store can't %s() - from %s %s() line %d in %s %s():%d",
      *a1,
      "k_alloc_items",
      a2,
      a3,
      a4,
      "klist.c",
      "k_alloc_items",
      19);
    sub_385C8(3, s, 1);
    sub_16BE0(1);
  }
  v6 = a1[10];
  if ( (int)v6 <= 0 )
  {
    v8 = a1[9];
  }
  else
  {
    v7 = a1[6];
    if ( (int)v6 <= (int)v7 )
      return result;
    v8 = a1[9];
    if ( (int)v6 < (int)&v8[(int)v7] )
      v8 = (const char *)(v6 - v7);
  }
  v9 = (char *)a1[13];
  v10 = a1[12] + 1;
  a1[12] = v10;
  v11 = (const char *)realloc(v9, 4 * (_DWORD)v10);
  a1[13] = v11;
  if ( !v11 )
  {
    snprintf(
      s,
      0x1000u,
      "List %s item_memory failed to realloc count=%d in %s %s():%d",
      *a1,
      a1[12],
      "klist.c",
      "k_alloc_items",
      33);
    sub_385C8(3, s, 1);
    sub_16BE0(1);
  }
  v12 = calloc((size_t)v8, 0x10u);
  v13 = v12;
  if ( !v12 )
  {
    snprintf(
      s,
      0x1000u,
      "List %s failed to calloc %d new items - total was %d, limit was %d in %s %s():%d",
      *a1,
      v8,
      a1[6],
      a1[10],
      "klist.c",
      "k_alloc_items",
      38);
    sub_385C8(3, s, 1);
    sub_16BE0(1);
  }
  v14 = v8 - 1;
  *(_DWORD *)&a1[13][4 * (_DWORD)(a1[12] - 1)] = v12;
  v15 = (int)*a1;
  v16 = a1[6];
  a1[7] = v8;
  a1[8] = v8;
  a1[6] = &v8[(_DWORD)v16];
  *v13 = v15;
  v13[1] = 0;
  v13[2] = v13 + 4;
  if ( (int)(v8 - 1) > 1 )
  {
    v17 = v13;
    v18 = 1;
    do
    {
      v19 = (int)*a1;
      ++v18;
      v17[5] = v17;
      v17[6] = v17 + 8;
      v17[4] = v19;
      v17 += 4;
    }
    while ( (const char *)v18 != v14 );
  }
  v20 = (char *)&v13[4 * (_DWORD)v14];
  *(_DWORD *)v20 = *a1;
  *((_DWORD *)v20 + 1) = &v13[4 * (_DWORD)(v8 - 2)];
  *((_DWORD *)v20 + 2) = 0;
  v21 = *((unsigned __int8 *)a1 + 44);
  a1[3] = (const char *)v13;
  if ( v21 )
    a1[4] = v20;
  do
  {
    v22 = (char *)a1[15];
    v23 = a1[14] + 1;
    a1[14] = v23;
    v24 = (const char *)realloc(v22, 4 * (_DWORD)v23);
    a1[15] = v24;
    if ( !v24 )
    {
      snprintf(
        s,
        0x1000u,
        "List %s data_memory failed to realloc count=%d in %s %s():%d",
        *a1,
        a1[14],
        "klist.c",
        "k_alloc_items",
        69);
      sub_385C8(3, s, 1);
      sub_16BE0(1);
    }
    result = (const char *)calloc(1u, (size_t)a1[5]);
    v13[3] = result;
    if ( !result )
    {
      snprintf(s, 0x1000u, "List %s failed to calloc item data in %s %s():%d", *a1, "klist.c", "k_alloc_items", 73);
      sub_385C8(3, s, 1);
      sub_16BE0(1);
    }
    *(_DWORD *)&a1[15][4 * (_DWORD)(a1[14] - 1)] = result;
    v13 = (_DWORD *)v13[2];
  }
  while ( v13 );
  return result;
}
