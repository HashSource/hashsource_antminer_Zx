void __fastcall dupcounters(cgpu_info *cgpu, uint64_t *checked, uint64_t *dups)
{
  _QWORD *dup_data; // r3

  dup_data = cgpu->dup_data;
  if ( dup_data )
  {
    *checked = dup_data[2];
    *dups = dup_data[3];
  }
  else
  {
    *checked = 0;
    *dups = 0;
  }
}
