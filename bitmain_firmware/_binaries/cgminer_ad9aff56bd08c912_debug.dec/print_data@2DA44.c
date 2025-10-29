api_data *__fastcall print_data(io_data *io_data, api_data *root, bool isjson, bool precom)
{
  _BOOL4 v5; // r7
  _BOOL4 v6; // r6
  cglock_t *lock; // r5
  const char *v8; // r1
  K_ITEM *v9; // r11
  cglock_t *v10; // r5
  K_ITEM *p_data; // r5
  char *v12; // r3
  const char *v13; // r9
  const char *v14; // r2
  api_data *next; // r3
  api_data *prev; // r2
  api_data *v17; // r0
  const char *v18; // r1
  const char *v19; // r1
  const char *v20; // r1
  const char *v21; // r1
  const char *v22; // r1
  cglock_t *v23; // r4
  const char *v24; // r2
  cglock_t *v25; // r4
  const char *v27; // r1
  const char *v28; // r1
  const char *v29; // r1
  const char *v30; // r2
  const char *v31; // r2
  const char *v32; // r2
  const char *v33; // r2
  const char *v34; // r2
  const char *v35; // r2
  const char *v36; // r2
  const char *v37; // r2
  const char *v38; // r2
  const char *v39; // r2
  const char *v40; // r2
  int v41; // r1
  int v42; // r3
  const char *v43; // r2
  const char *v44; // r2
  const char *v45; // r2
  const char *v46; // r2
  const char *v47; // r2
  const char *v48; // r2
  const char *v49; // r2
  const char *v50; // r1
  char *v51; // r6
  char *v52; // r3
  char *v53; // r0
  const char *v54; // r1
  const char *v55; // r1
  const char *v56; // r1
  K_ITEM *v57; // r0
  const char *data; // r1
  const char *v59; // r1
  int *v60; // r0
  const char *v61; // r2
  int *v62; // r0
  const char *v63; // r2
  int *v64; // r0
  const char *v65; // r2
  int *v66; // r0
  const char *v67; // r2
  int *v68; // r0
  const char *v69; // r2
  int *v70; // r0
  const char *v71; // r2
  int *v72; // r0
  const char *v73; // r2
  int *v74; // r0
  const char *v75; // r2
  const char *v76; // r1
  const char *v77; // r1
  char *format; // [sp+20h] [bp-104Ch]
  char *original; // [sp+24h] [bp-1048h]
  char *originala; // [sp+24h] [bp-1048h]
  char buf[64]; // [sp+28h] [bp-1044h] BYREF
  char tmp42[4100]; // [sp+68h] [bp-1004h] BYREF

  v5 = isjson;
  v6 = precom;
  lock = strbufs->lock;
  if ( pthread_mutex_lock(&lock->mutex) )
  {
    v68 = _errno_location();
    LOWORD(v69) = -968;
    HIWORD(v69) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v69, *v68, "api.c", "print_data", 1196);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( pthread_rwlock_wrlock(&lock->rwlock) )
  {
    v70 = _errno_location();
    LOWORD(v71) = -1020;
    HIWORD(v71) = (unsigned int)"d_rwlock_init errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v71, *v70, "api.c", "print_data", 1196);
    applog(3, tmp42, 1);
    quit(1);
  }
  LOWORD(v8) = 20356;
  HIWORD(v8) = (unsigned int)&_func___11888.__data.__nusers >> 16;
  v9 = k_unlink_head(strbufs, v8, "print_data", 1197);
  v10 = strbufs->lock;
  if ( pthread_rwlock_unlock(&v10->rwlock) )
  {
    v72 = _errno_location();
    LOWORD(v73) = -348;
    HIWORD(v73) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
    snprintf(tmp42, 0x1000u, v73, *v72, "api.c", "print_data", 1198);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( pthread_mutex_unlock(&v10->mutex) )
  {
    v74 = _errno_location();
    LOWORD(v75) = -920;
    HIWORD(v75) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v75, *v74, "api.c", "print_data", 1198);
    applog(3, tmp42, 1);
    quit(1);
  }
  selective_yield();
  p_data = (K_ITEM *)&v9->data;
  *((_DWORD *)v9->data + 1) = 0;
  if ( v6 )
  {
    LOWORD(v29) = -2296;
    HIWORD(v29) = (unsigned int)"{\n\t\t\"url\" : \"%s%s%s%s\"," >> 16;
    add_item_buf(p_data, v29);
  }
  if ( v5 )
  {
    LOWORD(v27) = 20364;
    HIWORD(v27) = (unsigned int)off_54F0C >> 16;
    add_item_buf(p_data, v27);
    if ( !root )
      goto LABEL_26;
  }
  else if ( !root )
  {
    goto LABEL_19;
  }
  LOWORD(v12) = -24208;
  LOWORD(v13) = 21624;
  HIWORD(v12) = (unsigned int)"n%d RT hash rate is %0.2fGHz/s" >> 16;
  format = v12;
  if ( v5 )
  {
LABEL_16:
    LOWORD(v19) = -2120;
    HIWORD(v19) = (unsigned int)",\n\"round-robin\" : true" >> 16;
    add_item_buf(p_data, v19);
    add_item_buf(p_data, root->name);
    LOWORD(v20) = -2120;
    HIWORD(v20) = (unsigned int)",\n\"round-robin\" : true" >> 16;
    add_item_buf(p_data, v20);
    LOWORD(v21) = 16004;
    HIWORD(v21) = (unsigned int)"proxy: %s" >> 16;
    add_item_buf(p_data, v21);
    switch ( root->type )
    {
      case api_data_type::API_ESCAPE:
        originala = (char *)root->data;
        v53 = escape_string(originala, 1);
        LOWORD(v54) = -2120;
        v51 = v53;
        HIWORD(v54) = (unsigned int)",\n\"round-robin\" : true" >> 16;
        add_item_buf(p_data, v54);
        add_item_buf(p_data, v51);
        LOWORD(v55) = -2120;
        HIWORD(v55) = (unsigned int)",\n\"round-robin\" : true" >> 16;
        add_item_buf(p_data, v55);
        v52 = originala;
        goto LABEL_56;
      case api_data_type::API_STRING:
      case api_data_type::API_CONST:
        LOWORD(v77) = -2120;
        HIWORD(v77) = (unsigned int)",\n\"round-robin\" : true" >> 16;
        add_item_buf(p_data, v77);
        data = (const char *)root->data;
        v57 = (K_ITEM *)&v9->data;
        goto LABEL_60;
      case api_data_type::API_UINT8:
        goto LABEL_29;
      case api_data_type::API_INT16:
        goto LABEL_28;
      case api_data_type::API_UINT16:
        goto LABEL_27;
      case api_data_type::API_INT:
        goto LABEL_46;
      case api_data_type::API_UINT:
      case api_data_type::API_UINT32:
        goto LABEL_11;
      case api_data_type::API_HEX32:
        LOWORD(v76) = -2120;
        HIWORD(v76) = (unsigned int)",\n\"round-robin\" : true" >> 16;
        add_item_buf(p_data, v76);
        snprintf(buf, 0x40u, format, *(_DWORD *)root->data);
        data = buf;
        v57 = (K_ITEM *)&v9->data;
        goto LABEL_60;
      case api_data_type::API_UINT64:
        goto LABEL_44;
      case api_data_type::API_INT64:
        goto LABEL_43;
      case api_data_type::API_DOUBLE:
        goto LABEL_42;
      case api_data_type::API_ELAPSED:
        goto LABEL_41;
      case api_data_type::API_BOOL:
        goto LABEL_38;
      case api_data_type::API_TIMEVAL:
        goto LABEL_37;
      case api_data_type::API_TIME:
        goto LABEL_36;
      case api_data_type::API_MHS:
      case api_data_type::API_UTILITY:
      case api_data_type::API_FREQ:
        goto LABEL_35;
      case api_data_type::API_MHTOTAL:
        goto LABEL_34;
      case api_data_type::API_TEMP:
        goto LABEL_33;
      case api_data_type::API_VOLTS:
      case api_data_type::API_AVG:
        goto LABEL_32;
      case api_data_type::API_HS:
        goto LABEL_31;
      case api_data_type::API_DIFF:
        goto LABEL_30;
      case api_data_type::API_PERCENT:
        goto LABEL_45;
      default:
        goto LABEL_49;
    }
  }
  while ( 1 )
  {
    add_item_buf(p_data, root->name);
    HIWORD(v13) = (unsigned int)"true" >> 16;
    add_item_buf(p_data, v13);
    switch ( root->type )
    {
      case api_data_type::API_ESCAPE:
        original = (char *)root->data;
        v51 = escape_string(original, 0);
        add_item_buf(p_data, v51);
        v52 = original;
LABEL_56:
        if ( v52 != v51 )
          free(v51);
        break;
      case api_data_type::API_STRING:
      case api_data_type::API_CONST:
        add_item_buf(p_data, (const char *)root->data);
        break;
      case api_data_type::API_UINT8:
LABEL_29:
        LOWORD(v32) = 21504;
        HIWORD(v32) = (unsigned int)" sent %d of remaining %d (sendc=%d)" >> 16;
        snprintf(buf, 0x40u, v32, *(unsigned __int8 *)root->data);
        goto LABEL_12;
      case api_data_type::API_INT16:
LABEL_28:
        LOWORD(v31) = -22732;
        HIWORD(v31) = (unsigned int)"dev.timeout = %d us" >> 16;
        snprintf(buf, 0x40u, v31, *(__int16 *)root->data);
        goto LABEL_12;
      case api_data_type::API_UINT16:
LABEL_27:
        LOWORD(v30) = 21504;
        HIWORD(v30) = (unsigned int)" sent %d of remaining %d (sendc=%d)" >> 16;
        snprintf(buf, 0x40u, v30, *(unsigned __int16 *)root->data);
        goto LABEL_12;
      case api_data_type::API_INT:
LABEL_46:
        LOWORD(v48) = -22732;
        HIWORD(v48) = (unsigned int)"dev.timeout = %d us" >> 16;
        snprintf(buf, 0x40u, v48, *(_DWORD *)root->data);
        goto LABEL_12;
      case api_data_type::API_UINT:
      case api_data_type::API_UINT32:
LABEL_11:
        LOWORD(v14) = 21504;
        HIWORD(v14) = (unsigned int)" sent %d of remaining %d (sendc=%d)" >> 16;
        snprintf(buf, 0x40u, v14, *(_DWORD *)root->data);
        goto LABEL_12;
      case api_data_type::API_HEX32:
        snprintf(buf, 0x40u, format, *(_DWORD *)root->data);
        add_item_buf(p_data, buf);
        break;
      case api_data_type::API_UINT64:
LABEL_44:
        LOWORD(v46) = 21508;
        HIWORD(v46) = (unsigned int)"t %d of remaining %d (sendc=%d)" >> 16;
        snprintf(buf, 0x40u, v46, root->data, *(_DWORD *)root->data, *((_DWORD *)root->data + 1));
        goto LABEL_12;
      case api_data_type::API_INT64:
LABEL_43:
        LOWORD(v45) = 544;
        HIWORD(v45) = (unsigned int)"SOLVED %d BLOCK%s!" >> 16;
        snprintf(buf, 0x40u, v45, root->data, *(_DWORD *)root->data, *((_DWORD *)root->data + 1));
        goto LABEL_12;
      case api_data_type::API_DOUBLE:
LABEL_42:
        LOWORD(v44) = 21516;
        HIWORD(v44) = (unsigned int)"remaining %d (sendc=%d)" >> 16;
        snprintf(buf, 0x40u, v44, root->data, *(_DWORD *)root->data, *((_DWORD *)root->data + 1));
        goto LABEL_12;
      case api_data_type::API_ELAPSED:
LABEL_41:
        LOWORD(v43) = 21520;
        HIWORD(v43) = (unsigned int)"ining %d (sendc=%d)" >> 16;
        snprintf(buf, 0x40u, v43, root->data, *(_DWORD *)root->data, *((_DWORD *)root->data + 1));
        goto LABEL_12;
      case api_data_type::API_BOOL:
LABEL_38:
        LOWORD(v42) = 26060;
        LOWORD(v41) = 21496;
        HIWORD(v42) = (unsigned int)"ls" >> 16;
        if ( *(_BYTE *)root->data )
        {
          HIWORD(v41) = (unsigned int)"" >> 16;
          v42 = v41;
        }
        snprintf(buf, 0x40u, "%s", v42);
        goto LABEL_12;
      case api_data_type::API_TIMEVAL:
LABEL_37:
        LOWORD(v40) = 21568;
        HIWORD(v40) = (unsigned int)" buf" >> 16;
        snprintf(buf, 0x40u, v40, *(_DWORD *)root->data, *((_DWORD *)root->data + 1));
        goto LABEL_12;
      case api_data_type::API_TIME:
LABEL_36:
        LOWORD(v39) = -2596;
        HIWORD(v39) = (unsigned int)"uota greatest common denominator set to %lu" >> 16;
        snprintf(buf, 0x40u, v39, *(_DWORD *)root->data);
        goto LABEL_12;
      case api_data_type::API_MHS:
      case api_data_type::API_UTILITY:
      case api_data_type::API_FREQ:
LABEL_35:
        LOWORD(v38) = 21528;
        HIWORD(v38) = (unsigned int)" (sendc=%d)" >> 16;
        snprintf(buf, 0x40u, v38, root->data, *(_DWORD *)root->data, *((_DWORD *)root->data + 1));
        goto LABEL_12;
      case api_data_type::API_MHTOTAL:
LABEL_34:
        LOWORD(v37) = 21544;
        HIWORD(v37) = (unsigned int)"ed to malloc pooldetails buf" >> 16;
        snprintf(buf, 0x40u, v37, root->data, *(_DWORD *)root->data, *((_DWORD *)root->data + 1));
        goto LABEL_12;
      case api_data_type::API_TEMP:
LABEL_33:
        LOWORD(v36) = 21528;
        HIWORD(v36) = (unsigned int)" (sendc=%d)" >> 16;
        snprintf(buf, 0x40u, v36, root->data, *(float *)root->data);
        goto LABEL_12;
      case api_data_type::API_VOLTS:
      case api_data_type::API_AVG:
LABEL_32:
        LOWORD(v35) = 21536;
        HIWORD(v35) = (unsigned int)"%d)" >> 16;
        snprintf(buf, 0x40u, v35, root->data, *(float *)root->data);
        goto LABEL_12;
      case api_data_type::API_HS:
LABEL_31:
        LOWORD(v34) = 21552;
        HIWORD(v34) = (unsigned int)"lloc pooldetails buf" >> 16;
        snprintf(buf, 0x40u, v34, root->data, *(_DWORD *)root->data, *((_DWORD *)root->data + 1));
        goto LABEL_12;
      case api_data_type::API_DIFF:
LABEL_30:
        LOWORD(v33) = 21560;
        HIWORD(v33) = (unsigned int)"ldetails buf" >> 16;
        snprintf(buf, 0x40u, v33, root->data, *(_DWORD *)root->data, *((_DWORD *)root->data + 1));
        goto LABEL_12;
      case api_data_type::API_PERCENT:
LABEL_45:
        LOWORD(v47) = 21544;
        HIWORD(v47) = (unsigned int)"ed to malloc pooldetails buf" >> 16;
        snprintf(buf, 0x40u, v47, root->data, *(double *)root->data * 100.0);
LABEL_12:
        add_item_buf(p_data, buf);
        break;
      default:
LABEL_49:
        if ( use_syslog || opt_log_output || opt_log_level > 2 )
        {
          LOWORD(v49) = 21580;
          HIWORD(v49) = (unsigned int)" killing cgminer" >> 16;
          snprintf(tmp42, 0x1000u, v49);
          applog(3, tmp42, 0);
        }
        if ( v5 )
        {
          LOWORD(v56) = -2120;
          HIWORD(v56) = (unsigned int)",\n\"round-robin\" : true" >> 16;
          add_item_buf(p_data, v56);
          LOWORD(data) = 21616;
          v57 = (K_ITEM *)&v9->data;
          HIWORD(data) = (unsigned int)"cgminer" >> 16;
LABEL_60:
          add_item_buf(v57, data);
          LOWORD(v59) = -2120;
          HIWORD(v59) = (unsigned int)",\n\"round-robin\" : true" >> 16;
          add_item_buf(p_data, v59);
        }
        else
        {
          LOWORD(v50) = 21616;
          HIWORD(v50) = (unsigned int)"cgminer" >> 16;
          add_item_buf(p_data, v50);
        }
        break;
    }
    free(root->name);
    if ( !root->data_was_malloc )
    {
      next = root->next;
      if ( next == root )
        break;
      goto LABEL_15;
    }
    free(root->data);
    next = root->next;
    if ( next == root )
      break;
LABEL_15:
    prev = root->prev;
    v17 = root;
    root = next;
    next->prev = prev;
    prev->next = next;
    free(v17);
    LOWORD(v18) = -2296;
    HIWORD(v18) = (unsigned int)"{\n\t\t\"url\" : \"%s%s%s%s\"," >> 16;
    add_item_buf(p_data, v18);
    if ( v5 )
      goto LABEL_16;
  }
  free(root);
  if ( !v5 )
  {
LABEL_19:
    LOWORD(v22) = -2396;
    HIWORD(v22) = (unsigned int)"ation" >> 16;
    add_item_buf(p_data, v22);
    goto LABEL_20;
  }
LABEL_26:
  LOWORD(v28) = 17792;
  HIWORD(v28) = (unsigned int)"confirmed mining.subscribe with extranonce1 %s extran2size %d" >> 16;
  add_item_buf(p_data, v28);
LABEL_20:
  io_add(io_data, *(char **)v9->data);
  v23 = strbufs->lock;
  if ( pthread_mutex_lock(&v23->mutex) )
  {
    v60 = _errno_location();
    LOWORD(v61) = -968;
    HIWORD(v61) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v61, *v60, "api.c", "print_data", 1368);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( pthread_rwlock_wrlock(&v23->rwlock) )
  {
    v62 = _errno_location();
    LOWORD(v63) = -1020;
    HIWORD(v63) = (unsigned int)"d_rwlock_init errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v63, *v62, "api.c", "print_data", 1368);
    applog(3, tmp42, 1);
    quit(1);
  }
  LOWORD(v24) = 20356;
  HIWORD(v24) = (unsigned int)&_func___11888.__data.__nusers >> 16;
  k_add_head(strbufs, v9, v24, "print_data", 1369);
  v25 = strbufs->lock;
  if ( pthread_rwlock_unlock(&v25->rwlock) )
  {
    v64 = _errno_location();
    LOWORD(v65) = -348;
    HIWORD(v65) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
    snprintf(tmp42, 0x1000u, v65, *v64, "api.c", "print_data", 1370);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( pthread_mutex_unlock(&v25->mutex) )
  {
    v66 = _errno_location();
    LOWORD(v67) = -920;
    HIWORD(v67) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v67, *v66, "api.c", "print_data", 1370);
    applog(3, tmp42, 1);
    quit(1);
  }
  selective_yield();
  return 0;
}
