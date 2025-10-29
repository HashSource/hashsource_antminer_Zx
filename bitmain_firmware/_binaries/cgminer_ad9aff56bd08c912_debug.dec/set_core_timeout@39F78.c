void __fastcall set_core_timeout(uint32_t timeout)
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
      set_core_timeout_chain(v3, timeout);
    v3 = (unsigned __int8)(v3 + 1);
  }
  while ( v3 != 4 );
  cgsleep_ms(10);
}
