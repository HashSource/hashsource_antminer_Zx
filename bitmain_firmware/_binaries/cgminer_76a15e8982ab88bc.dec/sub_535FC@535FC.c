int __fastcall sub_535FC(char *a1, unsigned __int8 *a2)
{
  char *v4; // r12
  char *v5; // r4
  __int64 v6; // t1
  unsigned __int8 *v7; // r1
  char *v8; // r0
  __int64 v9; // d18
  __int64 v10; // d21
  __int64 v11; // d17
  unsigned int v12; // r2
  __int64 v13; // d19

  memset(a1, 0, 0x168u);
  v4 = "";
  v5 = a1 - 8;
  do
  {
    v6 = *((_QWORD *)v4 + 1);
    v4 += 8;
    *((_QWORD *)v5 + 1) = v6;
    v5 += 8;
  }
  while ( v4 != (char *)&unk_693E0 );
  v7 = a2;
  v8 = a1;
  do
  {
    v9 = vshld_n_s64(v7[2], 0x10u) | vshld_n_s64(v7[1], 8u);
    LODWORD(v9) = *v7 | (unsigned int)v9;
    v10 = vshld_n_s64(v7[4], 0x20u) | vshld_n_s64(v7[3], 0x18u) | v9;
    v11 = vshld_n_s64(v7[5], 0x28u);
    v12 = v7[7];
    v13 = vshld_n_s64(v7[6], 0x30u);
    v7 += 8;
    *(_QWORD *)v8 ^= vshld_n_s64(v12, 0x38u) | v13 | v11 | v10;
    v8 += 8;
  }
  while ( v7 != a2 + 64 );
  return 0;
}
