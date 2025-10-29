int sub_17210()
{
  int result; // r0
  pthread_t newthread[2]; // [sp+4h] [bp-8h] BYREF

  sub_2A84C(&stru_76F04);
  result = pthread_create(newthread, 0, sub_231F0, 0);
  if ( result )
    sub_B3C8();
  return result;
}
