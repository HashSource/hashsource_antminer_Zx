int __fastcall sub_49CC8(int a1)
{
  int *v2; // r3
  int v3; // r12
  int v4; // r1
  int v5; // t1
  _BYTE *v6; // r2
  _BYTE *v7; // r2
  int v8; // r1
  int v9; // r10
  int *v11; // r2
  unsigned int v12; // r3
  int v13; // t1
  int v14; // r3
  int v15; // r2
  int v16; // r2
  int v17; // r10
  char *v18; // r9
  int v19; // t1
  unsigned int v20; // r7
  _BOOL4 v21; // r1
  bool v22; // zf
  int v23; // r11
  int v24; // r3
  int v25; // r2
  char v26; // [sp+14h] [bp-1048h]
  int v27; // [sp+18h] [bp-1044h]
  int v28; // [sp+1Ch] [bp-1040h]
  int v29; // [sp+20h] [bp-103Ch]
  int v30; // [sp+24h] [bp-1038h]
  int v31; // [sp+28h] [bp-1034h]
  int v32; // [sp+2Ch] [bp-1030h]
  int v33; // [sp+30h] [bp-102Ch]
  int v34; // [sp+34h] [bp-1028h]
  int v35; // [sp+38h] [bp-1024h] BYREF
  int v36; // [sp+3Ch] [bp-1020h]
  int v37; // [sp+40h] [bp-101Ch]
  int v38; // [sp+44h] [bp-1018h]
  int v39; // [sp+48h] [bp-1014h]
  int v40; // [sp+4Ch] [bp-1010h]
  int v41; // [sp+50h] [bp-100Ch]
  int v42; // [sp+54h] [bp-1008h] BYREF
  char s[4072]; // [sp+58h] [bp-1004h] BYREF

  v27 = *(_DWORD *)(a1 + 1170);
  v28 = *(_DWORD *)(a1 + 1174);
  v29 = *(_DWORD *)(a1 + 1178);
  v30 = *(_DWORD *)(a1 + 1182);
  v31 = *(_DWORD *)(a1 + 1186);
  v32 = *(_DWORD *)(a1 + 1190);
  v33 = *(_DWORD *)(a1 + 1194);
  v34 = *(_DWORD *)(a1 + 1198);
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    strcpy(s, "z15 init...\n");
    sub_38730(5, s, 0);
  }
  sub_56A90();
  while ( 1 )
  {
    if ( dword_7B198 > 0 )
    {
      v2 = (int *)dword_7B438;
      v3 = 0;
      do
      {
        v5 = *v2++;
        v4 = v5;
        v6 = *(_BYTE **)(v5 + 196);
        if ( v6 )
        {
          if ( *v6 )
          {
            v7 = *(_BYTE **)(v4 + 204);
            if ( v7 )
            {
              if ( *v7 )
                ++v3;
            }
          }
        }
      }
      while ( v2 != (int *)(dword_7B438 + 4 * dword_7B198) );
      if ( v3 )
        break;
    }
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
    {
      strcpy(s, "No valid pools, please configure them first!!!");
      sub_38730(4, s, 0);
    }
    sleep(5u);
  }
  sub_3B704();
  sub_3BA70();
  sub_3BB44(26);
  v35 = v27;
  v36 = v28;
  v37 = v29;
  v38 = v30;
  byte_9D6F3 = 1;
  v39 = v31;
  v40 = v32;
  v41 = v33;
  v42 = v34;
  strcpy((char *)&dword_78B94, "9.0.0.5");
  sub_45B30();
  sub_45D88((unsigned __int8)dword_76B78);
  sub_45B50();
  v8 = (unsigned __int8)v27;
  if ( (unsigned __int8)v27 != 81 )
  {
    if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 2 )
      return -1;
    v9 = -1;
    snprintf(
      s,
      0x1000u,
      "%s: config_parameter.token_type != 0x%x, it is 0x%x",
      "bitmain_ZCASH_init",
      81,
      (unsigned __int8)v35);
