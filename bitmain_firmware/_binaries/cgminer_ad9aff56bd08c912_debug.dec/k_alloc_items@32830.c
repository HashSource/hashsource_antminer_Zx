void __fastcall k_alloc_items(K_LIST *list, const char *file, const char *func, const int line)
{
  int limit; // r3
  int total; // r2
  int allocate; // r6
  void **item_memory; // r0
  __int64 v9; // kr00_8
  void **v10; // r0
  k_item *v11; // r5
  int v12; // r3
  const char *name; // r1
  __int64 v14; // r2
  _BOOL4 do_tail; // r2
  int v16; // r6
  k_item *v17; // r3
  k_item *v18; // r6
  const char *v19; // r8
  int v20; // r7
  int v21; // r6
  void **data_memory; // r0
  int v23; // r1
  void **v24; // r0
  void *v25; // r0
  const char *v26; // r2
  int v27; // r0
  int v28; // r5
  const char *v29; // r2
  int v30; // r1
  const char *v31; // r2
  int v32; // r1
  const char *v33; // r2
  int linea; // [sp+Ch] [bp-1014h]
  char tmp42[4096]; // [sp+20h] [bp-1000h] BYREF

  if ( list->is_store )
  {
    LOWORD(v27) = 26796;
    LOWORD(v28) = 27080;
    HIWORD(v27) = (unsigned int)"reated" >> 16;
    HIWORD(v28) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    LOWORD(v29) = 27016;
    HIWORD(v29) = (unsigned int)"" >> 16;
    snprintf(tmp42, 0x1000u, v29, list->name, v27, file, func, line, v28, v27, 19);
    applog(3, tmp42, 1);
    quit(1);
  }
  limit = list->limit;
  if ( limit <= 0 )
  {
    allocate = list->allocate;
  }
  else
  {
    total = list->total;
    if ( limit <= total )
      return;
    allocate = list->allocate;
    if ( limit < total + allocate )
      allocate = limit - total;
  }
  v9 = *(_QWORD *)&list->item_mem_count;
  item_memory = list->item_memory;
  list->item_mem_count = v9 + 1;
  v10 = (void **)realloc(item_memory, 4 * (v9 + 1));
  list->item_memory = v10;
  if ( !v10 )
  {
    LOWORD(v30) = 27080;
    HIWORD(v30) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    LOWORD(v31) = 27088;
    HIWORD(v31) = (unsigned int)"transfer_to_tail" >> 16;
    snprintf(tmp42, 0x1000u, v31, list->name, list->item_mem_count, v30, "k_alloc_items", 33);
    applog(3, tmp42, 1);
    quit(1);
  }
  v11 = (k_item *)calloc(allocate, 0x10u);
  if ( !v11 )
  {
    LOWORD(v32) = 26796;
    LOWORD(v33) = 27080;
    HIWORD(v32) = (unsigned int)"reated" >> 16;
    HIWORD(v33) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    linea = (int)v33;
    LOWORD(v33) = 27152;
    HIWORD(v33) = (unsigned int)"e can't %s() - from %s %s() line %d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v33, list->name, allocate, list->total, list->limit, linea, v32, 38);
    applog(3, tmp42, 1);
    quit(1);
  }
  DWORD1073741823(list->item_memory[list->item_mem_count]) = v11;
  v12 = list->total;
  name = list->name;
  list->count = allocate;
  list->count_up = allocate;
  list->total = v12 + allocate;
  v11->name = name;
  v11->prev = 0;
  v11->next = v11 + 1;
  if ( allocate > 2 )
  {
    HIDWORD(v14) = v11 + 2;
    do
    {
      LODWORD(v14) = HIDWORD(v14) - 32;
      *(_DWORD *)(HIDWORD(v14) - 16) = name;
      *(_QWORD *)(HIDWORD(v14) - 12) = v14;
      HIDWORD(v14) += 16;
    }
    while ( (k_item *)HIDWORD(v14) != &v11[allocate] );
  }
  do_tail = list->do_tail;
  v16 = allocate + 0xFFFFFFF;
  list->head = v11;
  v11[v16].name = name;
  v17 = &v11[v16 - 1];
  v18 = &v11[v16];
  v18->prev = v17;
  v18->next = 0;
  if ( do_tail )
    list->tail = v18;
  LOWORD(v20) = 26796;
  LOWORD(v21) = 27080;
  LOWORD(v19) = 27236;
  HIWORD(v20) = (unsigned int)"reated" >> 16;
  HIWORD(v21) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
  do
  {
    data_memory = list->data_memory;
    v23 = list->data_mem_count + 1;
    list->data_mem_count = v23;
    v24 = (void **)realloc(data_memory, 4 * v23);
    list->data_memory = v24;
    if ( !v24 )
    {
      HIWORD(v19) = (unsigned int)"ed to realloc count=%d in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v19, list->name, list->data_mem_count, v21, v20, 69);
      applog(3, tmp42, 1);
      quit(1);
    }
    v25 = calloc(1u, list->siz);
    v11->data = v25;
    if ( !v25 )
    {
      LOWORD(v26) = 27300;
      HIWORD(v26) = (unsigned int)" %d new items - total was %d, limit was %d in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v26, list->name, v21, v20, 73);
      applog(3, tmp42, 1);
      quit(1);
    }
    DWORD1073741823(list->data_memory[list->data_mem_count]) = v25;
    v11 = v11->next;
  }
  while ( v11 );
}
