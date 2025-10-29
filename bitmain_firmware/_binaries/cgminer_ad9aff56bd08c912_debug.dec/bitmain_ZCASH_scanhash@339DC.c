int64_t __fastcall bitmain_ZCASH_scanhash(thr_info *thr)
{
  void *(*v1)(void *); // r2
  pthread_t send_id; // [sp+4h] [bp-4h] BYREF

  LOWORD(v1) = 17029;
  HIWORD(v1) = ((unsigned int)&loc_34172 + 3) >> 16;
  h = 0;
  pthread_create(&send_id, 0, v1, thr);
  pthread_join(send_id, 0);
  return h;
}
