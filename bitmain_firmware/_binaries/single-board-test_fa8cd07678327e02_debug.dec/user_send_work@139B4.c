void __cdecl user_send_work(runtime_base_t *runtime, uint8_t *header, int sno_valid, int test_patten)
{
  uint8_t total_work; // r3
  char test_pattena; // [sp+0h] [bp+0h]
  char sno_valida; // [sp+4h] [bp+4h]
  work_input work; // [sp+10h] [bp+10h] BYREF
  int chainid; // [sp+A4h] [bp+A4h]

  sno_valida = sno_valid;
  test_pattena = test_patten;
  chainid = runtime->chain_id;
  memset(&work, 0, sizeof(work));
  *((_BYTE *)&work + 2) = *((_BYTE *)&work + 2) & 0xEF | (16 * (sno_valida & 1));
  *((_BYTE *)&work + 2) = *((_BYTE *)&work + 2) & 0xFE | test_pattena & 1;
  total_work = runtime->total_work;
  runtime->total_work = total_work + 1;
  work.workid = total_work;
  memcpy(work.work, header, sizeof(work.work));
  work_list_insert(work.workid, work.work);
  runtime->send_work(runtime->chain_status[chainid].fd, (uint8_t *)&work);
}
