int __fastcall sub_3C0A0(int a1)
{
  pthread_mutex_t *v2; // r5
  size_t v3; // r0
  unsigned int v4; // r6
  _BYTE *v5; // r7
  unsigned int v6; // r0

  v2 = (pthread_mutex_t *)((char *)&unk_78FAC + 24 * a1);
  pthread_mutex_lock(v2);
  v3 = sub_3BB78(a1);
  v4 = v3;
  if ( v3 )
  {
    v5 = malloc(v3);
    if ( v5 )
    {
      v6 = sub_3BD44(a1, v5, v4);
      if ( v6 != v4 )
        printf("%s: uart%d clear rx fifo error. nbytes = %d, len = %d\n", "clear_uart_rx_fifo", a1, v4, v6);
      free(v5);
    }
    usleep((__useconds_t)&unk_7A120);
    pthread_mutex_unlock(v2);
    return 1;
  }
  else
  {
    pthread_mutex_unlock(v2);
    return 0;
  }
}
