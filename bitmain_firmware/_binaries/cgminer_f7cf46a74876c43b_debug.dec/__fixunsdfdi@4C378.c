// Alternative name is '__aeabi_d2ulz'
UDItype __fastcall _fixunsdfdi(DFtype a)
{
  double v2; // d4
  UDItype result; // r0

  v2 = (double)(unsigned int)(a * 2.32830644e-10);
  HIDWORD(result) = (unsigned int)(a * 2.32830644e-10);
  LODWORD(result) = (unsigned int)(a - v2 * 4294967300.0);
  return result;
}
