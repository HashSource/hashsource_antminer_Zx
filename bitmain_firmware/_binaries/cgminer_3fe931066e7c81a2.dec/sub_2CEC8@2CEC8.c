int __fastcall sub_2CEC8(int a1)
{
  if ( *(_BYTE *)(a1 + 665) )
    sub_2AEE0(a1);
  if ( sub_2B8E8((_DWORD *)a1) && (!*(_BYTE *)(a1 + 604) || sub_2E69C((int *)a1)) && sub_2EA38((_DWORD *)a1) )
  {
    sub_1FD64((_DWORD *)a1);
    return 1;
  }
  else
  {
    sub_1FA14(a1);
    return 0;
  }
}
