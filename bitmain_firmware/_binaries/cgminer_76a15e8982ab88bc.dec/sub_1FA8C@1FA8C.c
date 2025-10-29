int __fastcall sub_1FA8C(int a1)
{
  int result; // r0

  result = sub_1859C(a1, (_BYTE *)(a1 + 129));
  if ( !result )
  {
    sub_2A7A4((struct timeval *)(a1 + 168));
    result = sub_1D9A0();
    if ( a1 == result )
      return sub_1A600(0);
  }
  return result;
}
