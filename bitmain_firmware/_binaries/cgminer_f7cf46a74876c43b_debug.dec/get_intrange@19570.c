void __fastcall get_intrange(char *arg, int *val1, int *val2)
{
  if ( sscanf(arg, "%d-%d", val1, val2) == 1 )
    *val2 = *val1;
}
