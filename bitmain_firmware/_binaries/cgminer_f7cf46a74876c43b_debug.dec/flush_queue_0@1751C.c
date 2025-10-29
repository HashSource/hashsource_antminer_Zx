// Alternative name is 'flush_queue.part.38'
void __fastcall flush_queue_0(cgpu_info *cgpu)
{
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  strcpy(tmp42, "Discarded queued work item");
  applog(7, tmp42, 0);
}
