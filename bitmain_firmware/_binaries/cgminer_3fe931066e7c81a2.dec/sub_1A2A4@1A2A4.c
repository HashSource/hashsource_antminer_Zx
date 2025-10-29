int __fastcall sub_1A2A4(int a1)
{
  bool v2; // zf
  unsigned int v3; // r0
  int v4; // r2
  _BYTE *v5; // r5
  int result; // r0
  unsigned int v7[1024]; // [sp+0h] [bp-1004h] BYREF

  v2 = byte_78E09 == 0;
  v3 = bswap32(bswap32(*(_DWORD *)(a1 + 68)) + 1);
  v4 = dword_7B4CC[0] + 1;
  ++*(_DWORD *)(a1 + 1728);
  *(_DWORD *)(a1 + 68) = v3;
  *(_DWORD *)(a1 + 1736) = 0;
  dword_7B4CC[0] = v4;
  if ( !v2 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    strcpy((char *)v7, "Successfully rolled work");
    sub_38730(7, (const char *)v7, 0);
  }
  v5 = *(_BYTE **)(a1 + 1796);
  if ( v5 )
  {
    sub_29830(v7, *(unsigned __int8 **)(a1 + 1796), 4);
    v7[0] = bswap32(bswap32(v7[0]) + 1);
    sub_296D8(v5, (char *)v7, 4);
  }
  result = sub_1A1E8();
  *(_DWORD *)(a1 + 1828) = result;
  return result;
}
