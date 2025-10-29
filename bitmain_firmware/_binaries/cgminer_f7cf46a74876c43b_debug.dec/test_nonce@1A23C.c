bool __fastcall test_nonce(work *work, uint32_t nonce)
{
  unsigned int v3; // r3

  *(_DWORD *)&work->data[76] = nonce;
  rebuild_hash(work);
  v3 = 0xFFFF;
  if ( !opt_scrypt )
    v3 = 0;
  return *(_DWORD *)&work->hash[28] <= v3;
}
