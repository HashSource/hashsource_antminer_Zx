void __noreturn sub_44B5C()
{
  int v0; // r3
  int v1; // r3
  int v2; // r2
  int v3; // r0
  int v4; // r1
  int v5; // r5
  int v6; // r4
  unsigned int v7; // lr
  unsigned int v8; // lr
  int v9; // r0
  int v10; // r5
  int v11; // r4
  int v12; // t1
  int v13; // lr
  int v14; // r2
  int v15; // r1
  int v16; // r12
  _DWORD *v17; // r4
  _DWORD *v18; // lr
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r12
  _DWORD *v24; // r4
  _DWORD *v25; // lr
  int v26; // r0
  int v27; // r1
  int v28; // r2
  int v29; // r3
  int v30; // r5
  unsigned int v31; // r7
  unsigned int v32; // r9
  int v33; // r6
  unsigned int v35; // r4
  int v36; // r12
  int v37; // r7
  int v38; // r12
  int v39; // r9
  unsigned int v41; // r4
  int *v42; // r6
  int v43; // r5
  unsigned int v44; // r4
  int v45; // r10
  int v46; // r3
  bool v47; // zf
  int v48; // r3
  int v49; // r3
  char *v50; // r3
  int v51; // r2
  int v52; // [sp+24h] [bp-1048h]
  int v53; // [sp+24h] [bp-1048h]
  int v54; // [sp+24h] [bp-1048h]
  int v55; // [sp+24h] [bp-1048h]
  int v56; // [sp+24h] [bp-1048h]
  int v57; // [sp+24h] [bp-1048h]
  char *v58; // [sp+28h] [bp-1044h]
  unsigned int v59; // [sp+30h] [bp-103Ch]
  int v60; // [sp+34h] [bp-1038h]
  int v61; // [sp+40h] [bp-102Ch] BYREF
  int v62; // [sp+44h] [bp-1028h]
  struct timeval v63; // [sp+48h] [bp-1024h] BYREF
  struct timeval v64; // [sp+50h] [bp-101Ch] BYREF
  int v65; // [sp+58h] [bp-1014h]
  int v66; // [sp+5Ch] [bp-1010h]
  int v67; // [sp+60h] [bp-100Ch]
  int v68; // [sp+64h] [bp-1008h]
  char s[4056]; // [sp+68h] [bp-1004h] BYREF

  v62 = 0;
  v61 = 0;
  sub_2A84C(&v63);
  sub_2A84C(&v64);
  sub_2A530(&v61, &v63);
  sub_2A530(&dword_790F4, &v64);
  v66 = 0;
  v67 = 0;
  v65 = 0;
  v68 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      sub_2A84C(&v63);
      sub_2A84C(&v64);
      v0 = v63.tv_sec - v61;
      if ( v63.tv_usec - v62 < 0 )
        --v0;
      if ( v0 <= 11999 )
        break;
      sub_2A530(&v61, &v63);
      sub_2A92C();
    }
    if ( v0 > 120 )
      break;
