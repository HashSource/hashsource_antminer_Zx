void __fastcall dev_error(cgpu_info *dev, dev_reason reason)
{
  dev->device_last_not_well = time(0);
  dev->device_not_well_reason = reason;
  switch ( reason )
  {
    case dev_reason::REASON_THREAD_FAIL_INIT:
      ++dev->thread_fail_init_count;
      break;
    case dev_reason::REASON_THREAD_ZERO_HASH:
      ++dev->thread_zero_hash_count;
      break;
    case dev_reason::REASON_THREAD_FAIL_QUEUE:
      ++dev->thread_fail_queue_count;
      break;
    case dev_reason::REASON_DEV_SICK_IDLE_60:
      ++dev->dev_sick_idle_60_count;
      break;
    case dev_reason::REASON_DEV_DEAD_IDLE_600:
      ++dev->dev_dead_idle_600_count;
      break;
    case dev_reason::REASON_DEV_NOSTART:
      ++dev->dev_nostart_count;
      break;
    case dev_reason::REASON_DEV_OVER_HEAT:
      ++dev->dev_over_heat_count;
      break;
    case dev_reason::REASON_DEV_THERMAL_CUTOFF:
      ++dev->dev_thermal_cutoff_count;
      break;
    case dev_reason::REASON_DEV_COMMS_ERROR:
      ++dev->dev_comms_error_count;
      break;
    case dev_reason::REASON_DEV_THROTTLE:
      ++dev->dev_throttle_count;
      break;
    default:
      return;
  }
}
