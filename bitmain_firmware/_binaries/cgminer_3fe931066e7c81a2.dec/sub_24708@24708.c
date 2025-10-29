int __fastcall sub_24708(int a1)
{
  int v2; // r4
  int v4; // r0

  v2 = *(_DWORD *)(a1 + 356);
  if ( v2 )
  {
    if ( sub_22B44(*(_DWORD *)(a1 + 356), 0) )
    {
      v4 = v2;
      v2 = 0;
      sub_159B4(v4);
      sub_19840();
    }
    else
    {
      sub_16624(a1, v2);
    }
    *(_DWORD *)(a1 + 356) = 0;
  }
  return v2;
}
