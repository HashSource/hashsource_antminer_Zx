bool __fastcall test_nonce_diff(work *work, uint32_t nonce, double diff)
{
  double v3; // d0
  double v5; // d7

  *(_DWORD *)&work->data[76] = nonce;
  rebuild_hash(work);
  v5 = 4294901760.0;
  if ( opt_scrypt )
    v5 = 2.81470682e14;
  return (unsigned __int64)(v5 / v3) >= *(_QWORD *)&work->hash[24];
}
