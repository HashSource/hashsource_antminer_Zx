void set_lowprio()
{
  if ( !nice(10) && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    set_lowprio_0();
}
