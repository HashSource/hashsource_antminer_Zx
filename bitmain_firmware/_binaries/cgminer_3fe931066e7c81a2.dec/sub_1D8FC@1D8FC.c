void __fastcall __noreturn sub_1D8FC(int a1, int a2)
{
  pthread_t newthread[2]; // [sp+4h] [bp-8h] BYREF

  if ( !pthread_create(newthread, 0, (void *(*)(void *))sub_11C1C, 0) )
  {
    if ( a2 )
    {
      sub_2A84C((struct timeval *)&dword_77148);
      sub_19ADC();
      if ( !byte_7BB18 && byte_78CA9 )
        sub_1C668();
    }
    else
    {
      sub_19ADC();
    }
    if ( dword_7728C > 0 )
    {
      kill(dword_7728C, 15);
      dword_7728C = 0;
    }
    pthread_cancel(newthread[0]);
    exit(a1);
  }
  exit(1);
}
