void *__fastcall ZCASH_fill_work(void *usrdata)
{
  pthread_t v2; // r0
  int v3; // r5
  const char *v4; // r2
  const char *v5; // r11
  int v6; // r6
  char *v7; // r3
  int v8; // r3
  int v9; // r2
  work *work; // r0
  work *v12; // r7
  int v13; // r1
  work *v14; // r0
  char *v15; // [sp+Ch] [bp-10B8h]
  thr_info *thr; // [sp+10h] [bp-10B4h]
  bitmain_ZCASH_info *info; // [sp+14h] [bp-10B0h]
  timeval send_start; // [sp+1Ch] [bp-10A8h] BYREF
  timeval last_send; // [sp+24h] [bp-10A0h] BYREF
  bm1740_work workdata; // [sp+2Ch] [bp-1098h] BYREF
  char tmp42[4100]; // [sp+C0h] [bp-1004h] BYREF

  v2 = pthread_self();
  pthread_detach(v2);
  v3 = *((unsigned __int8 *)usrdata + 4);
  info = *(bitmain_ZCASH_info **)usrdata;
  thr = *(thr_info **)(*(_DWORD *)usrdata + 630);
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v4) = -31108;
    HIWORD(v4) = (unsigned int)"as enough send fifo space, break\n" >> 16;
    snprintf(tmp42, 0x1000u, v4, v3);
    applog(7, tmp42, 0);
  }
  LOWORD(v5) = -31072;
  v6 = 0;
  cgtime(&send_start);
  cgtime(&last_send);
LABEL_6:
  while ( 1 )
  {
    v7 = (char *)&axi_fpga_addr + v3;
    if ( *((_BYTE *)&axi_fpga_addr + v3 + 668) )
      return 0;
    while ( 1 )
    {
      if ( !v7[652] || stop || certification_firmware )
      {
        cgsleep_ms(10);
        goto LABEL_6;
      }
      cgtime(&send_start);
      v8 = send_start.tv_usec - last_send.tv_usec;
      v9 = send_start.tv_sec - last_send.tv_sec;
      if ( send_start.tv_usec - last_send.tv_usec < 0 )
      {
        --v9;
        v8 += 1000000;
      }
      if ( *((_BYTE *)&axi_fpga_addr + v3 + 4) || v8 + 1000000 * v9 >= dev.timeout )
        break;
      cgsleep_us(500);
      v7 = (char *)&axi_fpga_addr + v3;
      if ( *((_BYTE *)&axi_fpga_addr + v3 + 668) )
        return 0;
    }
    cgtime(&last_send);
    while ( 1 )
    {
      work = get_work(thr, thr->id);
      if ( work )
        break;
      if ( use_syslog || opt_log_output || opt_log_level > 2 )
      {
        HIWORD(v5) = (unsigned int)"%s: uart%d clear rx fifo error. nbytes = %d, len = %d\n" >> 16;
        snprintf(tmp42, 0x1000u, v5, v6);
        applog(3, tmp42, 0);
      }
    }
    *((_BYTE *)&axi_fpga_addr + v3 + 4) = 0;
    v12 = work;
    v6 = work->id & 0x7F;
    v15 = &info->update_lock.mutex.__size[4 * v6];
    memset(&workdata, 0, sizeof(workdata));
    *((_BYTE *)&workdata + 2) = 32;
    workdata.workid = v6;
    memcpy(workdata.work, v12->equihash_data, sizeof(workdata.work));
    bm1740_makeup_work_0(&workdata.header_55, v13);
    pthread_mutex_lock(&work_queue_mutex);
    v14 = *(work **)(v15 + 118);
    if ( v14 )
    {
      free_work(v14);
      *(_DWORD *)(v15 + 118) = 0;
    }
    *(_DWORD *)(v15 + 118) = copy_work_noffset(v12, 0);
    pthread_mutex_unlock(&work_queue_mutex);
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "ChainID[%d] Wirte Work. workid=%d, jobid=%s", v3, v6, v12->job_id);
      applog(7, tmp42, 0);
    }
    uart_send(v3, &workdata.header_55, 0x92u);
    gBegin_get_nonce = 1;
    cgtime(&tv_send_job);
    cgsleep_us(500);
    free_work(v12);
  }
}
