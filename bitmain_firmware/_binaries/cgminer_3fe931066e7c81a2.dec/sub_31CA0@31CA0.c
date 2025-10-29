int __fastcall sub_31CA0(int a1)
{
  pthread_t v2; // r0

  v2 = pthread_self();
  pthread_detach(v2);
  pthread_setcanceltype(1, 0);
  sub_2F0B4("APIMcast");
  sub_3107C();
  *(_DWORD *)(a1 + 12) = 0;
  return 0;
}
