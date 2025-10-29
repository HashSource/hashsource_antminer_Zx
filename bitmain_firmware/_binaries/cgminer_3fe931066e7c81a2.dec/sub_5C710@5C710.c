int __fastcall sub_5C710(int a1, unsigned int a2)
{
  if ( !a2 )
    JUMPOUT(0x5CC00);
  return divsi3_skip_div0_test(a1, a2);
}
