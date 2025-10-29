int __fastcall sub_45D88(int a1)
{
  __int64 v1; // r0
  int v2; // r3

  if ( a1 <= 39 )
  {
    a1 = 40;
  }
  else if ( a1 > 100 )
  {
    v1 = 0x6400640000LL;
    goto LABEL_4;
  }
  if ( byte_79126 )
  {
    v1 = 0x6400640000LL;
  }
  else
  {
    BYTE4(v1) = a1;
    LODWORD(v1) = (100 - a1) | (a1 << 16);
  }
LABEL_4:
  v2 = dword_78E10[0];
  byte_9D6CA = BYTE4(v1);
  *(_DWORD *)(dword_78E10[0] + 132) = v1;
  *(_DWORD *)(v2 + 160) = v1;
  return v1;
}
