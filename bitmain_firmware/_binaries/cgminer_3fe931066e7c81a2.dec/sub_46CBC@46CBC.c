int sub_46CBC()
{
  int v0; // r6
  int v1; // r1
  int v2; // r3
  int v3; // t1
  _DWORD *v4; // r5
  int i; // r4
  int v6; // t1
  int *v7; // lr
  int v8; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // lr
  const char *v14; // lr
  int v15; // r12
  int *v16; // r7
  int v17; // r10
  int v18; // r8
  int v19; // r4
  int v20; // r0
  int v21; // r1
  int v22; // r2
  int v23; // r3
  int *v24; // lr
  int v25; // r0
  int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r1
  int v30; // r2
  int v31; // r3
  FILE *v32; // r7
  int v33; // r11
  int v34; // t1
  int v35; // r5
  int *v36; // r6
  int v37; // r3
  int v38; // [sp+0h] [bp-103Ch] BYREF
  int v39; // [sp+Ch] [bp-1030h]
  int v40; // [sp+10h] [bp-102Ch] BYREF
  _DWORD v41[9]; // [sp+14h] [bp-1028h] BYREF
  int s; // [sp+38h] [bp-1004h] BYREF
  int v43; // [sp+3Ch] [bp-1000h]
  int v44; // [sp+40h] [bp-FFCh]
  int v45; // [sp+44h] [bp-FF8h]
  int v46; // [sp+48h] [bp-FF4h]
  int v47; // [sp+4Ch] [bp-FF0h]
  int v48; // [sp+50h] [bp-FECh]
  int v49; // [sp+54h] [bp-FE8h]
  int v50; // [sp+58h] [bp-FE4h]
  int v51; // [sp+5Ch] [bp-FE0h]
  int v52; // [sp+60h] [bp-FDCh]
  __int16 v53; // [sp+64h] [bp-FD8h]

  memset(v41, 0, 12);
  sub_40454();
  dword_7C130[0] = sub_46A48((int)v41);
  if ( dword_7C130[0] > 0 )
  {
    v0 = 644283;
    v1 = 0;
    v2 = 644283;
    while ( 1 )
    {
      v3 = *(unsigned __int8 *)++v2;
      if ( v3 == 1 && *((_BYTE *)&v38 + v1 + 20) != 78 )
        break;
      v1 += 9;
      if ( v1 == 36 )
      {
        v4 = v41;
        for ( i = 0; i != 4; ++i )
        {
          v6 = *(unsigned __int8 *)++v0;
          if ( v6 == 1 )
          {
            v15 = 0;
            v39 = v0;
            v16 = &dword_7C130[3 * i + 61];
            do
            {
              v17 = v15 + 1;
              v18 = *(_DWORD *)&aResetAllHashBo[16 * *((unsigned __int8 *)v4 + v15 + 1) + 2220];
              if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
              {
                snprintf((char *)&s, 0x1000u, "pic read chain%d asic%d freq %d\n", i, v15, v18);
                sub_38730(5, (const char *)&s, 0);
              }
              v15 = v17;
              if ( (unsigned int)(v18 - 775) <= 0x32 )
                *v16 = v18;
              else
                *v16 = 800;
              ++v16;
            }
            while ( v17 != 3 );
            v0 = v39;
          }
          v4 = (_DWORD *)((char *)v4 + 9);
        }
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
        {
          v7 = (int *)&unk_6B9E8;
          goto LABEL_11;
        }
        return sub_46964();
      }
    }
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      v14 = "1 Goto scan mode and find the best frequency\n";
      goto LABEL_34;
    }
    return sub_46880();
  }
  v19 = access("/config/chips_freq.config", 0);
  if ( !v19 )
  {
    v32 = fopen("/config/chips_freq.config", "r");
    if ( v32 )
    {
      v33 = 644283;
      do
      {
        v34 = *(unsigned __int8 *)++v33;
        if ( v34 == 1 )
        {
          v35 = 0;
          v36 = &dword_7C130[3 * v19 + 61];
          do
          {
            ++v35;
            v40 = 0;
            fscanf(v32, "%d", &v40);
            v37 = v40;
            if ( (unsigned int)(v40 - 775) >= 0x33 )
              v37 = 800;
            *v36++ = v37;
          }
          while ( v35 != 3 );
        }
        ++v19;
      }
      while ( v19 != 4 );
      fclose(v32);
    }
    else
    {
      if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 4 )
        return sub_46964();
      snprintf((char *)&s, 0x1000u, "open %s failed\n", "/config/chips_freq.config");
      sub_38730(5, (const char *)&s, 0);
    }
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      v7 = (int *)&unk_6BA58;
LABEL_11:
      v8 = *v7;
      v9 = v7[1];
      v10 = v7[2];
      v11 = v7[3];
      v12 = v7[4];
      s = v8;
      v43 = v9;
      v44 = v10;
      v45 = v11;
      LOWORD(v46) = v12;
      BYTE2(v46) = BYTE2(v12);
      sub_38730(5, (const char *)&s, 0);
    }
    return sub_46964();
  }
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    v14 = "2 Goto scan mode and find the best frequency\n";
LABEL_34:
    v20 = *(_DWORD *)v14;
    v21 = *((_DWORD *)v14 + 1);
    v22 = *((_DWORD *)v14 + 2);
    v23 = *((_DWORD *)v14 + 3);
    v24 = (int *)(v14 + 16);
    s = v20;
    v43 = v21;
    v44 = v22;
    v45 = v23;
    v25 = *v24;
    v26 = v24[1];
    v27 = v24[2];
    v28 = v24[3];
    v24 += 4;
    v46 = v25;
    v47 = v26;
    v48 = v27;
    v49 = v28;
    v29 = v24[1];
    v30 = v24[2];
    v31 = v24[3];
    v50 = *v24;
    v51 = v29;
    v52 = v30;
    v53 = v31;
    sub_38730(5, (const char *)&s, 0);
  }
  return sub_46880();
}
