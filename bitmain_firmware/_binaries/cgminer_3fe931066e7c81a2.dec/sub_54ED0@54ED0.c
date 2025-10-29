int __fastcall sub_54ED0(char *a1, int a2)
{
  unsigned __int8 v3[18]; // [sp+0h] [bp-44h] BYREF
  __int16 v4; // [sp+12h] [bp-32h]
  __int16 v5; // [sp+14h] [bp-30h]
  __int16 v6; // [sp+16h] [bp-2Eh]
  __int16 v7; // [sp+18h] [bp-2Ch]
  __int16 v8; // [sp+1Ah] [bp-2Ah]
  __int16 v9; // [sp+1Ch] [bp-28h]
  __int16 v10; // [sp+1Eh] [bp-26h]
  int v11; // [sp+20h] [bp-24h]
  int v12; // [sp+24h] [bp-20h]
  int v13; // [sp+28h] [bp-1Ch]
  int v14; // [sp+2Ch] [bp-18h]
  int v15; // [sp+30h] [bp-14h]
  int v16; // [sp+34h] [bp-10h]
  int v17; // [sp+38h] [bp-Ch]
  int v18; // [sp+3Ch] [bp-8h]

  if ( (unsigned int)(a2 - 1) > 0x3F )
    return -1;
  v3[0] = a2;
  v3[2] = 1;
  v3[1] = 0;
  memset(&v3[4], 0, 14);
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v3[3] = 1;
  return sub_54DCC(a1, v3);
}
