int __fastcall sub_49488(double a1)
{
  __int64 v1; // r0
  __int64 v2; // r0

  if ( a1 >= 0.0 )
  {
    LODWORD(v2) = sub_494C0(a1);
  }
  else
  {
    HIDWORD(a1) ^= 0x80000000;
    LODWORD(v1) = sub_494C0(a1);
    return -v1;
  }
  return v2;
}
