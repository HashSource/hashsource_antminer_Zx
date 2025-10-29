char *__fastcall set_temp_cutoff(char *arg)
{
  if ( !arg )
    return "Invalid parameters for set temp cutoff";
  if ( !*arg )
    return "Invalid parameters for set temp cutoff";
  if ( (unsigned int)strtol(arg, 0, 10) > 0xC8 )
    return "Invalid value passed to set temp cutoff";
  temp_cutoff_str = arg;
  return 0;
}
