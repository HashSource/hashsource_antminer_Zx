_DWORD *sub_3A384()
{
  _DWORD *v0; // r0
  int v1; // r5
  _DWORD *v2; // r8
  const char *v3; // r2
  _DWORD *v4; // r0
  int v5; // r5
  _DWORD *v6; // r6
  const char *v7; // r2
  int i; // r5
  const char *v9; // r2
  _DWORD *v10; // r0
  _DWORD *v11; // r5
  __int64 v12; // r0
  __int64 v13; // r0
  int32x2_t v14; // d8
  double v15; // r0
  double v16; // d16
  int v17; // r6
  _DWORD *v18; // r0
  _DWORD *v19; // r5
  const char *v20; // r2
  int j; // r6
  char *v22; // r2
  int k; // r6
  _DWORD *v24; // r0
  int v25; // r8
  int v26; // r2
  int v27; // r4
  int v28; // r6
  int v29; // r7
  _DWORD *result; // r0
  const char *v31; // [sp+4h] [bp-28h]
  _DWORD s[4]; // [sp+8h] [bp-24h] BYREF
  _DWORD v33[5]; // [sp+18h] [bp-14h] BYREF

  v0 = sub_32CD4(0, "miner_count", &byte_9A49F, 0);
  v1 = 0;
  v2 = sub_32CD4(v0, "fan_num", &byte_9A4A0, 0);
  do
  {
    sprintf((char *)v33, "fan%d", v1 + 1);
    v3 = (char *)&unk_9A2A8 + 4 * v1++ + 457;
    v4 = sub_32D88(v2, (const char *)v33, v3, 0);
    v2 = v4;
  }
  while ( v1 != 6 );
  v5 = 0;
  v6 = sub_32CD4(v4, "temp_num", &byte_9A49F, 0);
  do
  {
    sprintf((char *)v33, "temp%d", v5 + 1);
    v7 = (char *)&unk_9A2A8 + 4 * v5++ + 621;
    v6 = sub_32CF8(v6, (const char *)v33, v7, 0);
  }
  while ( v5 != 4 );
  for ( i = 0; i != 4; ++i )
  {
    sprintf((char *)v33, "temp2_%d", i + 1);
    v9 = (char *)&unk_9A2A8 + 4 * i + 637;
    v10 = sub_32CF8(v6, (const char *)v33, v9, 0);
    v6 = v10;
  }
  v11 = sub_32D88(v10, "temp_max", (const char *)&dword_9A4AA, 0);
  LODWORD(v12) = sub_59FC8(dbl_78410 + dbl_78498 + dbl_78250);
  *(_QWORD *)&dword_77F28 = v12;
  v13 = v12 + dword_786CC;
  if ( v13 )
  {
    v14.n64_u32[0] = dword_786CC;
    v14.n64_u32[1] = dword_786CC;
    LODWORD(v15) = sub_59F1C(v13);
    v16 = vcvt_n_f64_s32(v14, 8u) / v15;
  }
  else
  {
    v16 = 0.0;
  }
  v17 = 0;
  *(double *)&dword_75C60 = v16;
  v18 = sub_35624(v11, "Device Hardware%", (const char *)&dword_75C60, 1);
  v19 = sub_32D40(v18, "no_matching_work", (const char *)&dword_786CC, 1);
  do
  {
    sprintf((char *)v33, "chain_acn%d", v17 + 1);
    v20 = (char *)&unk_9A2A8 + v17++ + 497;
    v19 = sub_32CD4(v19, (const char *)v33, v20, 0);
  }
  while ( v17 != 4 );
  for ( j = 0; j != 4; ++j )
  {
    sprintf((char *)v33, "chain_acs%d", j + 1);
    v22 = (char *)&unk_9A2A8 + 19 * j;
    v19 = sub_32C8C(v19, (const char *)v33, v22 + 323, 0);
  }
  for ( k = 0; k != 4; ++k )
  {
    sprintf((char *)v33, "chain_hw%d", k + 1);
    v24 = sub_32D88(v19, (const char *)v33, (const char *)&unk_9A2A8 + 4 * k + 211, 0);
    v19 = v24;
  }
  v25 = 0;
  do
  {
    memset(s, 0, sizeof(s));
    memset(v33, 0, 16);
    sprintf((char *)s, "frequency%d", v25 + 1);
    v26 = v25 + 280;
    ++v25;
    v31 = (char *)&unk_9A2A8 + 2 * v26 + 1;
    sprintf((char *)v33, "%u", *(unsigned __int16 *)v31);
    v19 = sub_32D1C(v19, (const char *)s, v31, 0);
  }
  while ( v25 != 4 );
  v27 = 0;
  do
  {
    v28 = v27 + 1;
    v29 = 16 * v27;
    sprintf((char *)v33, "chain_rate%d", v27 + 1);
    if ( byte_75C68 )
      sprintf(&byte_78ED0[v29], "%2.2f", dbl_75C70 / (double)dword_75C78);
    result = sub_32C8C(v19, (const char *)v33, &byte_78ED0[v29], 0);
    ++v27;
    v19 = result;
  }
  while ( v28 != 4 );
  return result;
}
