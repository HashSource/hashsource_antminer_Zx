void __fastcall submit_nonce_2(work *work)
{
  work *v2; // r4

  v2 = make_work();
  copy_work(v2, work, 0);
  submit_work_async(v2);
}
