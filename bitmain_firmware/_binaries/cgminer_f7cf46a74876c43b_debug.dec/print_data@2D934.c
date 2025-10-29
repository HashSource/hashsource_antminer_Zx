api_data *__fastcall print_data(io_data *io_data, api_data *root, bool isjson, bool precom)
{
  _BOOL4 v5; // r7
  _BOOL4 v6; // r6
  cglock_t *lock; // r5
  K_ITEM *v8; // r11
  cglock_t *v9; // r5
  K_ITEM *p_data; // r5
  api_data_type type; // r3
  api_data *next; // r3
  api_data *prev; // r2
  api_data *v14; // r0
  cglock_t *v15; // r4
  cglock_t *v16; // r4
  char *v18; // r3
  char *v19; // r6
  char *v20; // r3
  const char *data; // r1
  K_ITEM *v22; // r0
  int *v23; // r0
  int *v24; // r0
  int *v25; // r0
  int *v26; // r0
  int *v27; // r0
  int *v28; // r0
  int *v29; // r0
  int *v30; // r0
  char *original; // [sp+24h] [bp-1048h]
  char *originala; // [sp+24h] [bp-1048h]
  char buf[64]; // [sp+28h] [bp-1044h] BYREF
  char tmp42[4100]; // [sp+68h] [bp-1004h] BYREF

  v5 = isjson;
  v6 = precom;
  lock = strbufs->lock;
  if ( pthread_mutex_lock(&lock->mutex) )
  {
    v27 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", *v27, "api.c", "print_data", 1196);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( pthread_rwlock_wrlock(&lock->rwlock) )
  {
    v28 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d", *v28, "api.c", "print_data", 1196);
    applog(3, tmp42, 1);
    quit(1);
  }
  v8 = k_unlink_head(strbufs, "api.c", "print_data", 1197);
  v9 = strbufs->lock;
  if ( pthread_rwlock_unlock(&v9->rwlock) )
  {
    v29 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d", *v29, "api.c", "print_data", 1198);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( pthread_mutex_unlock(&v9->mutex) )
  {
    v30 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v30, "api.c", "print_data", 1198);
    applog(3, tmp42, 1);
    quit(1);
  }
  selective_yield();
  p_data = (K_ITEM *)&v8->data;
  *((_DWORD *)v8->data + 1) = 0;
  if ( v6 )
    add_item_buf(p_data, ",");
  if ( v5 )
  {
    add_item_buf(p_data, "{");
    if ( !root )
      goto LABEL_26;
  }
  else if ( !root )
  {
    goto LABEL_19;
  }
  if ( v5 )
  {
LABEL_16:
    add_item_buf(p_data, "\"");
    add_item_buf(p_data, root->name);
    add_item_buf(p_data, "\"");
    add_item_buf(p_data, ":");
    type = root->type;
    switch ( root->type )
    {
      case api_data_type::API_ESCAPE:
        originala = (char *)root->data;
        v19 = escape_string(originala, 1);
        add_item_buf(p_data, "\"");
        add_item_buf(p_data, v19);
        add_item_buf(p_data, "\"");
        v20 = originala;
        goto LABEL_56;
      case api_data_type::API_STRING:
      case api_data_type::API_CONST:
        add_item_buf(p_data, "\"");
        data = (const char *)root->data;
        v22 = (K_ITEM *)&v8->data;
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
        add_item_buf(p_data, "\"");
        snprintf(buf, 0x40u, "0x%08x", *(_DWORD *)root->data);
        data = buf;
        v22 = (K_ITEM *)&v8->data;
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
    add_item_buf(p_data, "=");
    type = root->type;
    switch ( root->type )
    {
      case api_data_type::API_ESCAPE:
        original = (char *)root->data;
        v19 = escape_string(original, 0);
        add_item_buf(p_data, v19);
        v20 = original;
LABEL_56:
        if ( v20 != v19 )
          free(v19);
        break;
      case api_data_type::API_STRING:
      case api_data_type::API_CONST:
        add_item_buf(p_data, (const char *)root->data);
        break;
      case api_data_type::API_UINT8:
LABEL_29:
        snprintf(buf, 0x40u, "%u", *(unsigned __int8 *)root->data);
        goto LABEL_12;
      case api_data_type::API_INT16:
LABEL_28:
        snprintf(buf, 0x40u, "%d", *(__int16 *)root->data);
        goto LABEL_12;
      case api_data_type::API_UINT16:
LABEL_27:
        snprintf(buf, 0x40u, "%u", *(unsigned __int16 *)root->data);
        goto LABEL_12;
      case api_data_type::API_INT:
LABEL_46:
        snprintf(buf, 0x40u, "%d", *(_DWORD *)root->data);
        goto LABEL_12;
      case api_data_type::API_UINT:
      case api_data_type::API_UINT32:
LABEL_11:
        snprintf(buf, 0x40u, "%u", *(_DWORD *)root->data);
        goto LABEL_12;
      case api_data_type::API_HEX32:
        snprintf(buf, 0x40u, "0x%08x", *(_DWORD *)root->data);
        add_item_buf(p_data, buf);
        break;
      case api_data_type::API_UINT64:
LABEL_44:
        snprintf(buf, 0x40u, "%llu", *(_QWORD *)root->data);
        goto LABEL_12;
      case api_data_type::API_INT64:
LABEL_43:
        snprintf(buf, 0x40u, "%lld", *(_QWORD *)root->data);
        goto LABEL_12;
      case api_data_type::API_DOUBLE:
LABEL_42:
        snprintf(buf, 0x40u, "%f", *(double *)root->data);
        goto LABEL_12;
      case api_data_type::API_ELAPSED:
LABEL_41:
        snprintf(buf, 0x40u, "%.0f", *(double *)root->data);
        goto LABEL_12;
      case api_data_type::API_BOOL:
LABEL_38:
        v18 = "false";
        if ( *(_BYTE *)root->data )
          v18 = "true";
        snprintf(buf, 0x40u, "%s", v18);
        goto LABEL_12;
      case api_data_type::API_TIMEVAL:
LABEL_37:
        snprintf(buf, 0x40u, "%ld.%06ld", *(_DWORD *)root->data, *((_DWORD *)root->data + 1));
        goto LABEL_12;
      case api_data_type::API_TIME:
LABEL_36:
        snprintf(buf, 0x40u, "%lu", *(_DWORD *)root->data);
        goto LABEL_12;
      case api_data_type::API_MHS:
      case api_data_type::API_UTILITY:
      case api_data_type::API_FREQ:
LABEL_35:
        snprintf(buf, 0x40u, "%.2f", *(double *)root->data);
        goto LABEL_12;
      case api_data_type::API_MHTOTAL:
LABEL_34:
        snprintf(buf, 0x40u, "%.4f", *(double *)root->data);
        goto LABEL_12;
      case api_data_type::API_TEMP:
LABEL_33:
        snprintf(buf, 0x40u, "%.2f", *(float *)root->data);
        goto LABEL_12;
      case api_data_type::API_VOLTS:
      case api_data_type::API_AVG:
LABEL_32:
        snprintf(buf, 0x40u, "%.3f", *(float *)root->data);
        goto LABEL_12;
      case api_data_type::API_HS:
LABEL_31:
        snprintf(buf, 0x40u, "%.15f", *(double *)root->data);
        goto LABEL_12;
      case api_data_type::API_DIFF:
LABEL_30:
        snprintf(buf, 0x40u, "%.8f", *(double *)root->data);
        goto LABEL_12;
      case api_data_type::API_PERCENT:
LABEL_45:
        snprintf(buf, 0x40u, "%.4f", *(double *)root->data * 100.0);
LABEL_12:
        add_item_buf(p_data, buf);
        break;
      default:
LABEL_49:
        if ( use_syslog || opt_log_output || opt_log_level > 2 )
        {
          snprintf(tmp42, 0x1000u, "API: unknown2 data type %d ignored", type);
          applog(3, tmp42, 0);
        }
        if ( v5 )
        {
          add_item_buf(p_data, "\"");
          data = "Unknown";
          v22 = (K_ITEM *)&v8->data;
LABEL_60:
          add_item_buf(v22, data);
          add_item_buf(p_data, "\"");
        }
        else
        {
          add_item_buf(p_data, "Unknown");
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
    v14 = root;
    root = next;
    next->prev = prev;
    prev->next = next;
    free(v14);
    add_item_buf(p_data, ",");
    if ( v5 )
      goto LABEL_16;
  }
  free(root);
  if ( !v5 )
  {
LABEL_19:
    add_item_buf(p_data, (const char *)&word_4F67C);
    goto LABEL_20;
  }
LABEL_26:
  add_item_buf(p_data, "}");
LABEL_20:
  io_add(io_data, *(char **)v8->data);
  v15 = strbufs->lock;
  if ( pthread_mutex_lock(&v15->mutex) )
  {
    v23 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", *v23, "api.c", "print_data", 1368);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( pthread_rwlock_wrlock(&v15->rwlock) )
  {
    v24 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d", *v24, "api.c", "print_data", 1368);
    applog(3, tmp42, 1);
    quit(1);
  }
  k_add_head(strbufs, v8, "api.c", "print_data", 1369);
  v16 = strbufs->lock;
  if ( pthread_rwlock_unlock(&v16->rwlock) )
  {
    v25 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d", *v25, "api.c", "print_data", 1370);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( pthread_mutex_unlock(&v16->mutex) )
  {
    v26 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v26, "api.c", "print_data", 1370);
    applog(3, tmp42, 1);
    quit(1);
  }
  selective_yield();
  return 0;
}
