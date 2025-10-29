char *__fastcall set_sched_start(const char *arg)
{
  if ( sscanf(arg, "%d:%d", &schedstart.tm.tm_hour, &schedstart.tm.tm_min) != 2 )
    return "Invalid time set, should be HH:MM";
  if ( schedstart.tm.tm_hour > 0x17u || schedstart.tm.tm_min > 0x3Bu )
    return "Invalid time set.";
  schedstart.enable = 1;
  return 0;
}
