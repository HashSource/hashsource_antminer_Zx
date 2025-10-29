void __fastcall clean_work(work *work)
{
  free(work->job_id);
  free(work->ntime);
  free(work->coinbase);
  free(work->nonce1);
  j_memset(work, 0, sizeof(work));
}
