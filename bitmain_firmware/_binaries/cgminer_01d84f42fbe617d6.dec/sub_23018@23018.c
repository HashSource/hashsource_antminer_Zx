void __noreturn sub_23018()
{
  double v0; // d0
  __int64 v1; // r4
  int v2; // r4
  int v3; // r0
  int v4; // r5
  int v5; // r3
  int v6; // r5
  int v7; // r3
  int v8; // r0
  int v9; // r4
  int v10; // r6
  int v11; // r3
  int v12; // r1
  int v13; // r4
  int *v14; // r3
  int v15; // r1
  int v16; // t1
  int v17; // r2
  int v18; // r4
  int v19; // r5
  bool v20; // cc
  int v21; // r1
  int v22; // r1
  int v23; // r3
  int v24; // r2
  bool v25; // zf
  int v26; // r0
  int v27; // r5
  int v28; // r10
  int v29; // r8
  int v30; // r0
  int v31; // r7
  const char *v32; // r0
  const char *v33; // r1
  int v34; // r8
  int v35; // r10
  int v36; // r1
  double v37; // d8
  __int64 v38; // d11
  WINDOW *v39; // r0
  const char *v40; // r3
  size_t v41; // r0
  int v42; // r3
  const char *v43; // r3
  int v44; // r3
  double v45; // r0
  double v46; // d11
  unsigned __int64 v47; // r0
  unsigned __int64 v48; // r0
  double v49; // r0
  int v50; // r0
  int v51; // r4
  int v52; // r2
  int v53; // r2
  int v54; // r0
  int v55; // r1
  double v56; // r0
  double v57; // d12
  int v58; // r8
  double v59; // d11
  double v60; // r0
  double v61; // d8
  int v62; // r0
  const char *v63; // r3
  double v64; // r0
  double v65; // r0
  unsigned __int64 v66; // r0
  unsigned __int64 v67; // r0
  double v68; // r0
  double v69; // r0
  double v70; // r0
  double v71; // r0
  double v72; // [sp+0h] [bp-9A4h]
  double v73; // [sp+8h] [bp-99Ch]
  int v74; // [sp+10h] [bp-994h]
  int v75; // [sp+48h] [bp-95Ch]
  __int64 v76; // [sp+58h] [bp-94Ch]
  struct timeval v77; // [sp+6Ch] [bp-938h] BYREF
  char dest[12]; // [sp+74h] [bp-930h] BYREF
  char v79[16]; // [sp+80h] [bp-924h] BYREF
  struct timeval v80[2]; // [sp+90h] [bp-914h] BYREF
  char v81[256]; // [sp+A0h] [bp-904h] BYREF
  _DWORD v82[512]; // [sp+1A0h] [bp-804h] BYREF

  pthread_setcanceltype(1, 0);
  sub_2F02C("Watchdog");
  sub_11C4C();
  sub_2B13C(&stru_615CC);
  HIDWORD(v1) = byte_6159C;
  LODWORD(v1) = byte_61574;
  v76 = v1;
LABEL_2:
  while ( 1 )
  {
    sleep(2u);
    sub_22C60();
    sub_1C834(-1, 0);
    if ( sub_19140() )
      break;
LABEL_3:
    sub_2B13C(v80);
    if ( byte_6373C )
      goto LABEL_181;
    if ( !sub_1161C() )
    {
      if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
      {
        snprintf(
          (char *)v82,
          0x800u,
          "Pausing execution as per stop time %02d:%02d scheduled",
          dword_63B9C,
          dword_63B98);
        sub_38438(4, (const char *)v82, 0);
      }
      v13 = (unsigned __int8)byte_63E14;
      if ( !byte_63E14 )
      {
        strcpy((char *)v82, "Terminating execution as planned");
        sub_38438(3, (const char *)v82, 1);
        sub_16724(v13);
      }
      if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
      {
        snprintf((char *)v82, 0x800u, "Will restart execution as scheduled at %02d:%02d", dword_63E20, dword_63E1C);
        sub_38438(4, (const char *)v82, 0);
      }
      byte_6373C = 1;
      if ( pthread_rwlock_rdlock(&rwlock) )
        sub_B76C("watchdog_thread", 9725);
      if ( dword_6410C > 0 )
      {
        v14 = (int *)dword_63B80;
        v15 = dword_63B80 + 4 * dword_6410C;
        do
        {
          v16 = *v14++;
          *(_BYTE *)(v16 + 60) = 1;
        }
        while ( v14 != (int *)v15 );
      }
      if ( pthread_rwlock_unlock(&rwlock) )
        sub_B700("watchdog_thread", 9728);
      off_60178();
      goto LABEL_22;
    }
    if ( byte_6373C )
    {
LABEL_181:
      if ( sub_1161C() )
      {
        if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
        {
          snprintf(
            (char *)v82,
            0x800u,
            "Restarting execution as per start time %02d:%02d scheduled",
            dword_63E20,
            dword_63E1C);
          sub_38438(4, (const char *)v82, 0);
        }
        if ( byte_63B90 && (byte_632F0 || byte_630C0 || dword_60964 > 3) )
        {
          snprintf((char *)v82, 0x800u, "Will pause execution as scheduled at %02d:%02d", dword_63B9C, dword_63B98);
          sub_38438(4, (const char *)v82, 0);
        }
        v2 = 0;
        byte_6373C = 0;
        while ( dword_6410C > v2 )
        {
          v3 = v2++;
          v4 = sub_1C36C(v3);
          if ( *(_DWORD *)(*(_DWORD *)(v4 + 36) + 32) != 1 )
          {
            v5 = (unsigned __int8)byte_630C1;
            *(_BYTE *)(v4 + 60) = 0;
            if ( v5 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
            {
              snprintf((char *)v82, 0x800u, "Pushing sem post to thread %d", *(_DWORD *)v4);
              sub_38438(7, (const char *)v82, 0);
            }
            sub_2F134((sem_t *)(v4 + 16), "cgminer.c", "watchdog_thread", 9750);
          }
        }
      }
    }
LABEL_22:
    if ( dword_63CC0 > 0 )
    {
      v6 = 0;
      while ( 1 )
      {
        v8 = sub_1AB68(v6);
        v9 = v8;
        v10 = **(_DWORD **)(v8 + 152);
        if ( !v10 )
          goto LABEL_35;
        (*(void (**)(void))(*(_DWORD *)(v8 + 4) + 32))();
        snprintf(v81, 8u, "%s %d", *(const char **)(*(_DWORD *)(v9 + 4) + 8), *(_DWORD *)(v9 + 8));
        if ( *(_BYTE *)(v10 + 61) || *(_DWORD *)(v9 + 32) == 1 )
          goto LABEL_35;
        v11 = *(_DWORD *)(v9 + 96);
        v12 = v80[0].tv_sec - *(_DWORD *)(v10 + 44);
        if ( v11 )
          break;
        if ( v12 <= 120 )
          goto LABEL_48;
        *(_QWORD *)(v9 + 48) = 0;
        v7 = (unsigned __int8)byte_632F0;
        *(_DWORD *)(v9 + 96) = 1;
        if ( v7 || byte_630C0 || dword_60964 > 2 )
        {
          snprintf((char *)v82, 0x800u, "%s: Idle for more than 60 seconds, declaring SICK!", v81);
          sub_38438(3, (const char *)v82, 0);
        }
        sub_2B13C((struct timeval *)(v10 + 52));
        sub_2ED00((_DWORD *)v9, 3);
        if ( !byte_600AC )
          goto LABEL_35;
        if ( byte_632F0 || byte_630C0 || dword_60964 > 2 )
        {
          snprintf((char *)v82, 0x800u, "%s: Attempting to restart", v81);
          sub_38438(3, (const char *)v82, 0);
        }
LABEL_34:
        sub_16704(v9);
LABEL_35:
        if ( dword_63CC0 <= ++v6 )
          goto LABEL_2;
      }
      if ( v12 <= 119 )
      {
        if ( v11 != 4 && (byte_632F0 || byte_630C0 || dword_60964 > 2) )
        {
          snprintf((char *)v82, 0x800u, "%s: Recovered, declaring WELL!", v81);
          sub_38438(3, (const char *)v82, 0);
        }
        *(_DWORD *)(v9 + 96) = 0;
        *(_DWORD *)(v9 + 240) = time(0);
        goto LABEL_35;
      }
      if ( v11 == 1 && v12 > 600 )
      {
        *(_DWORD *)(v9 + 96) = 2;
        if ( byte_632F0 || byte_630C0 || dword_60964 > 2 )
        {
          snprintf((char *)v82, 0x800u, "%s: Not responded for more than 10 minutes, declaring DEAD!", v81);
          sub_38438(3, (const char *)v82, 0);
        }
        sub_2B13C((struct timeval *)(v10 + 52));
        sub_2ED00((_DWORD *)v9, 4);
        goto LABEL_35;
      }
LABEL_48:
      if ( v80[0].tv_sec - *(_DWORD *)(v10 + 52) <= 60 )
        goto LABEL_35;
      if ( (unsigned int)(v11 - 1) > 1 )
        goto LABEL_35;
      sub_2B13C((struct timeval *)(v10 + 52));
      if ( !byte_600AC )
        goto LABEL_35;
      goto LABEL_34;
    }
  }
  if ( dword_64230 )
  {
    v17 = *(__int16 *)(dword_64230 + 4);
    v18 = v17 + 1;
    v19 = *(__int16 *)(dword_64230 + 6) + 1;
    v20 = v19 <= 79;
    if ( v19 > 79 )
      v20 = v18 <= 24;
    if ( !v20 )
    {
      if ( v18 > dword_61300 + 2 )
      {
        v21 = dword_612FC;
        if ( dword_61300 < dword_612FC )
        {
          if ( v17 <= dword_612FC )
            v21 = v17 - 1;
          dword_61300 = v21;
          dword_61304 = v21 + 1;
          mvwin((WINDOW *)dword_639D8, v21 + 1, 0);
          wresize((WINDOW *)dword_63D60, dword_61300, v19);
        }
      }
      v22 = v18 - dword_61304;
      if ( dword_639D8 )
        v23 = *(__int16 *)(dword_639D8 + 4);
      else
        v23 = -1;
      if ( dword_639D8 )
        v24 = *(__int16 *)(dword_639D8 + 6);
      else
        v24 = v23;
      if ( dword_639D8 )
      {
        ++v23;
        ++v24;
      }
      v25 = v19 == v24;
      if ( v19 == v24 )
        v25 = v22 == v23;
      if ( !v25 )
        wresize((WINDOW *)dword_639D8, v22, v19);
    }
  }
  v26 = sub_1D644();
  if ( byte_615D4 )
    v27 = 100;
  else
    v27 = 80;
  v75 = v26;
  wattr_on((WINDOW *)dword_63D60, 0x200000u, 0);
  snprintf((char *)v82, 0x100u, " cgminer version 4.9.0 - Started: %s", byte_613EC);
  mvwprintw((WINDOW *)dword_63D60, 0, 0, "%s", (const char *)v82);
  wattr_off((WINDOW *)dword_63D60, 0x200000u, 0);
  if ( wmove((WINDOW *)dword_63D60, 1, 0) != -1 )
    whline((WINDOW *)dword_63D60, 0x2Du, v27);
  snprintf((char *)v82, 0x100u, " %s", byte_61438);
  mvwprintw((WINDOW *)dword_63D60, 2, 0, "%s", (const char *)v82);
  wclrtoeol((WINDOW *)dword_63D60);
  v28 = (unsigned __int8)byte_615D4;
  if ( byte_615D4 )
  {
    v57 = dbl_63B88;
    v58 = dword_63E44;
    v59 = dbl_63C10;
    LODWORD(v60) = sub_493DC(*(__int64 *)&dword_636A8);
    v61 = v60 / dbl_5F898;
    v62 = sub_17F48();
    snprintf(
      (char *)v82,
      0x100u,
      " A:%.0f  R:%.0f  HW:%d  WU:%.1f/m | ST: %d  SS: %lld  NB: %d  LW: %d  GF: %d  RF: %d",
      v57,
      v59,
      v58,
      v61 * 60.0,
      v62,
      *(_QWORD *)&dword_64220,
      dword_640BC,
      dword_63A70,
      dword_639E4,
      dword_63410);
    mvwprintw((WINDOW *)dword_63D60, 3, 0, "%s", (const char *)v82);
  }
  else
  {
    v29 = (unsigned __int8)byte_6142C;
    if ( byte_6142C )
    {
      v30 = sub_17F48();
      snprintf(
        (char *)v82,
        0x100u,
        " ST: %d  SS: %lld  NB: %d  LW: %d  GF: %d  RF: %d",
        v30,
        *(_QWORD *)&dword_64220,
        dword_640BC,
        dword_63A70,
        dword_639E4,
        dword_63410);
      mvwprintw((WINDOW *)dword_63D60, 3, v28, "%s", (const char *)v82);
    }
    else
    {
      v72 = dbl_63B88;
      v74 = dword_63E44;
      v73 = dbl_63C10;
      LODWORD(v56) = sub_493DC(*(__int64 *)&dword_636A8);
      snprintf((char *)v82, 0x100u, " A:%.0f  R:%.0f  HW:%d  WU:%.1f/m", v72, v73, v74, v56 / dbl_5F898 * 60.0);
      mvwprintw((WINDOW *)dword_63D60, 3, v29, "%s", (const char *)v82);
    }
  }
  wclrtoeol((WINDOW *)dword_63D60);
  if ( (unsigned int)(dword_611AC - 3) > 1 || dword_63740 <= 1 )
  {
    v31 = *(unsigned __int8 *)(v75 + 632);
    if ( !*(_BYTE *)(v75 + 632) )
    {
      v32 = (const char *)(unsigned __int8)byte_64219;
      if ( !byte_64219 )
        v32 = "out";
      v33 = "LP";
      if ( byte_64219 )
        v32 = "";
      if ( *(_BYTE *)(v75 + 704) )
        v33 = "GBT";
      snprintf(
        (char *)v82,
        0x100u,
        " Connected to %s diff %s with%s %s as user %s",
        *(const char **)(v75 + 592),
        (const char *)(v75 + 48),
        v32,
        v33,
        *(const char **)(v75 + 172));
      mvwprintw((WINDOW *)dword_63D60, 4, v31, "%s", (const char *)v82);
      goto LABEL_113;
    }
    snprintf(
      (char *)v82,
      0x100u,
      " Connected to %s diff %s with stratum as user %s",
      *(const char **)(v75 + 592),
      (const char *)(v75 + 48),
      *(const char **)(v75 + 172));
  }
  else
  {
    v63 = "out";
    if ( byte_64219 )
      v63 = "";
    snprintf((char *)v82, 0x100u, " Connected to multiple pools with%s block change notify", v63);
  }
  mvwprintw((WINDOW *)dword_63D60, 4, 0, "%s", (const char *)v82);
LABEL_113:
  wclrtoeol((WINDOW *)dword_63D60);
  snprintf(
    (char *)v82,
    0x100u,
    " Block: %s...  Diff:%s  Started: %s  Best share: %s   ",
    byte_615BC,
    (const char *)v76,
    (const char *)HIDWORD(v76),
    (const char *)&dword_60064);
  mvwprintw((WINDOW *)dword_63D60, 5, 0, "%s", (const char *)v82);
  if ( wmove((WINDOW *)dword_63D60, 6, 0) != -1 )
    whline((WINDOW *)dword_63D60, 0x2Du, v27);
  if ( wmove((WINDOW *)dword_63D60, dword_61300 - 1, 0) != -1 )
    whline((WINDOW *)dword_63D60, 0x2Du, v27);
  strcpy((char *)v82, "[P]ool management [S]ettings [D]isplay options [Q]uit");
  mvwprintw((WINDOW *)dword_63D60, dword_61308 - 1, 1, "%s", (const char *)v82);
  if ( dword_63CC0 <= 0 )
  {
LABEL_146:
    if ( dword_63D60 )
      v52 = *(__int16 *)(dword_63D60 + 4) + 1;
    else
      v52 = -1;
    wtouchln((WINDOW *)dword_63D60, 0, v52, 1);
    wrefresh((WINDOW *)dword_63D60);
    if ( dword_639D8 )
      v53 = *(__int16 *)(dword_639D8 + 4);
    else
      v53 = -1;
    if ( dword_639D8 )
      ++v53;
    wtouchln((WINDOW *)dword_639D8, 0, v53, 1);
    wrefresh((WINDOW *)dword_639D8);
    if ( pthread_mutex_unlock(&stru_63D48) )
      sub_B694("unlock_curses", 2928);
    off_60178();
    goto LABEL_3;
  }
  v34 = 0;
  v35 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v50 = sub_1AB68(v35);
      v51 = v50;
      if ( !v50 )
        goto LABEL_142;
      if ( !byte_63EE0 )
      {
        v36 = v34 + dword_61308;
        if ( LINES - 1 > v34 + dword_61308 && dword_6130C > v34 )
          break;
      }
      ++v35;
      ++v34;
      if ( dword_63CC0 <= v35 )
        goto LABEL_146;
    }
    if ( *(_DWORD *)(v50 + 368) )
    {
      sub_2B13C(&v77);
      sub_2B314();
      v36 = v34 + dword_61308;
      v37 = v0;
    }
    else
    {
      v37 = dbl_5F898;
    }
    v38 = *(_QWORD *)(v51 + 192);
    v39 = (WINDOW *)dword_63D60;
    if ( v37 < 1.0 )
      v37 = 1.0;
    *(double *)(v51 + 88) = (double)*(int *)(v51 + 36) / v37 * 60.0;
    wmove(v39, v36, 0);
    sub_110F8(COERCE_DOUBLE(__PAIR64__(&dword_60098, v35)));
    v40 = *(const char **)(v51 + 28);
    if ( v40 )
    {
      strcpy(dest, "        ");
      strncpy(dest, v40, 8u);
    }
    else
    {
      sprintf(dest, "%-8d", *(_DWORD *)(v51 + 8));
    }
    snprintf((char *)v82, 0x100u, " %*d: %s %-8s: ", dword_60098, v35, *(const char **)(*(_DWORD *)(v51 + 4) + 8), dest);
    wprintw((WINDOW *)dword_63D60, "%s", (const char *)v82);
    v81[0] = 0;
    (*(void (__fastcall **)(char *, int, int))(*(_DWORD *)(v51 + 4) + 20))(v81, 256, v51);
    v41 = strlen(v81);
    if ( v41 <= 0x16 )
      strncat(v81, "                                        ", 23 - v41);
    snprintf((char *)v82, 0x100u, "%s | ", v81);
    wprintw((WINDOW *)dword_63D60, "%s", (const char *)v82);
    v42 = *(_DWORD *)(v51 + 96);
    if ( v42 == 2 )
    {
      v43 = "DEAD  ";
    }
    else if ( v42 == 1 )
    {
      v43 = "SICK  ";
    }
    else
    {
      v44 = *(_DWORD *)(v51 + 32);
      if ( v44 == 1 )
      {
        v43 = "OFF   ";
      }
      else
      {
        if ( v44 != 2 )
        {
          LODWORD(v45) = sub_493DC(v38);
          v46 = v45 / v37 * 60.0;
          if ( byte_615D4 )
          {
            LODWORD(v66) = sub_494C0(*(double *)(v51 + 80) / v37 * 1000000.0);
            sub_11130(v66, v79, 0x10u, 4);
            LODWORD(v67) = sub_494C0(*(double *)(v51 + 48) * 1000000.0);
            sub_11130(v67, (char *)v80, 0x10u, 4);
            HIDWORD(v68) = &dword_6009C;
            LODWORD(v68) = (int)v46;
            v69 = sub_110F8(v68);
            LODWORD(v69) = &dword_600A0;
            v70 = sub_110C4(v69);
            LODWORD(v70) = &dword_600A4;
            *(float *)&v0 = *(double *)(v51 + 208);
            sub_110C4(v70);
            LODWORD(v71) = *(_DWORD *)(v51 + 44);
            HIDWORD(v71) = &dword_600A8;
            sub_110F8(v71);
            snprintf(
              (char *)v82,
              0x100u,
              "%6s / %6sh/s WU:%*.1f/m A:%*.0f R:%*.0f HW:%*d",
              (const char *)v80,
              v79,
              dword_6009C + 2,
              v46,
              dword_600A0,
              *(double *)(v51 + 200),
              dword_600A4,
              *(double *)(v51 + 208),
              dword_600A8,
              *(_DWORD *)(v51 + 44));
            wprintw((WINDOW *)dword_63D60, "%s", (const char *)v82);
          }
          else
          {
            if ( byte_6142C )
            {
              LODWORD(v45) = &dword_600A0;
              v64 = sub_110C4(v45);
              LODWORD(v64) = &dword_600A4;
              *(float *)&v0 = *(double *)(v51 + 208);
              sub_110C4(v64);
              LODWORD(v65) = *(_DWORD *)(v51 + 44);
              HIDWORD(v65) = &dword_600A8;
              sub_110F8(v65);
              snprintf(
                (char *)v82,
                0x100u,
                "A:%*.0f R:%*.0f HW:%*d",
                dword_600A0,
                *(double *)(v51 + 200),
                dword_600A4,
                *(double *)(v51 + 208),
                dword_600A8,
                *(_DWORD *)(v51 + 44));
            }
            else
            {
              LODWORD(v47) = sub_494C0(*(double *)(v51 + 80) / v37 * 1000000.0);
              sub_11130(v47, v79, 0x10u, 4);
              LODWORD(v48) = sub_494C0(*(double *)(v51 + 48) * 1000000.0);
              sub_11130(v48, (char *)v80, 0x10u, 4);
              HIDWORD(v49) = &dword_6009C;
              LODWORD(v49) = (int)v46;
              sub_110F8(v49);
              snprintf((char *)v82, 0x100u, "%6s / %6sh/s WU:%*.1f/m", (const char *)v80, v79, dword_6009C + 2, v46);
            }
            wprintw((WINDOW *)dword_63D60, "%s", (const char *)v82);
          }
          goto LABEL_141;
        }
        v43 = "REST  ";
      }
    }
    v54 = *(_DWORD *)v43;
    v55 = *((_DWORD *)v43 + 1);
    LOWORD(v82[1]) = v55;
    v82[0] = v54;
    BYTE2(v82[1]) = BYTE2(v55);
    wprintw((WINDOW *)dword_63D60, "%s", (const char *)v82);
LABEL_141:
    v81[0] = 0;
    ++v34;
    (*(void (__fastcall **)(char *, int, int))(*(_DWORD *)(v51 + 4) + 24))(v81, 256, v51);
    snprintf((char *)v82, 0x100u, "%s", v81);
    wprintw((WINDOW *)dword_63D60, "%s", (const char *)v82);
    wclrtoeol((WINDOW *)dword_63D60);
LABEL_142:
    if ( dword_63CC0 <= ++v35 )
      goto LABEL_146;
  }
}
