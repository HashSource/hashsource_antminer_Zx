void __fastcall __noreturn sub_1D26C(int a1, int a2)
{
  pthread_t newthread[2]; // [sp+4h] [bp-8h] BYREF

  if ( !pthread_create(newthread, 0, (void *(*)(void *))sub_11B54, 0) )
  {
    if ( a2 )
    {
      sub_2A7A4((struct timeval *)&dword_73F80);
      sub_195CC();
      if ( !byte_78940 && byte_75AE8 )
        sub_1BFD8();
    }
    else
    {
      sub_195CC();
    }
    if ( dword_740C4 > 0 )
    {
      kill(dword_740C4, 15);
      dword_740C4 = 0;
    }
    pthread_cancel(newthread[0]);
    exit(a1);
  }
  exit(1);
}
