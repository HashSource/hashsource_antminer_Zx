int __fastcall sub_49464(int a1, int a2, int a3, int a4, char a5)
{
  unsigned __int8 v6; // r0
  int v7; // r5
  int v9; // r8
  int v10; // r6
  int v11; // r10
  unsigned __int8 *v12; // r2
  unsigned int v13; // r3
  unsigned __int8 *v14; // r0
  int v15; // t1
  int v16; // r11
  int v17; // r2
  int v18; // r3
  char v19; // r1
  int v20; // r3
  int v21; // r1
  int v22; // r2
  int v23; // r12
  int v24; // r0
  int v25; // r3
  int v26; // r0
  int v27; // r2
  int v28; // r12
  int v29; // r3
  int v30; // r3
  int v31; // r0
  int v32; // r4
  char *v33; // r5
  char *v34; // r7
  int v35; // r1
  void *v36; // r0
  unsigned int v37; // r6
  char *v38; // r12
  __int16 s1; // [sp+16h] [bp-1006h] BYREF
  char s[4072]; // [sp+18h] [bp-1004h] BYREF

  v6 = *(_BYTE *)(a3 + 3) / (unsigned __int8)byte_9A4C7;
  v7 = v6;
  if ( v6 > 2u )
  {
    if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 3 )
      return -1;
    snprintf(s, 0x1000u, "%s chipid %d is not exist", "nonce_handle", v6);
LABEL_6:
    sub_385C8(4, s, 0);
    return -1;
  }
  v9 = *(_BYTE *)(a3 + 2) & 0xF;
  v10 = a2 + 1456 * v6;
  memcpy((void *)(v10 + 91 * v9), (const void *)(a3 + 2), 0x5Bu);
  if ( v9 == 15 )
  {
    v11 = 0;
    while ( 1 )
    {
      v12 = (unsigned __int8 *)(v10 + 91 * v11);
      v13 = 0xFFFF;
      v14 = v12 + 89;
      do
      {
        v15 = *v12++;
        v13 = (unsigned __int16)(*(_WORD *)&aResetAllHashBo[2 * (v15 ^ (v13 >> 8)) + 424] ^ ((_WORD)v13 << 8));
      }
      while ( v12 != v14 );
      v16 = (unsigned __int16)((v13 >> 8) | ((_WORD)v13 << 8));
      s1 = (v13 >> 8) | ((_WORD)v13 << 8);
      if ( memcmp(&s1, (const void *)(v10 + 91 * v11 + 89), 2u) )
        break;
      if ( ++v11 == 16 )
      {
        v17 = 0;
        v18 = 0;
        while ( 1 )
        {
          v19 = *(_BYTE *)(v10 + v17);
          v17 += 91;
          if ( v18 != (v19 & 0xF) )
            break;
          if ( ++v18 == 16 )
          {
            v20 = *(unsigned __int8 *)(v10 + 1);
            v21 = v10;
            v22 = v10;
            v23 = 15;
            while ( 1 )
            {
              v24 = *(unsigned __int8 *)(v22 + 92);
              v22 += 91;
              if ( v24 != v20 )
                break;
              if ( !--v23 )
              {
                v25 = *(unsigned __int8 *)(v10 + 2);
                v26 = v10;
                v27 = 15;
                while ( 1 )
                {
                  v28 = *(unsigned __int8 *)(v26 + 93);
                  v26 += 91;
                  if ( v28 != v25 )
                    break;
                  if ( !--v27 )
                  {
                    v30 = *(unsigned __int8 *)(v10 + 3);
                    while ( 1 )
                    {
                      v31 = *(unsigned __int8 *)(v21 + 94);
                      ++v27;
                      v21 += 91;
                      if ( v31 != v30 )
                        break;
                      if ( v27 == 15 )
                      {
                        v32 = 0;
                        v33 = (char *)(a1 + 1357 * v7);
                        v34 = v33;
                        do
                        {
                          v35 = v10 + 91 * v32;
                          v36 = v34;
                          ++v32;
                          v34 += 85;
                          memcpy(v36, (const void *)(v35 + 4), 0x55u);
                        }
                        while ( v32 != 15 );
                        memcpy(v33 + 1275, (const void *)(v10 + 1369), 0x45u);
                        *((_DWORD *)v33 + 338) = *(_DWORD *)(v10 + 1450);
                        v33[1344] = *(_BYTE *)(v10 + 1366);
                        v33[1345] = *(_BYTE *)(v10 + 1367);
                        v33[1346] = *(_BYTE *)(v10 + 1368);
                        v33[1347] = *(_BYTE *)(v10 + 1441);
                        *((_DWORD *)v33 + 337) = *(_DWORD *)(v10 + 1442);
                        pthread_mutex_lock(&stru_75CC8);
                        v37 = dword_79080;
                        v38 = (char *)&dword_79080 + 1357 * dword_79080;
                        v38[1368] = a5;
                        v38[1356] = v33[1344];
                        v38[1357] = v33[1345] & 0x7F;
                        v38[1358] = v33[1346];
                        v38[1359] = v33[1347];
                        *((_DWORD *)v38 + 340) = *((_DWORD *)v33 + 337);
                        *((_DWORD *)v38 + 341) = *((_DWORD *)v33 + 338);
                        memcpy(v38 + 12, v33, 0x540u);
                        if ( v37 > 0x62 )
                          dword_79080 = 0;
                        else
                          dword_79080 = v37 + 1;
                        if ( (unsigned int)dword_79088 > 0x63 )
                        {
                          dword_79088 = 100;
                          if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
                          {
                            snprintf(s, 0x1000u, "%s: nonce fifo full!!!", "nonce_handle");
                            sub_385C8(4, s, 0);
                          }
                          pthread_mutex_unlock(&stru_75CC8);
                          sub_48470();
                          return 0;
                        }
                        else
                        {
                          ++dword_79088;
                          pthread_mutex_unlock(&stru_75CC8);
                          return 0;
                        }
                      }
                    }
                    if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
                    {
                      snprintf(s, 0x1000u, "nonceID is different %02x != %02x chipid=%d\n", v30, v31, v7);
                      goto LABEL_28;
                    }
                    goto LABEL_30;
                  }
                }
                if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
                {
                  snprintf(s, 0x1000u, "workID is different %02x != %02x\n", v25, v28);
                  goto LABEL_28;
                }
                goto LABEL_30;
              }
            }
            if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
            {
              snprintf(s, 0x1000u, "chip_addr is different %02x != %02x\n", v20, v24);
              goto LABEL_28;
            }
            goto LABEL_30;
          }
        }
        if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
        {
          snprintf(s, 0x1000u, "nonce is not continous i=%d\n", v18);
          goto LABEL_28;
        }
        goto LABEL_30;
      }
    }
    if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
    {
      snprintf(
        s,
        0x1000u,
        "%s CRC error. cal-crc=%x, chip-crc=%02x%02x\n",
        "bm1740_verify_nonce_integrality",
        v16,
        *(unsigned __int8 *)(v10 + 91 * v11 + 89),
        *(unsigned __int8 *)(v10 + 91 * v11 + 90));
LABEL_28:
      sub_385C8(3, s, 0);
      if ( byte_77B70 )
        goto LABEL_31;
    }
    if ( byte_75C48 )
      goto LABEL_31;
LABEL_30:
    if ( dword_73504 <= 3 )
      return -1;
LABEL_31:
    v29 = dword_76A2C++;
    snprintf(s, 0x1000u, "receive a error nonce. total = %u", v29);
    goto LABEL_6;
  }
  return 1;
}
