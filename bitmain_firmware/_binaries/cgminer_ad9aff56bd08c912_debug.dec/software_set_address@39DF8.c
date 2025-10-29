void software_set_address()
{
  unsigned int v0; // r4
  uint8_t *chain_exist; // r5
  int v2; // t1

  v0 = 0;
  chain_exist = dev.chain_exist;
  do
  {
    v2 = *chain_exist++;
    if ( v2 == 1 )
      software_set_address_chain(v0);
    ++v0;
  }
  while ( v0 != 4 );
  cgsleep_ms(10);
}
