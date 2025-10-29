void __noreturn sub_43F14()
{
  int v0; // r3
  int v1; // r0
  int v2; // r3
  int v3; // r5
  int v4; // r4
  int v5; // t1
  int v6; // r12
  _DWORD *v7; // r4
  _DWORD *v8; // lr
  int v9; // r0
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r5
  unsigned int v14; // r7
  unsigned int v15; // r9
  int v16; // r6
  unsigned int v18; // r4
  int v19; // r12
  int v20; // r7
  int v21; // r12
  int v22; // r9
  unsigned int v24; // r4
  int v25; // r6
  _DWORD *v26; // r5
  unsigned int v27; // r4
  int v28; // r10
  int v29; // r3
  bool v30; // zf
  int v31; // r3
  int v32; // r3
  char *v33; // r3
  int v34; // r2
  int v35; // r4
  int v36; // r1
  int v37; // [sp+20h] [bp-1044h]
  int v38; // [sp+20h] [bp-1044h]
  int v39; // [sp+20h] [bp-1044h]
  int v40; // [sp+20h] [bp-1044h]
  int v41; // [sp+20h] [bp-1044h]
  int v42; // [sp+20h] [bp-1044h]
  char *v43; // [sp+24h] [bp-1040h]
  unsigned int v44; // [sp+2Ch] [bp-1038h]
  int v45; // [sp+30h] [bp-1034h]
  int v46; // [sp+38h] [bp-102Ch] BYREF
  int v47; // [sp+3Ch] [bp-1028h]
  struct timeval v48; // [sp+40h] [bp-1024h] BYREF
  struct timeval v49; // [sp+48h] [bp-101Ch] BYREF
  int v50; // [sp+50h] [bp-1014h]
  int v51; // [sp+54h] [bp-1010h]
  int v52; // [sp+58h] [bp-100Ch]
  int v53; // [sp+5Ch] [bp-1008h]
  char s[4064]; // [sp+60h] [bp-1004h] BYREF

  v47 = 0;
  v46 = 0;
  sub_2A7A4(&v48);
  sub_2A7A4(&v49);
  sub_2A488(&v46, &v48);
  sub_2A488(&dword_75F34, &v49);
  v51 = 0;
  v52 = 0;
  v50 = 0;
  v53 = 0;
  while ( 1 )
  {
    sub_2A7A4(&v48);
    sub_2A7A4(&v49);
    v2 = v48.tv_sec - v46;
    if ( v48.tv_usec - v47 < 0 )
      --v2;
    if ( v2 > 11999 )
    {
      sub_2A488(&v46, &v48);
LABEL_58:
      v6 = 631739;
      v7 = &unk_78F58;
      v50 = 0;
      v51 = 0;
      v52 = 0;
      v53 = 0;
      do
      {
        v8 = v7;
        v9 = *(_DWORD *)v6;
        v7 += 4;
        v10 = *(_DWORD *)(v6 + 4);
        v11 = *(_DWORD *)(v6 + 8);
        v12 = *(_DWORD *)(v6 + 12);
        v6 += 16;
        *v8 = v9;
        v8[1] = v10;
        v8[2] = v11;
        v8[3] = v12;
      }
      while ( (_UNKNOWN *)v6 != &unk_9A3EB );
      v13 = 0;
      v14 = 0;
      v15 = 0;
      v16 = 631471;
      do
      {
        if ( *(unsigned __int8 *)++v16 )
        {
          v15 += *(unsigned __int8 *)(v16 + 489);
          if ( *(_BYTE *)(v16 + 489) )
          {
            v18 = 0;
            do
            {
              v19 = *(_DWORD *)((char *)&unk_9A2A8 + 12 * v13 + 4 * v18 + 227);
              v14 += v19;
              if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
              {
                snprintf(s, 0x1000u, "%s: chain %d asic %d asic_nonce_num %d", "check_miner_status", v13, v18, v19);
                sub_385C8(7, s, 0);
              }
              ++v18;
            }
            while ( *(unsigned __int8 *)(v16 + 489) > v18 );
          }
        }
        ++v13;
      }
      while ( v13 != 4 );
      if ( v15 )
      {
        if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
        {
          snprintf(s, 0x1000u, "%s: avg_num %d asic_num %d", "check_miner_status", v14, v15);
          sub_385C8(7, s, 0);
        }
        v44 = (v14 / v15) >> 3;
      }
      else
      {
        v44 = 1;
      }
      v20 = 631471;
      v21 = 0;
      v22 = 0;
      while ( 2 )
      {
        if ( !*(unsigned __int8 *)++v20 )
          goto LABEL_115;
        v24 = *(unsigned __int8 *)(v20 + 489);
        if ( !*(_BYTE *)(v20 + 489) )
        {
          v45 = 8 * v22;
          goto LABEL_114;
        }
        v45 = 8 * v22;
        v25 = 0;
        v26 = (_DWORD *)((char *)&unk_78F58 + 12 * v22 + 48);
        v27 = 0;
        v43 = (char *)&unk_9A2A8 + 19 * v22;
LABEL_83:
        if ( (v27 & 7) == 0 )
        {
          v28 = v25 + v27;
          if ( v25 + v27 > 0x13 && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
          {
            v37 = v21;
            snprintf(s, 0x1000u, aAsicNumErrD, v25 + v27);
            sub_385C8(3, s, 0);
            v21 = v37;
          }
          ++v25;
          v43[v28 + 323] = 32;
        }
        if ( v44 >= *(_DWORD *)((char *)&unk_9A2A8 + 12 * v22 + 4 * v27 + 227) )
        {
          v29 = (unsigned __int8)byte_75C68;
          *v26 = 1;
          if ( v29 )
            goto LABEL_117;
          if ( v25 + v27 > 0x13 && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
          {
            v38 = v21;
            snprintf(s, 0x1000u, aAsicNumErrD, v25 + v27);
            sub_385C8(3, s, 0);
            v21 = v38;
          }
          v30 = byte_75C49 == 0;
          v31 = *(int *)((char *)&v50 + v21);
          v43[v25 + 323 + v27] = 120;
          *(int *)((char *)&v50 + v21) = v31 + 1;
          if ( !v30 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
          {
            v39 = v21;
            snprintf(
              s,
              0x1000u,
              "x chain%d asic%d nonce_num=%d avg_num=%d\n",
              v22,
              v27,
              *(_DWORD *)((char *)&unk_9A2A8 + 12 * v22 + 4 * v27 + 227),
              v44);
            sub_385C8(7, s, 0);
            v21 = v39;
          }
        }
        else
        {
          *v26 = 0;
LABEL_117:
          if ( v25 + v27 > 0x13 && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
          {
            v42 = v21;
            snprintf(s, 0x1000u, aAsicNumErrD, v25 + v27);
            sub_385C8(3, s, 0);
            v21 = v42;
          }
          v43[v25 + 323 + v27] = 111;
        }
        if ( v27 > 0x13 && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
        {
          v40 = v21;
          snprintf(s, 0x1000u, aAsicNumErrD, v27);
          sub_385C8(3, s, 0);
          v21 = v40;
        }
        v32 = 3 * v22 + v27++;
        ++v26;
        v33 = (char *)&unk_9A2A8 + 4 * v32 + 224;
        v34 = *((_DWORD *)v33 + 1);
        v33[3] = 0;
        *((_DWORD *)v33 + 1) = v34 & 0xFF000000;
        if ( *(unsigned __int8 *)(v20 + 489) <= v27 )
        {
          v24 = v25 + v27;
          if ( v24 > 0x13 && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
          {
            v41 = v21;
            snprintf(s, 0x1000u, aAsicNumErrD, v24);
            sub_385C8(3, s, 0);
            v21 = v41;
          }
LABEL_114:
          *((_BYTE *)&unk_9A2A8 + 2 * v45 + 2 * v22 + v22 + v24 + 323) = 0;
LABEL_115:
          ++v22;
          v21 += 4;
          if ( v22 == 4 )
          {
            pthread_mutex_lock(&stru_75F40);
            pthread_cond_signal(&stru_78EA0);
            pthread_mutex_unlock(&stru_75F40);
            memset(&unk_9A3BB, 0, 0x30u);
            memset(&unk_9A38B, 0, 0x30u);
            sub_2A488(&v46, &v48);
            goto LABEL_37;
          }
          continue;
        }
        goto LABEL_83;
      }
    }
    if ( v2 > 120 )
      goto LABEL_58;
LABEL_37:
    if ( dword_9A4AA > 80 || dword_9A4AE > 110 )
    {
      if ( (unsigned __int8)++byte_75F5C <= 2u )
      {
        if ( !byte_75C7C && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
        {
          snprintf(
            s,
            0x1000u,
            "Temperature pcb:%d/chip:%d is higher than %d/%d'C for %d time, PWM is %d",
            dword_9A4AA,
            dword_9A4AE,
            80,
            110,
            (unsigned __int8)byte_75F5C,
            (unsigned __int8)byte_9A49E);
          sub_385C8(3, s, 0);
        }
      }
      else
      {
        byte_75F5D = 1;
        if ( !byte_75C7C && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
        {
          snprintf(
            s,
            0x1000u,
            "%s: the temperature pcb:%d/chip:%d is too high, close PIC and need reboot!!!",
            "check_miner_status",
            dword_9A4AA,
            dword_9A4AE);
          sub_385C8(3, s, 0);
        }
      }
    }
    else
    {
      byte_75F5C = 0;
      byte_75F5D = 0;
    }
    v0 = v49.tv_sec - dword_75F34;
    if ( v49.tv_usec - dword_75F38 < 0 )
      --v0;
    if ( v0 > 120 )
    {
      byte_75F5E = 1;
      if ( !byte_75C7C && byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
      {
        snprintf(
          s,
          0x1000u,
          "%s: We have lost internet for %d seconds, so don't send work to hashboard anymore",
          "check_miner_status",
          v0);
        sub_385C8(7, s, 0);
      }
    }
    else
    {
      byte_75F5E = 0;
    }
    if ( (unsigned __int8)byte_9A4A0 <= 1u )
    {
      v35 = 1;
    }
    else
    {
      if ( dword_9A2BC == 1 )
      {
        if ( dword_9A471 < (unsigned int)((unsigned __int64)(12686672634000LL * (unsigned __int8)dword_9A4CC) >> 32) >> 6 )
        {
          v35 = 2;
          goto LABEL_124;
        }
        if ( byte_9A49E == 100 && (unsigned int)dword_9A471 <= 0x1517 )
          goto LABEL_158;
      }
      if ( dword_9A2BC != 2 )
        goto LABEL_21;
      if ( dword_9A475 >= (unsigned int)((unsigned __int64)(9092115387700LL * (unsigned __int8)dword_9A4CC) >> 32) >> 6 )
      {
        if ( byte_9A49E != 100 || (unsigned int)dword_9A475 > 0xF1D )
        {
LABEL_21:
          dword_75F60 = 0;
LABEL_22:
          byte_75F65 = 0;
          goto LABEL_23;
        }
LABEL_158:
        v35 = 4;
        goto LABEL_124;
      }
      v35 = 3;
    }
LABEL_124:
    v36 = ++dword_75F60;
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(
        s,
        0x1000u,
        "ret:%d [%d:%d]fan_error_num:%d fan_num %d fan_pwm %d fan_speed_value[0] %d fan_speed_value[1] %d",
        v35,
        dword_9A2BC == 1,
        dword_9A2BC == 2,
        v36,
        (unsigned __int8)byte_9A4A0,
        (unsigned __int8)dword_9A4CC,
        dword_9A471,
        dword_9A475);
      sub_385C8(7, s, 0);
      v36 = dword_75F60;
    }
    if ( v36 <= 10 )
      goto LABEL_22;
    byte_75F65 = 1;
    switch ( v35 )
    {
      case 3:
        if ( !byte_75C7C && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
        {
          snprintf(
            s,
            0x1000u,
            "Fan Err! Disable PIC! Fan2 speed is too low %d pwm %d ",
            dword_9A475,
            (unsigned __int8)byte_9A49E);
LABEL_151:
          sub_385C8(3, s, 0);
        }
        break;
      case 4:
        if ( !byte_75C7C && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
        {
          snprintf(
            s,
            0x1000u,
            "Fan Err! Disable PIC! Fan1:%d Fan2:%d pwm %d",
            dword_9A471,
            dword_9A475,
            (unsigned __int8)byte_9A49E);
          sub_385C8(3, s, 0);
        }
        break;
      case 2:
        if ( !byte_75C7C && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
        {
          snprintf(
            s,
            0x1000u,
            "Fan Err! Disable PIC! Fan1 speed is too low %d pwm %d ",
            dword_9A471,
            (unsigned __int8)byte_9A49E);
          goto LABEL_151;
        }
        break;
      default:
        if ( !byte_75C7C && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
        {
          snprintf(s, 0x1000u, "Fan Err! Disable PIC! Fan num is %d", (unsigned __int8)byte_9A4A0);
          sub_385C8(3, s, 0);
        }
        break;
    }
LABEL_23:
    if ( byte_75C68 )
      byte_75F5E = 0;
    if ( byte_75F64 || byte_75F5E || byte_75F5D || byte_75F65 || byte_75F66 )
    {
      v1 = 1;
      byte_75F30 = 1;
      if ( !byte_75F67 && (byte_75F5D || byte_75F65) )
      {
        v3 = 631471;
        v4 = 0;
        byte_75C7C = 1;
        byte_75F67 = 1;
        do
        {
          v5 = *(unsigned __int8 *)++v3;
          if ( v5 == 1 )
          {
            pthread_mutex_lock(&stru_75F10);
            dword_75EDC = v4;
            sub_3F4AC();
            sub_2A884();
            pthread_mutex_unlock(&stru_75F10);
          }
          ++v4;
        }
        while ( v4 != 4 );
        v1 = (unsigned __int8)byte_75F30;
      }
    }
    else
    {
      v1 = (unsigned __int8)byte_75F67;
      byte_75F30 = 0;
      byte_75C7C = 0;
      if ( byte_75F67 )
      {
        v1 = 1;
        byte_75F30 = 1;
        byte_75C7C = 1;
      }
    }
    sub_43E78(v1);
    sub_2A884();
  }
}
