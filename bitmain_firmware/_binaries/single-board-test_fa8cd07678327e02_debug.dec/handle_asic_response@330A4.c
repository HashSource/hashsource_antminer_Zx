void *__cdecl __noreturn handle_asic_response(void *args)
{
  int v1; // r3
  char tmp42[1024]; // [sp+8h] [bp+8h] BYREF
  uint8_t header[4]; // [sp+408h] [bp+408h] BYREF
  int p_header; // [sp+40Ch] [bp+40Ch] BYREF
  int data_buf_wp; // [sp+410h] [bp+410h] BYREF
  int data_buf_rp; // [sp+414h] [bp+414h] BYREF
  int max; // [sp+418h] [bp+418h]
  uint8_t *tmp; // [sp+41Ch] [bp+41Ch]
  uint8_t *data_buf; // [sp+420h] [bp+420h]
  int data_buf_len; // [sp+424h] [bp+424h]
  uint8_t *receive_buf; // [sp+428h] [bp+428h]
  int resp_nonce_len; // [sp+42Ch] [bp+42Ch]
  int chainid; // [sp+430h] [bp+430h]
  runtime_base_t *runtime; // [sp+434h] [bp+434h]
  int i; // [sp+438h] [bp+438h]
  int len; // [sp+43Ch] [bp+43Ch]

  runtime = (runtime_base_t *)args;
  chainid = *((_DWORD *)args + 443);
  len = 0;
  resp_nonce_len = *((_DWORD *)args + 37) * *((_DWORD *)args + 36);
  receive_buf = (uint8_t *)calloc(1u, resp_nonce_len);
  data_buf_len = 50 * resp_nonce_len;
  data_buf = (uint8_t *)calloc(50 * resp_nonce_len, 1u);
  data_buf_rp = 0;
  data_buf_wp = 0;
  tmp = (uint8_t *)calloc(1u, runtime->asic_data_info.resp_frame_max_len);
  if ( !tmp )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "%s calloc tmp failed\n", "handle_asic_response");
      applog(2, tmp42, 0);
    }
    exit(1);
  }
  max = data_buf_len;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "Start A New Asic Response.Chain Id:[%d]\n", chainid);
    applog(2, tmp42, 0);
  }
  while ( 1 )
  {
    do
    {
LABEL_11:
      while ( !runtime->start_recv )
      {
        pthread_testcancel();
        usleep(0x186A0u);
      }
      usleep(0x1F4u);
      memset(receive_buf, 0, resp_nonce_len);
      len = uart_receive(runtime->chain_status[chainid].fd, receive_buf, resp_nonce_len);
      for ( i = 0; i < len; ++i )
      {
        data_buf[data_buf_wp] = receive_buf[i];
        add_point(&data_buf_wp, max);
      }
    }
    while ( data_buf_rp == data_buf_wp );
    if ( data_buf_wp <= data_buf_rp )
      v1 = data_buf_wp + data_buf_len - data_buf_rp;
    else
      v1 = data_buf_wp - data_buf_rp;
    len = v1;
    while ( len > 2 )
    {
      p_header = data_buf_rp;
      memset(header, 0, 3);
      for ( i = 0; i <= 2; ++i )
      {
        header[i] = data_buf[p_header];
        add_point(&p_header, max);
      }
      if ( header[0] == 170 && header[1] == 85 )
      {
        if ( (header[2] & 0xF0) == 0xE0 )
        {
          if ( runtime->asic_data_info.resp_nonce_frame_len > len )
            goto LABEL_11;
          for ( i = 0; runtime->asic_data_info.resp_nonce_frame_len > i; ++i )
          {
            tmp[i] = data_buf[data_buf_rp];
            add_point(&data_buf_rp, max);
          }
          len -= runtime->asic_data_info.resp_nonce_frame_len;
          runtime->nonce_handle(tmp, runtime->asic_data_info.resp_nonce_frame_len, chainid, runtime->addr_interval);
        }
        else if ( header[2] == 204 )
        {
          if ( runtime->asic_data_info.resp_pm_len > len )
            goto LABEL_11;
          for ( i = 0; runtime->asic_data_info.resp_pm_len > i; ++i )
          {
            tmp[i] = data_buf[data_buf_rp];
            add_point(&data_buf_rp, max);
          }
          len -= runtime->asic_data_info.resp_pm_len;
          runtime->pm_handle(tmp, runtime->asic_data_info.resp_pm_len, chainid);
        }
        else if ( header[2] == 208 )
        {
          if ( runtime->asic_data_info.resp_pt_len > len )
            goto LABEL_11;
          for ( i = 0; runtime->asic_data_info.resp_pt_len > i; ++i )
          {
            tmp[i] = data_buf[data_buf_rp];
            add_point(&data_buf_rp, max);
          }
          len -= runtime->asic_data_info.resp_pt_len;
          runtime->pt_handle(tmp, runtime->asic_data_info.resp_pt_len, chainid);
        }
        else
        {
          if ( runtime->asic_data_info.resp_reg_len > len )
            goto LABEL_11;
          for ( i = 0; runtime->asic_data_info.resp_reg_len > i; ++i )
          {
            tmp[i] = data_buf[data_buf_rp];
            add_point(&data_buf_rp, max);
          }
          len -= runtime->asic_data_info.resp_reg_len;
          runtime->reg_handle(tmp, runtime->asic_data_info.resp_reg_len, chainid);
        }
      }
      else
      {
        add_point(&data_buf_rp, max);
        --len;
      }
    }
  }
}
