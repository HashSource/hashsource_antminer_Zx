int godminer_register_status_monitor()
{
  add_chip_status_observer((int)godminer_chip_status_monitor);
  return add_fanspeed_observer((int)godminer_fan_monitor);
}
