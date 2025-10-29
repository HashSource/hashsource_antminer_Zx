bool __fastcall submit_nonce_direct(thr_info *thr, work *work, uint32_t nonce)
{
  work *v4; // r5

  *(_DWORD *)&work->data[76] = nonce;
  v4 = make_work();
  copy_work(v4, work, 0);
  submit_work_async(v4);
  return 1;
}
