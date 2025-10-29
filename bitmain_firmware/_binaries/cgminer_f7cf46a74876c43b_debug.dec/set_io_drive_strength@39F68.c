void set_io_drive_strength()
{
  int v0; // r4
  uint8_t *chain_exist; // r5
  int v2; // t1

  LOBYTE(v0) = 0;
  chain_exist = dev.chain_exist;
  do
  {
    v2 = *chain_exist++;
    if ( v2 == 1 )
      set_io_drive_strength_chain(v0);
    v0 = (unsigned __int8)(v0 + 1);
  }
  while ( v0 != 4 );
  cgsleep_ms(10);
}
