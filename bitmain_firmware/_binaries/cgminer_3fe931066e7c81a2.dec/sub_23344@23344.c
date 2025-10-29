void __noreturn sub_23344()
{
  double v0; // d0
  int v1; // r4
  int v2; // r0
  int v3; // r5
  int v4; // r3
  int v5; // r6
  __time_t tv_sec; // r2
  int v7; // r3
  int v8; // r0
  int v9; // r5
  int v10; // r7
  int v11; // r3
  int v12; // r1
  int v13; // r1
  int v14; // r3
  int v15; // r4
  int *v16; // r3
  int v17; // r1
  int v18; // t1
  int v19; // r2
  int v20; // r4
  int v21; // r5
  bool v22; // cc
  int v23; // r1
  int v24; // r1
  int v25; // r3
  int v26; // r2
  bool v27; // zf
  int v28; // r0
  int v29; // r5
  int v30; // r6
  int v31; // r8
  int v32; // r0
  int v33; // r6
  char *v34; // r0
  const char *v35; // r1
  int v36; // r8
  int v37; // r10
  int v38; // r1
  double v39; // d8
  WINDOW *v40; // r0
  __int64 v41; // d11
  const char *v42; // r3
  size_t v43; // r0
  int v44; // r3
  const char *v45; // r3
  int v46; // r3
  double v47; // r0
  double v48; // d11
  unsigned __int64 v49; // r0
  unsigned __int64 v50; // r0
  double v51; // r0
  int v52; // r5
  int v53; // r2
  int v54; // r2
  int v55; // r0
  int v56; // r1
  double v57; // r0
  double v58; // d12
  int v59; // r6
  double v60; // d11
  double v61; // r0
  double v62; // d8
  int v63; // r0
  const char *v64; // r3
  double v65; // r0
  double v66; // r0
  unsigned __int64 v67; // r0
  unsigned __int64 v68; // r0
  double v69; // r0
  double v70; // r0
  double v71; // r0
  double v72; // r0
  double v73; // [sp+0h] [bp-1194h]
  double v74; // [sp+8h] [bp-118Ch]
  int v75; // [sp+10h] [bp-1184h]
  int v76; // [sp+44h] [bp-1150h]
  struct timeval v77; // [sp+5Ch] [bp-1138h] BYREF
  char dest[12]; // [sp+64h] [bp-1130h] BYREF
  char v79[16]; // [sp+70h] [bp-1124h] BYREF
  struct timeval v80[2]; // [sp+80h] [bp-1114h] BYREF
  char s[256]; // [sp+90h] [bp-1104h] BYREF
  _DWORD v82[1020]; // [sp+190h] [bp-1004h] BYREF

  pthread_setcanceltype(1, 0);
  sub_2F0B4("Watchdog");
  sub_120F4();
  sub_2A84C((struct timeval *)&dword_77310);
LABEL_2:
  while ( 1 )
  {
    sleep(2u);
    sub_22F88();
    sub_1BBA4(-1, 0);
    if ( sub_17FE4() )
      break;
LABEL_3:
    sub_2A84C(v80);
    if ( byte_7B194 )
      goto LABEL_181;
    if ( !sub_118D4() )
    {
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
      {
        snprintf(
          (char *)v82,
          0x1000u,
          "Pausing execution as per stop time %02d:%02d scheduled",
          dword_7B5FC,
          dword_7B5F8);
        sub_38730(4, (const char *)v82, 0);
      }
      v15 = (unsigned __int8)byte_7B874;
      if ( !byte_7B874 )
      {
        strcpy((char *)v82, "Terminating execution as planned");
        sub_38730(3, (const char *)v82, 1);
        sub_16CA8(v15);
      }
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
      {
        snprintf((char *)v82, 0x1000u, "Will restart execution as scheduled at %02d:%02d", dword_7B880, dword_7B87C);
        sub_38730(4, (const char *)v82, 0);
      }
      byte_7B194 = 1;
      if ( pthread_rwlock_rdlock(&rwlock) )
        sub_B69C("watchdog_thread", 9721);
      if ( dword_7BB6C > 0 )
      {
        v16 = (int *)dword_7B5E0;
        v17 = dword_7B5E0 + 4 * dword_7BB6C;
        do
        {
          v18 = *v16++;
          *(_BYTE *)(v18 + 60) = 1;
        }
        while ( v16 != (int *)v17 );
      }
      if ( pthread_rwlock_unlock(&rwlock) )
        sub_B630("watchdog_thread", 9724);
      off_75ED8();
      goto LABEL_22;
    }
    if ( byte_7B194 )
    {
LABEL_181:
      if ( sub_118D4() )
      {
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
        {
          snprintf(
            (char *)v82,
            0x1000u,
            "Restarting execution as per start time %02d:%02d scheduled",
            dword_7B880,
            dword_7B87C);
          sub_38730(4, (const char *)v82, 0);
        }
        if ( byte_7B5F0 && (byte_7AD48 || byte_78E08 || dword_766C4 > 3) )
        {
          snprintf((char *)v82, 0x1000u, "Will pause execution as scheduled at %02d:%02d", dword_7B5FC, dword_7B5F8);
          sub_38730(4, (const char *)v82, 0);
        }
        v1 = 0;
        byte_7B194 = 0;
        while ( dword_7BB6C > v1 )
        {
          v2 = v1++;
          v3 = sub_1B124(v2);
          if ( *(_DWORD *)(*(_DWORD *)(v3 + 36) + 32) != 1 )
          {
            v4 = (unsigned __int8)byte_78E09;
            *(_BYTE *)(v3 + 60) = 0;
            if ( v4 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
            {
              snprintf((char *)v82, 0x1000u, "Pushing sem post to thread %d", *(_DWORD *)v3);
              sub_38730(7, (const char *)v82, 0);
            }
            sub_2F1BC((sem_t *)(v3 + 16), "cgminer.c", "watchdog_thread", 9746);
          }
        }
      }
    }
LABEL_22:
    if ( dword_7B720 > 0 )
    {
      v5 = 0;
      while ( 1 )
      {
        v8 = sub_1B83C(v5);
        v9 = v8;
        v10 = **(_DWORD **)(v8 + 152);
        if ( !v10 )
          goto LABEL_35;
        (*(void (**)(void))(*(_DWORD *)(v8 + 4) + 32))();
        snprintf(s, 8u, "%s %d", *(const char **)(*(_DWORD *)(v9 + 4) + 8), *(_DWORD *)(v9 + 8));
        if ( *(_BYTE *)(v10 + 61) || *(_DWORD *)(v9 + 32) == 1 )
          goto LABEL_35;
        v11 = *(_DWORD *)(v9 + 96);
        v12 = *(_DWORD *)(v10 + 44);
        if ( v11 )
          break;
        tv_sec = v80[0].tv_sec;
        if ( v80[0].tv_sec - v12 <= 120 )
          goto LABEL_48;
        *(_QWORD *)(v9 + 48) = 0;
        v7 = (unsigned __int8)byte_7AD48;
        *(_DWORD *)(v9 + 96) = 1;
        if ( v7 || byte_78E08 || dword_766C4 > 2 )
        {
          snprintf((char *)v82, 0x1000u, "%s: Idle for more than 60 seconds, declaring SICK!", s);
          sub_38730(3, (const char *)v82, 0);
        }
        sub_2A84C((struct timeval *)(v10 + 52));
        sub_2ED88((_DWORD *)v9, 3);
        if ( !byte_75E0C )
          goto LABEL_35;
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
        {
          snprintf((char *)v82, 0x1000u, "%s: Attempting to restart", s);
          sub_38730(3, (const char *)v82, 0);
        }
LABEL_34:
        sub_16C88(v9);
LABEL_35:
        if ( dword_7B720 <= ++v5 )
          goto LABEL_2;
      }
      tv_sec = v80[0].tv_sec;
      v13 = v80[0].tv_sec - v12;
      if ( v13 <= 119 )
      {
        if ( v11 != 4 && (byte_7AD48 || byte_78E08 || dword_766C4 > 2) )
        {
          snprintf((char *)v82, 0x1000u, "%s: Recovered, declaring WELL!", s);
          sub_38730(3, (const char *)v82, 0);
        }
        *(_DWORD *)(v9 + 96) = 0;
        *(_DWORD *)(v9 + 240) = time(0);
        goto LABEL_35;
      }
      if ( v11 == 1 && v13 > 600 )
      {
        v14 = (unsigned __int8)byte_7AD48;
        *(_DWORD *)(v9 + 96) = 2;
        if ( v14 || byte_78E08 || dword_766C4 > 2 )
        {
          snprintf((char *)v82, 0x1000u, "%s: Not responded for more than 10 minutes, declaring DEAD!", s);
          sub_38730(3, (const char *)v82, 0);
        }
        sub_2A84C((struct timeval *)(v10 + 52));
        sub_2ED88((_DWORD *)v9, 4);
        goto LABEL_35;
      }
LABEL_48:
      if ( tv_sec - *(_DWORD *)(v10 + 52) <= 60 )
        goto LABEL_35;
      if ( (unsigned int)(v11 - 1) > 1 )
        goto LABEL_35;
      sub_2A84C((struct timeval *)(v10 + 52));
      if ( !byte_75E0C )
        goto LABEL_35;
      goto LABEL_34;
    }
  }
  if ( dword_7BC90 )
  {
    v19 = *(__int16 *)(dword_7BC90 + 4);
    v20 = v19 + 1;
    v21 = *(__int16 *)(dword_7BC90 + 6) + 1;
    v22 = v21 <= 79;
    if ( v21 > 79 )
      v22 = v20 <= 24;
    if ( !v22 )
    {
      if ( v20 > dword_77020 + 2 )
      {
        v23 = dword_7701C;
        if ( dword_77020 < dword_7701C )
        {
          if ( v19 <= dword_7701C )
            v23 = v19 - 1;
          dword_77020 = v23;
          dword_77024 = v23 + 1;
          mvwin((WINDOW *)dword_7B430, v23 + 1, 0);
          wresize((WINDOW *)dword_7B7C0, dword_77020, v21);
        }
      }
      v24 = v20 - dword_77024;
      if ( dword_7B430 )
        v25 = *(__int16 *)(dword_7B430 + 4);
      else
        v25 = -1;
      if ( dword_7B430 )
        v26 = *(__int16 *)(dword_7B430 + 6);
      else
        v26 = v25;
      if ( dword_7B430 )
      {
        ++v25;
        ++v26;
      }
      v27 = v21 == v26;
      if ( v21 == v26 )
        v27 = v24 == v25;
      if ( !v27 )
        wresize((WINDOW *)dword_7B430, v24, v21);
    }
  }
  v28 = sub_1DA58();
  if ( byte_77318 )
    v29 = 100;
  else
    v29 = 80;
  v76 = v28;
  wattr_on((WINDOW *)dword_7B7C0, 0x200000u, 0);
  snprintf((char *)v82, 0x100u, " cgminer version 4.9.0 - Started: %s", byte_77260);
  mvwprintw((WINDOW *)dword_7B7C0, 0, 0, "%s", (const char *)v82);
  wattr_off((WINDOW *)dword_7B7C0, 0x200000u, 0);
  if ( wmove((WINDOW *)dword_7B7C0, 1, 0) != -1 )
    whline((WINDOW *)dword_7B7C0, 0x2Du, v29);
  snprintf((char *)v82, 0x100u, " %s", byte_77160);
  mvwprintw((WINDOW *)dword_7B7C0, 2, 0, "%s", (const char *)v82);
  wclrtoeol((WINDOW *)dword_7B7C0);
  v30 = (unsigned __int8)byte_77318;
  if ( byte_77318 )
  {
    v58 = dbl_7B5E8;
    v59 = dword_7B8A4;
    v60 = dbl_7B670;
    LODWORD(v61) = sub_5CB64(*(__int64 *)&dword_7B100);
    v62 = v61 / dbl_755F8;
    v63 = sub_188A8();
    snprintf(
      (char *)v82,
      0x100u,
      " A:%.0f  R:%.0f  HW:%d  WU:%.1f/m | ST: %d  SS: %lld  NB: %d  LW: %d  GF: %d  RF: %d",
      v58,
      v60,
      v59,
      v62 * 60.0,
      v63,
      *(_QWORD *)&dword_7BC80,
      dword_7BB1C,
      dword_7B4CC[0],
      dword_7B43C,
      dword_7AE68);
    mvwprintw((WINDOW *)dword_7B7C0, 3, 0, "%s", (const char *)v82);
  }
  else
  {
    v31 = (unsigned __int8)byte_77154;
    if ( byte_77154 )
    {
      v32 = sub_188A8();
      snprintf(
        (char *)v82,
        0x100u,
        " ST: %d  SS: %lld  NB: %d  LW: %d  GF: %d  RF: %d",
        v32,
        *(_QWORD *)&dword_7BC80,
        dword_7BB1C,
        dword_7B4CC[0],
        dword_7B43C,
        dword_7AE68);
      mvwprintw((WINDOW *)dword_7B7C0, 3, v30, "%s", (const char *)v82);
    }
    else
    {
      v73 = dbl_7B5E8;
      v75 = dword_7B8A4;
      v74 = dbl_7B670;
      LODWORD(v57) = sub_5CB64(*(__int64 *)&dword_7B100);
      snprintf((char *)v82, 0x100u, " A:%.0f  R:%.0f  HW:%d  WU:%.1f/m", v73, v74, v75, v57 / dbl_755F8 * 60.0);
      mvwprintw((WINDOW *)dword_7B7C0, 3, v31, "%s", (const char *)v82);
    }
  }
  wclrtoeol((WINDOW *)dword_7B7C0);
  if ( (unsigned int)(dword_76EFC - 3) > 1 || dword_7B198 <= 1 )
  {
    v33 = *(unsigned __int8 *)(v76 + 664);
    if ( !*(_BYTE *)(v76 + 664) )
    {
      v34 = (char *)(unsigned __int8)byte_7BC79;
      if ( !byte_7BC79 )
        v34 = "out";
      v35 = "LP";
      if ( byte_7BC79 )
        v34 = "";
      if ( *(_BYTE *)(v76 + 760) )
        v35 = "GBT";
      snprintf(
        (char *)v82,
        0x100u,
        " Connected to %s diff %s with%s %s as user %s",
        *(const char **)(v76 + 624),
        (const char *)(v76 + 48),
        v34,
        v35,
        *(const char **)(v76 + 204));
      mvwprintw((WINDOW *)dword_7B7C0, 4, v33, "%s", (const char *)v82);
      goto LABEL_113;
    }
    snprintf(
      (char *)v82,
      0x100u,
      " Connected to %s diff %s with stratum as user %s",
      *(const char **)(v76 + 624),
      (const char *)(v76 + 48),
      *(const char **)(v76 + 204));
  }
  else
  {
    v64 = "out";
    if ( byte_7BC79 )
      v64 = "";
    snprintf((char *)v82, 0x100u, " Connected to multiple pools with%s block change notify", v64);
  }
  mvwprintw((WINDOW *)dword_7B7C0, 4, 0, "%s", (const char *)v82);
LABEL_113:
  wclrtoeol((WINDOW *)dword_7B7C0);
  snprintf(
    (char *)v82,
    0x100u,
    " Block: %s...  Diff:%s  Started: %s  Best share: %s   ",
    byte_77300,
    byte_772B8,
    byte_772E0,
    (const char *)&dword_75DC4);
  mvwprintw((WINDOW *)dword_7B7C0, 5, 0, "%s", (const char *)v82);
  if ( wmove((WINDOW *)dword_7B7C0, 6, 0) != -1 )
    whline((WINDOW *)dword_7B7C0, 0x2Du, v29);
  if ( wmove((WINDOW *)dword_7B7C0, dword_77020 - 1, 0) != -1 )
    whline((WINDOW *)dword_7B7C0, 0x2Du, v29);
  strcpy((char *)v82, "[P]ool management [S]ettings [D]isplay options [Q]uit");
  mvwprintw((WINDOW *)dword_7B7C0, dword_77028 - 1, 1, "%s", (const char *)v82);
  if ( dword_7B720 <= 0 )
  {
LABEL_146:
    if ( dword_7B7C0 )
      v53 = *(__int16 *)(dword_7B7C0 + 4) + 1;
    else
      v53 = -1;
    wtouchln((WINDOW *)dword_7B7C0, 0, v53, 1);
    wrefresh((WINDOW *)dword_7B7C0);
    if ( dword_7B430 )
      v54 = *(__int16 *)(dword_7B430 + 4);
    else
      v54 = -1;
    if ( dword_7B430 )
      ++v54;
    wtouchln((WINDOW *)dword_7B430, 0, v54, 1);
    wrefresh((WINDOW *)dword_7B430);
    if ( pthread_mutex_unlock(&mutex) )
      sub_B5C4("unlock_curses", 2930);
    off_75ED8();
    goto LABEL_3;
  }
  v36 = 0;
  v37 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v52 = sub_1B83C(v37);
      if ( !v52 )
        goto LABEL_142;
      if ( !byte_7B940 )
      {
        v38 = v36 + dword_77028;
        if ( LINES - 1 > v36 + dword_77028 && dword_7702C > v36 )
          break;
      }
      ++v37;
      ++v36;
      if ( dword_7B720 <= v37 )
        goto LABEL_146;
    }
    if ( *(_DWORD *)(v52 + 368) )
    {
      sub_2A84C(&v77);
      sub_2AA24();
      v38 = v36 + dword_77028;
      v39 = v0;
    }
    else
    {
      v39 = dbl_755F8;
    }
    v40 = (WINDOW *)dword_7B7C0;
    v41 = *(_QWORD *)(v52 + 192);
    if ( v39 < 1.0 )
      v39 = 1.0;
    *(double *)(v52 + 88) = (double)*(int *)(v52 + 36) / v39 * 60.0;
    wmove(v40, v38, 0);
    sub_11548(COERCE_DOUBLE(__PAIR64__(&dword_75DF8, v37)));
    v42 = *(const char **)(v52 + 28);
    if ( v42 )
    {
      strcpy(dest, "        ");
      strncpy(dest, v42, 8u);
    }
    else
    {
      sprintf(dest, "%-8d", *(_DWORD *)(v52 + 8));
    }
    snprintf((char *)v82, 0x100u, " %*d: %s %-8s: ", dword_75DF8, v37, *(const char **)(*(_DWORD *)(v52 + 4) + 8), dest);
    wprintw((WINDOW *)dword_7B7C0, "%s", (const char *)v82);
    s[0] = 0;
    (*(void (__fastcall **)(char *, int, int))(*(_DWORD *)(v52 + 4) + 20))(s, 256, v52);
    v43 = strlen(s);
    if ( v43 <= 0x16 )
      strncat(s, "                                        ", 23 - v43);
    snprintf((char *)v82, 0x100u, "%s | ", s);
    wprintw((WINDOW *)dword_7B7C0, "%s", (const char *)v82);
    v44 = *(_DWORD *)(v52 + 96);
    if ( v44 == 2 )
    {
      v45 = "DEAD  ";
    }
    else if ( v44 == 1 )
    {
      v45 = "SICK  ";
    }
    else
    {
      v46 = *(_DWORD *)(v52 + 32);
      if ( v46 == 1 )
      {
        v45 = "OFF   ";
      }
      else
      {
        if ( v46 != 2 )
        {
          LODWORD(v47) = sub_5CB64(v41);
          v48 = v47 / v39 * 60.0;
          if ( byte_77318 )
          {
            LODWORD(v67) = sub_5CC48(*(double *)(v52 + 80) / v39 * 1000000.0);
            sub_11580(v67, v79, 0x10u, 4);
            LODWORD(v68) = sub_5CC48(*(double *)(v52 + 48) * 1000000.0);
            sub_11580(v68, (char *)v80, 0x10u, 4);
            HIDWORD(v69) = &dword_75DFC;
            LODWORD(v69) = (int)v48;
            v70 = sub_11548(v69);
            LODWORD(v70) = &dword_75E00;
            v71 = sub_11514(v70);
            LODWORD(v71) = &dword_75E04;
            *(float *)&v0 = *(double *)(v52 + 208);
            sub_11514(v71);
            LODWORD(v72) = *(_DWORD *)(v52 + 44);
            HIDWORD(v72) = &dword_75E08;
            sub_11548(v72);
            snprintf(
              (char *)v82,
              0x100u,
              "%6s / %6sh/s WU:%*.1f/m A:%*.0f R:%*.0f HW:%*d",
              (const char *)v80,
              v79,
              dword_75DFC + 2,
              v48,
              dword_75E00,
              *(double *)(v52 + 200),
              dword_75E04,
              *(double *)(v52 + 208),
              dword_75E08,
              *(_DWORD *)(v52 + 44));
            wprintw((WINDOW *)dword_7B7C0, "%s", (const char *)v82);
          }
          else
          {
            if ( byte_77154 )
            {
              LODWORD(v47) = &dword_75E00;
              v65 = sub_11514(v47);
              LODWORD(v65) = &dword_75E04;
              *(float *)&v0 = *(double *)(v52 + 208);
              sub_11514(v65);
              LODWORD(v66) = *(_DWORD *)(v52 + 44);
              HIDWORD(v66) = &dword_75E08;
              sub_11548(v66);
              snprintf(
                (char *)v82,
                0x100u,
                "A:%*.0f R:%*.0f HW:%*d",
                dword_75E00,
                *(double *)(v52 + 200),
                dword_75E04,
                *(double *)(v52 + 208),
                dword_75E08,
                *(_DWORD *)(v52 + 44));
            }
            else
            {
              LODWORD(v49) = sub_5CC48(*(double *)(v52 + 80) / v39 * 1000000.0);
              sub_11580(v49, v79, 0x10u, 4);
              LODWORD(v50) = sub_5CC48(*(double *)(v52 + 48) * 1000000.0);
              sub_11580(v50, (char *)v80, 0x10u, 4);
              HIDWORD(v51) = &dword_75DFC;
              LODWORD(v51) = (int)v48;
              sub_11548(v51);
              snprintf((char *)v82, 0x100u, "%6s / %6sh/s WU:%*.1f/m", (const char *)v80, v79, dword_75DFC + 2, v48);
            }
            wprintw((WINDOW *)dword_7B7C0, "%s", (const char *)v82);
          }
          goto LABEL_141;
        }
        v45 = "REST  ";
      }
    }
    v55 = *(_DWORD *)v45;
    v56 = *((_DWORD *)v45 + 1);
    LOWORD(v82[1]) = v56;
    v82[0] = v55;
    BYTE2(v82[1]) = BYTE2(v56);
    wprintw((WINDOW *)dword_7B7C0, "%s", (const char *)v82);
LABEL_141:
    s[0] = 0;
    ++v36;
    (*(void (__fastcall **)(char *, int, int))(*(_DWORD *)(v52 + 4) + 24))(s, 256, v52);
    snprintf((char *)v82, 0x100u, "%s", s);
    wprintw((WINDOW *)dword_7B7C0, "%s", (const char *)v82);
    wclrtoeol((WINDOW *)dword_7B7C0);
LABEL_142:
    if ( dword_7B720 <= ++v37 )
      goto LABEL_146;
  }
}
