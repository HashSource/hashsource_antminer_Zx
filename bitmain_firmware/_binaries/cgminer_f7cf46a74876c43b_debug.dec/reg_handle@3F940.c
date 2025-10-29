void __fastcall reg_handle(uint8_t *str, int len, uint32_t chainid)
{
  char v4; // r6
  int v5; // r0
  uint32_t p_wr; // r1
  bool v7; // cc
  uint32_t v8; // r3
  char *v9; // r3
  uint8_t v10; // r2
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  v4 = chainid;
  v5 = CRC5(str + 2, 0x33u);
  if ( (str[8] & 0x1F) == v5 )
  {
    if ( reg_fifo.reg_value_num > 0x63 || reg_fifo.p_wr > 0x63 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        strcpy(tmp42, "Will Clean!");
        applog(5, tmp42, 0);
      }
      clear_register_value_buf();
    }
    else
    {
      pthread_mutex_lock(&reg_mutex);
      p_wr = reg_fifo.p_wr;
      v7 = reg_fifo.p_wr > 0x62;
      v8 = reg_fifo.p_wr;
      *(_DWORD *)reg_fifo.reg_buffer[v8].reg_data = *(_DWORD *)(str + 3);
      v9 = (char *)&reg_fifo + v8 * 7;
      v9[17] = str[7];
      v10 = str[2];
      v9[18] = v4;
      v9[12] = v10;
      if ( v7 )
      {
        reg_fifo.p_wr = 0;
      }
      else
      {
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          snprintf(tmp42, 0x1000u, "%s: p_wr = %d reg_value_num = %d", "reg_handle", p_wr, reg_fifo.reg_value_num);
          applog(7, tmp42, 0);
        }
        ++reg_fifo.p_wr;
      }
      if ( reg_fifo.reg_value_num > 0x63 )
      {
        reg_fifo.reg_value_num = 100;
        if ( use_syslog || opt_log_output || opt_log_level > 3 )
        {
          snprintf(tmp42, 0x1000u, "%s: reg fifo full!!!", "reg_handle");
          applog(4, tmp42, 0);
        }
      }
      else
      {
        ++reg_fifo.reg_value_num;
      }
      pthread_mutex_unlock(&reg_mutex);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    snprintf(tmp42, 0x1000u, "%s CRC error crc = %02x\n", "reg_handle", v5);
    applog(3, tmp42, 0);
  }
}
