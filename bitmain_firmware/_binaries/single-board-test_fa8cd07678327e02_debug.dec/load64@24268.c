uint64_t __cdecl load64(const void *src)
{
  unsigned __int64 w; // [sp+28h] [bp+28h]

  w = *(unsigned __int8 *)src
    | (*((unsigned __int8 *)src + 1) << 8)
    | (*((unsigned __int8 *)src + 2) << 16)
    | (unsigned __int64)(*((unsigned __int8 *)src + 3) << 24);
  HIDWORD(w) = (*((unsigned __int8 *)src + 7) << 24)
             | (*((unsigned __int8 *)src + 6) << 16)
             | (*((unsigned __int8 *)src + 5) << 8)
             | *((unsigned __int8 *)src + 4);
  return w;
}
