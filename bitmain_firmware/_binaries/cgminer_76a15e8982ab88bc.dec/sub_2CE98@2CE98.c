int __fastcall sub_2CE98(_DWORD *a1, int *a2)
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
  int v44; // r6
  _DWORD *v45; // r0
  const char *v46; // r8
  const char *v47; // r10
  char *v48; // r9
  char *v49; // r1
  const char *v50; // r2
  const char *v51; // r3
  int v52; // r0
  int v53; // r0
  unsigned __int8 *v54; // r0
  unsigned __int8 *v55; // r6
  unsigned int v56; // r11
  unsigned int v57; // r12
  unsigned int v58; // lr
  unsigned int v59; // r3
  unsigned int v60; // r1
  unsigned int v61; // r9
  unsigned int v62; // r7
  _DWORD *v63; // r0
  _DWORD *v64; // r0
  _DWORD *v65; // r0
  _DWORD *v66; // r0
  int v67; // r0
  void *v68; // r0
  char *v69; // r3
  void *v70; // r0
  int v71; // r3
  int *v72; // r0
  int *v73; // r0
  int *v74; // r0
  int *v75; // r0
  int *v76; // r0
  int *v77; // r0
  int *v78; // r0
  int *v79; // r0
  size_t maxlen; // [sp+1Ch] [bp-2228h]
  char *v81; // [sp+20h] [bp-2224h]
  char *v82; // [sp+24h] [bp-2220h]
  char *v83; // [sp+28h] [bp-221Ch]
  _BOOL4 v84; // [sp+2Ch] [bp-2218h]
  pthread_mutex_t *v85; // [sp+30h] [bp-2214h]
  pthread_rwlock_t *rwlock; // [sp+34h] [bp-2210h]
  char *v87; // [sp+3Ch] [bp-2208h] BYREF
  char *v88; // [sp+40h] [bp-2204h] BYREF
  int v89[23]; // [sp+44h] [bp-2200h] BYREF
  char v90[160]; // [sp+A0h] [bp-21A4h] BYREF
  unsigned int v91[64]; // [sp+140h] [bp-2104h] BYREF
  char s[8192]; // [sp+240h] [bp-2004h] BYREF

  if ( !a2 )
    return 0;
  v5 = sub_565E8(a2, 0, (char *)v89);
  v6 = v5;
  if ( !v5 )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      v13 = 0;
      snprintf(s, 0x1000u, "JSON decode failed(%d): %s", v89[0], v90);
      sub_385C8(7, s, 0);
      return v13;
    }
    return 0;
  }
  v7 = (_DWORD *)sub_571D8(v5, "method");
  if ( !v7 )
    goto LABEL_22;
  v8 = (_DWORD *)sub_571D8(v6, "error");
  v9 = (_DWORD *)sub_571D8(v6, "params");
  if ( v8 && *v8 != 7 )
  {
    v10 = (const char *)sub_54C0C(v8, 3);
    v11 = v10;
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(s, 0x1000u, "JSON-RPC method decode failed: %s", v10);
      sub_385C8(7, s, 0);
    }
    v12 = (char *)v11;
    v13 = 0;
    free(v12);
    goto LABEL_8;
  }
  v17 = (const char *)sub_57530(v7);
  v18 = v17;
  if ( !v17 )
    goto LABEL_22;
  if ( !strncasecmp(v17, "mining.notify", 0xDu) )
  {
    v25 = sub_2924C(v9, 0);
    v81 = sub_2924C(v9, 1u);
    v26 = sub_2924C(v9, 2u);
    v27 = sub_2924C(v9, 3u);
    v28 = sub_2924C(v9, 4u);
    v82 = sub_2924C(v9, 5u);
    v83 = sub_2924C(v9, 6u);
    if ( sub_573C0(v9, 7u) )
    {
      v30 = sub_573C0(v9, 7u);
      v29 = *v30 - 5;
      v84 = *v30 == 5;
    }
    else
    {
      v84 = 0;
    }
    v31 = v25 == 0;
    if ( v25 )
      v31 = v26 == 0;
    if ( v31 )
    {
      if ( !v25 )
      {
LABEL_140:
        if ( v26 )
          free(v26);
        if ( v28 )
          free(v28);
        if ( v27 )
          free(v27);
        if ( v81 )
          free(v81);
        if ( v83 )
          free(v83);
        v44 = 0;
        if ( v82 )
          free(v82);
        goto LABEL_130;
      }
    }
    else
    {
      v32 = v27 == 0;
      if ( v27 )
        v32 = v28 == 0;
      if ( !v32 )
      {
        v33 = v81 == 0;
        if ( v81 )
          v33 = v83 == 0;
        if ( !v33 && v82 )
        {
          if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
          {
            strcpy(s, "Valid Notify\n");
            sub_385C8(7, s, 0);
          }
          v85 = (pthread_mutex_t *)(a1 + 61);
          if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 61)) )
            sub_B650("parse_notify_equihash", 2142);
          rwlock = (pthread_rwlock_t *)(a1 + 67);
          if ( pthread_rwlock_wrlock((pthread_rwlock_t *)(a1 + 67)) )
          {
            v75 = _errno_location();
            snprintf(
              s,
              0x1000u,
              "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
              *v75,
              "util.c",
              "parse_notify_equihash",
              2142);
            sub_385C8(3, s, 1);
            sub_16BE0(1);
          }
          free((void *)a1[168]);
          free((void *)a1[169]);
          free((void *)a1[171]);
          free((void *)a1[172]);
          free((void *)a1[173]);
          a1[168] = v25;
          a1[169] = v26;
          a1[171] = v81;
          a1[172] = v83;
          a1[173] = v82;
          *((_BYTE *)a1 + 696) = v84;
          v34 = *((double *)a1 + 231);
          if ( v34 > 0.0 )
            *((double *)a1 + 89) = v34;
          if ( v84 )
            *((_QWORD *)a1 + 81) = 0;
          v35 = strlen(v81);
          v36 = strlen(v26);
          a1[464] = v36 + v35;
          v37 = (int)(v36 + v35) / 2;
          v38 = strlen(v82);
          v39 = strlen(v83);
          a1[464] = v37;
          v31 = byte_75C49 == 0;
          v40 = 2 * ((v39 >> 1) + (v38 >> 1) + 84 + v37) + 1;
          a1[176] = v40;
          if ( !v31 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
          {
            snprintf(s, 0x1000u, "%s: pool->swork.header_len = %d", "parse_notify_equihash", v40);
            sub_385C8(7, s, 0);
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
            sub_385C8(3, s, 1);
            sub_16BE0(1);
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
          if ( sub_29788((_BYTE *)a1 + 1604, (unsigned __int8 *)v2, 128) )
          {
            v42 = *(_QWORD *)&dword_78470;
            ++a1[37];
            *(_QWORD *)&dword_78470 = v42 + 1;
            if ( pthread_rwlock_unlock(rwlock) )
            {
              v74 = _errno_location();
              snprintf(
                s,
                0x1000u,
                "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                *v74,
                "util.c",
                "parse_notify_equihash",
                2214);
              sub_385C8(3, s, 1);
              sub_16BE0(1);
            }
            sub_292E0(v85, "parse_notify_equihash", 2214);
            off_72D18();
            if ( a1 == (_DWORD *)sub_1D9A0() )
              byte_786D4 = 1;
            v29 = (unsigned __int8)byte_781A8;
            if ( !byte_781A8 )
              goto LABEL_129;
            v29 = (unsigned __int8)byte_75C49;
            if ( !byte_75C49 )
              goto LABEL_129;
            if ( byte_77B70 || byte_75C48 || dword_73504 > 6 )
            {
              snprintf(s, 0x1000u, "job_id: %s", v25);
              sub_385C8(7, s, 0);
              v29 = (unsigned __int8)byte_75C49;
              if ( !byte_75C49 )
                goto LABEL_129;
              if ( byte_77B70 )
                goto LABEL_105;
            }
            if ( byte_75C48 || dword_73504 > 6 )
            {
LABEL_105:
              snprintf(s, 0x1000u, "version: %s", v81);
              sub_385C8(7, s, 0);
              v29 = (unsigned __int8)byte_75C49;
              if ( !byte_75C49 )
                goto LABEL_129;
              if ( byte_77B70 )
                goto LABEL_109;
            }
            if ( byte_75C48 || dword_73504 > 6 )
            {
LABEL_109:
              snprintf(s, 0x1000u, "prev_hash: %s", v26);
              sub_385C8(7, s, 0);
              v29 = (unsigned __int8)byte_75C49;
              if ( !byte_75C49 )
                goto LABEL_129;
              if ( byte_77B70 )
                goto LABEL_113;
            }
            if ( byte_75C48 || dword_73504 > 6 )
            {
LABEL_113:
              snprintf(s, 0x1000u, "merkle: %s", v27);
              sub_385C8(7, s, 0);
              v29 = (unsigned __int8)byte_75C49;
              if ( !byte_75C49 )
                goto LABEL_129;
              if ( byte_77B70 )
                goto LABEL_117;
            }
            if ( byte_75C48 || dword_73504 > 6 )
            {
LABEL_117:
              snprintf(s, 0x1000u, "reserved: %s", v28);
              sub_385C8(7, s, 0);
              v29 = (unsigned __int8)byte_75C49;
              if ( !byte_75C49 )
                goto LABEL_129;
              if ( byte_77B70 )
                goto LABEL_121;
            }
            if ( byte_75C48 || dword_73504 > 6 )
            {
LABEL_121:
              snprintf(s, 0x1000u, "nbit: %s", v83);
              sub_385C8(7, s, 0);
              v29 = (unsigned __int8)byte_75C49;
              if ( !byte_75C49 )
                goto LABEL_129;
              if ( byte_77B70 )
                goto LABEL_218;
            }
            if ( byte_75C48 || dword_73504 > 6 )
            {
LABEL_218:
              snprintf(s, 0x1000u, "ntime: %s", v82);
              sub_385C8(7, s, 0);
              v29 = (unsigned __int8)byte_75C49;
              if ( !byte_75C49 )
                goto LABEL_129;
              if ( byte_77B70 )
              {
LABEL_126:
                v43 = "yes";
                if ( !v84 )
                  v43 = dword_63494;
                snprintf(s, 0x1000u, "clean: %s", v43);
                sub_385C8(7, s, 0);
                goto LABEL_129;
              }
            }
            if ( byte_75C48 )
              goto LABEL_126;
            v29 = dword_73504;
            if ( dword_73504 > 6 )
              goto LABEL_126;
LABEL_129:
            v44 = 1;
LABEL_130:
            if ( v2 )
              free(v2);
            if ( v44 )
              v29 = 1;
            else
              *((_BYTE *)a1 + 667) = 0;
            if ( v44 )
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
          if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
          {
            snprintf(s, 0x1000u, "%s: Failed to convert header to header_bin, got %s", "parse_notify_equihash", v2);
            sub_385C8(4, s, 0);
          }
          sub_29264(rwlock, "parse_notify_equihash", 2205);
          sub_292E0(v85, "parse_notify_equihash", 2205);
          off_72D18();
          sub_1FA8C((int)a1);
        }
      }
    }
    free(v25);
    goto LABEL_140;
  }
  if ( !strncasecmp(v18, "mining.set_extranonce", 0x15u) )
  {
    v13 = sub_29904((int)a1, v9, 0);
    goto LABEL_8;
  }
  if ( !strncasecmp(v18, "mining.set_difficulty", 0x15u) )
  {
    v23 = sub_573C0(v9, 0);
    sub_57730((int)v23);
    if ( v3 == 0.0 )
    {
      v13 = 0;
      goto LABEL_8;
    }
    if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 61)) )
      sub_B650("parse_diff", 2464);
    if ( pthread_rwlock_wrlock((pthread_rwlock_t *)(a1 + 67)) )
    {
      v79 = _errno_location();
      snprintf(s, 0x1000u, "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d", *v79, "util.c", "parse_diff", 2464);
      sub_385C8(3, s, 1);
      sub_16BE0(1);
    }
    v24 = *((double *)a1 + 230);
    *((double *)a1 + 230) = v3;
    if ( pthread_rwlock_unlock((pthread_rwlock_t *)(a1 + 67)) )
    {
      v77 = _errno_location();
      snprintf(s, 0x1000u, "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d", *v77, "util.c", "parse_diff", 2467);
      sub_385C8(3, s, 1);
      sub_16BE0(1);
    }
    if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 61)) )
    {
      v76 = _errno_location();
      snprintf(s, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v76, "util.c", "parse_diff", 2467);
      sub_385C8(3, s, 1);
      sub_16BE0(1);
    }
    off_72D18();
    if ( v3 == v24 )
    {
      if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
      {
        v71 = *a1;
        v13 = 1;
        snprintf(s, 0x1000u, "Pool %d difficulty set to %f", v71, v3);
        sub_385C8(7, s, 0);
        goto LABEL_8;
      }
      goto LABEL_60;
    }
    if ( v3 == (double)(int)v3 )
    {
      if ( !byte_75C49 || !byte_77B70 && !byte_75C48 && dword_73504 <= 6 )
        goto LABEL_60;
      snprintf(s, 0x1000u, "Pool %d difficulty changed to %d", *a1, (int)v3);
    }
    else
    {
      if ( !byte_75C49 || !byte_77B70 && !byte_75C48 && dword_73504 <= 6 )
        goto LABEL_60;
      snprintf(s, 0x1000u, "Pool %d difficulty changed to %.1f", *a1, v3);
    }
    goto LABEL_59;
  }
  if ( !strncasecmp(v18, "client.reconnect", 0x10u) )
  {
    memset(v91, 0, 0xFFu);
    v45 = sub_573C0(v9, 0);
    v46 = (const char *)sub_57530(v45);
    if ( !v46 )
    {
      v46 = (const char *)a1[156];
      goto LABEL_184;
    }
    v47 = (const char *)a1[156];
    v48 = strchr(v47, 46);
    if ( v48 )
    {
      v49 = strchr(v46, 46);
      if ( v49 )
      {
        if ( !strcmp(v48, v49) )
        {
LABEL_184:
          v65 = sub_573C0(v9, 1u);
          v66 = sub_57530(v65);
          if ( !v66 )
            v66 = (_DWORD *)a1[152];
          snprintf((char *)v91, 0xFEu, "%s:%s", v46, v66);
          if ( sub_2AAAC((char *)v91, &v87, &v88) )
          {
            if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
            {
              snprintf(s, 0x1000u, "Stratum reconnect requested from pool %d to %s", *a1, (const char *)v91);
              sub_385C8(4, s, 0);
            }
            sub_1922C(a1);
            if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 182)) )
              sub_B650("parse_reconnect", 2622);
            sub_28A40((int)a1);
            v67 = a1[153];
            *((_BYTE *)a1 + 667) = 0;
            *((_BYTE *)a1 + 665) = 0;
            if ( v67 )
              close(v67);
            v68 = (void *)a1[156];
            v69 = v87;
            a1[153] = 0;
            a1[150] = v69;
            a1[156] = v69;
            free(v68);
            v70 = (void *)a1[152];
            a1[152] = v88;
            free(v70);
            if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 182)) )
            {
              v78 = _errno_location();
              snprintf(
                s,
                0x1000u,
                "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
                *v78,
                "util.c",
                "parse_reconnect",
                2631);
              sub_385C8(3, s, 1);
              sub_16BE0(1);
            }
            off_72D18();
            v13 = sub_2CE20((int)a1);
            goto LABEL_8;
          }
          goto LABEL_22;
        }
        if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 2 )
          goto LABEL_22;
        v50 = "Denied stratum reconnect request to non-matching domain url '%s'";
        v51 = v47;
      }
      else
      {
        if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 2 )
          goto LABEL_22;
        v51 = v46;
        v50 = "Denied stratum reconnect request to url without domain '%s'";
      }
    }
    else
    {
      if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 2 )
        goto LABEL_22;
      v51 = v47;
      v50 = "Denied stratum reconnect request for pool without domain '%s'";
    }
    v13 = 0;
    snprintf(s, 0x1000u, v50, v51);
    sub_385C8(3, s, 0);
    goto LABEL_8;
  }
  if ( !strncasecmp(v18, "client.get_version", 0x12u) )
  {
    v22 = sub_571D8(v6, "id");
    if ( !v22 )
      goto LABEL_43;
    v52 = sub_571D8(v6, "id");
    v53 = sub_57600(v52);
    sprintf(s, "{\"id\": %d, \"result\": \"cgminer/4.9.0\", \"error\": null}", v53);
LABEL_42:
    v21 = strlen(s);
    v22 = sub_2B520((int)a1, s, v21);
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
    v63 = sub_573C0(v9, 0);
    v64 = sub_57530(v63);
    if ( !v64 )
      goto LABEL_22;
    if ( !byte_75C49 || !byte_77B70 && !byte_75C48 && dword_73504 <= 6 )
    {
LABEL_60:
      v13 = 1;
      goto LABEL_8;
    }
    snprintf(s, 0x1000u, "Pool %d message: %s", *a1, v64);
LABEL_59:
    sub_385C8(7, s, 0);
    goto LABEL_60;
  }
  if ( !strncasecmp(v18, "mining.ping", 0xBu) )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(s, 0x1000u, "Pool %d ping", *a1);
      sub_385C8(7, s, 0);
    }
    if ( sub_571D8(v6, "id") )
    {
      v19 = sub_571D8(v6, "id");
      v20 = sub_57600(v19);
      sprintf(s, "{\"id\": %d, \"result\": \"pong\", \"error\": null}", v20);
      goto LABEL_42;
    }
  }
  else if ( !strncasecmp(v18, "mining.set_target", 0x11u) )
  {
    v54 = (unsigned __int8 *)sub_2924C(v9, 0);
    v55 = v54;
    if ( v54 )
    {
      sub_29788(v91, v54, 32);
      if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 61)) )
        sub_B650("parse_target", 2695);
      if ( pthread_rwlock_wrlock((pthread_rwlock_t *)(a1 + 67)) )
      {
        v73 = _errno_location();
        snprintf(s, 0x1000u, "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d", *v73, "util.c", "parse_target", 2695);
        sub_385C8(3, s, 1);
        sub_16BE0(1);
      }
      v56 = bswap32(v91[7]);
      v57 = v91[4];
      v58 = bswap32(v91[6]);
      v59 = v91[3];
      v60 = bswap32(v91[5]);
      a1[25] = bswap32(v91[0]);
      v61 = v91[2];
      v62 = v91[1];
      a1[19] = v58;
      a1[20] = v60;
      a1[21] = bswap32(v57);
      a1[22] = bswap32(v59);
      a1[18] = v56;
      a1[23] = bswap32(v61);
      a1[24] = bswap32(v62);
      sub_29264((pthread_rwlock_t *)(a1 + 67), "parse_target", 2698);
      if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 61)) )
      {
        v72 = _errno_location();
        snprintf(s, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v72, "util.c", "parse_target", 2698);
        sub_385C8(3, s, 1);
        sub_16BE0(1);
      }
      v13 = 1;
      off_72D18();
      free(v55);
      goto LABEL_8;
    }
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      strcpy(s, "parse_target: Missing an array value.");
      sub_385C8(7, s, 0);
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
      sub_5779C((void **)v6);
  }
  return v13;
}
