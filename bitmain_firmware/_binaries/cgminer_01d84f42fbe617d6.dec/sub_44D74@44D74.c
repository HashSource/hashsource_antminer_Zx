int __fastcall sub_44D74(int a1, int a2)
{
  int v3; // r4

  v3 = sub_44BA4(a1, a2);
  if ( (unsigned int)(v3 + 2) > 1 )
    DataWriter::WriteByte((const void **)(a1 + 40), v3);
  return v3;
}
