int __fastcall sub_2CF40(_DWORD *a1, int *a2)
{
  char *v2; // r11
  double v3; // d0
  int *v5; // r0
  int *v6; // r4
  _DWORD *v7; // r8
  _DWORD *v8; // r7
  _DWORD *v9; // r6
  const char *v10; // r0
  const char *v11; // r5
  char *v12; // r0
  int v13; // r5
  int v14; // r3
  int v15; // r3
  const char *v17; // r0
  const char *v18; // r7
  int v19; // r0
  int v20; // r0
  size_t v21; // r0
  int v22; // r0
  _DWORD *v23; // r0
  double v24; // d9
  char *v25; // r8
  char *v26; // r7
  char *v27; // r10
  char *v28; // r9
  int v29; // r3
  _DWORD *v30; // r0
  bool v31; // zf
  bool v32; // zf
  bool v33; // zf
  double v34; // d16
  size_t v35; // r11
  size_t v36; // r0
  int v37; // r11
  size_t v38; // r6
  size_t v39; // r0
  size_t v40; // r1
  char *v41; // r0
  __int64 v42; // r2
  const char *v43; // r3
  struct timezone *v44; // r8
  int v45; // r6
  _DWORD *v46; // r0
  const char *v47; // r8
  const char *v48; // r10
  char *v49; // r9
  char *v50; // r1
  const char *v51; // r2
  const char *v52; // r3
  int v53; // r0
  int v54; // r0
  unsigned __int8 *v55; // r0
  unsigned __int8 *v56; // r6
  unsigned int v57; // r11
  __time_t tv_sec; // r12
  unsigned int v59; // lr
  __suseconds_t tv_usec; // r3
  unsigned int v61; // r1
  __time_t v62; // r9
  __suseconds_t v63; // r7
  _DWORD *v64; // r0
  _DWORD *v65; // r0
  _DWORD *v66; // r0
  _DWORD *v67; // r0
  int v68; // r0
  void *v69; // r0
  char *v70; // r3
  void *v71; // r0
  int v72; // r3
  struct timezone *v73; // r1
  unsigned int v74; // r8
  int *v75; // r0
  int *v76; // r0
  int *v77; // r0
  int *v78; // r0
  int *v79; // r0
  int *v80; // r0
  int *v81; // r0
  int *v82; // r0
  size_t maxlen; // [sp+1Ch] [bp-2228h]
  char *v84; // [sp+20h] [bp-2224h]
  char *v85; // [sp+24h] [bp-2220h]
  char *v86; // [sp+28h] [bp-221Ch]
  _BOOL4 v87; // [sp+2Ch] [bp-2218h]
  pthread_mutex_t *v88; // [sp+30h] [bp-2214h]
  pthread_rwlock_t *rwlock; // [sp+34h] [bp-2210h]
  unsigned int v90; // [sp+38h] [bp-220Ch] BYREF
  char *v91; // [sp+3Ch] [bp-2208h] BYREF
  char *v92; // [sp+40h] [bp-2204h] BYREF
  int v93[23]; // [sp+44h] [bp-2200h] BYREF
  char v94[160]; // [sp+A0h] [bp-21A4h] BYREF
  struct timeval v95[32]; // [sp+140h] [bp-2104h] BYREF
  char s[8192]; // [sp+240h] [bp-2004h] BYREF

  if ( !a2 )
    return 0;
  v5 = sub_59230(a2, 0, (char *)v93);
  v6 = v5;
  if ( !v5 )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      v13 = 0;
      snprintf(s, 0x1000u, "JSON decode failed(%d): %s", v93[0], v94);
      sub_38730(7, s, 0);
      return v13;
    }
    return 0;
  }
  v7 = (_DWORD *)sub_59E20(v5, "method");
  if ( !v7 )
    goto LABEL_22;
  v8 = (_DWORD *)sub_59E20(v6, "error");
  v9 = (_DWORD *)sub_59E20(v6, "params");
  if ( v8 && *v8 != 7 )
  {
    v10 = (const char *)sub_57854(v8, 3);
    v11 = v10;
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(s, 0x1000u, "JSON-RPC method decode failed: %s", v10);
      sub_38730(7, s, 0);
    }
    v12 = (char *)v11;
    v13 = 0;
    free(v12);
    goto LABEL_8;
  }
  v17 = (const char *)sub_5A178(v7);
  v18 = v17;
  if ( !v17 )
    goto LABEL_22;
  if ( !strncasecmp(v17, "mining.notify", 0xDu) )
  {
    v25 = sub_292F4(v9, 0);
    v85 = sub_292F4(v9, 1u);
    v26 = sub_292F4(v9, 2u);
    v27 = sub_292F4(v9, 3u);
    v28 = sub_292F4(v9, 4u);
    v84 = sub_292F4(v9, 5u);
    v86 = sub_292F4(v9, 6u);
    if ( sub_5A008(v9, 7u) )
    {
      v30 = sub_5A008(v9, 7u);
      v29 = *v30 - 5;
      v87 = *v30 == 5;
    }
    else
    {
      v87 = 0;
    }
    v31 = v25 == 0;
    if ( v25 )
      v31 = v26 == 0;
    if ( v31 )
    {
      if ( !v25 )
      {
LABEL_141:
        if ( v26 )
          free(v26);
        if ( v28 )
          free(v28);
        if ( v27 )
          free(v27);
        if ( v85 )
          free(v85);
        if ( v86 )
          free(v86);
        v45 = 0;
        if ( v84 )
          free(v84);
        goto LABEL_131;
      }
    }
    else
    {
      v32 = v27 == 0;
      if ( v27 )
        v32 = v28 == 0;
      if ( !v32 )
      {
        v33 = v85 == 0;
        if ( v85 )
          v33 = v86 == 0;
        if ( !v33 && v84 )
        {
          if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
          {
            strcpy(s, "Valid Notify\n");
            sub_38730(7, s, 0);
          }
          v88 = (pthread_mutex_t *)(a1 + 61);
          if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 61)) )
            sub_B708("parse_notify_equihash", 2142);
          rwlock = (pthread_rwlock_t *)(a1 + 67);
          if ( pthread_rwlock_wrlock((pthread_rwlock_t *)(a1 + 67)) )
          {
            v77 = _errno_location();
            snprintf(
              s,
              0x1000u,
              "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
              *v77,
              "util.c",
              "parse_notify_equihash",
              2142);
            sub_38730(3, s, 1);
            sub_16CA8(1);
          }
          free((void *)a1[168]);
          free((void *)a1[169]);
          free((void *)a1[171]);
          free((void *)a1[172]);
          free((void *)a1[173]);
          a1[168] = v25;
          a1[169] = v26;
          a1[171] = v85;
          a1[172] = v86;
          a1[173] = v84;
          *((_BYTE *)a1 + 696) = v87;
          v34 = *((double *)a1 + 231);
          if ( v34 > 0.0 )
            *((double *)a1 + 89) = v34;
          if ( v87 )
            *((_QWORD *)a1 + 81) = 0;
          v35 = strlen(v85);
          v36 = strlen(v26);
          a1[464] = v36 + v35;
          v37 = (int)(v36 + v35) / 2;
          v38 = strlen(v84);
          v39 = strlen(v86);
          a1[464] = v37;
          v31 = byte_78E09 == 0;
          v40 = 2 * ((v39 >> 1) + (v38 >> 1) + 84 + v37) + 1;
          a1[176] = v40;
          if ( !v31 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
          {
            snprintf(s, 0x1000u, "%s: pool->swork.header_len = %d", "parse_notify_equihash", v40);
            sub_38730(7, s, 0);
            v40 = a1[176];
          }
          if ( (v40 & 3) != 0 )
          {
            v40 = (v40 & 0xFFFFFFFC) + 4;
            a1[176] = v40;
          }
          maxlen = v40;
          v41 = (char *)malloc(v40);
          v2 = v41;
          if ( !v41 )
          {
            snprintf(
              s,
              0x1000u,
              "%s: Failed to malloc header. in %s %s():%d",
              "parse_notify_equihash",
              "util.c",
              "parse_notify_equihash",
              2188);
            sub_38730(3, s, 1);
            sub_16CA8(1);
          }
          snprintf(
            v41,
            maxlen,
            "%s%s%s%s%s%s%s",
            (const char *)a1[171],
            (const char *)a1[169],
            v27,
            v28,
            (const char *)a1[173],
            (const char *)a1[172],
            "0000000000000000000000000000000000000000");
          if ( sub_29830((_BYTE *)a1 + 1604, (unsigned __int8 *)v2, 128) )
          {
            v42 = *(_QWORD *)&dword_7B648;
            ++a1[37];
            *(_QWORD *)&dword_7B648 = v42 + 1;
            if ( pthread_rwlock_unlock(rwlock) )
            {
              v75 = _errno_location();
              snprintf(
                s,
                0x1000u,
                "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                *v75,
                "util.c",
                "parse_notify_equihash",
                2214);
              sub_38730(3, s, 1);
              sub_16CA8(1);
            }
            sub_29388(v88, "parse_notify_equihash", 2214);
            off_75ED8();
            if ( a1 == (_DWORD *)sub_1DA58() )
              byte_7B8AC = 1;
            v29 = (unsigned __int8)byte_7B380;
            if ( !byte_7B380 )
              goto LABEL_129;
            v29 = (unsigned __int8)byte_78E09;
            if ( !byte_78E09 )
              goto LABEL_129;
            if ( byte_7AD48 || byte_78E08 || dword_766C4 > 6 )
            {
              snprintf(s, 0x1000u, "job_id: %s", v25);
              sub_38730(7, s, 0);
              v29 = (unsigned __int8)byte_78E09;
              if ( !byte_78E09 )
                goto LABEL_129;
              if ( byte_7AD48 )
                goto LABEL_105;
            }
            if ( byte_78E08 || dword_766C4 > 6 )
            {
LABEL_105:
              snprintf(s, 0x1000u, "version: %s", v85);
              sub_38730(7, s, 0);
              v29 = (unsigned __int8)byte_78E09;
              if ( !byte_78E09 )
                goto LABEL_129;
              if ( byte_7AD48 )
                goto LABEL_109;
            }
            if ( byte_78E08 || dword_766C4 > 6 )
            {
LABEL_109:
              snprintf(s, 0x1000u, "prev_hash: %s", v26);
              sub_38730(7, s, 0);
              v29 = (unsigned __int8)byte_78E09;
              if ( !byte_78E09 )
                goto LABEL_129;
              if ( byte_7AD48 )
                goto LABEL_113;
            }
            if ( byte_78E08 || dword_766C4 > 6 )
            {
LABEL_113:
              snprintf(s, 0x1000u, "merkle: %s", v27);
              sub_38730(7, s, 0);
              v29 = (unsigned __int8)byte_78E09;
              if ( !byte_78E09 )
                goto LABEL_129;
              if ( byte_7AD48 )
                goto LABEL_117;
            }
            if ( byte_78E08 || dword_766C4 > 6 )
            {
LABEL_117:
              snprintf(s, 0x1000u, "reserved: %s", v28);
              sub_38730(7, s, 0);
              v29 = (unsigned __int8)byte_78E09;
              if ( !byte_78E09 )
                goto LABEL_129;
              if ( byte_7AD48 )
                goto LABEL_121;
            }
            if ( byte_78E08 || dword_766C4 > 6 )
            {
LABEL_121:
              snprintf(s, 0x1000u, "nbit: %s", v86);
              sub_38730(7, s, 0);
              v29 = (unsigned __int8)byte_78E09;
              if ( !byte_78E09 )
                goto LABEL_129;
              if ( byte_7AD48 )
                goto LABEL_226;
            }
            if ( byte_78E08 || dword_766C4 > 6 )
            {
LABEL_226:
              snprintf(s, 0x1000u, "ntime: %s", v84);
              sub_38730(7, s, 0);
              v29 = (unsigned __int8)byte_78E09;
              if ( !byte_78E09 )
                goto LABEL_129;
              if ( byte_7AD48 )
              {
LABEL_126:
                v43 = "yes";
                if ( !v87 )
                  v43 = dword_660D4;
                snprintf(s, 0x1000u, "clean: %s", v43);
                sub_38730(7, s, 0);
                goto LABEL_129;
              }
            }
            if ( byte_78E08 )
              goto LABEL_126;
            v29 = dword_766C4;
            if ( dword_766C4 > 6 )
              goto LABEL_126;
LABEL_129:
            v44 = (struct timezone *)(unsigned __int8)byte_78CA8;
            if ( !byte_78CA8 )
            {
              sub_29830(&v90, (unsigned __int8 *)v84, 4);
              v73 = v44;
              v74 = v90;
              gettimeofday(v95, v73);
              if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
              {
                snprintf(s, 0x1000u, "stime.tv_sec %lu, block_ntime %lu\n", v95[0].tv_sec, v74);
                sub_38730(5, s, 0);
              }
              if ( v74 > v95[0].tv_sec + 3600 )
              {
                v95[0].tv_sec = v74;
                settimeofday(v95, 0);
              }
              v29 = 1;
              byte_78CA8 = 1;
            }
            v45 = 1;
LABEL_131:
            if ( v2 )
              free(v2);
            if ( v45 )
              v29 = 1;
            else
              *((_BYTE *)a1 + 667) = 0;
            if ( v45 )
            {
              *((_BYTE *)a1 + 667) = v29;
              v13 = v29;
            }
            else
            {
              v13 = 0;
            }
            goto LABEL_8;
          }
          if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
          {
            snprintf(s, 0x1000u, "%s: Failed to convert header to header_bin, got %s", "parse_notify_equihash", v2);
            sub_38730(4, s, 0);
          }
          sub_2930C(rwlock, "parse_notify_equihash", 2205);
          sub_29388(v88, "parse_notify_equihash", 2205);
          off_75ED8();
          sub_1FB44((int)a1);
        }
      }
    }
    free(v25);
    goto LABEL_141;
  }
  if ( !strncasecmp(v18, "mining.set_extranonce", 0x15u) )
  {
    v13 = sub_299AC((int)a1, v9, 0);
    goto LABEL_8;
  }
  if ( !strncasecmp(v18, "mining.set_difficulty", 0x15u) )
  {
    v23 = sub_5A008(v9, 0);
    sub_5A378((int)v23);
    if ( v3 == 0.0 )
    {
      v13 = 0;
      goto LABEL_8;
    }
    if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 61)) )
      sub_B708("parse_diff", 2483);
    if ( pthread_rwlock_wrlock((pthread_rwlock_t *)(a1 + 67)) )
    {
      v80 = _errno_location();
      snprintf(s, 0x1000u, "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d", *v80, "util.c", "parse_diff", 2483);
      sub_38730(3, s, 1);
      sub_16CA8(1);
    }
    v24 = *((double *)a1 + 230);
    *((double *)a1 + 230) = v3;
    if ( pthread_rwlock_unlock((pthread_rwlock_t *)(a1 + 67)) )
    {
      v82 = _errno_location();
      snprintf(s, 0x1000u, "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d", *v82, "util.c", "parse_diff", 2486);
      sub_38730(3, s, 1);
      sub_16CA8(1);
    }
    if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 61)) )
    {
      v81 = _errno_location();
      snprintf(s, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v81, "util.c", "parse_diff", 2486);
      sub_38730(3, s, 1);
      sub_16CA8(1);
    }
    off_75ED8();
    if ( v3 == v24 )
    {
      if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
      {
        v72 = *a1;
        v13 = 1;
        snprintf(s, 0x1000u, "Pool %d difficulty set to %f", v72, v3);
        sub_38730(7, s, 0);
        goto LABEL_8;
      }
      goto LABEL_60;
    }
    if ( v3 == (double)(int)v3 )
    {
      if ( !byte_78E09 || !byte_7AD48 && !byte_78E08 && dword_766C4 <= 6 )
        goto LABEL_60;
      snprintf(s, 0x1000u, "Pool %d difficulty changed to %d", *a1, (int)v3);
    }
    else
    {
      if ( !byte_78E09 || !byte_7AD48 && !byte_78E08 && dword_766C4 <= 6 )
        goto LABEL_60;
      snprintf(s, 0x1000u, "Pool %d difficulty changed to %.1f", *a1, v3);
    }
    goto LABEL_59;
  }
  if ( !strncasecmp(v18, "client.reconnect", 0x10u) )
  {
    memset(v95, 0, 0xFFu);
    v46 = sub_5A008(v9, 0);
    v47 = (const char *)sub_5A178(v46);
    if ( !v47 )
    {
      v47 = (const char *)a1[156];
      goto LABEL_185;
    }
    v48 = (const char *)a1[156];
    v49 = strchr(v48, 46);
    if ( v49 )
    {
      v50 = strchr(v47, 46);
      if ( v50 )
      {
        if ( !strcmp(v49, v50) )
        {
LABEL_185:
          v66 = sub_5A008(v9, 1u);
          v67 = sub_5A178(v66);
          if ( !v67 )
            v67 = (_DWORD *)a1[152];
          snprintf((char *)v95, 0xFEu, "%s:%s", v47, v67);
          if ( sub_2AB54((char *)v95, &v91, &v92) )
          {
            if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
            {
              snprintf(s, 0x1000u, "Stratum reconnect requested from pool %d to %s", *a1, (const char *)v95);
              sub_38730(4, s, 0);
            }
            sub_185C8(a1);
            if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 182)) )
              sub_B708("parse_reconnect", 2641);
            sub_28AE8((int)a1);
            v68 = a1[153];
            *((_BYTE *)a1 + 667) = 0;
            *((_BYTE *)a1 + 665) = 0;
            if ( v68 )
              close(v68);
            v69 = (void *)a1[156];
            v70 = v91;
            a1[153] = 0;
            a1[150] = v70;
            a1[156] = v70;
            free(v69);
            v71 = (void *)a1[152];
            a1[152] = v92;
            free(v71);
            if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 182)) )
            {
              v76 = _errno_location();
              snprintf(
                s,
                0x1000u,
                "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
                *v76,
                "util.c",
                "parse_reconnect",
                2650);
              sub_38730(3, s, 1);
              sub_16CA8(1);
            }
            off_75ED8();
            v13 = sub_2CEC8((int)a1);
            goto LABEL_8;
          }
          goto LABEL_22;
        }
        if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 2 )
          goto LABEL_22;
        v51 = "Denied stratum reconnect request to non-matching domain url '%s'";
        v52 = v48;
      }
      else
      {
        if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 2 )
          goto LABEL_22;
        v52 = v47;
        v51 = "Denied stratum reconnect request to url without domain '%s'";
      }
    }
    else
    {
      if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 2 )
        goto LABEL_22;
      v52 = v48;
      v51 = "Denied stratum reconnect request for pool without domain '%s'";
    }
    v13 = 0;
    snprintf(s, 0x1000u, v51, v52);
    sub_38730(3, s, 0);
    goto LABEL_8;
  }
  if ( !strncasecmp(v18, "client.get_version", 0x12u) )
  {
    v22 = sub_59E20(v6, "id");
    if ( !v22 )
      goto LABEL_43;
    v53 = sub_59E20(v6, "id");
    v54 = sub_5A248(v53);
    sprintf(s, "{\"id\": %d, \"result\": \"cgminer/4.9.0\", \"error\": null}", v54);
LABEL_42:
    v21 = strlen(s);
    v22 = sub_2B5C8((int)a1, s, v21);
LABEL_43:
    v13 = v22;
    goto LABEL_8;
  }
  if ( !strncasecmp(v18, "client.show_message", 0x13u) )
  {
    if ( !v9 )
      goto LABEL_22;
    if ( *v9 != 1 )
      goto LABEL_22;
    v64 = sub_5A008(v9, 0);
    v65 = sub_5A178(v64);
    if ( !v65 )
      goto LABEL_22;
    if ( !byte_78E09 || !byte_7AD48 && !byte_78E08 && dword_766C4 <= 6 )
    {
LABEL_60:
      v13 = 1;
      goto LABEL_8;
    }
    snprintf(s, 0x1000u, "Pool %d message: %s", *a1, v65);
LABEL_59:
    sub_38730(7, s, 0);
    goto LABEL_60;
  }
  if ( !strncasecmp(v18, "mining.ping", 0xBu) )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(s, 0x1000u, "Pool %d ping", *a1);
      sub_38730(7, s, 0);
    }
    if ( sub_59E20(v6, "id") )
    {
      v19 = sub_59E20(v6, "id");
      v20 = sub_5A248(v19);
      sprintf(s, "{\"id\": %d, \"result\": \"pong\", \"error\": null}", v20);
      goto LABEL_42;
    }
  }
  else if ( !strncasecmp(v18, "mining.set_target", 0x11u) )
  {
    v55 = (unsigned __int8 *)sub_292F4(v9, 0);
    v56 = v55;
    if ( v55 )
    {
      sub_29830(v95, v55, 32);
      if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 61)) )
        sub_B708("parse_target", 2714);
      if ( pthread_rwlock_wrlock((pthread_rwlock_t *)(a1 + 67)) )
      {
        v79 = _errno_location();
        snprintf(s, 0x1000u, "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d", *v79, "util.c", "parse_target", 2714);
        sub_38730(3, s, 1);
        sub_16CA8(1);
      }
      v57 = bswap32(v95[3].tv_usec);
      tv_sec = v95[2].tv_sec;
      v59 = bswap32(v95[3].tv_sec);
      tv_usec = v95[1].tv_usec;
      v61 = bswap32(v95[2].tv_usec);
      a1[25] = bswap32(v95[0].tv_sec);
      v62 = v95[1].tv_sec;
      v63 = v95[0].tv_usec;
      a1[19] = v59;
      a1[20] = v61;
      a1[21] = bswap32(tv_sec);
      a1[22] = bswap32(tv_usec);
      a1[18] = v57;
      a1[23] = bswap32(v62);
      a1[24] = bswap32(v63);
      sub_2930C((pthread_rwlock_t *)(a1 + 67), "parse_target", 2717);
      if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 61)) )
      {
        v78 = _errno_location();
        snprintf(s, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v78, "util.c", "parse_target", 2717);
        sub_38730(3, s, 1);
        sub_16CA8(1);
      }
      v13 = 1;
      off_75ED8();
      free(v56);
      goto LABEL_8;
    }
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      strcpy(s, "parse_target: Missing an array value.");
      sub_38730(7, s, 0);
    }
  }
LABEL_22:
  v13 = 0;
LABEL_8:
  v14 = v6[1];
  if ( v14 != -1 )
  {
    v15 = v14 - 1;
    v6[1] = v15;
    if ( !v15 )
      sub_5A3E4((void **)v6);
  }
  return v13;
}
