int __fastcall sub_34C60(int a1, int a2, int a3, int a4)
{
  int v6; // r4
  _DWORD *v7; // r0
  _DWORD *v8; // r0
  _DWORD *v9; // r0
  _DWORD *v10; // r0
  _DWORD *v11; // r0
  int result; // r0
  _DWORD *v13; // r0
  _DWORD *v14; // r0
  _DWORD *v15; // r0
  _DWORD *v16; // r0
  _DWORD *v17; // r1

  sub_3305C((unsigned int *)a1, 22, 0, 0, a4);
  if ( a4 )
  {
    v6 = sub_307C8((unsigned int *)a1, ",\"VERSION\":[");
    v7 = sub_32E1C(0, "CGMiner", a49, 0);
    v8 = sub_32E40(v7, "API", "3.1", 0);
    v9 = sub_32E1C(v8, "Miner", (const char *)&dword_78B94, 0);
    v10 = sub_32E1C(v9, "CompileTime", s, 0);
    v11 = sub_32E1C(v10, "Type", byte_78850, 0);
    result = sub_32534((unsigned int *)a1, (int)v11, 1, 0);
    if ( v6 )
      *(_BYTE *)(a1 + 13) = 1;
  }
  else
  {
    sub_307C8((unsigned int *)a1, "VERSION,");
    v13 = sub_32E1C(0, "CGMiner", a49, 0);
    v14 = sub_32E40(v13, "API", "3.1", 0);
    v15 = sub_32E1C(v14, "Miner", (const char *)&dword_78B94, 0);
    v16 = sub_32E1C(v15, "CompileTime", s, 0);
    v17 = sub_32E1C(v16, "Type", byte_78850, 0);
    return sub_32534((unsigned int *)a1, (int)v17, 0, 0);
  }
  return result;
}
