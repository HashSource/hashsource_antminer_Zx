int __fastcall sub_1FB44(int a1)
{
  int result; // r0

  result = sub_18834(a1, (_BYTE *)(a1 + 129));
  if ( !result )
  {
    sub_2A84C((struct timeval *)(a1 + 168));
    result = sub_1DA58();
    if ( a1 == result )
      return sub_19BF8(0);
  }
  return result;
}
