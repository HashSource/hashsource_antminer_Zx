void *__cdecl nonce_scanhash(void *args)
{
  uint8_t work[140]; // [sp+20h] [bp+8h] BYREF
  char tmp42[1024]; // [sp+ACh] [bp+94h] BYREF
  nonce_rb_format nonce_tmp; // [sp+4ACh] [bp+494h] BYREF
  int ticket_mask; // [sp+9FCh] [bp+9E4h] BYREF
  int nonceNum; // [sp+A00h] [bp+9E8h] BYREF
  int valid; // [sp+A04h] [bp+9ECh]
  int chainid; // [sp+A08h] [bp+9F0h]
  runtime_base_t *runtime; // [sp+A0Ch] [bp+9F4h]
  int asic; // [sp+A10h] [bp+9F8h]
  int asic_index; // [sp+A14h] [bp+9FCh]

  runtime = (runtime_base_t *)args;
  nonceNum = 0;
  nonce_fifo_num(&nonceNum);
  while ( nonceNum )
  {
    --nonceNum;
    pop_nonce(&nonce_tmp);
    chainid = nonce_tmp.chain_id;
    memset(work, 0, sizeof(work));
    work_list_find(nonce_tmp.work_id, work);
    memcpy(&runtime->nonce_verify_info, work, runtime->nonce_verify_info.work_len);
    memcpy(runtime->nonce_verify_info.nonce, nonce_tmp.chip_nonce, runtime->nonce_verify_info.nonce_len);
    memcpy(runtime->nonce_verify_info.sol, &nonce_tmp, runtime->nonce_verify_info.sol_len);
    memset(runtime->nonce_verify_info.target, 0, runtime->nonce_verify_info.target_len);
    ticket_mask = 0;
    valid = runtime->nonce_verify(&runtime->nonce_verify_info, &ticket_mask, runtime->nonce_shift);
    if ( runtime->new_block )
    {
      runtime->new_block = 0;
      memset(
        runtime->chain_status[chainid].one_work_nonce_each_asic,
        0,
        4 * runtime->chain_status[chainid].design_asic_num);
      memset(
        runtime->chain_status[chainid].one_work_invalid_nonce_each_asic,
        0,
        4 * runtime->chain_status[chainid].design_asic_num);
      memset(
        runtime->chain_status[chainid].one_work_invalid_nonce_each_asic_type,
        0,
        12 * runtime->chain_status[chainid].design_asic_num);
    }
    if ( valid )
    {
      ++runtime->invalid_nonce_total;
      for ( asic = 0; asic <= 2; ++asic )
      {
        if ( nonce_tmp.chip_addr / runtime->addr_interval == asic )
        {
          ++runtime->chain_status[chainid].nonce_invalid_num_each_asic[asic];
          ++runtime->chain_status[chainid].one_work_invalid_nonce_each_asic[asic];
          if ( valid == 1 )
          {
            ++runtime->chain_status[chainid].one_work_invalid_nonce_each_asic_type[asic][1];
          }
          else if ( valid == 2 )
          {
            ++runtime->chain_status[chainid].one_work_invalid_nonce_each_asic_type[asic][2];
          }
          if ( use_syslog || opt_log_output || opt_log_level >= 0 )
          {
            snprintf(
              tmp42,
              0x400u,
              "Fail:invalid nonce: chainid=%d chipaddr=%02x nonces=%d tm=%d errtype=%d\n",
              chainid,
              nonce_tmp.chip_addr,
              runtime->chain_status[chainid].one_work_invalid_nonce_each_asic[asic],
              ticket_mask,
              valid);
            applog(0, tmp42, 0);
          }
        }
      }
    }
    else
    {
      ++runtime->valid_nonce_total;
      for ( asic_index = 0; asic_index <= 2; ++asic_index )
      {
        if ( nonce_tmp.chip_addr / runtime->addr_interval == asic_index )
        {
          ++runtime->chain_status[chainid].one_work_nonce_each_asic[asic_index];
          ++runtime->chain_status[chainid].nonce_num_each_asic[asic_index];
          if ( g_patten.start )
            is_patten_match(asic_index, nonce_tmp.chip_nonce, nonce_tmp.Nonce);
          if ( use_syslog || opt_log_output || opt_log_level > 0 )
          {
            snprintf(
              tmp42,
              0x400u,
              "Success:valid nonce: chainid=%d chipaddr=%02x nonces=%d total=%d tm=%d err=%d\n",
              chainid,
              nonce_tmp.chip_addr,
              runtime->chain_status[chainid].one_work_nonce_each_asic[asic_index],
              runtime->submit_nonce,
              ticket_mask,
              valid);
            applog(1, tmp42, 0);
          }
          if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 3) )
          {
            snprintf(
              tmp42,
              0x400u,
              "SHA256:%02x%02x%02x%02x\n",
              nonce_tmp.sha256[0],
              nonce_tmp.sha256[1],
              nonce_tmp.sha256[2],
              nonce_tmp.sha256[3]);
            applog(4, tmp42, 0);
          }
        }
      }
      if ( app_conf->work_mode == 1
        && ((int (__fastcall *)(uint8_t *, zcash_work_info *))runtime->nonce_verify_target_match)(
             runtime->nonce_verify_info.target,
             &g_work_info) )
      {
        runtime->nonce_submit(
          (uint8_t *)&nonce_tmp,
          (uint8_t *)&runtime->nonce_verify_info,
          g_work_info.fixed_nonce_bytes,
          g_work_info.job_id);
      }
    }
  }
  return 0;
}
