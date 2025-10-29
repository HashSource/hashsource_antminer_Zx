_DWORD *__fastcall sub_3030C(char *a1, size_t n, int a3)
{
  _DWORD *v3; // r3
  char *v4; // r12
  int v6; // t1
  int v8[33]; // [sp+0h] [bp-A8h] BYREF
  char v9; // [sp+84h] [bp-24h] BYREF

  v3 = &unk_72F18;
  v4 = &v9;
  do
  {
    v6 = v3[1];
    ++v3;
    *((_DWORD *)v4 + 1) = v6;
    v4 += 4;
  }
  while ( v3 != (_DWORD *)&unk_72F38 );
  v8[0] = 0;
  v8[1] = 0;
  sub_30174(v8, a1, n);
  return sub_30214(v8, a3);
}
