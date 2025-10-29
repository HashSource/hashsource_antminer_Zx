int __fastcall sub_43500(int a1, int a2, int a3)
{
  char v4; // r7
  char v5; // r6
  _DWORD v7[2]; // [sp+14h] [bp-1010h] BYREF
  __int16 v8; // [sp+1Ch] [bp-1008h]
  char v9; // [sp+1Eh] [bp-1006h]
  char s[4064]; // [sp+20h] [bp-1004h] BYREF

  v7[1] = 0;
  v8 = 0;
  v4 = a2;
  v5 = a3;
  v7[0] = 0;
  v9 = 0;
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "chainID%d %s txndata %d txnzero %d", a1, "set_txn_data_chain", a2, a3);
    sub_385C8(5, s, 0);
  }
  dword_739A0 = (2 * (v4 & 1)) | v5 & 1;
  sub_3CA8C((int)v7, 1, 0, 88, dword_739A0);
  sub_3BFB4(a1, v7, 0xBu);
  return sub_2A884();
}
