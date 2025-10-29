int64_t __fastcall bitmain_ZCASH_scanhash(thr_info *thr)
{
  pthread_t send_id; // [sp+4h] [bp-4h] BYREF

  h = 0;
  pthread_create(&send_id, 0, bitmain_scanhash, thr);
  pthread_join(send_id, 0);
  return h;
}
