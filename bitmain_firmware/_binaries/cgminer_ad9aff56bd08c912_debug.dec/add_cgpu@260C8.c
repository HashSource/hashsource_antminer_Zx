int __fastcall add_cgpu(cgpu_info *a1)
{
  int v1; // r6
  char *name; // r4
  size_t v3; // r5
  int v4; // r3
  int v5; // r7
  int v6; // r0
  unsigned __int8 *v7; // lr
  unsigned int v8; // r1
  int v9; // r12
  int v10; // r4
  int v11; // r2
  int v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r2
  int v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r2
  int v18; // r3
  unsigned int v19; // r1
  unsigned int v20; // r2
  size_t v21; // r7
  _DWORD *v22; // r1
  int v23; // r0
  unsigned int v24; // r4
  unsigned int v25; // r7
  int v26; // r3
  unsigned int v27; // r0
  unsigned int v28; // r7
  int v29; // r3
  int v30; // r4
  int v31; // r7
  int v32; // r4
  int v33; // r4
  int v34; // r3
  const char *v35; // r2
  int v36; // r3
  const char *v37; // r2
  int v38; // r3
  const char *v39; // r2
  int v40; // r3
  const char *v41; // r2
  int v42; // r3
  int v43; // r3
  char *v45; // r0
  char *v46; // r3
  _DWORD *v47; // r7
  char *v48; // r4
  __int64 v49; // r2
  _DWORD *v50; // r4
  int v51; // r8
  unsigned int v52; // r5
  int v53; // r3
  size_t v54; // r0
  unsigned int v55; // r10
  unsigned __int8 *v56; // r11
  int v57; // r4
  int v58; // r0
  int v59; // r8
  int v60; // r1
  int v61; // r3
  unsigned __int8 *v62; // r9
  int v63; // r12
  unsigned int v64; // r8
  unsigned int v65; // r3
  int v66; // r2
  unsigned int v67; // r3
  unsigned int v68; // r8
  int v69; // r2
  unsigned int v70; // r3
  unsigned int v71; // r8
  size_t v72; // r0
  int v73; // r3
  unsigned int v74; // r1
  unsigned int v75; // r0
  int v76; // r3
  unsigned int v77; // r1
  unsigned int v78; // r0
  unsigned int v79; // r3
  unsigned int v80; // r3
  __int64 v81; // r0
  int v82; // r3
  int v83; // r2
  int v84; // r1
  _DWORD *v85; // r2
  __int64 v86; // r2
  int v87; // r4
  _DWORD *v88; // r6
  unsigned int v89; // r1
  unsigned int v90; // r3
  int v91; // r1
  unsigned int v92; // r4
  int v93; // r9
  _DWORD *v94; // r5
  _DWORD *v95; // r8
  int v96; // r4
  char *v97; // r11
  unsigned int v98; // r2
  int v99; // r3
  _DWORD *v100; // r3
  unsigned int v101; // r2
  unsigned int v102; // r1
  bool v103; // cc
  int v104; // r2
  int v105; // r3
  int v106; // r3
  _DWORD *v107; // r0
  void *v108; // r0
  unsigned __int8 *v109; // r9
  unsigned int v110; // r8
  char *s2; // [sp+Ch] [bp-8h]
  void *s2a; // [sp+Ch] [bp-8h]
  char *s2b; // [sp+Ch] [bp-8h]

  v1 = devids_17132;
  s2 = a1->drv->name;
  if ( devids_17132 )
  {
    name = a1->drv->name;
    v3 = strlen(name);
    v4 = -1640531527;
    v5 = -17973521;
    v6 = -1640531527;
    if ( v3 > 0xB )
    {
      v7 = (unsigned __int8 *)(name + 12);
      v110 = v3;
      v8 = -1640531527;
      do
      {
        v9 = *(v7 - 6);
        v110 -= 12;
        v10 = *(v7 - 7);
        v11 = *(v7 - 2);
        v109 = v7;
        v12 = *(v7 - 10);
        v7 += 12;
        v13 = v8 + (v9 << 16) + (v10 << 8) + *(v7 - 20) + (*(v7 - 17) << 24);
        v14 = (v11 << 16) + (*(v7 - 15) << 8) + *(v7 - 16) + (*(v7 - 13) << 24) + v5;
        v15 = ((v12 << 16) + (*(v7 - 23) << 8) + *(v7 - 24) + (*(v7 - 21) << 24) - v13 - v14 + v6) ^ (v14 >> 13);
        v16 = (v13 - v14 - v15) ^ (v15 << 8);
        v17 = (v14 - v15 - v16) ^ (v16 >> 13);
        v18 = (v15 - v16 - v17) ^ (v17 >> 12);
        v19 = (v16 - v17 - v18) ^ (v18 << 16);
        v20 = (v17 - v18 - v19) ^ (v19 >> 5);
        v6 = (v18 - v19 - v20) ^ (v20 >> 3);
        v8 = (v19 - v20 - v6) ^ (v6 << 10);
        v5 = (v20 - v6 - v8) ^ (v8 >> 15);
      }
      while ( v110 > 0xB );
      v4 = v8;
    }
    else
    {
      v109 = (unsigned __int8 *)s2;
      v110 = v3;
    }
    v21 = v5 + v3;
    switch ( v110 )
    {
      case 1u:
        goto LABEL_18;
      case 2u:
        goto LABEL_17;
      case 3u:
        goto LABEL_16;
      case 4u:
        goto LABEL_15;
      case 5u:
        goto LABEL_14;
      case 6u:
        goto LABEL_13;
      case 7u:
        goto LABEL_12;
      case 8u:
        goto LABEL_11;
      case 9u:
        goto LABEL_10;
      case 0xAu:
        goto LABEL_9;
      case 0xBu:
        v21 += v109[10] << 24;
LABEL_9:
        v21 += v109[9] << 16;
LABEL_10:
        v21 += v109[8] << 8;
LABEL_11:
        v4 += v109[7] << 24;
LABEL_12:
        v4 += v109[6] << 16;
LABEL_13:
        v4 += v109[5] << 8;
LABEL_14:
        v4 += v109[4];
LABEL_15:
        v6 += v109[3] << 24;
LABEL_16:
        v6 += v109[2] << 16;
LABEL_17:
        v6 += v109[1] << 8;
LABEL_18:
        v6 += *v109;
        break;
      default:
        break;
    }
    v22 = *(_DWORD **)(devids_17132 + 8);
    v23 = (v6 - v4 - v21) ^ (v21 >> 13);
    v24 = (v4 - v21 - v23) ^ (v23 << 8);
    v25 = (v21 - v23 - v24) ^ (v24 >> 13);
    v26 = (v23 - v24 - v25) ^ (v25 >> 12);
    v27 = (v24 - v25 - v26) ^ (v26 << 16);
    v28 = (v25 - v26 - v27) ^ (v27 >> 5);
    v29 = (v26 - v27 - v28) ^ (v28 >> 3);
    v30 = *(_DWORD *)(*v22
                    + 12
                    * (((v28 - v29 - ((v27 - v28 - v29) ^ (v29 << 10)))
                      ^ (((v27 - v28 - v29) ^ (v29 << 10)) >> 15))
                     & (v22[1] - 1)));
    if ( v30 )
    {
      v31 = -v22[5];
      v32 = v30 - v22[5];
      if ( v32 )
      {
        while ( *(_DWORD *)(v32 + 32) != v3 || memcmp(*(const void **)(v32 + 28), s2, v3) )
        {
          v33 = *(_DWORD *)(v32 + 24);
          if ( v33 )
          {
            v32 = v33 + v31;
            if ( v32 )
              continue;
          }
          goto LABEL_36;
        }
        v34 = *(_DWORD *)(v32 + 4) + 1;
        *(_DWORD *)(v32 + 4) = v34;
        a1->device_id = v34;
LABEL_27:
        if ( !pthread_rwlock_wrlock(&devices_lock) )
          goto LABEL_28;
LABEL_81:
        wr_lock((pthread_rwlock_t *)(&_func___17121.__align + 4), (const char *)0x28CC, v35, v36);
      }
    }
LABEL_36:
    v45 = (char *)malloc(0x28u);
    v46 = s2;
    v47 = v45;
    v48 = v45 + 8;
    s2a = v45 + 8;
    v49 = *(unsigned int *)v46;
    *((_DWORD *)v45 + 7) = v45;
    *((_DWORD *)v45 + 4) = 0;
    *(_QWORD *)v45 = v49;
    a1->device_id = HIDWORD(v49);
    *((_DWORD *)v45 + 8) = strlen(v45);
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 8) + 16) + 8) = v47;
    v47[3] = *(_DWORD *)(*(_DWORD *)(v1 + 8) + 16) - *(_DWORD *)(*(_DWORD *)(v1 + 8) + 20);
    *(_DWORD *)(*(_DWORD *)(v1 + 8) + 16) = v48;
    v50 = *(_DWORD **)(v1 + 8);
  }
  else
  {
    v47 = malloc(0x28u);
    v106 = *(_DWORD *)s2;
    a1->device_id = 0;
    v47[4] = 0;
    *v47 = v106;
    v47[1] = 0;
    v47[7] = v47;
    v47[8] = strlen((const char *)v47);
    v47[3] = 0;
    devids_17132 = (int)v47;
    v107 = malloc(0x2Cu);
    v50 = v107;
    v47[2] = v107;
    if ( !v107 )
      goto LABEL_89;
    memset(v107 + 3, 0, 0x20u);
    s2a = v47 + 2;
    v50[4] = v47 + 2;
    v50[1] = 32;
    v50[2] = 5;
    v50[5] = 8;
    v108 = calloc(0x180u, 1u);
    *v50 = v108;
    if ( !v108 )
      goto LABEL_89;
    v1 = (int)v47;
    v50[10] = -1609490463;
  }
  v51 = -17973521;
  v52 = -1640531527;
  ++v50[3];
  v53 = *(_DWORD *)(v1 + 8);
  v47[9] = -17973521;
  v47[2] = v53;
  v54 = strlen((const char *)v47);
  v55 = v54;
  if ( v54 <= 0xB )
  {
    v57 = -1640531527;
    v62 = (unsigned __int8 *)v47;
  }
  else
  {
    v56 = (unsigned __int8 *)(v47 + 3);
    v57 = -1640531527;
    v58 = -17973521;
    do
    {
      v59 = *(v56 - 2);
      v55 -= 12;
      v60 = *(v56 - 3);
      v61 = *(v56 - 6);
      v62 = v56;
      v63 = *(v56 - 7);
      v56 += 12;
      v64 = (v59 << 16) + (v60 << 8) + *(v56 - 16) + (*(v56 - 13) << 24) + v58;
      v65 = (v61 << 16) + (v63 << 8) + *(v56 - 20) + (*(v56 - 17) << 24) + v52;
      v66 = ((*(v56 - 22) << 16) + (*(v56 - 23) << 8) + *(v56 - 24) + (*(v56 - 21) << 24) - v64 - v65 + v57)
          ^ (v64 >> 13);
      v67 = (v65 - v64 - v66) ^ (v66 << 8);
      v68 = (v64 - v66 - v67) ^ (v67 >> 13);
      v69 = (v66 - v67 - v68) ^ (v68 >> 12);
      v70 = (v67 - v68 - v69) ^ (v69 << 16);
      v71 = (v68 - v69 - v70) ^ (v70 >> 5);
      v57 = (v69 - v70 - v71) ^ (v71 >> 3);
      v52 = (v70 - v71 - v57) ^ (v57 << 10);
      v58 = (v71 - v57 - v52) ^ (v52 >> 15);
      v47[9] = v58;
    }
    while ( v55 > 0xB );
    v51 = (v71 - v57 - v52) ^ (v52 >> 15);
    v54 = strlen((const char *)v47);
  }
  v72 = v54 + v51;
  v47[9] = v72;
  switch ( v55 )
  {
    case 1u:
      goto LABEL_53;
    case 2u:
      goto LABEL_52;
    case 3u:
      goto LABEL_51;
    case 4u:
      goto LABEL_50;
    case 5u:
      goto LABEL_49;
    case 6u:
      goto LABEL_48;
    case 7u:
      goto LABEL_47;
    case 8u:
      goto LABEL_46;
    case 9u:
      goto LABEL_45;
    case 0xAu:
      goto LABEL_44;
    case 0xBu:
      v72 += v62[10] << 24;
      v47[9] = v72;
LABEL_44:
      v72 += v62[9] << 16;
      v47[9] = v72;
LABEL_45:
      v72 += v62[8] << 8;
      v47[9] = v72;
LABEL_46:
      v52 += v62[7] << 24;
LABEL_47:
      v52 += v62[6] << 16;
LABEL_48:
      v52 += v62[5] << 8;
LABEL_49:
      v52 += v62[4];
LABEL_50:
      v57 += v62[3] << 24;
LABEL_51:
      v57 += v62[2] << 16;
LABEL_52:
      v57 += v62[1] << 8;
LABEL_53:
      v57 += *v62;
      break;
    default:
      break;
  }
  v73 = (v57 - v52 - v72) ^ (v72 >> 13);
  v74 = (v52 - v72 - v73) ^ (v73 << 8);
  v75 = (v72 - v73 - v74) ^ (v74 >> 13);
  v76 = (v73 - v74 - v75) ^ (v75 >> 12);
  v77 = (v74 - v75 - v76) ^ (v76 << 16);
  v78 = (v75 - v76 - v77) ^ (v77 >> 5);
  v79 = v76 - v77 - v78;
  v80 = (v78 - (v79 ^ (v78 >> 3)) - ((v77 - v78 - (v79 ^ (v78 >> 3))) ^ ((v79 ^ (v78 >> 3)) << 10)))
      ^ (((v77 - v78 - (v79 ^ (v78 >> 3))) ^ ((v79 ^ (v78 >> 3)) << 10)) >> 15);
  v47[9] = v80;
  v81 = *(_QWORD *)*(_DWORD *)(v1 + 8);
  v82 = 12 * (v80 & (HIDWORD(v81) - 1));
  ++*(_DWORD *)(v81 + v82 + 4);
  HIDWORD(v81) = *(_DWORD *)(**(_DWORD **)(v1 + 8) + v82);
  v47[5] = 0;
  v47[6] = HIDWORD(v81);
  v83 = **(_DWORD **)(v1 + 8);
  v84 = *(_DWORD *)(v83 + v82);
  v85 = (_DWORD *)(v83 + v82);
  if ( v84 )
  {
    *(_DWORD *)(v84 + 12) = s2a;
    v85 = (_DWORD *)(**(_DWORD **)(v1 + 8) + v82);
  }
  *v85 = s2a;
  v86 = *(_QWORD *)(**(_DWORD **)(v1 + 8) + v82 + 4);
  if ( (unsigned int)v86 < 10 * (HIDWORD(v86) + 1) )
    goto LABEL_27;
  v87 = v47[2];
  if ( *(_DWORD *)(v87 + 36) == 1 )
    goto LABEL_27;
  v88 = calloc(24 * *(_DWORD *)(v87 + 4), 1u);
  if ( !v88 )
