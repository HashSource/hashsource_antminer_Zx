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
  void **data_memory; // r0
  int v20; // r1
  void **v21; // r0
  void *v22; // r0
  char tmp42[4096]; // [sp+20h] [bp-1000h] BYREF

  if ( list->is_store )
  {
    snprintf(
      tmp42,
      0x1000u,
      "List %s store can't %s() - from %s %s() line %d in %s %s():%d",
      list->name,
      "k_alloc_items",
      file,
      func,
      line,
      "klist.c",
      "k_alloc_items",
      19);
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
    snprintf(
      tmp42,
      0x1000u,
      "List %s item_memory failed to realloc count=%d in %s %s():%d",
      list->name,
      list->item_mem_count,
      "klist.c",
      "k_alloc_items",
      33);
    applog(3, tmp42, 1);
    quit(1);
  }
  v11 = (k_item *)calloc(allocate, 0x10u);
  if ( !v11 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "List %s failed to calloc %d new items - total was %d, limit was %d in %s %s():%d",
      list->name,
      allocate,
      list->total,
      list->limit,
      "klist.c",
      "k_alloc_items",
      38);
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
  do
  {
    data_memory = list->data_memory;
    v20 = list->data_mem_count + 1;
    list->data_mem_count = v20;
    v21 = (void **)realloc(data_memory, 4 * v20);
    list->data_memory = v21;
    if ( !v21 )
    {
      snprintf(
        tmp42,
        0x1000u,
        "List %s data_memory failed to realloc count=%d in %s %s():%d",
        list->name,
        list->data_mem_count,
        "klist.c",
        "k_alloc_items",
        69);
      applog(3, tmp42, 1);
      quit(1);
    }
    v22 = calloc(1u, list->siz);
    v11->data = v22;
    if ( !v22 )
    {
      snprintf(
        tmp42,
        0x1000u,
        "List %s failed to calloc item data in %s %s():%d",
        list->name,
        "klist.c",
        "k_alloc_items",
        73);
      applog(3, tmp42, 1);
      quit(1);
    }
    DWORD1073741823(list->data_memory[list->data_mem_count]) = v22;
    v11 = v11->next;
  }
  while ( v11 );
}
