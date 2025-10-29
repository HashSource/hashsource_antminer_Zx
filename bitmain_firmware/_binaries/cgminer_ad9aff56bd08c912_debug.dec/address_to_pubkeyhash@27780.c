void __fastcall address_to_pubkeyhash(unsigned __int8 *pkh, const char *addr)
{
  int v3; // t1
  int v4; // r7
  int v5; // r6
  int v6; // r1
  unsigned __int8 b58bin[28]; // [sp+4h] [bp-20h] BYREF

  memset(b58bin, 0, 25);
  b58tobin(b58bin, addr);
  pkh[2] = 20;
  v3 = *(_DWORD *)&b58bin[1];
  *pkh = 118;
  pkh[1] = -87;
  *(_DWORD *)(pkh + 3) = v3;
  v4 = *(_DWORD *)&b58bin[9];
  v5 = *(_DWORD *)&b58bin[13];
  *(_DWORD *)(pkh + 7) = *(_DWORD *)&b58bin[5];
  v6 = *(_DWORD *)&b58bin[17];
  *(_DWORD *)(pkh + 11) = v4;
  *(_DWORD *)(pkh + 15) = v5;
  *(_DWORD *)(pkh + 19) = v6;
  pkh[23] = -120;
  pkh[24] = -84;
}
