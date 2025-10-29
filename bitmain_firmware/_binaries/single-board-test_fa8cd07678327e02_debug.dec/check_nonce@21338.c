void *__cdecl check_nonce(void *args)
{
  int nonceNum; // [sp+Ch] [bp+Ch] BYREF
  nonce_rb_format nonce_tmp; // [sp+10h] [bp+10h] BYREF
  int asic_index; // [sp+560h] [bp+560h]
  runtime_base_t *runtime; // [sp+564h] [bp+564h]

  runtime = (runtime_base_t *)args;
  nonceNum = 0;
  nonce_fifo_num(&nonceNum);
  while ( nonceNum )
  {
    --nonceNum;
    pop_nonce(&nonce_tmp);
    asic_index = nonce_tmp.chip_addr / runtime->addr_interval;
    is_patten_match(asic_index, nonce_tmp.chip_nonce, nonce_tmp.Nonce);
  }
  return 0;
}
