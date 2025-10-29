void __noreturn sub_2328C()
{
  double v0; // d0
  __int64 v1; // r4
  int v2; // r4
  int v3; // r0
  int v4; // r5
  int v5; // r3
  int v6; // r6
  __time_t tv_sec; // r2
  int v8; // r3
  int v9; // r0
  int v10; // r5
  int v11; // r7
  int v12; // r3
  int v13; // r1
  int v14; // r1
  int v15; // r3
  int v16; // r4
  int *v17; // r3
  int v18; // r1
  int v19; // t1
  int v20; // r2
  int v21; // r4
  int v22; // r5
  bool v23; // cc
  int v24; // r1
  int v25; // r1
  int v26; // r3
  int v27; // r2
  bool v28; // zf
  int v29; // r0
  int v30; // r5
  int v31; // r6
  int v32; // r8
  int v33; // r0
  int v34; // r6
  char *v35; // r0
  const char *v36; // r1
  int v37; // r8
  int v38; // r10
  int v39; // r1
  double v40; // d8
  WINDOW *v41; // r0
  __int64 v42; // d11
  const char *v43; // r3
  size_t v44; // r0
  int v45; // r3
  const char *v46; // r3
  int v47; // r3
  double v48; // r0
  double v49; // d11
  unsigned __int64 v50; // r0
  unsigned __int64 v51; // r0
  double v52; // r0
  int v53; // r5
  int v54; // r2
  int v55; // r2
  int v56; // r0
  int v57; // r1
  double v58; // r0
  double v59; // d12
  int v60; // r6
  double v61; // d11
  double v62; // r0
  double v63; // d8
  int v64; // r0
  const char *v65; // r3
  double v66; // r0
  double v67; // r0
  unsigned __int64 v68; // r0
  unsigned __int64 v69; // r0
  double v70; // r0
  double v71; // r0
  double v72; // r0
  double v73; // r0
  double v74; // [sp+0h] [bp-119Ch]
  double v75; // [sp+8h] [bp-1194h]
  int v76; // [sp+10h] [bp-118Ch]
  int v77; // [sp+48h] [bp-1154h]
  __int64 v78; // [sp+50h] [bp-114Ch]
  struct timeval v79; // [sp+64h] [bp-1138h] BYREF
  char dest[12]; // [sp+6Ch] [bp-1130h] BYREF
  char v81[16]; // [sp+78h] [bp-1124h] BYREF
  struct timeval v82[2]; // [sp+88h] [bp-1114h] BYREF
  char s[256]; // [sp+98h] [bp-1104h] BYREF
  _DWORD v84[1018]; // [sp+198h] [bp-1004h] BYREF

  pthread_setcanceltype(1, 0);
  sub_2EF24("Watchdog");
  sub_1202C();
  sub_2A7A4(&stru_7414C);
  HIDWORD(v1) = byte_7411C;
  LODWORD(v1) = byte_740F4;
  v78 = v1;
LABEL_2:
  while ( 1 )
  {
    sleep(2u);
    sub_22ED0();
    sub_1B514(-1, 0);
    if ( sub_196AC() )
      break;
LABEL_3:
    sub_2A7A4(v82);
    if ( byte_77FBC )
      goto LABEL_181;
    if ( !sub_1180C() )
    {
      if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
      {
        snprintf(
          (char *)v84,
          0x1000u,
          "Pausing execution as per stop time %02d:%02d scheduled",
          dword_78424,
          dword_78420);
        sub_385C8(4, (const char *)v84, 0);
      }
      v16 = (unsigned __int8)byte_7869C;
      if ( !byte_7869C )
      {
        strcpy((char *)v84, "Terminating execution as planned");
        sub_385C8(3, (const char *)v84, 1);
        sub_16BE0(v16);
      }
      if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
      {
        snprintf((char *)v84, 0x1000u, "Will restart execution as scheduled at %02d:%02d", dword_786A8, dword_786A4);
        sub_385C8(4, (const char *)v84, 0);
      }
      byte_77FBC = 1;
      if ( pthread_rwlock_rdlock(&rwlock) )
        sub_B5E4("watchdog_thread", 9708);
      if ( dword_78994 > 0 )
      {
        v17 = (int *)dword_78408;
        v18 = dword_78408 + 4 * dword_78994;
        do
        {
          v19 = *v17++;
          *(_BYTE *)(v19 + 60) = 1;
        }
        while ( v17 != (int *)v18 );
      }
      if ( pthread_rwlock_unlock(&rwlock) )
        sub_B578("watchdog_thread", 9711);
      off_72D18();
      goto LABEL_22;
    }
    if ( byte_77FBC )
    {
LABEL_181:
      if ( sub_1180C() )
      {
        if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
        {
          snprintf(
            (char *)v84,
            0x1000u,
            "Restarting execution as per start time %02d:%02d scheduled",
            dword_786A8,
            dword_786A4);
          sub_385C8(4, (const char *)v84, 0);
        }
        if ( byte_78418 && (byte_77B70 || byte_75C48 || dword_73504 > 3) )
        {
          snprintf((char *)v84, 0x1000u, "Will pause execution as scheduled at %02d:%02d", dword_78424, dword_78420);
          sub_385C8(4, (const char *)v84, 0);
        }
        v2 = 0;
        byte_77FBC = 0;
        while ( dword_78994 > v2 )
        {
          v3 = v2++;
          v4 = sub_1AA90(v3);
          if ( *(_DWORD *)(*(_DWORD *)(v4 + 36) + 32) != 1 )
          {
            v5 = (unsigned __int8)byte_75C49;
            *(_BYTE *)(v4 + 60) = 0;
            if ( v5 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
            {
              snprintf((char *)v84, 0x1000u, "Pushing sem post to thread %d", *(_DWORD *)v4);
              sub_385C8(7, (const char *)v84, 0);
            }
            sub_2F02C((sem_t *)(v4 + 16), "cgminer.c", "watchdog_thread", 9733);
          }
        }
      }
    }
LABEL_22:
    if ( dword_78548 > 0 )
    {
      v6 = 0;
      while ( 1 )
      {
        v9 = sub_1B1A8(v6);
        v10 = v9;
        v11 = **(_DWORD **)(v9 + 152);
        if ( !v11 )
          goto LABEL_35;
        (*(void (**)(void))(*(_DWORD *)(v9 + 4) + 32))();
        snprintf(s, 8u, "%s %d", *(const char **)(*(_DWORD *)(v10 + 4) + 8), *(_DWORD *)(v10 + 8));
        if ( *(_BYTE *)(v11 + 61) || *(_DWORD *)(v10 + 32) == 1 )
          goto LABEL_35;
        v12 = *(_DWORD *)(v10 + 96);
        v13 = *(_DWORD *)(v11 + 44);
        if ( v12 )
          break;
        tv_sec = v82[0].tv_sec;
        if ( v82[0].tv_sec - v13 <= 120 )
          goto LABEL_48;
        *(_QWORD *)(v10 + 48) = 0;
        v8 = (unsigned __int8)byte_77B70;
        *(_DWORD *)(v10 + 96) = 1;
        if ( v8 || byte_75C48 || dword_73504 > 2 )
        {
          snprintf((char *)v84, 0x1000u, "%s: Idle for more than 60 seconds, declaring SICK!", s);
          sub_385C8(3, (const char *)v84, 0);
        }
        sub_2A7A4((struct timeval *)(v11 + 52));
        sub_2EBF8((_DWORD *)v10, 3);
        if ( !byte_72C4C )
          goto LABEL_35;
        if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
        {
          snprintf((char *)v84, 0x1000u, "%s: Attempting to restart", s);
          sub_385C8(3, (const char *)v84, 0);
        }
LABEL_34:
        sub_16BC0(v10);
LABEL_35:
        if ( dword_78548 <= ++v6 )
          goto LABEL_2;
      }
      tv_sec = v82[0].tv_sec;
      v14 = v82[0].tv_sec - v13;
      if ( v14 <= 119 )
      {
        if ( v12 != 4 && (byte_77B70 || byte_75C48 || dword_73504 > 2) )
        {
          snprintf((char *)v84, 0x1000u, "%s: Recovered, declaring WELL!", s);
          sub_385C8(3, (const char *)v84, 0);
        }
        *(_DWORD *)(v10 + 96) = 0;
        *(_DWORD *)(v10 + 240) = time(0);
        goto LABEL_35;
      }
      if ( v12 == 1 && v14 > 600 )
      {
        v15 = (unsigned __int8)byte_77B70;
        *(_DWORD *)(v10 + 96) = 2;
        if ( v15 || byte_75C48 || dword_73504 > 2 )
        {
          snprintf((char *)v84, 0x1000u, "%s: Not responded for more than 10 minutes, declaring DEAD!", s);
          sub_385C8(3, (const char *)v84, 0);
        }
        sub_2A7A4((struct timeval *)(v11 + 52));
        sub_2EBF8((_DWORD *)v10, 4);
        goto LABEL_35;
      }
LABEL_48:
      if ( tv_sec - *(_DWORD *)(v11 + 52) <= 60 )
        goto LABEL_35;
      if ( (unsigned int)(v12 - 1) > 1 )
        goto LABEL_35;
      sub_2A7A4((struct timeval *)(v11 + 52));
      if ( !byte_72C4C )
        goto LABEL_35;
      goto LABEL_34;
    }
  }
  if ( dword_78AB8 )
  {
    v20 = *(__int16 *)(dword_78AB8 + 4);
    v21 = v20 + 1;
    v22 = *(__int16 *)(dword_78AB8 + 6) + 1;
    v23 = v22 <= 79;
    if ( v22 > 79 )
      v23 = v21 <= 24;
    if ( !v23 )
    {
      if ( v21 > dword_73E88 + 2 )
      {
        v24 = dword_73E84;
        if ( dword_73E88 < dword_73E84 )
        {
          if ( v20 <= dword_73E84 )
            v24 = v20 - 1;
          dword_73E88 = v24;
          dword_73E8C = v24 + 1;
          mvwin((WINDOW *)dword_78258, v24 + 1, 0);
          wresize((WINDOW *)dword_785E8, dword_73E88, v22);
        }
      }
      v25 = v21 - dword_73E8C;
      if ( dword_78258 )
        v26 = *(__int16 *)(dword_78258 + 4);
      else
        v26 = -1;
      if ( dword_78258 )
        v27 = *(__int16 *)(dword_78258 + 6);
      else
        v27 = v26;
      if ( dword_78258 )
      {
        ++v26;
        ++v27;
      }
      v28 = v22 == v27;
      if ( v22 == v27 )
        v28 = v25 == v26;
      if ( !v28 )
        wresize((WINDOW *)dword_78258, v25, v22);
    }
  }
  v29 = sub_1D9A0();
  if ( byte_74154 )
    v30 = 100;
  else
    v30 = 80;
  v77 = v29;
  wattr_on((WINDOW *)dword_785E8, 0x200000u, 0);
  snprintf((char *)v84, 0x100u, " cgminer version 4.9.0 - Started: %s", byte_74098);
  mvwprintw((WINDOW *)dword_785E8, 0, 0, "%s", (const char *)v84);
  wattr_off((WINDOW *)dword_785E8, 0x200000u, 0);
  if ( wmove((WINDOW *)dword_785E8, 1, 0) != -1 )
    whline((WINDOW *)dword_785E8, 0x2Du, v30);
  snprintf((char *)v84, 0x100u, " %s", byte_73F98);
  mvwprintw((WINDOW *)dword_785E8, 2, 0, "%s", (const char *)v84);
  wclrtoeol((WINDOW *)dword_785E8);
  v31 = (unsigned __int8)byte_74154;
  if ( byte_74154 )
  {
    v59 = dbl_78410;
    v60 = dword_786CC;
    v61 = dbl_78498;
    LODWORD(v62) = sub_59F1C(*(__int64 *)&dword_77F28);
    v63 = v62 / dbl_72438;
    v64 = sub_191B0();
    snprintf(
      (char *)v84,
      0x100u,
      " A:%.0f  R:%.0f  HW:%d  WU:%.1f/m | ST: %d  SS: %lld  NB: %d  LW: %d  GF: %d  RF: %d",
      v59,
      v61,
      v60,
      v63 * 60.0,
      v64,
      *(_QWORD *)&dword_78AA8,
      dword_78944,
      dword_782F4,
      dword_78264,
      dword_77C90);
    mvwprintw((WINDOW *)dword_785E8, 3, 0, "%s", (const char *)v84);
  }
  else
  {
    v32 = (unsigned __int8)byte_73F8C;
    if ( byte_73F8C )
    {
      v33 = sub_191B0();
      snprintf(
        (char *)v84,
        0x100u,
        " ST: %d  SS: %lld  NB: %d  LW: %d  GF: %d  RF: %d",
        v33,
        *(_QWORD *)&dword_78AA8,
        dword_78944,
        dword_782F4,
        dword_78264,
        dword_77C90);
      mvwprintw((WINDOW *)dword_785E8, 3, v31, "%s", (const char *)v84);
    }
    else
    {
      v74 = dbl_78410;
      v76 = dword_786CC;
      v75 = dbl_78498;
      LODWORD(v58) = sub_59F1C(*(__int64 *)&dword_77F28);
      snprintf((char *)v84, 0x100u, " A:%.0f  R:%.0f  HW:%d  WU:%.1f/m", v74, v75, v76, v58 / dbl_72438 * 60.0);
      mvwprintw((WINDOW *)dword_785E8, 3, v32, "%s", (const char *)v84);
    }
  }
  wclrtoeol((WINDOW *)dword_785E8);
  if ( (unsigned int)(dword_73D34 - 3) > 1 || dword_77FC0 <= 1 )
  {
    v34 = *(unsigned __int8 *)(v77 + 664);
    if ( !*(_BYTE *)(v77 + 664) )
    {
      v35 = (char *)(unsigned __int8)byte_78AA1;
      if ( !byte_78AA1 )
        v35 = "out";
      v36 = "LP";
      if ( byte_78AA1 )
        v35 = "";
      if ( *(_BYTE *)(v77 + 760) )
        v36 = "GBT";
      snprintf(
        (char *)v84,
        0x100u,
        " Connected to %s diff %s with%s %s as user %s",
        *(const char **)(v77 + 624),
        (const char *)(v77 + 48),
        v35,
        v36,
        *(const char **)(v77 + 204));
      mvwprintw((WINDOW *)dword_785E8, 4, v34, "%s", (const char *)v84);
      goto LABEL_113;
    }
    snprintf(
      (char *)v84,
      0x100u,
      " Connected to %s diff %s with stratum as user %s",
      *(const char **)(v77 + 624),
      (const char *)(v77 + 48),
      *(const char **)(v77 + 204));
  }
  else
  {
    v65 = "out";
    if ( byte_78AA1 )
      v65 = "";
    snprintf((char *)v84, 0x100u, " Connected to multiple pools with%s block change notify", v65);
  }
  mvwprintw((WINDOW *)dword_785E8, 4, 0, "%s", (const char *)v84);
LABEL_113:
  wclrtoeol((WINDOW *)dword_785E8);
  snprintf(
    (char *)v84,
    0x100u,
    " Block: %s...  Diff:%s  Started: %s  Best share: %s   ",
    byte_7413C,
    (const char *)v78,
    (const char *)HIDWORD(v78),
    (const char *)&dword_72C04);
  mvwprintw((WINDOW *)dword_785E8, 5, 0, "%s", (const char *)v84);
  if ( wmove((WINDOW *)dword_785E8, 6, 0) != -1 )
    whline((WINDOW *)dword_785E8, 0x2Du, v30);
  if ( wmove((WINDOW *)dword_785E8, dword_73E88 - 1, 0) != -1 )
    whline((WINDOW *)dword_785E8, 0x2Du, v30);
  strcpy((char *)v84, "[P]ool management [S]ettings [D]isplay options [Q]uit");
  mvwprintw((WINDOW *)dword_785E8, dword_73E90 - 1, 1, "%s", (const char *)v84);
  if ( dword_78548 <= 0 )
  {
LABEL_146:
    if ( dword_785E8 )
      v54 = *(__int16 *)(dword_785E8 + 4) + 1;
    else
      v54 = -1;
    wtouchln((WINDOW *)dword_785E8, 0, v54, 1);
    wrefresh((WINDOW *)dword_785E8);
    if ( dword_78258 )
      v55 = *(__int16 *)(dword_78258 + 4);
    else
      v55 = -1;
    if ( dword_78258 )
      ++v55;
    wtouchln((WINDOW *)dword_78258, 0, v55, 1);
    wrefresh((WINDOW *)dword_78258);
    if ( pthread_mutex_unlock(&stru_785D0) )
      sub_B50C("unlock_curses", 2930);
    off_72D18();
    goto LABEL_3;
  }
  v37 = 0;
  v38 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v53 = sub_1B1A8(v38);
      if ( !v53 )
        goto LABEL_142;
      if ( !byte_78768 )
      {
        v39 = v37 + dword_73E90;
        if ( LINES - 1 > v37 + dword_73E90 && dword_73E94 > v37 )
          break;
      }
      ++v38;
      ++v37;
      if ( dword_78548 <= v38 )
        goto LABEL_146;
    }
    if ( *(_DWORD *)(v53 + 368) )
    {
      sub_2A7A4(&v79);
      sub_2A97C();
      v39 = v37 + dword_73E90;
      v40 = v0;
    }
    else
    {
      v40 = dbl_72438;
    }
    v41 = (WINDOW *)dword_785E8;
    v42 = *(_QWORD *)(v53 + 192);
    if ( v40 < 1.0 )
      v40 = 1.0;
    *(double *)(v53 + 88) = (double)*(int *)(v53 + 36) / v40 * 60.0;
    wmove(v41, v39, 0);
    sub_11480(COERCE_DOUBLE(__PAIR64__(&dword_72C38, v38)));
    v43 = *(const char **)(v53 + 28);
    if ( v43 )
    {
      strcpy(dest, "        ");
      strncpy(dest, v43, 8u);
    }
    else
    {
      sprintf(dest, "%-8d", *(_DWORD *)(v53 + 8));
    }
    snprintf((char *)v84, 0x100u, " %*d: %s %-8s: ", dword_72C38, v38, *(const char **)(*(_DWORD *)(v53 + 4) + 8), dest);
    wprintw((WINDOW *)dword_785E8, "%s", (const char *)v84);
    s[0] = 0;
    (*(void (__fastcall **)(char *, int, int))(*(_DWORD *)(v53 + 4) + 20))(s, 256, v53);
    v44 = strlen(s);
    if ( v44 <= 0x16 )
      strncat(s, "                                        ", 23 - v44);
    snprintf((char *)v84, 0x100u, "%s | ", s);
    wprintw((WINDOW *)dword_785E8, "%s", (const char *)v84);
    v45 = *(_DWORD *)(v53 + 96);
    if ( v45 == 2 )
    {
      v46 = "DEAD  ";
    }
    else if ( v45 == 1 )
    {
      v46 = "SICK  ";
    }
    else
    {
      v47 = *(_DWORD *)(v53 + 32);
      if ( v47 == 1 )
      {
        v46 = "OFF   ";
      }
      else
      {
        if ( v47 != 2 )
        {
          LODWORD(v48) = sub_59F1C(v42);
          v49 = v48 / v40 * 60.0;
          if ( byte_74154 )
          {
            LODWORD(v68) = sub_5A000(*(double *)(v53 + 80) / v40 * 1000000.0);
            sub_114B8(v68, v81, 0x10u, 4);
            LODWORD(v69) = sub_5A000(*(double *)(v53 + 48) * 1000000.0);
            sub_114B8(v69, (char *)v82, 0x10u, 4);
            HIDWORD(v70) = &dword_72C3C;
            LODWORD(v70) = (int)v49;
            v71 = sub_11480(v70);
            LODWORD(v71) = &dword_72C40;
            v72 = sub_1144C(v71);
            LODWORD(v72) = &dword_72C44;
            *(float *)&v0 = *(double *)(v53 + 208);
            sub_1144C(v72);
            LODWORD(v73) = *(_DWORD *)(v53 + 44);
            HIDWORD(v73) = &dword_72C48;
            sub_11480(v73);
            snprintf(
              (char *)v84,
              0x100u,
              "%6s / %6sh/s WU:%*.1f/m A:%*.0f R:%*.0f HW:%*d",
              (const char *)v82,
              v81,
              dword_72C3C + 2,
              v49,
              dword_72C40,
              *(double *)(v53 + 200),
              dword_72C44,
              *(double *)(v53 + 208),
              dword_72C48,
              *(_DWORD *)(v53 + 44));
            wprintw((WINDOW *)dword_785E8, "%s", (const char *)v84);
          }
          else
          {
            if ( byte_73F8C )
            {
              LODWORD(v48) = &dword_72C40;
              v66 = sub_1144C(v48);
              LODWORD(v66) = &dword_72C44;
              *(float *)&v0 = *(double *)(v53 + 208);
              sub_1144C(v66);
              LODWORD(v67) = *(_DWORD *)(v53 + 44);
              HIDWORD(v67) = &dword_72C48;
              sub_11480(v67);
              snprintf(
                (char *)v84,
                0x100u,
                "A:%*.0f R:%*.0f HW:%*d",
                dword_72C40,
                *(double *)(v53 + 200),
                dword_72C44,
                *(double *)(v53 + 208),
                dword_72C48,
                *(_DWORD *)(v53 + 44));
            }
            else
            {
              LODWORD(v50) = sub_5A000(*(double *)(v53 + 80) / v40 * 1000000.0);
              sub_114B8(v50, v81, 0x10u, 4);
              LODWORD(v51) = sub_5A000(*(double *)(v53 + 48) * 1000000.0);
              sub_114B8(v51, (char *)v82, 0x10u, 4);
              HIDWORD(v52) = &dword_72C3C;
              LODWORD(v52) = (int)v49;
              sub_11480(v52);
              snprintf((char *)v84, 0x100u, "%6s / %6sh/s WU:%*.1f/m", (const char *)v82, v81, dword_72C3C + 2, v49);
            }
            wprintw((WINDOW *)dword_785E8, "%s", (const char *)v84);
          }
          goto LABEL_141;
        }
        v46 = "REST  ";
      }
    }
    v56 = *(_DWORD *)v46;
    v57 = *((_DWORD *)v46 + 1);
    LOWORD(v84[1]) = v57;
    v84[0] = v56;
    BYTE2(v84[1]) = BYTE2(v57);
    wprintw((WINDOW *)dword_785E8, "%s", (const char *)v84);
LABEL_141:
    s[0] = 0;
    ++v37;
    (*(void (__fastcall **)(char *, int, int))(*(_DWORD *)(v53 + 4) + 24))(s, 256, v53);
    snprintf((char *)v84, 0x100u, "%s", s);
    wprintw((WINDOW *)dword_785E8, "%s", (const char *)v84);
    wclrtoeol((WINDOW *)dword_785E8);
LABEL_142:
    if ( dword_78548 <= ++v38 )
      goto LABEL_146;
  }
}
