int __fastcall sub_29500(int a1)
{
  pthread_mutex_t *v1; // r5
  int v3; // r0

  v1 = (pthread_mutex_t *)(a1 + 728);
  if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 728)) )
    sub_B650("clear_sock", 1955);
  do
    v3 = *(_DWORD *)(a1 + 612);
  while ( v3 && recv(v3, *(void **)(a1 + 616), 0x1FFCu, 0) > 0 );
  sub_292E0(v1, "clear_sock", 1964);
  off_72D18();
  return sub_28A40(a1);
}
