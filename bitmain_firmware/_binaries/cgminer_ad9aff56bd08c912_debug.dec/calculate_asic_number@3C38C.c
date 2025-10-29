int __fastcall calculate_asic_number(unsigned int actual_asic_number)
{
  if ( actual_asic_number != 1 && actual_asic_number != 2 )
  {
    if ( actual_asic_number - 3 <= 1 )
    {
      return 4;
    }
    else if ( actual_asic_number - 5 <= 3 )
    {
      return 8;
    }
    else if ( actual_asic_number - 9 <= 7 )
    {
      return 16;
    }
    else if ( actual_asic_number - 17 <= 0xF )
    {
      return 32;
    }
    else if ( actual_asic_number - 33 <= 0x1F )
    {
      return 64;
    }
    else if ( actual_asic_number - 65 <= 0x3F )
    {
      return 128;
    }
    else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      return calculate_asic_number_0(actual_asic_number);
    }
    else
    {
      return -1;
    }
  }
  return actual_asic_number;
}
