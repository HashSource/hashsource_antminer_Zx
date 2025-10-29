void __noreturn show_stats_func_z15_3chips()
{
  char str[16]; // [sp+8h] [bp+0h] BYREF
  int len; // [sp+18h] [bp+10h]
  int time_counter; // [sp+1Ch] [bp+14h]

  time_counter = 0;
  while ( 1 )
  {
    memset(lcd_output, 32, sizeof(lcd_output));
    sprintf(lcd_output, "time %ds", time_counter);
    memset(str, 0, sizeof(str));
    sprintf(
      str,
      "nonce=%d %d %d",
      *g_patten.asic_recv_nonces,
      g_patten.asic_recv_nonces[1],
      g_patten.asic_recv_nonces[2]);
    len = strlen(str);
    memset(&str[len], 32, 16 - len);
    *(_DWORD *)&lcd_output[16] = *(_DWORD *)str;
    *(_DWORD *)&lcd_output[20] = *(_DWORD *)&str[4];
    *(_DWORD *)&lcd_output[24] = *(_DWORD *)&str[8];
    *(_DWORD *)&lcd_output[28] = *(_DWORD *)&str[12];
    sprintf(&lcd_output[32], "chip: %d'C      ", chip_high);
    sprintf(&lcd_output[48], "pcb : %d'C      ", pcb_high);
    ++time_counter;
    write(cgpu.lcd_fd, lcd_output, 0x40u);
    usleep((__useconds_t)&nonce_fifo.nonce_buffer[508].Nonce[1188]);
  }
}
