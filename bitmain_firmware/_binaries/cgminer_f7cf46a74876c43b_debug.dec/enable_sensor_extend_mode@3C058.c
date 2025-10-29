void enable_sensor_extend_mode()
{
  int v0; // r4
  uint8_t *chain_exist; // r6
  int v2; // t1
  int i; // r5
  unsigned __int8 v4; // r1

  LOBYTE(v0) = 0;
  chain_exist = dev.chain_exist;
  do
  {
    v2 = *chain_exist++;
    if ( v2 == 1 )
    {
      for ( i = 0; i != 3; ++i )
      {
        v4 = i;
        write_i2c_reg(v0, v4, 0x4Cu, 9u, 4u);
      }
    }
    v0 = (unsigned __int8)(v0 + 1);
  }
  while ( v0 != 4 );
}
