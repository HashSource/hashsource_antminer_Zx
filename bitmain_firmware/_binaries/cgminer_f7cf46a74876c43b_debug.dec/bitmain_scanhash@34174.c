void *__fastcall bitmain_scanhash(void *arg)
{
  bitmain_ZCASH_info *v1; // r4
  uint32_t nonce_num; // r11
  work *v3; // r6
  uint32_t v4; // r7
  int work_id; // r8
  unsigned int chain_id; // r4
  int v7; // r9
  uint32_t v8; // r3
  work *v9; // r0
  uint8_t *v10; // r3
  unsigned __int8 *hash; // r2
  unsigned int v12; // r0
  unsigned int v13; // t1
  unsigned int v14; // t1
  bool v15; // cc
  int valid; // r0
  int v17; // r0
  char *v19; // r8
  work *v20; // r0
  unsigned int v21; // r8
  int *v22; // r0
  char *v23; // r9
  int *v24; // r0
  int *v25; // r0
  int *v26; // r0
  bitmain_ZCASH_info *info; // [sp+14h] [bp-1718h]
  unsigned int chip_addr; // [sp+18h] [bp-1714h]
  int nonce_id; // [sp+1Ch] [bp-1710h]
  cgpu_info *bitmain_ZCASH; // [sp+24h] [bp-1708h]
  pthread_rwlock_t *rwlock; // [sp+2Ch] [bp-1700h]
  uint8_t nonce_bin[4]; // [sp+34h] [bp-16F8h] BYREF
  timeval current; // [sp+38h] [bp-16F4h] BYREF
  uint8_t s[32]; // [sp+40h] [bp-16ECh] BYREF
  uint8_t v36[32]; // [sp+60h] [bp-16CCh] BYREF
  blake2b_state digest[1]; // [sp+80h] [bp-16ACh] BYREF
  uint8_t nonce[1344]; // [sp+1E8h] [bp-1544h] BYREF
  uint8_t tmp42[4100]; // [sp+728h] [bp-1004h] BYREF

  v1 = *(bitmain_ZCASH_info **)(*((_DWORD *)arg + 9) + 20);
  bitmain_ZCASH = (cgpu_info *)*((_DWORD *)arg + 9);
  info = v1;
  memset(nonce, 0, sizeof(nonce));
  cgtime(&current);
  h = 0;
  pthread_mutex_lock(&nonce_mutex);
  nonce_num = nonce_fifo.nonce_num;
  pthread_mutex_unlock(&nonce_mutex);
  if ( pthread_mutex_lock(&v1->update_lock.mutex) )
  {
    v25 = _errno_location();
    snprintf(
      (char *)tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
      *v25,
      "driver-btm-zcash.c",
      "bitmain_scanhash",
      6344);
    applog(3, (const char *)tmp42, 1);
    quit(1);
  }
  rwlock = &v1->update_lock.rwlock;
  if ( pthread_rwlock_rdlock(&v1->update_lock.rwlock) )
  {
    v26 = _errno_location();
    snprintf(
      (char *)tmp42,
      0x1000u,
      "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
      *v26,
      "driver-btm-zcash.c",
      "bitmain_scanhash",
      6344);
    applog(3, (const char *)tmp42, 1);
    quit(1);
  }
  if ( pthread_mutex_unlock(&v1->update_lock.mutex) )
  {
    v24 = _errno_location();
    snprintf(
      (char *)tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v24,
      "driver-btm-zcash.c",
      "bitmain_scanhash",
      6344);
    applog(3, (const char *)tmp42, 1);
    quit(1);
  }
  if ( !nonce_num )
    goto LABEL_24;
  v3 = 0;
  v4 = nonce_num;
  while ( 1 )
  {
    pthread_mutex_lock(&nonce_mutex);
    --v4;
    --nonce_fifo.nonce_num;
    work_id = nonce_fifo.nonce_buffer[nonce_fifo.p_rd].work_id;
    nonce_id = nonce_fifo.nonce_buffer[nonce_fifo.p_rd].nonce_id;
    chain_id = nonce_fifo.nonce_buffer[nonce_fifo.p_rd].chain_id;
    chip_addr = nonce_fifo.nonce_buffer[nonce_fifo.p_rd].chip_addr;
    memcpy(nonce, &nonce_fifo.nonce_buffer[nonce_fifo.p_rd], sizeof(nonce));
    v7 = *(_DWORD *)nonce_fifo.nonce_buffer[nonce_fifo.p_rd].chip_nonce;
    v8 = nonce_fifo.p_rd > 0x62 ? 0 : nonce_fifo.p_rd + 1;
    nonce_fifo.p_rd = v8;
    pthread_mutex_unlock(&nonce_mutex);
    if ( chain_id > 4 )
      break;
    pthread_mutex_lock(&work_queue_mutex);
    v9 = info->work_queue[work_id];
    if ( v9 )
      v3 = copy_work_noffset(v9, 0);
    pthread_mutex_unlock(&work_queue_mutex);
    if ( v3 )
    {
      *(_DWORD *)&v3->equihash_data[136] = v7;
      memcpy(&v3->equihash_data[143], nonce, 0x540u);
      digestInit(digest, 200, 9);
      blake2b_update(digest, v3->equihash_data, 0x8Cu);
      memset(s, 0, sizeof(s));
      memset(v36, 0, sizeof(v36));
      memcpy(tmp42, v3->equihash_data, 0x5CFu);
      Sha256_Onestep(tmp42, 0x5CFu, s);
      Sha256_Onestep(s, 0x20u, v36);
      v10 = (uint8_t *)digest;
      hash = v3->hash;
      while ( 1 )
      {
        v13 = *--v10;
        v12 = v13;
        v14 = *--hash;
        v15 = v12 > v14;
        if ( v12 < v14 )
        {
LABEL_17:
          valid = IsValidSolution(digest, nonce);
          if ( valid )
            goto LABEL_32;
          submit_nonce_direct((thr_info *)arg, v3, 1u);
          goto LABEL_19;
        }
        if ( v15 )
          break;
        if ( v36 == v10 )
          goto LABEL_17;
      }
      valid = IsValidSolution(digest, nonce);
      if ( valid )
      {
LABEL_32:
        if ( valid == 2 )
        {
          v19 = (char *)&dev.chain_asic_nonce[chain_id + 3][(unsigned __int8)(chip_addr / dev.addrInterval) + 2] + 1;
          ++*(_DWORD *)(v19 + 3);
        }
        if ( zero_stats_flag )
        {
          zero_stats_flag = 0;
          dev.chain_hw[0] = 0;
          dev.chain_hw[1] = 0;
          dev.chain_hw[2] = 0;
          dev.chain_hw[3] = 0;
        }
LABEL_36:
        cg_logwork(v3, nonce_bin, 1);
        v20 = v3;
        v3 = 0;
        free_work(v20);
        if ( !v4 )
        {
LABEL_24:
          if ( !pthread_rwlock_unlock(rwlock) )
            goto LABEL_25;
LABEL_51:
          v22 = _errno_location();
          snprintf(
            (char *)tmp42,
            0x1000u,
            "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
            *v22,
            "driver-btm-zcash.c",
            "bitmain_scanhash",
            6453);
          applog(3, (const char *)tmp42, 1);
          quit(1);
        }
        continue;
      }
LABEL_19:
      v17 = dev.chain_exist[chain_id];
      ++h;
      ++*(_QWORD *)&(&axi_fpga_addr)[2 * chain_id + 20];
      if ( !v17 )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 2 )
        {
          snprintf((char *)tmp42, 0x1000u, "ChainID Cause Error! ChainID:[%d]", chain_id);
          applog(3, (const char *)tmp42, 0);
        }
        goto LABEL_23;
      }
      v21 = (unsigned __int8)(chip_addr / dev.addrInterval);
      if ( v21 <= 2 )
      {
        update_work_stats((thr_info *)arg, v3);
        v23 = (char *)&dev.chain_hw[3 * chain_id + 3 + v21] + 1;
        ++*(_DWORD *)(v23 + 3);
        goto LABEL_36;
      }
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        snprintf((char *)tmp42, 0x1000u, "Which Nonce Cause Err![%d] %08x", v21, nonce_id);
        applog(7, (const char *)tmp42, 0);
        if ( !v4 )
          goto LABEL_24;
        continue;
      }
LABEL_23:
      if ( !v4 )
        goto LABEL_24;
    }
    else
    {
      if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
        goto LABEL_23;
      snprintf(
        (char *)tmp42,
        0x1000u,
        "%s %d: work %02x not find error",
        bitmain_ZCASH->drv->name,
        bitmain_ZCASH->device_id,
        work_id);
      applog(3, (const char *)tmp42, 0);
      if ( !v4 )
        goto LABEL_24;
    }
  }
  if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
    goto LABEL_24;
  snprintf((char *)tmp42, 0x1000u, "Error:scanhash chainid=%u\n", chain_id);
  applog(5, (const char *)tmp42, 0);
  if ( pthread_rwlock_unlock(rwlock) )
    goto LABEL_51;
LABEL_25:
  selective_yield();
  h *= 0xFFFFLL;
  return 0;
}
