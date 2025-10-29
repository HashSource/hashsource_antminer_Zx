int __fastcall sub_4A754(int a1, int a2, int a3, int a4, char a5)
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
  int v23; // r4
  int v24; // r0
  int v25; // r3
  int v26; // r2
  int v27; // r0
  int v28; // r3
  int v29; // r3
  int v30; // r0
  char *v31; // r5
  char *v32; // r7
  int v33; // r1
  void *v34; // r0
  unsigned int v35; // r6
  char *v36; // r12
  __int16 s1; // [sp+16h] [bp-1006h] BYREF
  char s[4072]; // [sp+18h] [bp-1004h] BYREF

  v6 = *(_BYTE *)(a3 + 3) / (unsigned __int8)byte_9D6F3;
  v7 = v6;
  if ( v6 > 2u )
  {
    if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 3 )
      return -1;
    snprintf(s, 0x1000u, "%s chipid %d is not exist", "nonce_handle", v6);
LABEL_6:
    sub_38730(4, s, 0);
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
        v13 = (unsigned __int16)(*(_WORD *)&aResetAllHashBo[2 * (v15 ^ (v13 >> 8)) + 404] ^ ((_WORD)v13 << 8));
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
                while ( 1 )
                {
                  v27 = *(unsigned __int8 *)(v26 + 93);
                  ++v23;
                  v26 += 91;
                  if ( v27 != v25 )
                    break;
                  if ( v23 == 15 )
                  {
                    v29 = *(unsigned __int8 *)(v10 + 3);
                    while ( 1 )
                    {
                      v30 = *(unsigned __int8 *)(v21 + 94);
                      v21 += 91;
                      if ( v30 != v29 )
                        break;
                      if ( !--v23 )
                      {
                        v31 = (char *)(a1 + 1357 * v7);
                        v32 = v31;
                        do
                        {
                          v33 = v10 + 91 * v23;
                          v34 = v32;
                          ++v23;
                          v32 += 85;
                          memcpy(v34, (const void *)(v33 + 4), 0x55u);
                        }
                        while ( v23 != 15 );
                        memcpy(v31 + 1275, (const void *)(v10 + 1369), 0x45u);
                        *((_DWORD *)v31 + 338) = *(_DWORD *)(v10 + 1450);
                        v31[1344] = *(_BYTE *)(v10 + 1366);
                        v31[1345] = *(_BYTE *)(v10 + 1367);
                        v31[1346] = *(_BYTE *)(v10 + 1368);
                        v31[1347] = *(_BYTE *)(v10 + 1441);
                        *((_DWORD *)v31 + 337) = *(_DWORD *)(v10 + 1442);
                        pthread_mutex_lock(&stru_78E88);
                        v35 = dword_7C28C;
                        v36 = (char *)&dword_7C28C + 1357 * dword_7C28C;
                        v36[1368] = a5;
                        v36[1356] = v31[1344];
                        v36[1357] = v31[1345] & 0x7F;
                        v36[1358] = v31[1346];
                        v36[1359] = v31[1347];
                        *((_DWORD *)v36 + 340) = *((_DWORD *)v31 + 337);
                        *((_DWORD *)v36 + 341) = *((_DWORD *)v31 + 338);
                        memcpy(v36 + 12, v31, 0x540u);
                        if ( v35 > 0x62 )
                          dword_7C28C = 0;
                        else
                          dword_7C28C = v35 + 1;
                        if ( (unsigned int)dword_7C294 > 0x63 )
                        {
                          dword_7C294 = 100;
                          if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
                          {
                            snprintf(s, 0x1000u, "%s: nonce fifo full!!!", "nonce_handle");
                            sub_38730(4, s, 0);
                          }
                        }
                        else
                        {
                          ++dword_7C294;
                        }
                        pthread_mutex_unlock(&stru_78E88);
                        return 0;
                      }
                    }
                    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
                    {
                      snprintf(s, 0x1000u, "nonceID is different %02x != %02x chipid=%d\n", v29, v30, v7);
                      goto LABEL_28;
                    }
                    goto LABEL_30;
                  }
                }
                if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
                {
                  snprintf(s, 0x1000u, "workID is different %02x != %02x\n", v25, v27);
                  goto LABEL_28;
                }
                goto LABEL_30;
              }
            }
            if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
            {
              snprintf(s, 0x1000u, "chip_addr is different %02x != %02x\n", v20, v24);
              goto LABEL_28;
            }
            goto LABEL_30;
          }
        }
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
        {
          snprintf(s, 0x1000u, "nonce is not continous i=%d\n", v18);
          goto LABEL_28;
        }
        goto LABEL_30;
      }
    }
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
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
      sub_38730(3, s, 0);
      if ( byte_7AD48 )
        goto LABEL_31;
    }
    if ( byte_78E08 )
      goto LABEL_31;
LABEL_30:
    if ( dword_766C4 <= 3 )
      return -1;
LABEL_31:
    v28 = dword_79BFC++;
    snprintf(s, 0x1000u, "receive a error nonce. total = %u", v28);
    goto LABEL_6;
  }
  return 1;
}
