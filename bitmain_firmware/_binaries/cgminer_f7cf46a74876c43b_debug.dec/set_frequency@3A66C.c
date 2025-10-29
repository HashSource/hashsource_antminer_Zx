void __fastcall set_frequency(unsigned int frequency)
{
  uint8_t *chain_exist; // r5
  int v3; // r4
  int v4; // t1

  chain_exist = dev.chain_exist;
  LOBYTE(v3) = 0;
  do
  {
    v4 = *chain_exist++;
    if ( v4 == 1 )
      set_frequency_chain(v3, frequency);
    v3 = (unsigned __int8)(v3 + 1);
  }
  while ( v3 != 4 );
  cgsleep_ms(10);
}
