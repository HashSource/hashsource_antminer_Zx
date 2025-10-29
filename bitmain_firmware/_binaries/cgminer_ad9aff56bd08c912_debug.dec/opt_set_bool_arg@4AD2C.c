char *__fastcall opt_set_bool_arg(const char *arg, bool *b)
{
  const char *v4; // r1
  const char *v5; // r1
  const char *v6; // r1

  if ( !strcasecmp(arg, "yes")
    || (LOWORD(v4) = 21496, HIWORD(v4) = (unsigned int)&sec_key[3][1] >> 16, !strcasecmp(arg, v4)) )
  {
    *b = 1;
    return 0;
  }
  else
  {
    LOWORD(v5) = 17908;
    HIWORD(v5) = (unsigned int)"mem_addr = 0x%x\n" >> 16;
    if ( !strcasecmp(arg, v5)
      || (LOWORD(v6) = 26060, HIWORD(v6) = (unsigned int)"x, read_back_data[1] = 0x%02x" >> 16, !strcasecmp(arg, v6)) )
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
