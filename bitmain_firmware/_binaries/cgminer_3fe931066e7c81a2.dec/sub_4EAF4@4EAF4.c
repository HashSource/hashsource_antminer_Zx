int __fastcall sub_4EAF4(void *a1, unsigned int a2)
{
  int v4; // r11
  int *v5; // r6
  _DWORD *v6; // r5
  unsigned int v7; // t1
  signed int v8; // r8
  int v9; // lr
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // r0
  _BYTE *v17; // r0
  int v18; // r10
  int v19; // r8
  size_t v20; // r11
  unsigned int v21; // r7
  int v22; // r9
  int v23; // r6
  int v24; // r5
  int v25; // r3
  int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r10
  char *v30; // r0
  size_t v31; // r10
  _BYTE *v33; // r2
  int v34; // r3
  char *s; // [sp+8h] [bp-894h]
  size_t n; // [sp+Ch] [bp-890h]
  int v38; // [sp+10h] [bp-88Ch]
  size_t v39; // [sp+18h] [bp-884h]
  unsigned int v40; // [sp+30h] [bp-86Ch]
  _BYTE *dest; // [sp+34h] [bp-868h]
  int v42; // [sp+38h] [bp-864h]
  size_t v43; // [sp+3Ch] [bp-860h]
  _DWORD v44[7]; // [sp+44h] [bp-858h] BYREF
  __int16 v45; // [sp+60h] [bp-83Ch]
  _DWORD v46[7]; // [sp+64h] [bp-838h] BYREF
  __int16 v47; // [sp+80h] [bp-81Ch]
  int v48; // [sp+94h] [bp-808h] BYREF
  _DWORD v49[513]; // [sp+98h] [bp-804h] BYREF

  v4 = 0;
  v5 = &v48;
  dest = malloc(0x4400u);
  v6 = dest + 30;
  s = (char *)malloc(0x4400u);
  memset(v49, 0, 0x800u);
  sub_4DF94(a2, 1344, (int)v49, 2048, 0x15u, 1u);
  do
  {
    v7 = v5[1];
    ++v5;
    v8 = bswap32(v7);
    sub_4DF30(a1, v8 / 2, v46, 0x32u);
    sub_4DF94((unsigned int)v46 + 25 * (v8 % 2), 25, (int)v44, 30, 0x14u, 0);
    v9 = (int)v6 - 30;
    v10 = v44[1];
    v11 = v44[2];
    v12 = v44[3];
    *(_DWORD *)((char *)v6 - 30) = v44[0];
    *(_DWORD *)((char *)v6 - 26) = v10;
    *(_DWORD *)((char *)v6 - 22) = v11;
    v13 = v44[4];
    v14 = v44[5];
    v15 = v44[6];
    *(_DWORD *)((char *)v6 - 18) = v12;
    *(_DWORD *)((char *)v6 - 14) = v13;
    LOWORD(v12) = v45;
    v16 = v49[v4++];
    *(_DWORD *)((char *)v6 - 10) = v14;
    *((_WORD *)v6 - 1) = v12;
    *(_DWORD *)((char *)v6 - 6) = v15;
    *v6 = v16;
    v6 = (_DWORD *)((char *)v6 + 34);
    v17 = sub_29730(v9, 34);
    free(v17);
  }
  while ( v4 != 512 );
  v18 = 30;
  v19 = 512;
  v20 = 4;
  n = 27;
  while ( 1 )
  {
    v40 = v19;
    if ( v19 )
    {
      v42 = 2 * v20;
      v19 = 0;
      v21 = 0;
      v39 = v18 + v20;
      v22 = v18;
      v23 = (int)&dest[v18 + v20];
      v24 = (int)dest;
      v38 = 2 * (v18 + v20);
      v43 = n;
      while ( 1 )
      {
        v25 = 0;
        do
        {
          v26 = *(unsigned __int8 *)(v24 + v25);
          v27 = *(unsigned __int8 *)(v23 + v25++);
          if ( v26 != v27 )
          {
            puts("Invalid solution: invalid collision length between StepRows");
            goto LABEL_18;
          }
        }
        while ( v25 != 3 );
        if ( sub_4EA38(v23, v24, v22, v20) )
        {
          puts("Invalid solution: Index tree incorrectly ordered");
          goto LABEL_18;
        }
        if ( !sub_4EA58(v24, v23, v22, v20) )
          break;
        v28 = 0;
        memset(v46, 0, sizeof(v46));
        v47 = 0;
        do
        {
          *((_BYTE *)v46 + v28) = *(_BYTE *)(v23 + v28) ^ *(_BYTE *)(v24 + v28);
          ++v28;
        }
        while ( v28 < v22 );
        ++v19;
        v29 = (2 * v20 + n) * (v21 >> 1);
        v21 = 2 * v19;
        v23 += v38;
        v30 = &s[v29];
        v31 = n + v29;
        memcpy(v30, (char *)v46 + 3, n);
        memcpy(&s[v31], (const void *)(v22 + v24), v20);
        memcpy(&s[v31 + v20], (const void *)(v22 + v39 + v24), v20);
        v24 += v38;
        if ( v40 <= 2 * v19 )
        {
          v18 = v22;
          goto LABEL_15;
        }
      }
      puts("Invalid solution: duplicate indices");
      free(dest);
      free(s);
      return 1;
    }
    v42 = 2 * v20;
    v43 = n;
LABEL_15:
    v18 -= 3;
    memcpy(dest, s, 0x4400u);
    memset(s, 0, 0x4400u);
    n -= 3;
    if ( v18 == 3 )
      break;
    v20 = v42;
  }
  if ( v43 )
  {
    v33 = dest;
    v34 = (unsigned __int8)*dest;
    if ( *dest )
    {
LABEL_18:
      free(dest);
      free(s);
      return 2;
    }
    while ( ++v34 != v43 )
    {
      if ( *++v33 )
        goto LABEL_18;
    }
  }
  free(dest);
  free(s);
  return 0;
}
