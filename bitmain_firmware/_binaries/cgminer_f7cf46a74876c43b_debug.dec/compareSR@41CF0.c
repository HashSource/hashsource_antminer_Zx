int __fastcall compareSR(const void *p1, const void *p2)
{
  return j_memcmp(p1, p2, compare_size);
}