LABEL_89:
    exit(-1);
  v89 = *(_DWORD *)(v87 + 12);
  v90 = v89 >> (*(_QWORD *)(v87 + 8) + 1);
  if ( ((2 * *(_DWORD *)(v87 + 4) - 1) & v89) != 0 )
    ++v90;
  *(_DWORD *)(v87 + 24) = v90;
  *(_DWORD *)(v47[2] + 28) = 0;
  v91 = v47[2];
  v92 = *(_DWORD *)(v91 + 4);
  if ( v92 )
  {
    v93 = 0;
    for ( s2b = 0; (unsigned int)s2b < v92; ++s2b )
    {
      v94 = *(_DWORD **)(*(_DWORD *)v91 + v93);
      if ( v94 )
      {
        while ( 1 )
        {
          v95 = (_DWORD *)v94[4];
          v96 = 3 * ((2 * v92 - 1) & v94[7]);
          v97 = (char *)&v88[v96];
          v98 = *((_DWORD *)v97 + 1) + 1;
          *((_DWORD *)v97 + 1) = v98;
          if ( v98 > *(_DWORD *)(v91 + 24) )
          {
            ++*(_DWORD *)(v91 + 28);
            *((_DWORD *)v97 + 2) = *((_DWORD *)v97 + 1) / *(_DWORD *)(v47[2] + 24);
          }
          v94[3] = 0;
          v94[4] = v88[v96];
          v99 = v88[v96];
          if ( v99 )
            *(_DWORD *)(v99 + 12) = v94;
          v88[v96] = v94;
          v91 = v47[2];
          if ( !v95 )
            break;
          v92 = *(_DWORD *)(v91 + 4);
          v94 = v95;
        }
        v92 = *(_DWORD *)(v91 + 4);
      }
      v93 += 12;
    }
  }
  free(*(void **)v91);
  *(_DWORD *)(v47[2] + 4) *= 2;
  ++*(_DWORD *)(v47[2] + 8);
  *(_DWORD *)v47[2] = v88;
  v100 = (_DWORD *)v47[2];
  v101 = v100[7];
  v102 = v100[3];
  v103 = v101 > v102 >> 1;
  if ( v101 <= v102 >> 1 )
    v104 = 0;
  else
    v104 = v100[8];
  if ( v103 )
    ++v104;
  v100[8] = v104;
  v105 = v47[2];
  if ( *(_DWORD *)(v105 + 32) > 1u )
    *(_DWORD *)(v105 + 36) = 1;
  if ( pthread_rwlock_wrlock(&devices_lock) )
    goto LABEL_81;
LABEL_28:
  devices = (cgpu_info **)realloc(devices, 4 * (total_devices + new_devices + 2));
  if ( pthread_rwlock_unlock(&devices_lock) )
    rw_unlock((pthread_rwlock_t *)(&_func___17121.__align + 4), (const char *)0x28CE, v37, v38);
  selective_yield();
  if ( pthread_mutex_lock(&stats_lock) )
    mutex_lock((pthread_mutex_t *)(&_func___17121.__align + 4), (const char *)0x28D0, v39, v40);
  a1->last_device_valid_work = time(0);
  if ( pthread_mutex_unlock(&stats_lock) )
    mutex_unlock_noyield((pthread_mutex_t *)(&_func___17121.__align + 4), (const char *)0x28D2, v41, v42);
  selective_yield();
  if ( hotplug_mode )
  {
    v43 = new_devices + total_devices;
    ++new_devices;
  }
  else
  {
    v43 = total_devices++;
  }
  devices[v43] = a1;
  if ( total_devices - zombie_devs > most_devices )
    most_devices = total_devices - zombie_devs;
  return 1;
}
