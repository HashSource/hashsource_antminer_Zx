int __fastcall sub_48B34(int a1)
{
  int v2; // lr
  int v3; // lr
  char v4; // r2
  int v5; // r1
  int result; // r0
  int *v7; // r2
  unsigned int v8; // r3
  int v9; // t1
  int v10; // r3
  int v11; // r2
  int v12; // r2
  int v13; // r10
  char *v14; // r9
  int v15; // t1
  int v16; // r8
  char v17; // r2
  int v18; // r8
  int v19; // r11
  int v20; // r12
  int v21; // [sp+18h] [bp-104Ch]
  char v22; // [sp+1Ch] [bp-1048h]
  int v23; // [sp+20h] [bp-1044h]
  int v24; // [sp+24h] [bp-1040h]
  int v25; // [sp+28h] [bp-103Ch]
  int v26; // [sp+2Ch] [bp-1038h]
  int v27; // [sp+30h] [bp-1034h]
  int v28; // [sp+34h] [bp-1030h]
  int v29; // [sp+38h] [bp-102Ch]
  int v30; // [sp+3Ch] [bp-1028h]
  int v31; // [sp+40h] [bp-1024h] BYREF
  int v32; // [sp+44h] [bp-1020h]
  int v33; // [sp+48h] [bp-101Ch]
  int v34; // [sp+4Ch] [bp-1018h]
  int v35; // [sp+50h] [bp-1014h]
  int v36; // [sp+54h] [bp-1010h]
  int v37; // [sp+58h] [bp-100Ch]
  int v38; // [sp+5Ch] [bp-1008h] BYREF
  char s[4064]; // [sp+60h] [bp-1004h] BYREF

  v23 = *(_DWORD *)(a1 + 1170);
  v24 = *(_DWORD *)(a1 + 1174);
  v25 = *(_DWORD *)(a1 + 1178);
  v26 = *(_DWORD *)(a1 + 1182);
  v27 = *(_DWORD *)(a1 + 1186);
  v28 = *(_DWORD *)(a1 + 1190);
  v29 = *(_DWORD *)(a1 + 1194);
  v30 = *(_DWORD *)(a1 + 1198);
  sub_3B5B8();
  sub_3B848();
  sub_3B998(26);
  if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
  {
    strcpy(s, "bitmain_ZCASH_init");
    sub_385C8(4, s, 0);
  }
  v31 = v23;
  v32 = v24;
  v33 = v25;
  v34 = v26;
  v2 = (unsigned __int8)dword_739B0;
  byte_9A4C7 = 1;
  v35 = v27;
  v36 = v28;
  v37 = v29;
  v38 = v30;
  strcpy((char *)&dword_759D0, "9.0.0.5");
  if ( (unsigned __int8)dword_739B0 <= 0x27u )
  {
    v2 = 40;
  }
  else if ( (unsigned __int8)dword_739B0 > 0x64u )
  {
    v3 = 6553600;
    v4 = 100;
    goto LABEL_7;
  }
  if ( byte_75F66 )
  {
    v3 = 6553600;
    v4 = 100;
  }
  else
  {
    v4 = v2;
    v3 = (100 - v2) | (v2 << 16);
  }
LABEL_7:
  byte_9A49E = v4;
  *(_DWORD *)(dword_75C50[0] + 132) = v3;
  sub_44DB4();
  v5 = (unsigned __int8)v31;
  if ( (unsigned __int8)v31 == 81 )
  {
    v7 = &v31;
    v8 = 255;
    while ( 1 )
    {
      v8 = (unsigned __int16)(*(_WORD *)&aResetAllHashBo[2 * (v5 ^ (v8 >> 8)) + 424] ^ ((_WORD)v8 << 8));
      if ( v7 == (int *)((char *)&v38 + 1) )
        break;
      v9 = *((unsigned __int8 *)v7 + 1);
      v7 = (int *)((char *)v7 + 1);
      v5 = v9;
    }
    if ( HIWORD(v38) == v8 )
    {
      v10 = 0;
      do
      {
        v11 = v10 + 28;
        ++v10;
        v12 = a1 + 4 * v11;
        *(_WORD *)(v12 + 6) = 0;
        *(_WORD *)(v12 + 8) = 0;
      }
      while ( v10 != 128 );
      sub_43D30();
      if ( byte_75C68 )
      {
        BYTE2(v34) = 50;
        dword_75C78 = (unsigned __int8)byte_9A49F;
        LOBYTE(v33) = v33 | 2;
      }
      sub_40A98();
      sub_40B80();
      sleep(1u);
      result = sub_40E7C();
      if ( result != -3 )
      {
        v22 = v33;
        dword_9A4CC = dword_9A4CC & 0xFF0000FF | 0x2CE00;
        sub_3A1EC();
        sub_2A884();
        sub_40C68();
        sub_2A884();
        sub_3E9FC(870);
        sub_2A884();
        sub_40DA4();
        sub_2A884();
        if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
        {
          snprintf(s, 0x1000u, "%s %d", "reset_all_hash_board_high", 4076);
          sub_385C8(5, s, 0);
        }
        v13 = 0;
        v14 = &byte_9A2B0;
        *(_DWORD *)(dword_75C50[0] + 52) = 0;
        sub_2A884();
        sub_43C74(a1);
        sleep(3u);
        sub_432BC(v32);
        sub_2A884();
        sub_45A7C();
        byte_9A4C6 = 1;
        sub_46EEC();
        sub_2A884();
        sleep(2u);
        sub_4821C(1);
        sub_2A884();
        do
        {
          v15 = (unsigned __int8)*v14++;
          if ( v15 == 1 )
          {
            v19 = 3;
            byte_76A24[v13] = 1;
            while ( 1 )
            {
              v20 = (unsigned __int8)v14[488];
              if ( v20 == 3 )
                break;
              v21 = (unsigned __int8)byte_77B70;
              byte_76A24[v13] = 1;
              if ( !v21 && !byte_75C48 && dword_73504 <= 4
                || (snprintf(
                      s,
                      0x1000u,
                      "recheck: chainid %d exist %d asicnum %d realnum %d",
                      v13,
                      (unsigned __int8)*(v14 - 1),
                      v20,
                      3),
                    sub_385C8(5, s, 0),
                    byte_76A24[v13]) )
              {
                sub_483A4(a1, (unsigned __int8)v13);
                if ( --v19 )
                  continue;
              }
              goto LABEL_40;
            }
            byte_76A24[v13] = 0;
          }
LABEL_40:
          ++v13;
        }
        while ( v13 != 4 );
        sub_43204(681);
        sub_45DE8();
        sub_434BC(dword_7399C);
        sub_2A884();
        sub_42318();
        sub_2A884();
        sub_42454(dword_739B4);
        sub_2A884();
        sub_45464();
        if ( (v22 & 4) != 0 )
        {
          dword_9A2B8 = 10000000;
          if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
          {
            snprintf(s, 0x1000u, "dev.timeout = %d us", 10000000);
            sub_385C8(5, s, 0);
          }
        }
        result = sub_48A54();
        if ( result != -7 )
        {
          v16 = BYTE2(v34);
          byte_9A4CB = (v33 & 2) != 0;
          LOBYTE(dword_9A4CC) = BYTE2(v34);
          if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
          {
            snprintf(s, 0x1000u, "%s: fan_eft : %d  fan_pwm : %d", "bitmain_ZCASH_init", (v33 & 2) != 0, BYTE2(v34));
            sub_385C8(5, s, 0);
          }
          if ( (v22 & 2) != 0 && (unsigned int)v16 <= 0x64 )
          {
            if ( v16 < 40 )
              v16 = 40;
            if ( byte_75F66 )
            {
              v18 = 6553600;
              v17 = 100;
            }
            else
            {
              v17 = v16;
              v18 = (100 - v16) | (v16 << 16);
            }
            byte_9A49E = v17;
            *(_DWORD *)(dword_75C50[0] + 132) = v18;
          }
          else
          {
            sub_45120();
          }
          result = sub_48598();
          if ( result != -8 )
          {
            sleep(1u);
            result = sub_48840((void *)a1);
            if ( result != -5 )
            {
              result = sub_4892C();
              if ( result != -6 )
              {
                sub_43668();
                byte_75F2C[0] = 1;
                byte_75F2D = 1;
                byte_75F2E = 1;
                byte_75F2F = 1;
                if ( byte_77B70 || (result = (unsigned __int8)byte_75C48, byte_75C48) || dword_73504 > 4 )
                {
                  snprintf(s, 0x1000u, "% done", "bitmain_ZCASH_init");
                  sub_385C8(5, s, 0);
                  return 0;
                }
              }
            }
          }
        }
      }
    }
    else if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
    {
      snprintf(
        s,
        0x1000u,
        "%s: config_parameter.crc = 0x%x, but we calculate it as 0x%x",
        "bitmain_ZCASH_init",
        HIWORD(v38),
        v8);
      sub_385C8(3, s, 0);
      return -2;
    }
    else
    {
      return -2;
    }
  }
  else if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
  {
    snprintf(
      s,
      0x1000u,
      "%s: config_parameter.token_type != 0x%x, it is 0x%x",
      "bitmain_ZCASH_init",
      81,
      (unsigned __int8)v31);
    sub_385C8(3, s, 0);
    return -1;
  }
  else
  {
    return -1;
  }
  return result;
}
