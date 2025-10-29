__int64 register_tm_clones()
{
  __int64 result; // r0

  LODWORD(result) = &stdscr;
  HIDWORD(result) = 0;
  return result;
}
