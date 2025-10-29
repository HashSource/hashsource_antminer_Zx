unsigned int __fastcall clear_uart_send_fifo(unsigned __int8 which_chain)
{
  int v1; // r5
  int v2; // r10
  char v3; // r9
  int v4; // r4
  unsigned int v5; // r8
  unsigned int v6; // r8
  pthread_mutex_t *mutex; // [sp+4h] [bp-10h]

  v1 = which_chain;
  printf("--- %s\n", "clear_uart_send_fifo");
  mutex = &uart_send_mutex[v1];
  pthread_mutex_lock(mutex);
  switch ( v1 )
  {
    case 0:
      v2 = 96;
      v3 = 24;
      goto LABEL_3;
    case 1:
      v2 = 96;
      v3 = 16;
      goto LABEL_3;
    case 2:
      v2 = 96;
      v3 = 8;
      goto LABEL_3;
    case 3:
      v2 = 96;
      v3 = 0;
      goto LABEL_3;
    case 4:
      v2 = 97;
      v3 = 24;
      goto LABEL_3;
    case 5:
      v2 = 97;
      v3 = 16;
      goto LABEL_3;
    case 6:
      v2 = 97;
      v3 = 8;
      goto LABEL_3;
    case 7:
      v2 = 97;
      v3 = 0;
      goto LABEL_3;
    case 8:
      v2 = 98;
      v3 = 24;
      goto LABEL_3;
    case 9:
      v2 = 98;
      v3 = 16;
LABEL_3:
      v4 = 21;
      break;
    default:
      printf("%s: The uart%d is not supported!!!\n", "clear_uart_send_fifo", v1);
      v6 = 1;
      pthread_mutex_unlock(mutex);
      return v6;
  }
  while ( 1 )
  {
    v5 = (unsigned __int8)(axi_fpga_addr[v2] >> v3);
    if ( v5 == 255 )
      break;
    printf("%s: waiting fpga uart%d clear send fifo space ...\n", "clear_uart_send_fifo", v1);
    usleep(0xBB8u);
    if ( !--v4 )
    {
      printf("%s: uart%d always dose not has enough send fifo space, break\n", "clear_uart_send_fifo", v1);
      pthread_mutex_unlock(mutex);
      return v5;
    }
  }
  v6 = 0;
  pthread_mutex_unlock(mutex);
  return v6;
}
