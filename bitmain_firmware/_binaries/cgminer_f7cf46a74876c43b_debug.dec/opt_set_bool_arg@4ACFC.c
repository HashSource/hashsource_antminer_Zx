char *__fastcall opt_set_bool_arg(const char *arg, bool *b)
{
  const char *v4; // r1
  const char *v5; // r1
  const char *v6; // r1

  if ( !strcasecmp(arg, "yes")
    || (LOWORD(v4) = 21368, HIWORD(v4) = (unsigned int)"ure_offset_value_chain_sensor" >> 16, !strcasecmp(arg, v4)) )
  {
    *b = 1;
    return 0;
  }
  else
  {
    LOWORD(v5) = 17780;
    HIWORD(v5) = (unsigned int)"t ASIC baud = %d, error!!!\n" >> 16;
    if ( !strcasecmp(arg, v5)
      || (LOWORD(v6) = 25936,
          HIWORD(v6) = (unsigned int)"data[3] = 0x%x, \t\tread_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x, \t\tread_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x\n" >> 16,
          !strcasecmp(arg, v6)) )
    {
      *b = 0;
      return 0;
    }
    else
    {
      return opt_invalid_argument(arg);
    }
  }
}
