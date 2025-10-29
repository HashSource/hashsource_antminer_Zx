char *__fastcall set_sched_stop(const char *arg)
{
  if ( sscanf(arg, "%d:%d", &schedstop.tm.tm_hour, &schedstop.tm.tm_min) != 2 )
    return "Invalid time set, should be HH:MM";
  if ( schedstop.tm.tm_hour > 0x17u || schedstop.tm.tm_min > 0x3Bu )
    return "Invalid time set.";
  schedstop.enable = 1;
  return 0;
}
