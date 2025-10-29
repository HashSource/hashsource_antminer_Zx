int sub_16C8C()
{
  int result; // r0
  pthread_t newthread[2]; // [sp+4h] [bp-8h] BYREF

  sub_2B13C(&stru_611B4);
  result = pthread_create(newthread, 0, sub_22EC4, 0);
  if ( result )
    sub_B498();
  return result;
}
