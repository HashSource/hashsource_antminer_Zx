uint64_t __cdecl rotr64(const uint64_t w, const unsigned int c)
{
  return (w << (-(char)c & 0x3F)) | (w >> c);
}
