void __fastcall null_device_drv(device_drv *drv)
{
  drv->get_api_stats = noop_get_api_stats;
  drv->drv_detect = noop_detect;
  drv->get_statline_before = blank_get_statline_before;
  drv->get_statline = (void (*)(char *, size_t, cgpu_info *))noop_get_statline;
  drv->set_device = 0;
  drv->thread_prepare = (bool (*)(thr_info *))noop_thread_prepare;
  drv->can_limit_work = noop_can_limit_work;
  drv->thread_init = (bool (*)(thr_info *))noop_thread_init;
  drv->prepare_work = noop_prepare_work;
  drv->hash_work = (void (*)(thr_info *))noop_hash_work;
  drv->hw_error = (void (*)(thr_info *))noop_hw_error;
  drv->thread_shutdown = (void (*)(thr_info *))noop_thread_shutdown;
  drv->thread_enable = (void (*)(thr_info *))noop_thread_enable;
  drv->max_diff = 1.0;
  drv->min_diff = 1.0;
  drv->reinit_device = noop_reinit_device;
  drv->identify_device = noop_reinit_device;
  drv->zero_stats = noop_reinit_device;
  drv->flush_work = noop_reinit_device;
  drv->update_work = noop_reinit_device;
  drv->get_stats = noop_get_stats;
  drv->queue_full = noop_get_stats;
}
