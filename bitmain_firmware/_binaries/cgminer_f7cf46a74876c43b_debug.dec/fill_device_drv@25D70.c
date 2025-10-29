void __fastcall fill_device_drv(device_drv *drv)
{
  if ( drv->drv_detect )
  {
    if ( drv->reinit_device )
      goto LABEL_3;
  }
  else
  {
    drv->drv_detect = noop_detect;
    if ( drv->reinit_device )
    {
LABEL_3:
      if ( drv->get_statline_before )
        goto LABEL_4;
      goto LABEL_23;
    }
  }
  drv->reinit_device = noop_reinit_device;
  if ( drv->get_statline_before )
  {
LABEL_4:
    if ( drv->get_statline )
      goto LABEL_5;
    goto LABEL_24;
  }
LABEL_23:
  drv->get_statline_before = blank_get_statline_before;
  if ( drv->get_statline )
  {
LABEL_5:
    if ( drv->get_stats )
      goto LABEL_6;
    goto LABEL_25;
  }
LABEL_24:
  drv->get_statline = (void (*)(char *, size_t, cgpu_info *))noop_get_statline;
  if ( drv->get_stats )
  {
LABEL_6:
    if ( drv->thread_prepare )
      goto LABEL_7;
    goto LABEL_26;
  }
LABEL_25:
  drv->get_stats = noop_get_stats;
  if ( drv->thread_prepare )
  {
LABEL_7:
    if ( drv->can_limit_work )
      goto LABEL_8;
    goto LABEL_27;
  }
LABEL_26:
  drv->thread_prepare = (bool (*)(thr_info *))noop_thread_prepare;
  if ( drv->can_limit_work )
  {
LABEL_8:
    if ( drv->thread_init )
      goto LABEL_9;
    goto LABEL_28;
  }
LABEL_27:
  drv->can_limit_work = noop_can_limit_work;
  if ( drv->thread_init )
  {
LABEL_9:
    if ( drv->prepare_work )
      goto LABEL_10;
    goto LABEL_29;
  }
LABEL_28:
  drv->thread_init = (bool (*)(thr_info *))noop_thread_init;
  if ( drv->prepare_work )
  {
LABEL_10:
    if ( drv->hw_error )
      goto LABEL_11;
    goto LABEL_30;
  }
LABEL_29:
  drv->prepare_work = noop_prepare_work;
  if ( drv->hw_error )
  {
LABEL_11:
    if ( drv->thread_shutdown )
      goto LABEL_12;
    goto LABEL_31;
  }
LABEL_30:
  drv->hw_error = (void (*)(thr_info *))noop_hw_error;
  if ( drv->thread_shutdown )
  {
LABEL_12:
    if ( drv->thread_enable )
      goto LABEL_13;
    goto LABEL_32;
  }
LABEL_31:
  drv->thread_shutdown = (void (*)(thr_info *))noop_thread_shutdown;
  if ( drv->thread_enable )
  {
LABEL_13:
    if ( drv->hash_work )
      goto LABEL_14;
    goto LABEL_33;
  }
LABEL_32:
  drv->thread_enable = (void (*)(thr_info *))noop_thread_enable;
  if ( drv->hash_work )
  {
LABEL_14:
    if ( drv->flush_work )
      goto LABEL_15;
    goto LABEL_34;
  }
LABEL_33:
  drv->hash_work = hash_sole_work;
  if ( drv->flush_work )
  {
LABEL_15:
    if ( drv->update_work )
      goto LABEL_16;
    goto LABEL_35;
  }
LABEL_34:
  drv->flush_work = noop_reinit_device;
  if ( drv->update_work )
  {
LABEL_16:
    if ( drv->queue_full )
      goto LABEL_17;
LABEL_36:
    drv->queue_full = noop_get_stats;
    if ( drv->zero_stats )
      goto LABEL_18;
    goto LABEL_37;
  }
LABEL_35:
  drv->update_work = noop_reinit_device;
  if ( !drv->queue_full )
    goto LABEL_36;
LABEL_17:
  if ( drv->zero_stats )
    goto LABEL_18;
LABEL_37:
  drv->zero_stats = noop_reinit_device;
LABEL_18:
  if ( drv->max_diff == 0.0 )
    drv->max_diff = 1.0;
}
