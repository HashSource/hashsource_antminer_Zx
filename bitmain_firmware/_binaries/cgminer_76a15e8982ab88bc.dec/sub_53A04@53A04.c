int __fastcall sub_53A04(int a1, void *a2, size_t a3)
{
  bool v6; // zf
  unsigned int v7; // r2
  unsigned __int8 *v8; // r9
  __int64 v9; // r6
  int v10; // r3
  unsigned __int64 v11; // r0
  int v12; // r0
  int v13; // r11
  char *v14; // r12
  __int64 v15; // t1
  __int64 v17; // r4
  unsigned __int64 v18; // r6
  size_t v19; // r2
  _BYTE v20[64]; // [sp+0h] [bp-44h] BYREF
  char v21; // [sp+40h] [bp-4h] BYREF

  memset(v20, 0, sizeof(v20));
  v6 = a2 == 0;
  if ( a2 )
    v6 = a3 == 0;
  if ( v6 || a3 > 0x40 || *(_QWORD *)(a1 + 80) )
    return -1;
  v7 = *(_DWORD *)(a1 + 352);
  v8 = (unsigned __int8 *)(a1 + 96);
  if ( v7 > 0x80 )
  {
    v17 = *(_QWORD *)(a1 + 72);
    v18 = *(_QWORD *)(a1 + 64) + 128LL;
    *(_QWORD *)(a1 + 64) = v18;
    *(_QWORD *)(a1 + 72) = v17 + (v18 <= 0x7F);
    sub_4D798(a1, (unsigned __int8 *)(a1 + 96));
    v19 = *(_DWORD *)(a1 + 352) - 128;
    *(_DWORD *)(a1 + 352) = v19;
    memcpy((void *)(a1 + 96), (const void *)(a1 + 224), v19);
    v7 = *(_DWORD *)(a1 + 352);
  }
  v9 = *(_QWORD *)(a1 + 72);
  v10 = *(unsigned __int8 *)(a1 + 356);
  v11 = *(_QWORD *)(a1 + 64) + v7;
  *(_QWORD *)(a1 + 64) = v11;
  *(_QWORD *)(a1 + 72) = v9 + (v11 < v7);
  if ( v10 )
    *(_QWORD *)(a1 + 88) = -1;
  *(_QWORD *)(a1 + 80) = -1;
  memset((void *)(a1 + v7 + 96), 0, 256 - v7);
  v12 = a1;
  v13 = a1 - 8;
  sub_4D798(v12, v8);
  v14 = v20;
  do
  {
    v15 = *(_QWORD *)(v13 + 8);
    v13 += 8;
    *(_QWORD *)v14 = v15;
    v14 += 8;
  }
  while ( v14 != &v21 );
  memcpy(a2, v20, a3);
  return 0;
}
