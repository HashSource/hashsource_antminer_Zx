void __fastcall sub_1AA18(pthread_rwlock_t *a1)
{
  void **nr_readers; // r5
  char v3[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( a1 && !pthread_rwlock_trywrlock(a1 + 10) )
  {
    nr_readers = (void **)a1[11].__nr_readers;
    a1[11].__nr_readers = 0;
    if ( pthread_rwlock_unlock(a1 + 10) )
      sub_B630("flush_queue", 9004);
    off_75ED8();
    if ( nr_readers )
    {
      sub_15780(nr_readers);
      if ( byte_78E09 )
      {
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 6 )
        {
          strcpy(v3, "Discarded queued work item");
          sub_38730(7, v3, 0);
        }
      }
    }
  }
}
