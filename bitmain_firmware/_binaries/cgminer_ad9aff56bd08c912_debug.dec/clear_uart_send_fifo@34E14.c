unsigned int __fastcall clear_uart_send_fifo(unsigned __int8 which_chain)
{
  int v1; // r5
  const char *v2; // r0
  int v3; // r10
  char v4; // r9
  const char *v5; // r6
  int v6; // r4
  unsigned int v7; // r8
  unsigned int v8; // r8
  const char *v10; // r0
  const char *v11; // r0
  pthread_mutex_t *mutex; // [sp+4h] [bp-10h]

  v1 = which_chain;
  LOWORD(v2) = -31320;
  HIWORD(v2) = (unsigned int)"ap failed!" >> 16;
  printf(v2, "clear_uart_send_fifo");
  mutex = &uart_send_mutex[v1];
  pthread_mutex_lock(mutex);
  switch ( v1 )
  {
    case 0:
      v3 = 96;
      v4 = 24;
      goto LABEL_3;
    case 1:
      v3 = 96;
      v4 = 16;
      goto LABEL_3;
    case 2:
      v3 = 96;
      v4 = 8;
      goto LABEL_3;
    case 3:
      v3 = 96;
      v4 = 0;
      goto LABEL_3;
    case 4:
      v3 = 97;
      v4 = 24;
      goto LABEL_3;
    case 5:
      v3 = 97;
      v4 = 16;
      goto LABEL_3;
    case 6:
      v3 = 97;
      v4 = 8;
      goto LABEL_3;
    case 7:
      v3 = 97;
      v4 = 0;
      goto LABEL_3;
    case 8:
      v3 = 98;
      v4 = 24;
      goto LABEL_3;
    case 9:
      v3 = 98;
      v4 = 16;
LABEL_3:
      LOWORD(v5) = -31312;
      v6 = 21;
      break;
    default:
      LOWORD(v11) = -31356;
      HIWORD(v11) = (unsigned int)"a_mem_addr = 0x%x\n" >> 16;
      printf(v11, "clear_uart_send_fifo", v1);
      v8 = 1;
      pthread_mutex_unlock(mutex);
      return v8;
  }
  while ( 1 )
  {
    v7 = (unsigned __int8)(axi_fpga_addr[v3] >> v4);
    if ( v7 == 255 )
      break;
    HIWORD(v5) = (unsigned int)"d!" >> 16;
    printf(v5, "clear_uart_send_fifo", v1);
    usleep(0xBB8u);
    if ( !--v6 )
    {
      LOWORD(v10) = -31260;
      HIWORD(v10) = (unsigned int)"t ASIC baud = %d, error!!!\n" >> 16;
      printf(v10, "clear_uart_send_fifo", v1);
      pthread_mutex_unlock(mutex);
      return v7;
    }
  }
  v8 = 0;
  pthread_mutex_unlock(mutex);
  return v8;
}
