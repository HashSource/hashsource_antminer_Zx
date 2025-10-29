void init_pcba_args()
{
  runtime_base_t *runtime; // [sp+0h] [bp+0h]
  int i; // [sp+4h] [bp+4h]
  int ia; // [sp+4h] [bp+4h]

  runtime = cgpu.runtime;
  for ( i = 0; i <= 0; ++i )
    runtime->chain_status[i].real_asic_num = 0;
  for ( ia = 0; ia <= 2; ++ia )
  {
    chip_temp[ia] = 0;
    pcb_temp[ia] = 0;
  }
  gChain = -1;
  pcb_high = 0;
  chip_high = 0;
}
