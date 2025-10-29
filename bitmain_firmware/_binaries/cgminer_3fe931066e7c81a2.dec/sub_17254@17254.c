int __fastcall sub_17254(char *a1)
{
  char *v2; // r0
  bool v3; // zf
  int v4; // r5
  _DWORD *v6; // r8
  int v7; // r10
  int v8; // r11
  char *v9; // r0
  char *v10; // r12
  char *v11; // r9
  signed int v12; // r2
  size_t v13; // r0
  const char *v14; // r8
  size_t v15; // r11
  size_t v16; // r10
  size_t v17; // r5
  char *v18; // r0
  const char *v19; // r8
  char *v20; // r0
  int v21; // r0
  int v22; // r5
  char *v23; // r7
  int v24; // r1
  int v25; // r2
  int v26; // r3
  int v27; // r1
  int v28; // r2
  int v29; // r3
  _DWORD v30[4]; // [sp+14h] [bp-1500h] BYREF
  char *v31; // [sp+24h] [bp-14F0h]
  _BYTE v32[64]; // [sp+28h] [bp-14ECh] BYREF
  int v33[42]; // [sp+68h] [bp-14ACh] BYREF
  char s[1024]; // [sp+110h] [bp-1404h] BYREF
  char v35[4080]; // [sp+510h] [bp-1004h] BYREF

  if ( dword_76FF8 )
  {
    if ( fgets(s, 1024, (FILE *)dword_76FF8) )
      goto LABEL_3;
    if ( !dword_77004 )
      goto LABEL_25;
LABEL_9:
    fclose((FILE *)dword_76FF8);
    dword_76FF8 = 0;
    return sub_17254(a1);
  }
  else
  {
    if ( !dword_76FFC )
    {
      strcpy(v35, "BENCHFILE Invalid benchfile NULL");
      sub_38730(3, v35, 1);
      sub_16CA8(1);
    }
    dword_76FF8 = (int)fopen((const char *)dword_76FFC, "r");
    if ( !dword_76FF8 )
    {
      snprintf(v35, 0x1000u, "BENCHFILE Failed to open benchfile '%s'", (const char *)dword_76FFC);
      sub_38730(3, v35, 1);
      sub_16CA8(1);
    }
    dword_77000 = 0;
    if ( !fgets(s, 1024, (FILE *)dword_76FF8) )
    {
      snprintf(v35, 0x1000u, "BENCHFILE Failed to read benchfile '%s'", (const char *)dword_76FFC);
      sub_38730(3, v35, 1);
      sub_16CA8(1);
    }
    dword_77004 = 0;
    while ( 1 )
    {
LABEL_3:
      v2 = s;
      v3 = s[0] == 35;
      if ( s[0] != 35 )
        v3 = s[0] == 0;
      ++dword_77000;
      if ( !v3 && s[0] != 47 )
        break;
      if ( !fgets(s, 1024, (FILE *)dword_76FF8) )
      {
        if ( dword_77004 )
          goto LABEL_9;
LABEL_25:
        snprintf(v35, 0x1000u, "BENCHFILE No work in benchfile '%s'", dword_76FFC);
        sub_38730(3, v35, 1);
        sub_16CA8(1);
      }
    }
    v6 = v30;
    v7 = 0;
    v8 = 1;
    v30[0] = s;
    do
    {
      v9 = strchr(v2, 44);
      v6[1] = v9;
      if ( !v9 )
      {
        snprintf(
          v35,
          0x1000u,
          "BENCHFILE Invalid input file line %d - field count is %d but should be %d",
          dword_77000,
          v8,
          5);
        sub_38730(3, v35, 1);
        sub_16CA8(1);
      }
      v10 = *(char **)((char *)&unk_5D6AC + v7);
      if ( v10 && &v9[-*v6] != v10 )
      {
        snprintf(
          v35,
          0x1000u,
          "BENCHFILE Invalid input file line %d field %d (%s) length is %d but should be %d",
          dword_77000,
          v8,
          *(const char **)((char *)&unk_5D6AC + v7 + 4),
          &v9[-*v6],
          v10);
        sub_38730(3, v35, 1);
        sub_16CA8(1);
      }
      ++v8;
      *v9 = 0;
      v7 += 8;
      v6[1] = v9 + 1;
      v2 = v9 + 1;
      ++v6;
    }
    while ( v8 != 5 );
    v11 = v31;
    v12 = strlen(v31);
    if ( v12 <= 9 )
    {
      snprintf(
        v35,
        0x1000u,
        "BENCHFILE Invalid input file line %d field %d (%s) length is %d but should be least %d",
        dword_77000,
        5,
        "NonceTime",
        v12,
        10);
      sub_38730(3, v35, 1);
      sub_16CA8(1);
    }
    sprintf(v35, "0000000%c", *(unsigned __int8 *)v30[0]);
    v13 = strlen(v35);
    v14 = (const char *)(v30[2] + 56);
    v15 = v13 + 64;
    v16 = v13;
    v17 = v13;
    do
    {
      v18 = &v35[v17];
      v17 += 8;
      sprintf(v18, "%.8s", v14);
      v14 -= 8;
    }
    while ( v17 != v15 );
    v19 = (const char *)(v30[1] + 56);
    do
    {
      v20 = &v35[v17];
      v17 += 8;
      sprintf(v20, "%.8s", v19);
      v19 -= 8;
    }
    while ( v17 != v16 + 128 );
    v21 = strtol(v11, 0, 10);
    sprintf(&v35[v17], "%08lx", v21);
    v22 = 0;
    strcpy(&v35[v16 + 136], (const char *)v30[3]);
    memset(a1, 0, 0x7B0u);
    sub_29830(a1, (unsigned __int8 *)v35, (int)(v16 + 144) >> 1);
    do
    {
      *(_DWORD *)&v32[v22] = bswap32(*(_DWORD *)&a1[v22]);
      v22 += 4;
    }
    while ( v22 != 64 );
    v23 = a1 + 128;
    sub_302D0(v33);
    sub_30304(v33, v32, 0x40u);
    v4 = 1;
    v24 = v33[35];
    v25 = v33[36];
    v26 = v33[37];
    ++dword_77004;
    *(_DWORD *)v23 = v33[34];
    *((_DWORD *)v23 + 1) = v24;
    *((_DWORD *)v23 + 2) = v25;
    *((_DWORD *)v23 + 3) = v26;
    v23 += 16;
    v27 = v33[39];
    v28 = v33[40];
    v29 = v33[41];
    *(_DWORD *)v23 = v33[38];
    *((_DWORD *)v23 + 1) = v27;
    *((_DWORD *)v23 + 2) = v28;
    *((_DWORD *)v23 + 3) = v29;
  }
  return v4;
}
