int __fastcall sub_29EAC(unsigned int *a1, unsigned int *a2)
{
  unsigned int *v2; // r12
  unsigned int *v3; // r2
  int v5; // r3
  unsigned int v6; // r5
  unsigned int v7; // t1
  unsigned int v8; // t1
  bool v9; // cf
  int v10; // r5
  unsigned int v12; // r1
  unsigned int v13; // r8
  unsigned int v14; // r7
  unsigned int v15; // r11
  unsigned int v16; // lr
  unsigned int v17; // r10
  unsigned int v18; // r12
  unsigned int v19; // r2
  unsigned int v20; // r10
  unsigned int v21; // r8
  unsigned int v22; // r7
  unsigned int v23; // r2
  unsigned int v24; // r3
  unsigned int v25; // lr
  unsigned int v26; // r12
  char *v27; // r7
  char *v28; // r6
  const char *v29; // r12
  _DWORD v30[8]; // [sp+8h] [bp-1044h] BYREF
  _DWORD v31[8]; // [sp+28h] [bp-1024h] BYREF
  char s[4088]; // [sp+48h] [bp-1004h] BYREF

  v2 = a1 + 8;
  v3 = a2 + 8;
  v5 = 7;
  while ( 1 )
  {
    v7 = *--v2;
    v6 = v7;
    --v5;
    v8 = *--v3;
    v9 = v6 >= v8;
    if ( v6 > v8 )
      break;
    if ( !v9 || v5 == -1 )
    {
      v10 = 1;
      goto LABEL_7;
    }
  }
  v10 = 0;
LABEL_7:
  if ( byte_75C49 )
  {
    v12 = a1[6];
    v13 = a1[3];
    v14 = a1[2];
    v15 = bswap32(a1[7]);
    v16 = a1[1];
    v17 = bswap32(a1[4]);
    v18 = *a1;
    v30[2] = bswap32(a1[5]);
    v30[3] = v17;
    v30[0] = v15;
    v19 = a2[7];
    v20 = a2[6];
    v30[4] = bswap32(v13);
    v21 = a2[5];
    v30[5] = bswap32(v14);
    v22 = a2[4];
    v31[0] = bswap32(v19);
    v23 = a2[1];
    v24 = *a2;
    v30[6] = bswap32(v16);
    v25 = a2[3];
    v30[7] = bswap32(v18);
    v26 = a2[2];
    v30[1] = bswap32(v12);
    v31[7] = bswap32(v24);
    v31[3] = bswap32(v22);
    v31[4] = bswap32(v25);
    v31[5] = bswap32(v26);
    v31[6] = bswap32(v23);
    v31[1] = bswap32(v20);
    v31[2] = bswap32(v21);
    v27 = sub_29688((int)v30, 32);
    v28 = sub_29688((int)v31, 32);
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      v29 = "no (false positive; hash > target)";
      if ( v10 )
        v29 = "YES (hash <= target)";
      snprintf(s, 0x1000u, " Proof: %s\nTarget: %s\nTrgVal? %s", v27, v28, v29);
      sub_385C8(7, s, 0);
    }
    free(v27);
    free(v28);
  }
  return v10;
}
