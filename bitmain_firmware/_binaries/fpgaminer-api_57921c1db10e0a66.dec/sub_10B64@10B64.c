__int64 sub_10B64()
{
  __int64 result; // r0

  LODWORD(result) = &stderr;
  HIDWORD(result) = 0;
  return result;
}
