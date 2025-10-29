int __fastcall sub_538C8(char *a1, int a2, const void *a3, size_t a4)
{
  bool v7; // zf
  unsigned __int8 v9[18]; // [sp+0h] [bp-C4h] BYREF
  __int16 v10; // [sp+12h] [bp-B2h]
  __int16 v11; // [sp+14h] [bp-B0h]
  __int16 v12; // [sp+16h] [bp-AEh]
  __int16 v13; // [sp+18h] [bp-ACh]
  __int16 v14; // [sp+1Ah] [bp-AAh]
  __int16 v15; // [sp+1Ch] [bp-A8h]
  __int16 v16; // [sp+1Eh] [bp-A6h]
  int v17; // [sp+20h] [bp-A4h]
  int v18; // [sp+24h] [bp-A0h]
  int v19; // [sp+28h] [bp-9Ch]
  int v20; // [sp+2Ch] [bp-98h]
  int v21; // [sp+30h] [bp-94h]
  int v22; // [sp+34h] [bp-90h]
  int v23; // [sp+38h] [bp-8Ch]
  int v24; // [sp+3Ch] [bp-88h]
  char s[132]; // [sp+40h] [bp-84h] BYREF

  if ( (unsigned int)(a2 - 1) > 0x3F )
    return -1;
  v7 = a3 == 0;
  if ( a3 )
    v7 = a4 == 0;
  if ( v7 )
    return -1;
  if ( a4 > 0x40 )
    return -1;
  v9[1] = a4;
  v9[0] = a2;
  memset(&v9[4], 0, 14);
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v9[2] = 1;
  v9[3] = 1;
  if ( sub_535FC(a1, v9) < 0 )
    return -1;
  memset(s, 0, 0x80u);
  memcpy(s, a3, a4);
  sub_537BC((int)a1, s, 0x80u);
  off_739D4(s, 0, 0x80u);
  return 0;
}
