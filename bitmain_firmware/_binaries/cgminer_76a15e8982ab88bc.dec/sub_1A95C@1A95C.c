void __fastcall sub_1A95C(pthread_rwlock_t *a1)
{
  void **nr_readers; // r5
  char v3[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( a1 && !pthread_rwlock_trywrlock(a1 + 10) )
  {
    nr_readers = (void **)a1[11].__nr_readers;
    a1[11].__nr_readers = 0;
    if ( pthread_rwlock_unlock(a1 + 10) )
      sub_B578("flush_queue", 8991);
    off_72D18();
    if ( nr_readers )
    {
      sub_156B8(nr_readers);
      if ( byte_75C49 )
      {
        if ( byte_77B70 || byte_75C48 || dword_73504 > 6 )
        {
          strcpy(v3, "Discarded queued work item");
          sub_385C8(7, v3, 0);
        }
      }
    }
  }
}
