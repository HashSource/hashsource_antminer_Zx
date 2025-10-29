int __fastcall sub_295A8(int a1)
{
  pthread_mutex_t *v1; // r5
  int v3; // r0

  v1 = (pthread_mutex_t *)(a1 + 728);
  if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 728)) )
    sub_B708("clear_sock", 1955);
  do
    v3 = *(_DWORD *)(a1 + 612);
  while ( v3 && recv(v3, *(void **)(a1 + 616), 0x1FFCu, 0) > 0 );
  sub_29388(v1, "clear_sock", 1964);
  off_75ED8();
  return sub_28AE8(a1);
}
