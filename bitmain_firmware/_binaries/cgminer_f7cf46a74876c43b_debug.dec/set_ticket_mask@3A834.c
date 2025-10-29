void __fastcall set_ticket_mask(unsigned int ticket_mask)
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
      set_ticket_mask_chain(v3, ticket_mask);
    v3 = (unsigned __int8)(v3 + 1);
  }
  while ( v3 != 4 );
}
