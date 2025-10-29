void __fastcall check_asic_reg(unsigned __int8 which_chain, unsigned __int8 chip_addr, unsigned __int8 reg, bool mode)
{
  uint32_t v4; // r5
  int v5; // r11
  int v6; // r10
  unsigned int status_cmd; // r0
  int i; // r4
  uint32_t reg_value_num; // r7
  int v10; // r4
  uint32_t p_rd; // r3
  char *v12; // r2
  int v13; // r0
  int v14; // r2
  unsigned int v15; // r3
  unsigned int v16; // r1
  unsigned __int8 *v17; // r12
  bool *v18; // r0
  int v19; // r1
  int v20; // t1
  uint8_t regaddr; // [sp+0h] [bp-1044h]
  uint8_t all[4]; // [sp+10h] [bp-1034h]
  int v23; // [sp+18h] [bp-102Ch]
  int16_t v24; // [sp+2Ch] [bp-1018h]
  uint8_t cmd_buf[8]; // [sp+38h] [bp-100Ch] BYREF
  char tmp42[4100]; // [sp+40h] [bp-1004h] BYREF

  v4 = mode;
  v5 = which_chain;
  *(_DWORD *)cmd_buf = 0;
  v6 = reg;
  *(_DWORD *)all = chip_addr;
  *(_DWORD *)&cmd_buf[3] = 0;
  clear_register_value_buf();
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(
      tmp42,
      0x1000u,
      "%s: check chain J%d mode %d chipaddr %02x regaddr %02x",
      "check_asic_reg",
      v5,
      v4,
      *(_DWORD *)all,
      v6);
    applog(7, tmp42, 0);
  }
  status_cmd = bm1740_makeup_get_status_cmd(cmd_buf, v4, all[0], v6, regaddr);
  uart_send(v5, cmd_buf, status_cmd);
  if ( !v6 && *((_BYTE *)&axi_fpga_addr + v5 + 3456) )
    dev.chain_asic_num[v5] = 0;
  for ( i = 0; i != 3; ++i )
  {
LABEL_9:
    usleep(0x493E0u);
    pthread_mutex_lock(&reg_mutex);
    reg_value_num = reg_fifo.reg_value_num;
    pthread_mutex_unlock(&reg_mutex);
    if ( reg_value_num )
    {
      v10 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          pthread_mutex_lock(&reg_mutex);
          p_rd = reg_fifo.p_rd;
          v12 = (char *)&reg_fifo + 7 * reg_fifo.p_rd;
          v13 = (unsigned __int8)v12[18];
          if ( v13 == v5 )
            break;
          ++reg_fifo.p_rd;
          if ( p_rd == 99 )
            reg_fifo.p_rd = 0;
          --reg_fifo.reg_value_num;
          if ( use_syslog || opt_log_output || opt_log_level > 4 )
          {
            snprintf(
              tmp42,
              0x1000u,
              "%s: the return data is from chain%d, but it should be from chain%d chipaddr=0x%02x reg=0x%02x\n",
              "check_asic_reg",
              v13,
              v5,
              *(_DWORD *)all,
              v6);
            applog(5, tmp42, 0);
          }
          ++v10;
          pthread_mutex_unlock(&reg_mutex);
          if ( reg_value_num == v10 )
          {
LABEL_25:
            i = 0;
            goto LABEL_9;
          }
        }
        v14 = (unsigned __int8)v12[17];
        v15 = bswap32(*(_DWORD *)reg_fifo.reg_buffer[reg_fifo.p_rd].reg_data);
        if ( v6 )
        {
          switch ( v6 )
          {
            case 12:
              if ( use_syslog || opt_log_output || opt_log_level > 4 )
              {
                snprintf(tmp42, 0x1000u, "%s: the asic freq is 0x%08x", "check_asic_reg", v15);
LABEL_31:
                applog(5, tmp42, 0);
              }
              break;
            case 20:
              if ( use_syslog || opt_log_output || opt_log_level > 4 )
              {
                snprintf(tmp42, 0x1000u, "%s: the asic tm is 0x%08x", "check_asic_reg", v15);
                goto LABEL_31;
              }
              break;
            case 28:
              if ( use_syslog || opt_log_output || opt_log_level > 4 )
              {
                snprintf(tmp42, 0x1000u, "%s: the asic misc is 0x%08x", "check_asic_reg", v15);
                goto LABEL_31;
              }
              break;
            case 32:
              if ( (v15 & 0xC0000000) == 0 )
              {
                v17 = TempChipAddr;
                v18 = g_chip_temp_return[(__int16)v5][0];
                v24 = (unsigned __int8)v15 - 64;
                v23 = v15 & 0xFF00;
                v19 = 4 * (__int16)v5;
                do
                {
                  v20 = *v17++;
                  if ( v14 == v20 )
                  {
                    if ( (v15 & 0xFF00) != 0 )
                    {
                      switch ( v23 )
                      {
                        case 256:
                          v18[1] = 1;
                          dev.chain_asic_temp[0][v19 - v5][1] = v24;
                          break;
                        case 4352:
                          send_back_gTempOffsetValue[v19] = v15;
                          v18[2] = 1;
                          break;
                        case 65024:
                          sensor_id[v19] = v15;
                          v18[3] = 1;
                          break;
                      }
                    }
                    else
                    {
                      *v18 = 1;
                      dev.chain_asic_temp[0][v19 - v5][0] = v24;
                    }
                  }
                  ++v19;
                  v18 += 4;
                }
                while ( v19 != 4 * (__int16)v5 + 3 );
              }
              break;
            case 84:
              if ( use_syslog || opt_log_output || opt_log_level > 4 )
              {
                snprintf(tmp42, 0x1000u, "%s: the start nonce offset is 0x%08x", "check_asic_reg", v15);
                goto LABEL_31;
              }
              break;
            default:
              if ( v6 == 48 && (use_syslog || opt_log_output || opt_log_level > 4) )
              {
                snprintf(tmp42, 0x1000u, "%s: the asic IO strength is 0x%08x", "check_asic_reg", v15);
                goto LABEL_31;
              }
              break;
          }
        }
        else if ( *((_BYTE *)&axi_fpga_addr + v5 + 3456) )
        {
          ++dev.chain_asic_num[v5];
        }
        else if ( use_syslog || opt_log_output || opt_log_level > 4 )
        {
          snprintf(tmp42, 0x1000u, "%s: the asic address is 0x%08x", "check_asic_reg", v15);
          goto LABEL_31;
        }
        ++v10;
        ++reg_fifo.p_rd;
        --reg_fifo.reg_value_num;
        if ( reg_fifo.p_rd == 100 )
          reg_fifo.p_rd = 0;
        pthread_mutex_unlock(&reg_mutex);
        if ( reg_value_num == v10 )
          goto LABEL_25;
      }
    }
    usleep((__useconds_t)&loc_1869E + 2);
  }
  if ( !v6 )
  {
    v16 = dev.chain_asic_num[v5];
    if ( dev.max_asic_num_in_one_chain < v16 )
      dev.max_asic_num_in_one_chain = dev.chain_asic_num[v5];
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      snprintf(tmp42, 0x1000u, "%s: chain J%d has %d ASIC", "check_asic_reg", v5, v16);
      applog(5, tmp42, 0);
    }
  }
  clear_register_value_buf();
}
