void __fastcall set_txn_data(int txn_shalow, int txn_zero)
{
  uint8_t *chain_exist; // r5
  int v5; // r4
  int v6; // t1

  chain_exist = dev.chain_exist;
  LOBYTE(v5) = 0;
  do
  {
    v6 = *chain_exist++;
    if ( v6 == 1 )
      set_txn_data_chain(v5, txn_shalow, txn_zero);
    v5 = (unsigned __int8)(v5 + 1);
  }
  while ( v5 != 4 );
}
