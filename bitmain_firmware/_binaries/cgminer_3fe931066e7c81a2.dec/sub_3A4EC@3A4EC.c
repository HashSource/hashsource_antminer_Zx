_DWORD *sub_3A4EC()
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

  v0 = sub_32E64(0, "miner_count", &byte_9D6CB, 0);
  v1 = 0;
  v2 = sub_32E64(v0, "fan_num", &byte_9D6CC, 0);
  do
  {
    sprintf((char *)v33, "fan%d", v1 + 1);
    v3 = (char *)&unk_9D4B4 + 4 * v1++ + 489;
    v4 = sub_32F18(v2, (const char *)v33, v3, 0);
    v2 = v4;
  }
  while ( v1 != 6 );
  v5 = 0;
  v6 = sub_32E64(v4, "temp_num", &byte_9D6CB, 0);
  do
  {
    sprintf((char *)v33, "temp%d", v5 + 1);
    v7 = (char *)&unk_9D4B4 + 4 * v5++ + 653;
    v6 = sub_32E88(v6, (const char *)v33, v7, 0);
  }
  while ( v5 != 4 );
  for ( i = 0; i != 4; ++i )
  {
    sprintf((char *)v33, "temp2_%d", i + 1);
    v9 = (char *)&unk_9D4B4 + 4 * i + 669;
    v10 = sub_32E88(v6, (const char *)v33, v9, 0);
    v6 = v10;
  }
  v11 = sub_32F18(v10, "temp_max", (const char *)&dword_9D6D6, 0);
  LODWORD(v12) = sub_5CC10(dbl_7B5E8 + dbl_7B670 + dbl_7B428);
  *(_QWORD *)&dword_7B100 = v12;
  v13 = v12 + dword_7B8A4;
  if ( v13 )
  {
    v14.n64_u32[0] = dword_7B8A4;
    v14.n64_u32[1] = dword_7B8A4;
    LODWORD(v15) = sub_5CB64(v13);
    v16 = vcvt_n_f64_s32(v14, 8u) / v15;
  }
  else
  {
    v16 = 0.0;
  }
  v17 = 0;
  *(double *)&dword_78E20 = v16;
  v18 = sub_357A4(v11, "Device Hardware%", (const char *)&dword_78E20, 1);
  v19 = sub_32ED0(v18, "no_matching_work", (const char *)&dword_7B8A4, 1);
  do
  {
    sprintf((char *)v33, "chain_acn%d", v17 + 1);
    v20 = (char *)&unk_9D4B4 + v17++ + 529;
    v19 = sub_32E64(v19, (const char *)v33, v20, 0);
  }
  while ( v17 != 4 );
  for ( j = 0; j != 4; ++j )
  {
    sprintf((char *)v33, "chain_acs%d", j + 1);
    v22 = (char *)&unk_9D4B4 + 19 * j;
    v19 = sub_32E1C(v19, (const char *)v33, v22 + 355, 0);
  }
  for ( k = 0; k != 4; ++k )
  {
    sprintf((char *)v33, "chain_hw%d", k + 1);
    v24 = sub_32F18(v19, (const char *)v33, (const char *)&unk_9D4B4 + 4 * k + 243, 0);
    v19 = v24;
  }
  v25 = 0;
  do
  {
    memset(s, 0, sizeof(s));
    memset(v33, 0, 16);
    sprintf((char *)s, "frequency%d", v25 + 1);
    v26 = v25 + 296;
    ++v25;
    v31 = (char *)&unk_9D4B4 + 2 * v26 + 1;
    sprintf((char *)v33, "%u", *(unsigned __int16 *)v31);
    v19 = sub_32EAC(v19, (const char *)s, v31, 0);
  }
  while ( v25 != 4 );
  v27 = 0;
  do
  {
    v28 = v27 + 1;
    v29 = 16 * v27;
    sprintf((char *)v33, "chain_rate%d", v27 + 1);
    if ( byte_78E28 )
      sprintf(&byte_7C0A8[v29], "%2.2f", dbl_78E30 / (double)dword_78E38);
    result = sub_32E1C(v19, (const char *)v33, &byte_7C0A8[v29], 0);
    ++v27;
    v19 = result;
  }
  while ( v28 != 4 );
  return result;
}