LABEL_6:
    if ( dword_9D6D6 > 80 || dword_9D6DA > 110 )
    {
      if ( (unsigned __int8)++byte_7911C <= 2u )
      {
        if ( !byte_78E3C && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
        {
          snprintf(
            s,
            0x1000u,
            "Temperature pcb:%d/chip:%d is higher than %d/%d'C for %d time, PWM is %d",
            dword_9D6D6,
            dword_9D6DA,
            80,
            110,
            (unsigned __int8)byte_7911C,
            (unsigned __int8)byte_9D6CA);
          sub_38730(3, s, 0);
        }
      }
      else
      {
        byte_7911D = 1;
        if ( !byte_78E3C && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
        {
          snprintf(
            s,
            0x1000u,
            "%s: the temperature pcb:%d/chip:%d is too high, close PIC and need reboot!!!",
            "check_miner_status",
            dword_9D6D6,
            dword_9D6DA);
          sub_38730(3, s, 0);
        }
      }
    }
    else
    {
      byte_7911C = 0;
      byte_7911D = 0;
    }
    v1 = v64.tv_sec - dword_790F4;
    if ( v64.tv_usec - dword_790F8 < 0 )
      --v1;
    if ( v1 > 120 )
    {
      byte_7911E = 1;
      if ( !byte_78E3C && byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
      {
        snprintf(
          s,
          0x1000u,
          "%s: We have lost internet for %d seconds, so don't send work to hashboard anymore",
          "check_miner_status",
          v1);
        sub_38730(7, s, 0);
      }
    }
    else
    {
      byte_7911E = 0;
    }
    if ( (dword_9D4C8 & 1) != 0 )
    {
      v4 = 1;
      v2 = 0;
    }
    else
    {
      v2 = 1;
      while ( 1 )
      {
        v3 = dword_9D4C8 & (1 << v2);
        if ( v3 )
          break;
        if ( ++v2 == 32 )
        {
          v2 = -1;
          v4 = 0;
          goto LABEL_27;
        }
      }
      v4 = v2 + 1;
      if ( (unsigned int)(v2 + 1) > 0x1F )
      {
        v3 = 1;
LABEL_28:
        v4 = -1;
        v5 = 0;
        goto LABEL_29;
      }
    }
    v3 = 1;
    if ( (dword_9D4C8 & (1 << v4)) == 0 )
    {
LABEL_27:
      while ( (unsigned int)++v4 <= 0x1F )
      {
        if ( (dword_9D4C8 & (1 << v4)) != 0 )
          goto LABEL_91;
      }
      goto LABEL_28;
    }
LABEL_91:
    v5 = 1;
LABEL_29:
    if ( (unsigned __int8)byte_9D6CC > 1u )
    {
      if ( v3 )
      {
        v7 = *(_DWORD *)((char *)&unk_9D4B4 + 4 * v2 + 489);
        if ( v7 < (unsigned int)((unsigned __int64)(12686672634000LL * (unsigned __int8)dword_9D6F8) >> 32) >> 6 )
        {
          v6 = 2;
          goto LABEL_67;
        }
        if ( byte_9D6CA == 100 && v7 < 0x12C0 )
          goto LABEL_66;
      }
      if ( !v5 )
        goto LABEL_39;
      v8 = *(_DWORD *)((char *)&unk_9D4B4 + 4 * v4 + 489);
      if ( v8 >= (unsigned int)((unsigned __int64)(9092115387700LL * (unsigned __int8)dword_9D6F8) >> 32) >> 6 )
      {
        if ( byte_9D6CA != 100 || v8 >= 0xD70 )
        {
LABEL_39:
          dword_79120 = 0;
LABEL_40:
          byte_79125 = 0;
          goto LABEL_41;
        }
LABEL_66:
        v6 = 4;
        goto LABEL_67;
      }
      v6 = 3;
    }
    else
    {
      v6 = 1;
    }
LABEL_67:
    v13 = ++dword_79120;
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(
        s,
        0x1000u,
        "ret:%d [%d:%d]fan_error_num:%d fan_num %d fan_pwm %d fan1_speed_value %d fan2_speed_value %d",
        v6,
        v3,
        v5,
        v13,
        (unsigned __int8)byte_9D6CC,
        (unsigned __int8)dword_9D6F8,
        *(_DWORD *)((char *)&unk_9D4B4 + 4 * v2 + 489),
        *(_DWORD *)((char *)&unk_9D4B4 + 4 * v4 + 489));
      sub_38730(7, s, 0);
      v13 = dword_79120;
    }
    if ( v13 <= 20 )
      goto LABEL_40;
    v14 = 1;
    byte_79125 = 1;
    if ( (dword_9D4C8 & 1) == 0 )
    {
      while ( 1 )
      {
        v15 = dword_9D4C8 & (1 << v14);
        if ( v15 )
          break;
        if ( ++v14 == 32 )
        {
          v14 = -1;
          goto LABEL_78;
        }
      }
      v15 = v14 + 1;
      if ( v14 != 31 )
        goto LABEL_78;
      goto LABEL_82;
    }
    v15 = 1;
    v14 = 0;
LABEL_78:
    if ( (dword_9D4C8 & (1 << v15)) == 0 )
    {
      while ( (unsigned int)++v15 <= 0x1F )
      {
        if ( (dword_9D4C8 & (1 << v15)) != 0 )
          goto LABEL_83;
      }
LABEL_82:
      v15 = -1;
    }
LABEL_83:
    switch ( v6 )
    {
      case 3:
        if ( !byte_78E3C && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
        {
          snprintf(
            s,
            0x1000u,
            "Fan Err! Disable PIC! Fan2 speed is too low %d pwm %d ",
            *(_DWORD *)((char *)&unk_9D4B4 + 4 * v15 + 489),
            (unsigned __int8)byte_9D6CA);
LABEL_178:
          sub_38730(3, s, 0);
        }
        break;
      case 4:
        if ( !byte_78E3C && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
        {
          snprintf(
            s,
            0x1000u,
            "Fan Err! Disable PIC! Fan1:%d Fan2:%d pwm %d",
            *(_DWORD *)((char *)&unk_9D4B4 + 4 * v14 + 489),
            *(_DWORD *)((char *)&unk_9D4B4 + 4 * v15 + 489),
            (unsigned __int8)byte_9D6CA);
          sub_38730(3, s, 0);
        }
        break;
      case 2:
        if ( !byte_78E3C && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
        {
          snprintf(
            s,
            0x1000u,
            "Fan Err! Disable PIC! Fan1 speed is too low %d pwm %d ",
            *(_DWORD *)((char *)&unk_9D4B4 + 4 * v14 + 489),
            (unsigned __int8)byte_9D6CA);
          goto LABEL_178;
        }
        break;
      default:
        if ( !byte_78E3C && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
        {
          snprintf(s, 0x1000u, "Fan Err! Disable PIC! Fan num is %d", (unsigned __int8)byte_9D6CC);
          sub_38730(3, s, 0);
        }
        break;
    }
LABEL_41:
    if ( byte_78E28 )
      byte_7911E = 0;
    if ( byte_79124 || byte_7911E || byte_7911D || byte_79125 || byte_79126 )
    {
      v9 = 1;
      byte_790F0 = 1;
      if ( !byte_79127 && (byte_7911D || byte_79125) )
      {
        v10 = 644283;
        v11 = 0;
        byte_78E3C = 1;
        byte_79127 = 1;
        do
        {
          v12 = *(unsigned __int8 *)++v10;
          if ( v12 == 1 )
          {
            pthread_mutex_lock(&stru_790D0);
            dword_7909C = v11;
            sub_3FC24();
            sub_2A92C();
            pthread_mutex_unlock(&stru_790D0);
          }
          ++v11;
        }
        while ( v11 != 4 );
        v9 = (unsigned __int8)byte_790F0;
      }
    }
    else
    {
      v9 = (unsigned __int8)byte_79127;
      byte_790F0 = 0;
      byte_78E3C = 0;
      if ( byte_79127 )
      {
        v9 = 1;
        byte_790F0 = 1;
        byte_78E3C = 1;
      }
    }
    sub_44AC0(v9);
    sub_2A92C();
  }
  v16 = 644583;
  v17 = &unk_7C134;
  v65 = 0;
  v66 = 0;
  v67 = 0;
  v68 = 0;
  do
  {
    v18 = v17;
    v19 = *(_DWORD *)v16;
    v17 += 4;
    v20 = *(_DWORD *)(v16 + 4);
    v21 = *(_DWORD *)(v16 + 8);
    v22 = *(_DWORD *)(v16 + 12);
    v16 += 16;
    *v18 = v19;
    v18[1] = v20;
    v18[2] = v21;
    v18[3] = v22;
  }
  while ( (_UNKNOWN *)v16 != &unk_9D617 );
  v23 = 644535;
  v24 = &unk_7C164;
  do
  {
    v25 = v24;
    v26 = *(_DWORD *)v23;
    v24 += 4;
    v27 = *(_DWORD *)(v23 + 4);
    v28 = *(_DWORD *)(v23 + 8);
    v29 = *(_DWORD *)(v23 + 12);
    v23 += 16;
    *v25 = v26;
    v25[1] = v27;
    v25[2] = v28;
    v25[3] = v29;
  }
  while ( (_UNKNOWN *)v23 != &unk_9D5E7 );
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 644283;
  do
  {
    if ( *(unsigned __int8 *)++v33 )
    {
      v32 += *(unsigned __int8 *)(v33 + 521);
      if ( *(_BYTE *)(v33 + 521) )
      {
        v35 = 0;
        do
        {
          v36 = *(_DWORD *)((char *)&unk_9D4B4 + 12 * v30 + 4 * v35 + 259);
          v31 += v36;
          if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
          {
            snprintf(s, 0x1000u, "%s: chain %d asic %d asic_nonce_num %d", "check_miner_status", v30, v35, v36);
            sub_38730(7, s, 0);
          }
          ++v35;
        }
        while ( *(unsigned __int8 *)(v33 + 521) > v35 );
      }
    }
    ++v30;
  }
  while ( v30 != 4 );
  if ( v32 )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(s, 0x1000u, "%s: avg_num %d asic_num %d", "check_miner_status", v31, v32);
      sub_38730(7, s, 0);
    }
    v59 = (v31 / v32) >> 3;
  }
  else
  {
    v59 = 1;
  }
  v37 = 644283;
  v38 = 0;
  v39 = 0;
LABEL_123:
  if ( !*(unsigned __int8 *)++v37 )
    goto LABEL_158;
  v41 = *(unsigned __int8 *)(v37 + 521);
  if ( !*(_BYTE *)(v37 + 521) )
  {
    v60 = 8 * v39;
    goto LABEL_157;
  }
  v60 = 8 * v39;
  v42 = &dword_7C130[3 * v39 + 25];
  v43 = 0;
  v44 = 0;
  v58 = (char *)&unk_9D4B4 + 19 * v39;
  while ( 1 )
  {
    if ( (v44 & 7) == 0 )
    {
      v45 = v44 + v43;
      if ( v44 + v43 > 0x13 && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
      {
        v52 = v38;
        snprintf(s, 0x1000u, aAsicNumErrD, v44 + v43);
        sub_38730(3, s, 0);
        v38 = v52;
      }
      ++v43;
      v58[v45 + 355] = 32;
    }
    if ( v59 >= *(_DWORD *)((char *)&unk_9D4B4 + 12 * v39 + 4 * v44 + 259) )
    {
      v46 = (unsigned __int8)byte_78E28;
      *v42 = 1;
      if ( !v46 )
      {
        if ( v43 + v44 > 0x13 && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
        {
          v53 = v38;
          snprintf(s, 0x1000u, aAsicNumErrD, v43 + v44);
          sub_38730(3, s, 0);
          v38 = v53;
        }
        v47 = byte_78E09 == 0;
        v48 = *(int *)((char *)&v65 + v38);
        v58[v43 + 355 + v44] = 120;
        *(int *)((char *)&v65 + v38) = v48 + 1;
        if ( !v47 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
        {
          v54 = v38;
          snprintf(
            s,
            0x1000u,
            "x chain%d asic%d nonce_num=%d avg_num=%d\n",
            v39,
            v44,
            *(_DWORD *)((char *)&unk_9D4B4 + 12 * v39 + 4 * v44 + 259),
            v59);
          sub_38730(7, s, 0);
          v38 = v54;
        }
        goto LABEL_146;
      }
    }
    else
    {
      *v42 = 0;
    }
    if ( v43 + v44 > 0x13 && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
    {
      v57 = v38;
      snprintf(s, 0x1000u, aAsicNumErrD, v43 + v44);
      sub_38730(3, s, 0);
      v38 = v57;
    }
    v58[v43 + 355 + v44] = 111;
LABEL_146:
    if ( v44 > 0x13 && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
    {
      v55 = v38;
      snprintf(s, 0x1000u, aAsicNumErrD, v44);
      sub_38730(3, s, 0);
      v38 = v55;
    }
    v49 = 3 * v39 + v44++;
    ++v42;
    v50 = (char *)&unk_9D4B4 + 4 * v49 + 256;
    v51 = *((_DWORD *)v50 + 1);
    v50[3] = 0;
    *((_DWORD *)v50 + 1) = v51 & 0xFF000000;
    if ( *(unsigned __int8 *)(v37 + 521) <= v44 )
    {
      v41 = v43 + v44;
      if ( v41 > 0x13 && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
      {
        v56 = v38;
        snprintf(s, 0x1000u, aAsicNumErrD, v41);
        sub_38730(3, s, 0);
        v38 = v56;
      }
LABEL_157:
      *((_BYTE *)&unk_9D4B4 + 2 * v60 + 2 * v39 + v39 + v41 + 355) = 0;
LABEL_158:
      ++v39;
      v38 += 4;
      if ( v39 == 4 )
      {
        pthread_mutex_lock(&stru_79100);
        pthread_cond_signal(&stru_7C078);
        pthread_mutex_unlock(&stru_79100);
        memset(&unk_9D5E7, 0, 0x30u);
        memset(&unk_9D5B7, 0, 0x30u);
        sub_2A530(&v61, &v63);
        goto LABEL_6;
      }
      goto LABEL_123;
    }
  }
}
