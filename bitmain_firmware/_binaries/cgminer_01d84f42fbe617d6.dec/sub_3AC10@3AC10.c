_DWORD *sub_3AC10()
{
  _DWORD *v0; // r0
  int v1; // r6
  _DWORD *v2; // r0
  _DWORD *v3; // r4
  _DWORD *v4; // r4
  _DWORD *v5; // r0
  _DWORD *v6; // r4
  _DWORD *v7; // r0
  int i; // r6
  const char *v9; // r2
  int j; // r6
  _DWORD *v11; // r0
  int k; // r6
  const char *v13; // r2
  _DWORD *v14; // r0
  _DWORD *v15; // r4
  __int64 v16; // r0
  __int64 v17; // r0
  double v18; // d8
  double v19; // r0
  double v20; // d16
  int v21; // r6
  _DWORD *v22; // r0
  _DWORD *v23; // r4
  const char *v24; // r2
  int m; // r6
  char *v26; // r2
  int n; // r6
  _DWORD *v28; // r0
  int ii; // r5
  const char *v30; // r2
  int v31; // r3
  unsigned __int64 v32; // d16
  _QWORD *v33; // r2
  int v34; // t1
  double v36; // [sp+8h] [bp-18h] BYREF
  char s[16]; // [sp+10h] [bp-10h] BYREF

  v0 = sub_32D44(0, "miner_count", &byte_C5468, 0);
  v1 = 0;
  v2 = sub_32CFC(v0, "frequency", byte_C5494, 0);
  v3 = sub_32D44(v2, "fan_num", &byte_C5469, 0);
  sprintf(s, "fan%d", 1);
  v4 = sub_32DF8(v3, s, (const char *)&dword_C544A, 0);
  sprintf(s, "fan%d", 2);
  v5 = sub_32DF8(v4, s, (const char *)dword_C544E, 0);
  v6 = sub_32D44(v5, "temp_num", &byte_C5468, 0);
  do
  {
    sprintf(s, "temp%d", v1 + 1);
    v7 = sub_32D68(v6, s, (const char *)&unk_C4BCC + 64 * v1++ + 320, 0);
    v6 = v7;
  }
  while ( v1 != 4 );
  for ( i = 0; i != 4; ++i )
  {
    sprintf(s, "temp2_%d", i + 1);
    v9 = (char *)&unk_C4BCC + 64 * i + 322;
    v6 = sub_32D68(v6, s, v9, 0);
  }
  for ( j = 0; j != 4; ++j )
  {
    sprintf(s, "temp3%d", j + 1);
    v11 = sub_32D68(v6, s, (const char *)&unk_C4BCC + 64 * j + 312, 0);
    v6 = v11;
  }
  for ( k = 0; k != 4; ++k )
  {
    sprintf(s, "temp4_%d", k + 1);
    v13 = (char *)&unk_C4BCC + 64 * k + 314;
    v14 = sub_32D68(v6, s, v13, 0);
    v6 = v14;
  }
  v15 = sub_32DF8(v14, "temp_max", (const char *)dword_C5473, 0);
  LODWORD(v16) = sub_49488(dbl_63B88 + dbl_63C10 + dbl_639D0);
  *(_QWORD *)&dword_636A8 = v16;
  v17 = v16 + dword_63E44;
  if ( v17 )
  {
    v18 = (double)dword_63E44;
    LODWORD(v19) = sub_493DC(v17);
    v20 = v18 / v19;
  }
  else
  {
    v20 = 0.0;
  }
  v36 = v20;
  v21 = 0;
  v22 = sub_35684(v15, "Device Hardware%", (const char *)&v36, 0);
  v23 = sub_32DB0(v22, "no_matching_work", (const char *)&dword_63E44, 0);
  do
  {
    sprintf(s, "chain_acn%d", v21 + 1);
    v24 = (char *)&unk_C4BCC + v21++ + 2198;
    v23 = sub_32D44(v23, s, v24, 0);
  }
  while ( v21 != 4 );
  for ( m = 0; m != 4; ++m )
  {
    sprintf(s, "chain_acs%d", m + 1);
    v26 = (char *)&unk_C4BCC + 88 * m;
    v23 = sub_32CFC(v23, s, v26 + 1800, 0);
  }
  for ( n = 0; n != 4; ++n )
  {
    sprintf(s, "chain_hw%d", n + 1);
    v28 = sub_32DF8(v23, s, (const char *)&unk_C4BCC + 4 * n + 632, 0);
    v23 = v28;
  }
  for ( ii = 0; ii != 4; ++ii )
  {
    sprintf(s, "chain_rate%d", ii + 1);
    v30 = &byte_65E6C[16 * ii];
    v23 = sub_32CFC(v23, s, v30, 0);
  }
  v31 = 805859;
  v32 = 0;
  v33 = qword_63100;
  do
  {
    v34 = *(unsigned __int8 *)++v31;
    if ( v34 == 1 )
      v32 += *v33;
    ++v33;
  }
  while ( v31 != 805863 );
  sub_3AA38(v32, byte_62E38, 6, 0);
  return v23;
}
