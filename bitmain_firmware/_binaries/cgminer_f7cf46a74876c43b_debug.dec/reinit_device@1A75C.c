void __fastcall reinit_device(cgpu_info *cgpu)
{
  if ( cgpu->deven != dev_enable::DEV_DISABLED )
    ((void (*)(void))cgpu->drv->reinit_device)();
}
