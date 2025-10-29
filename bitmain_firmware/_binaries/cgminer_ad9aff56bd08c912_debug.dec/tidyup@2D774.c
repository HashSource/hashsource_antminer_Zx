void __fastcall tidyup(void *arg)
{
  const char *v2; // r2
  int v3; // r3
  int v4; // r0
  io_list *v5; // r6
  io_list *v6; // r4
  io_list *next; // r5
  io_list *v8; // r0
  const char *v9; // r2
  int v10; // r3

  if ( pthread_mutex_lock(&quit_restart_lock) )
    mutex_lock_1((pthread_mutex_t *)&_func___12372, (const char *)0x120C, v2, v3);
  v4 = *(_DWORD *)arg;
  bye = 1;
  if ( v4 != -1 )
  {
    shutdown(v4, 2);
    close(*(_DWORD *)arg);
    *(_DWORD *)arg = -1;
  }
  if ( ipaccess )
  {
    free(ipaccess);
    ipaccess = 0;
  }
  v5 = io_head;
  if ( io_head )
  {
    v6 = io_head;
    do
    {
      next = v6->next;
      free(v6->io_data->ptr);
      free(v6->io_data);
      v8 = v6;
      v6 = next;
      free(v8);
    }
    while ( v5 != next );
    io_head = 0;
  }
  if ( pthread_mutex_unlock(&quit_restart_lock) )
    mutex_unlock_noyield_1((pthread_mutex_t *)&_func___12372, (const char *)0x1221, v9, v10);
  selective_yield();
}
