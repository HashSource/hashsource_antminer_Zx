int sub_17148()
{
  int result; // r0
  pthread_t newthread[2]; // [sp+4h] [bp-8h] BYREF

  sub_2A7A4(&stru_73D3C);
  result = pthread_create(newthread, 0, sub_23138, 0);
  if ( result )
    sub_B310();
  return result;
}
