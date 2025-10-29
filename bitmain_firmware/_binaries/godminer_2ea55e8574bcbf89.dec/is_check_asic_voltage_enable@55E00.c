int is_check_asic_voltage_enable()
{
  int result; // r0

  result = (unsigned __int8)byte_17420C;
  if ( byte_17420C )
    return (unsigned __int8)byte_174218;
  return result;
}
