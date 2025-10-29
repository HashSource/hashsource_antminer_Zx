int __fastcall chain_reset(char a1)
{
  chain_reset_low(a1);
  usleep((__useconds_t)&stru_1869C.st_value);
  return chain_reset_high(a1);
}
