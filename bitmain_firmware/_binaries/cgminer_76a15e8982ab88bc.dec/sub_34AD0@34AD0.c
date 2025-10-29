int __fastcall sub_34AD0(int a1, int a2, int a3, int a4)
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

  sub_32ECC((unsigned int *)a1, 22, 0, 0, a4);
  if ( a4 )
  {
    v6 = sub_30638((unsigned int *)a1, ",\"VERSION\":[");
    v7 = sub_32C8C(0, "CGMiner", a49, 0);
    v8 = sub_32CB0(v7, "API", "3.1", 0);
    v9 = sub_32C8C(v8, "Miner", (const char *)&dword_759D0, 0);
    v10 = sub_32C8C(v9, "CompileTime", s, 0);
    v11 = sub_32C8C(v10, "Type", byte_7568C, 0);
    result = sub_323A4((unsigned int *)a1, (int)v11, 1, 0);
    if ( v6 )
      *(_BYTE *)(a1 + 13) = 1;
  }
  else
  {
    sub_30638((unsigned int *)a1, "VERSION,");
    v13 = sub_32C8C(0, "CGMiner", a49, 0);
    v14 = sub_32CB0(v13, "API", "3.1", 0);
    v15 = sub_32C8C(v14, "Miner", (const char *)&dword_759D0, 0);
    v16 = sub_32C8C(v15, "CompileTime", s, 0);
    v17 = sub_32C8C(v16, "Type", byte_7568C, 0);
    return sub_323A4((unsigned int *)a1, (int)v17, 0, 0);
  }
  return result;
}
