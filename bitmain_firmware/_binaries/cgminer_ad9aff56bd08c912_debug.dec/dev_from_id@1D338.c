int __fastcall dev_from_id(int thr_id)
{
  return get_thread(thr_id)->cgpu->device_id;
}
