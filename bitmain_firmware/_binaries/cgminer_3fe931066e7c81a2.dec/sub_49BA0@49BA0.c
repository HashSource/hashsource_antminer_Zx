int __fastcall sub_49BA0(int a1)
{
  int v1; // r4
  int v2; // r6

  v1 = (a1 << 16) | 0x1900000;
  pthread_mutex_lock(&stru_790A0);
  v2 = sub_3C708(v1);
  sub_3C708(v1);
  sub_2A92C();
  pthread_mutex_unlock(&stru_790A0);
  return v2;
}
