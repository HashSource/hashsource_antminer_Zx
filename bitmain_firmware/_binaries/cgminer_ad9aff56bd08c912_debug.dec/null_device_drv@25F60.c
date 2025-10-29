void __fastcall null_device_drv(device_drv *drv)
{
  api_data *(*v1)(cgpu_info *); // r2
  void (*v2)(bool); // r4
  void (*v3)(char *, size_t, cgpu_info *); // r1
  void (*v4)(char *, size_t, cgpu_info *); // r3
  bool (*v5)(thr_info *); // r5

  LOWORD(v1) = 20645;
  HIWORD(v1) = (unsigned int)&algn_15052[3] >> 16;
  LOWORD(v2) = 20641;
  LOWORD(v3) = 20621;
  LOWORD(v4) = 30181;
  HIWORD(v2) = (unsigned int)frame_dummy >> 16;
  HIWORD(v3) = ((unsigned int)&loc_1503A + 3) >> 16;
  HIWORD(v4) = (unsigned int)&loc_17594 >> 16;
  drv->get_api_stats = v1;
  LOWORD(v5) = 30189;
  drv->drv_detect = v2;
  LOWORD(v2) = 20629;
  drv->get_statline_before = v3;
  LOWORD(v3) = 30193;
  drv->get_statline = v4;
  LOWORD(v4) = 20637;
  drv->set_device = 0;
  LOWORD(v1) = 30185;
  HIWORD(v5) = ((unsigned int)&loc_1759A + 3) >> 16;
  HIWORD(v2) = (unsigned int)&loc_15044 >> 16;
  HIWORD(v3) = (unsigned int)&locret_175A0 >> 16;
  HIWORD(v4) = (unsigned int)&loc_1504C >> 16;
  HIWORD(v1) = ((unsigned int)&loc_17596 + 3) >> 16;
  drv->thread_prepare = v5;
  drv->can_limit_work = (uint64_t (*)(thr_info *))v2;
  LOWORD(v5) = 30197;
  LOWORD(v2) = 30201;
  drv->thread_init = (bool (*)(thr_info *))v3;
  drv->prepare_work = (bool (*)(thr_info *, work *))v4;
  LOWORD(v3) = 30205;
  LOWORD(v4) = 20617;
  drv->hash_work = (void (*)(thr_info *))v1;
  LOWORD(v1) = 20625;
  HIWORD(v4) = (unsigned int)_do_global_dtors_aux >> 16;
  HIWORD(v5) = (unsigned int)submit_tested_work_0 >> 16;
  HIWORD(v2) = ((unsigned int)&loc_175A6 + 3) >> 16;
  HIWORD(v1) = ((unsigned int)&loc_1503A + 7) >> 16;
  HIWORD(v3) = (unsigned int)&loc_175AC >> 16;
  drv->hw_error = (void (*)(thr_info *))v5;
  drv->thread_shutdown = (void (*)(thr_info *))v2;
  drv->thread_enable = (void (*)(thr_info *))v3;
  drv->max_diff = 1.0;
  drv->min_diff = 1.0;
  drv->reinit_device = (void (*)(cgpu_info *))v4;
  drv->identify_device = (void (*)(cgpu_info *))v4;
  drv->zero_stats = (void (*)(cgpu_info *))v4;
  drv->flush_work = (void (*)(cgpu_info *))v4;
  drv->update_work = (void (*)(cgpu_info *))v4;
  drv->get_stats = (bool (*)(cgpu_info *))v1;
  drv->queue_full = (bool (*)(cgpu_info *))v1;
}
