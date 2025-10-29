int __fastcall sub_44FEC(int a1)
{
  __int64 v1; // r0

  if ( a1 <= 39 )
  {
    a1 = 40;
  }
  else if ( a1 > 100 )
  {
    v1 = 0x6400640000LL;
    goto LABEL_4;
  }
  if ( byte_75F66 )
  {
    v1 = 0x6400640000LL;
  }
  else
  {
    BYTE4(v1) = a1;
    LODWORD(v1) = (100 - a1) | (a1 << 16);
  }
LABEL_4:
  byte_9A49E = BYTE4(v1);
  *(_DWORD *)(dword_75C50[0] + 132) = v1;
  return v1;
}
