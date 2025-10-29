int __fastcall sub_48A0C(int a1)
{
  int v1; // r4
  int v2; // r6

  v1 = (a1 << 16) | 0x1900000;
  pthread_mutex_lock(&stru_75EE0);
  v2 = sub_3C3E8(v1);
  sub_3C3E8(v1);
  sub_2A884();
  pthread_mutex_unlock(&stru_75EE0);
  return v2;
}