LABEL_25:
    sub_38730(3, s, 0);
    return v9;
  }
  v11 = &v35;
  v12 = 255;
  while ( 1 )
  {
    v12 = (unsigned __int16)(*(_WORD *)&aResetAllHashBo[2 * (v8 ^ (v12 >> 8)) + 404] ^ ((_WORD)v12 << 8));
    if ( v11 == (int *)((char *)&v42 + 1) )
      break;
    v13 = *((unsigned __int8 *)v11 + 1);
    v11 = (int *)((char *)v11 + 1);
    v8 = v13;
  }
  if ( HIWORD(v42) != v12 )
  {
    if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 2 )
      return -2;
    v9 = -2;
    snprintf(
      s,
      0x1000u,
      "%s: config_parameter.crc = 0x%x, but we calculate it as 0x%x",
      "bitmain_ZCASH_init",
      HIWORD(v42),
      v12);
    goto LABEL_25;
  }
  v14 = 0;
  do
  {
    v15 = v14 + 28;
    ++v14;
    v16 = a1 + 4 * v15;
    *(_WORD *)(v16 + 6) = 0;
    *(_WORD *)(v16 + 8) = 0;
  }
  while ( v14 != 128 );
  sub_44978();
  if ( byte_78E28 )
  {
    BYTE2(v38) = 50;
    dword_78E38 = (unsigned __int8)byte_9D6CB;
    LOBYTE(v37) = v37 | 2;
  }
  sub_41308();
  sub_413F0();
  sleep(1u);
  v9 = sub_416EC();
  if ( v9 != -3 )
  {
    if ( !access("/tmp/delete_freq", 0) )
    {
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
      {
        strcpy(s, "delete freq data and scan freq again\n");
        sub_38730(5, s, 0);
      }
      memset(s, 0, 36);
      sub_46B94((unsigned __int8 *)s);
      system("rm /tmp/delete_freq");
      sleep(3u);
      exit(1);
    }
    v26 = v37;
    if ( (v37 & 8) == 0 )
      goto LABEL_45;
    v22 = (unsigned __int16)v39 == 800;
    if ( (unsigned __int16)v39 != 800 )
      v22 = (unsigned __int16)v39 == 0;
    if ( v22 )
LABEL_45:
      dword_9D6F8 = dword_9D6F8 & 0xFF0000FF | 0x32000;
    else
      *(_WORD *)((char *)&dword_9D6F8 + 1) = v39;
    sub_3A354();
    sub_2A92C();
    sub_414D8();
    sub_2A92C();
    sub_2A92C();
    sub_41614();
    sub_2A92C();
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(s, 0x1000u, "%s %d", "reset_all_hash_board_high", 4392);
      sub_38730(5, s, 0);
    }
    v17 = 0;
    v18 = &byte_9D4BC;
    *(_DWORD *)(dword_78E10[0] + 52) = 0;
    sub_2A92C();
    sub_448BC(a1);
    sleep(3u);
    sub_43F04(v36);
    sub_2A92C();
    sub_467B0();
    byte_9D6F2 = 1;
    sub_481B4();
    sub_2A92C();
    sleep(2u);
    sub_49578(1);
    sub_2A92C();
    do
    {
      v19 = (unsigned __int8)*v18++;
      if ( v19 == 1 )
      {
        v23 = 3;
        byte_79BF4[v17] = 1;
        while ( 1 )
        {
          v24 = (unsigned __int8)v18[520];
          if ( v24 == 3 )
            break;
          v25 = (unsigned __int8)byte_7AD48;
          byte_79BF4[v17] = 1;
          if ( !v25 && !byte_78E08 && dword_766C4 <= 4
            || (snprintf(
                  s,
                  0x1000u,
                  "recheck: chainid %d exist %d asicnum %d realnum %d",
                  v17,
                  (unsigned __int8)*(v18 - 1),
                  v24,
                  3),
                sub_38730(5, s, 0),
                byte_79BF4[v17]) )
          {
            sub_49700(a1, (unsigned __int8)v17);
            if ( --v23 )
              continue;
          }
          goto LABEL_52;
        }
        byte_79BF4[v17] = 0;
      }
LABEL_52:
      ++v17;
    }
    while ( v17 != 4 );
    sub_46CBC();
    sub_44104(dword_76B60);
    sub_2A92C();
    sub_43060();
    sub_2A92C();
    sub_432C0(dword_76B74);
    sub_2A92C();
    sub_4330C(0);
    sub_2A92C();
    sub_4614C();
    sub_463C8();
    sub_43594(0);
    if ( (v26 & 4) != 0 )
    {
      dword_9D4C4 = 100000000;
      if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 4 )
      {
        v20 = BYTE2(v38);
        byte_9D6F7 = (v37 & 2) != 0;
        v21 = (v37 & 2) != 0;
        LOBYTE(dword_9D6F8) = BYTE2(v38);
LABEL_58:
        if ( !byte_78E08 && dword_766C4 <= 4 )
        {
LABEL_61:
          if ( (v26 & 2) != 0 && v20 <= 0x64 )
            sub_45D88(v20);
          else
            sub_45EC0();
          v9 = sub_498F4();
          if ( v9 != -8 )
          {
            sleep(1u);
            sub_49BE8();
            if ( v9 != -7 )
            {
              v9 = sub_499D4((void *)a1);
              if ( v9 != -5 )
              {
                v9 = sub_49AC0();
                if ( v9 != -6 )
                {
                  sub_442B0();
                  byte_790EC[0] = 1;
                  byte_790ED = 1;
                  byte_790EE = 1;
                  byte_790EF = 1;
                  if ( byte_7AD48 || (v9 = (unsigned __int8)byte_78E08, byte_78E08) || dword_766C4 > 4 )
                  {
                    v9 = 0;
                    snprintf(s, 0x1000u, "%s done", "bitmain_ZCASH_init");
                    sub_38730(5, s, 0);
                  }
                }
              }
            }
          }
          return v9;
        }
LABEL_60:
        snprintf(s, 0x1000u, "%s: fan_eft : %d  fan_pwm : %d", "bitmain_ZCASH_init", v21, v20);
        sub_38730(5, s, 0);
        goto LABEL_61;
      }
      snprintf(s, 0x1000u, "dev.timeout = %d us", 100000000);
      sub_38730(5, s, 0);
    }
    v20 = BYTE2(v38);
    byte_9D6F7 = (v37 & 2) != 0;
    v21 = (v37 & 2) != 0;
    LOBYTE(dword_9D6F8) = BYTE2(v38);
    if ( byte_7AD48 )
      goto LABEL_60;
    goto LABEL_58;
  }
  return v9;
}
