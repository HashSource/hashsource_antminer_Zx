int __fastcall sub_59AC8(int a1, unsigned int a2)
{
  if ( !a2 )
    JUMPOUT(0x59FB8);
  return divsi3_skip_div0_test(a1, a2);
}
