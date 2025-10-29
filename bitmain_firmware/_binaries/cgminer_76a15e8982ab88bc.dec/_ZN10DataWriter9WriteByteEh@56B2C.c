int __fastcall DataWriter::WriteByte(const void **this, unsigned __int8 a2)
{
  unsigned __int8 v3; // [sp+7h] [bp-5h] BYREF

  v3 = a2;
  return sub_56A68(this, &v3, 1u);
}
