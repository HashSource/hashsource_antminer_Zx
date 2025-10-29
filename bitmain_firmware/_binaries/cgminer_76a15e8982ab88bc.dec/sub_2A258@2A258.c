int __fastcall sub_2A258(int a1, const struct timespec *a2)
{
  pthread_mutex_t *v2; // r5
  int *v5; // r3
  _DWORD *v6; // r1
  int v7; // r12
  int v8; // r4
  int v10; // r0

  v2 = (pthread_mutex_t *)(a1 + 12);
  if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 12)) )
    sub_B650("tq_pop", 1286);
  v5 = *(int **)a1;
  if ( a1 != *(_DWORD *)a1 )
    goto LABEL_3;
  if ( a2 )
    v10 = pthread_cond_timedwait((pthread_cond_t *)(a1 + 40), v2, a2);
  else
    v10 = pthread_cond_wait((pthread_cond_t *)(a1 + 40), v2);
  if ( v10 )
  {
    v8 = 0;
    goto LABEL_4;
  }
  v5 = *(int **)a1;
  if ( a1 == *(_DWORD *)a1 )
  {
    v8 = 0;
  }
  else
  {
LABEL_3:
    v6 = (_DWORD *)v5[1];
    v7 = *v5;
    v8 = *(v5 - 1);
    *(_DWORD *)(v7 + 4) = v6;
    *v6 = v7;
    *v5 = 0;
    v5[1] = 0;
    free(v5 - 1);
  }
LABEL_4:
  sub_292E0(v2, "tq_pop", 1305);
  off_72D18();
  return v8;
}
