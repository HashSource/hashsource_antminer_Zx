int __fastcall sub_19C7C(int a1)
{
  bool v2; // zf
  unsigned int v3; // r0
  int v4; // r2
  _BYTE *v5; // r5
  int result; // r0
  unsigned int v7[513]; // [sp+0h] [bp-804h] BYREF

  v2 = byte_630C1 == 0;
  v3 = bswap32(bswap32(*(_DWORD *)(a1 + 68)) + 1);
  v4 = dword_63A70 + 1;
  ++*(_DWORD *)(a1 + 240);
  *(_DWORD *)(a1 + 68) = v3;
  *(_DWORD *)(a1 + 248) = 0;
  dword_63A70 = v4;
  if ( !v2 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
  {
    strcpy((char *)v7, "Successfully rolled work");
    sub_38438(7, (const char *)v7, 0);
  }
  v5 = *(_BYTE **)(a1 + 308);
  if ( v5 )
  {
    sub_295B8(v7, *(unsigned __int8 **)(a1 + 308), 4);
    v7[0] = bswap32(bswap32(v7[0]) + 1);
    sub_29460(v5, (char *)v7, 4);
  }
  result = sub_19BC0();
  *(_DWORD *)(a1 + 340) = result;
  return result;
}
