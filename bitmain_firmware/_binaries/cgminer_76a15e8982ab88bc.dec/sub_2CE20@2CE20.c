int __fastcall sub_2CE20(int a1)
{
  if ( *(_BYTE *)(a1 + 665) )
    sub_2AE38(a1);
  if ( sub_2B840((_DWORD *)a1) && (!*(_BYTE *)(a1 + 604) || sub_2E50C((int *)a1)) && sub_2E8A8((_DWORD *)a1) )
  {
    sub_1FCAC((_DWORD *)a1);
    return 1;
  }
  else
  {
    sub_1F95C(a1);
    return 0;
  }
}
