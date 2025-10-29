void *__fastcall ZCASH_fill_work(void *usrdata)
{
  pthread_t v2; // r0
  int v3; // r5
  int v4; // r6
  char *v5; // r3
  int v6; // r3
  int v7; // r2
  work *work; // r0
  work *v10; // r7
  int v11; // r1
  work *v12; // r0
  char *v13; // [sp+Ch] [bp-10B8h]
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
    snprintf(tmp42, 0x1000u, "Start To Fill Work!ChainIndex:[%d]", v3);
    applog(7, tmp42, 0);
  }
  v4 = 0;
  cgtime(&send_start);
  cgtime(&last_send);
LABEL_6:
  while ( 1 )
  {
    v5 = (char *)&axi_fpga_addr + v3;
    if ( *((_BYTE *)&axi_fpga_addr + v3 + 668) )
      return 0;
    while ( 1 )
    {
      if ( !v5[652] || stop || certification_firmware )
      {
        cgsleep_ms(10);
        goto LABEL_6;
      }
      cgtime(&send_start);
      v6 = send_start.tv_usec - last_send.tv_usec;
      v7 = send_start.tv_sec - last_send.tv_sec;
      if ( send_start.tv_usec - last_send.tv_usec < 0 )
      {
        --v7;
        v6 += 1000000;
      }
      if ( *((_BYTE *)&axi_fpga_addr + v3 + 4) || v6 + 1000000 * v7 >= dev.timeout )
        break;
      cgsleep_us(500);
      v5 = (char *)&axi_fpga_addr + v3;
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
        snprintf(tmp42, 0x1000u, "Work Error![%d]", v4);
        applog(3, tmp42, 0);
      }
    }
    *((_BYTE *)&axi_fpga_addr + v3 + 4) = 0;
    v10 = work;
    v4 = work->id & 0x7F;
    v13 = &info->update_lock.mutex.__size[4 * v4];
    memset(&workdata, 0, sizeof(workdata));
    *((_BYTE *)&workdata + 2) = 32;
    workdata.workid = v4;
    memcpy(workdata.work, v10->equihash_data, sizeof(workdata.work));
    bm1740_makeup_work_0(&workdata.header_55, v11);
    pthread_mutex_lock(&work_queue_mutex);
    v12 = *(work **)(v13 + 118);
    if ( v12 )
    {
      free_work(v12);
      *(_DWORD *)(v13 + 118) = 0;
    }
    *(_DWORD *)(v13 + 118) = copy_work_noffset(v10, 0);
    pthread_mutex_unlock(&work_queue_mutex);
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "ChainID[%d] Wirte Work. workid=%d, jobid=%s", v3, v4, v10->job_id);
      applog(7, tmp42, 0);
    }
    uart_send(v3, &workdata.header_55, 0x92u);
    gBegin_get_nonce = 1;
    cgtime(&tv_send_job);
    cgsleep_us(500);
    free_work(v10);
  }
}
