int __fastcall sub_54F8C(int a1, char *src, unsigned __int64 n)
{
  unsigned __int64 v3; // r4
  int v6; // r3
  int v7; // r10
  int v8; // r6
  int v9; // r12
  unsigned __int64 v10; // r2
  void *srca; // [sp+4h] [bp-8h]

  v3 = n;
  if ( n )
  {
    v6 = *(_DWORD *)(a1 + 352);
    srca = (void *)(a1 + 224);
    while ( 1 )
    {
      v7 = 256 - v6;
      v8 = 256 - v6;
      if ( (unsigned int)(256 - v6) >= v3 )
        break;
      memcpy((void *)(a1 + v6 + 96), src, 256 - v6);
      v9 = *(_DWORD *)(a1 + 352);
      v10 = *(_QWORD *)(a1 + 64) + 128LL;
      *(_QWORD *)(a1 + 64) = v10;
      src += v7;
      *(_QWORD *)(a1 + 72) += v10 <= 0x7F;
      *(_DWORD *)(a1 + 352) = v9 + v7;
      v3 -= (unsigned int)v8;
      sub_4EF68(a1, (unsigned __int8 *)(a1 + 96));
      memcpy((void *)(a1 + 96), srca, 0x80u);
      v6 = *(_DWORD *)(a1 + 352) - 128;
      *(_DWORD *)(a1 + 352) = v6;
      if ( !v3 )
        return 0;
    }
    memcpy((void *)(a1 + v6 + 96), src, v3);
    *(_DWORD *)(a1 + 352) += v3;
  }
  return 0;
}
