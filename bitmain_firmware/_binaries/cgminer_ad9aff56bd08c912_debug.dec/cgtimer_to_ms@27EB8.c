int __fastcall cgtimer_to_ms(cgtimer_t *cgt)
{
  return cgt->tv_nsec / 1000000 + 1000 * cgt->tv_sec;
}
