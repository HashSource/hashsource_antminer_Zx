unsigned int __fastcall uart_send(unsigned __int8 which_uart, volatile unsigned __int8 *buf, unsigned int length)
{
  int v3; // r9
  int v5; // r10
  char v6; // r8
  int v7; // r11
  unsigned int *v8; // r4
  int v9; // r7
  unsigned int v10; // r7
  unsigned __int8 *v11; // r2
  int v12; // r3
  unsigned int v13; // r2
  int v14; // r3
  int v15; // r7
  unsigned int v16; // r1
  int v18; // [sp+0h] [bp-1224h]
  pthread_mutex_t *mutex; // [sp+8h] [bp-121Ch]
  int v20; // [sp+Ch] [bp-1218h]
  unsigned int chain_send_buffer_addr; // [sp+14h] [bp-1210h]
  unsigned __int8 send_buf[512]; // [sp+20h] [bp-1204h] BYREF
  char tmp42[4100]; // [sp+220h] [bp-1004h] BYREF

  v3 = which_uart;
  memset(send_buf, 0, sizeof(send_buf));
  mutex = &uart_send_mutex[v3];
  pthread_mutex_lock(mutex);
  switch ( v3 )
  {
    case 0:
      v5 = 96;
      chain_send_buffer_addr = 101;
      v6 = 24;
      v20 = 100;
      goto LABEL_3;
    case 1:
      v5 = 96;
      v6 = 16;
      chain_send_buffer_addr = 103;
      v20 = 102;
      goto LABEL_3;
    case 2:
      v5 = 96;
      chain_send_buffer_addr = 105;
      v6 = 8;
      v20 = 104;
      goto LABEL_3;
    case 3:
      v5 = 96;
      chain_send_buffer_addr = 107;
      v6 = 0;
      v20 = 106;
      goto LABEL_3;
    case 4:
      v5 = 97;
      chain_send_buffer_addr = 109;
      v6 = 24;
      v20 = 108;
      goto LABEL_3;
    case 5:
      v5 = 97;
      chain_send_buffer_addr = 111;
      v6 = 16;
      v20 = 110;
      goto LABEL_3;
    case 6:
      v5 = 97;
      chain_send_buffer_addr = 113;
      v6 = 8;
      v20 = 112;
      goto LABEL_3;
    case 7:
      v5 = 97;
      chain_send_buffer_addr = 115;
      v6 = 0;
      v20 = 114;
      goto LABEL_3;
    case 8:
      v5 = 98;
      chain_send_buffer_addr = 117;
      v6 = 24;
      v20 = 116;
      goto LABEL_3;
    case 9:
      v5 = 98;
      chain_send_buffer_addr = 119;
      v6 = 16;
      v20 = 118;
LABEL_3:
      v7 = 21;
      break;
    default:
      if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
        return 0;
      snprintf(tmp42, 0x1000u, "%s: The uart%d is not supported!!!\n", "uart_send", v18);
      goto LABEL_33;
  }
  while ( 1 )
  {
    v8 = axi_fpga_addr;
    if ( length <= (unsigned __int8)(axi_fpga_addr[v5] >> v6) )
      break;
    usleep(0xBB8u);
    if ( !--v7 )
    {
      pthread_mutex_unlock(mutex);
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        snprintf(tmp42, 0x1000u, "%s: uart%d always dose not has enough send fifo space, break\n", "uart_send", v3);
LABEL_33:
        applog(5, tmp42, 0);
      }
      return 0;
    }
  }
  if ( (axi_fpga_addr[v20] & 0x80000000) != 0 )
  {
    v9 = 21;
    while ( 1 )
    {
      usleep(0xBB8u);
      v8 = axi_fpga_addr;
      if ( (axi_fpga_addr[v20] & 0x80000000) == 0 )
        break;
      if ( !--v9 )
      {
        pthread_mutex_unlock(mutex);
        if ( use_syslog || opt_log_output || opt_log_level > 4 )
        {
          snprintf(tmp42, 0x1000u, "%s: uart%d always busy, break\n", "uart_send", v3);
          goto LABEL_33;
        }
        return 0;
      }
    }
  }
  memcpy(send_buf, (const void *)buf, length);
  v10 = length >> 2;
  if ( length >> 2 )
  {
    v11 = send_buf;
    do
    {
      v12 = v11[1];
      v11 += 4;
      v8[chain_send_buffer_addr] = (v12 << 16) | (*(v11 - 4) << 24) | *(v11 - 1) | (*(v11 - 2) << 8);
      v8 = axi_fpga_addr;
    }
    while ( &send_buf[4 * v10] != v11 );
  }
  v13 = length & 3;
  if ( (length & 3) != 0 )
  {
    v14 = send_buf[4 * v10];
    v15 = 4 * v10;
    v16 = v14 << 24;
    if ( v13 == 2 )
    {
      v16 |= send_buf[v15 + 1] << 16;
    }
    else if ( v13 == 3 )
    {
      v16 |= (send_buf[v15 + 2] << 8) | (send_buf[v15 + 1] << 16);
    }
    v8[chain_send_buffer_addr] = v16;
    v8 = axi_fpga_addr;
  }
  v8[v20] = length | 0x80000000;
  pthread_mutex_unlock(mutex);
  return length;
}
