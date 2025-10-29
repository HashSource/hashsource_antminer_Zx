api_data *__fastcall api_add_data_full(api_data *root, char *name, api_data_type type, void *data, bool copy_data)
{
  api_data *v9; // r4
  char *v10; // r0
  api_data *prev; // r3
  api_data *v12; // r9
  api_data *result; // r0
  _DWORD *v14; // r0
  int v15; // r3
  _WORD *v16; // r0
  __int16 v17; // r3
  _QWORD *v18; // r0
  __int64 v19; // r2
  size_t v20; // r5
  void *v21; // r0
  _BYTE *v22; // r0
  char v23; // r3
  _BYTE *v24; // r0
  char v25; // r3
  _DWORD *v26; // r0
  int v27; // r1
  _DWORD *v28; // r2
  int v29; // r0
  _DWORD *v30; // r0
  int v31; // r3

  v9 = (api_data *)malloc(0x18u);
  v10 = _strdup(name);
  v9->type = type;
  v9->name = v10;
  if ( root )
  {
    prev = root->prev;
    v12 = root;
    v9->next = root;
    root->prev = v9;
    v9->prev = prev;
    prev->next = v9;
  }
  else
  {
    v9->prev = v9;
    v12 = v9;
    v9->next = v9;
  }
  v9->data_was_malloc = copy_data;
  if ( !data )
  {
    v9->data_was_malloc = 0;
    data = "(null)";
    v9->type = api_data_type::API_CONST;
LABEL_7:
    v9->data = data;
    return v12;
  }
  if ( !copy_data )
    goto LABEL_7;
  switch ( type )
  {
    case api_data_type::API_UINT8:
      v24 = malloc(4u);
      v25 = *(_BYTE *)data;
      v9->data = v24;
      *v24 = v25;
      return v12;
    case api_data_type::API_INT16:
    case api_data_type::API_UINT16:
      v16 = malloc(4u);
      v17 = *(_WORD *)data;
      v9->data = v16;
      *v16 = v17;
      return v12;
    case api_data_type::API_INT:
    case api_data_type::API_UINT:
    case api_data_type::API_UINT32:
    case api_data_type::API_HEX32:
    case api_data_type::API_TIME:
      v14 = malloc(4u);
      v15 = *(_DWORD *)data;
      v9->data = v14;
      *v14 = v15;
      result = v12;
      break;
    case api_data_type::API_UINT64:
    case api_data_type::API_INT64:
    case api_data_type::API_DOUBLE:
    case api_data_type::API_ELAPSED:
    case api_data_type::API_MHS:
    case api_data_type::API_MHTOTAL:
    case api_data_type::API_UTILITY:
    case api_data_type::API_FREQ:
    case api_data_type::API_HS:
    case api_data_type::API_DIFF:
    case api_data_type::API_PERCENT:
      v18 = malloc(8u);
      v19 = *(_QWORD *)data;
      v9->data = v18;
      *v18 = v19;
      return v12;
    case api_data_type::API_BOOL:
      v22 = malloc(1u);
      v23 = *(_BYTE *)data;
      v9->data = v22;
      *v22 = v23;
      return v12;
    case api_data_type::API_TIMEVAL:
      v26 = malloc(8u);
      v27 = *((_DWORD *)data + 1);
      v28 = v26;
      v29 = *(_DWORD *)data;
      v9->data = v28;
      *v28 = v29;
      v28[1] = v27;
      return v12;
    case api_data_type::API_TEMP:
    case api_data_type::API_VOLTS:
    case api_data_type::API_AVG:
      v30 = malloc(4u);
      v31 = *(_DWORD *)data;
      v9->data = v30;
      *v30 = v31;
      return v12;
    default:
      v20 = strlen((const char *)data) + 1;
      v21 = malloc(v20);
      v9->data = v21;
      memcpy(v21, data, v20);
      return v12;
  }
  return result;
}
