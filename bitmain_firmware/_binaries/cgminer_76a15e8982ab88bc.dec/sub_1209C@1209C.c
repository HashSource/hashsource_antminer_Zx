int __fastcall sub_1209C(int a1)
{
  pthread_t v2; // r0

  v2 = pthread_self();
  pthread_detach(v2);
  pthread_setcanceltype(1, 0);
  sub_2EF24("API");
  sub_1202C();
  sub_365FC(dword_73D30);
  *(_DWORD *)(a1 + 12) = 0;
  return 0;
}
