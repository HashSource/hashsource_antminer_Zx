int __fastcall sub_3BD70(int a1)
{
  int v2; // r10
  char v3; // r8
  int v4; // r4
  int v5; // r5

  printf("--- %s\n", "clear_uart_send_fifo");
  pthread_mutex_lock(&stru_75CFC[a1]);
  switch ( a1 )
  {
    case 0:
      v2 = 4096;
      v3 = 24;
      goto LABEL_3;
    case 1:
      v2 = 4096;
      v3 = 16;
      goto LABEL_3;
    case 2:
      v2 = 4096;
      v3 = 8;
      goto LABEL_3;
    case 3:
      v2 = 4096;
      v3 = 0;
      goto LABEL_3;
    case 4:
      v2 = 4100;
      v3 = 24;
      goto LABEL_3;
    case 5:
      v2 = 4100;
      v3 = 16;
      goto LABEL_3;
    case 6:
      v2 = 4100;
      v3 = 8;
      goto LABEL_3;
    case 7:
      v2 = 4100;
      v3 = 0;
      goto LABEL_3;
    case 8:
      v2 = 4104;
      v3 = 24;
      goto LABEL_3;
    case 9:
      v2 = 4104;
      v3 = 16;
LABEL_3:
      v4 = 21;
      break;
    default:
      v5 = 1;
      printf("%s: The uart%d is not supported!!!\n", "clear_uart_send_fifo", a1);
      pthread_mutex_unlock(&stru_75CFC[a1]);
      return v5;
  }
  while ( 1 )
  {
    v5 = (unsigned __int8)(*(_DWORD *)(dword_75C50[0] + v2) >> v3);
    if ( v5 == 255 )
      break;
    printf("%s: waiting fpga uart%d clear send fifo space ...\n", "clear_uart_send_fifo", a1);
    usleep(0xBB8u);
    if ( !--v4 )
    {
      printf("%s: uart%d always dose not has enough send fifo space, break\n", "clear_uart_send_fifo", a1);
      pthread_mutex_unlock(&stru_75CFC[a1]);
      return v5;
    }
  }
  v5 = 0;
  pthread_mutex_unlock(&stru_75CFC[a1]);
  return v5;
}
