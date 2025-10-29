int __fastcall sub_4EEE0(char *a1, int a2, int a3)
{
  int v6; // r0
  _DWORD v8[16]; // [sp+0h] [bp-40h] BYREF

  memset(v8, 0, sizeof(v8));
  HIWORD(v8[0]) = 257;
  v6 = sub_5C710(512, a2);
  v8[14] = a2;
  v8[15] = a3;
  qmemcpy(&v8[12], "ZcashPoW", 8);
  LOBYTE(v8[0]) = a2 * v6 / 8;
  return sub_54DCC(a1, (unsigned __int8 *)v8);
}
