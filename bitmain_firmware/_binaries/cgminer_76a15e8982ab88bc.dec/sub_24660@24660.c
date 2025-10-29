int __fastcall sub_24660(int a1)
{
  int v2; // r4
  int v4; // r0

  v2 = *(_DWORD *)(a1 + 356);
  if ( v2 )
  {
    if ( sub_22A8C(*(_DWORD *)(a1 + 356), 0) )
    {
      v4 = v2;
      v2 = 0;
      sub_158EC(v4);
      sub_1852C();
    }
    else
    {
      sub_1655C(a1, v2);
    }
    *(_DWORD *)(a1 + 356) = 0;
  }
  return v2;
}
