int __cdecl compareSR(const void *p1, const void *p2)
{
  return memcmp(p1, p2, compare_size);
}
