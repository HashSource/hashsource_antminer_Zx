int __fastcall strbuffer_append_byte(strbuffer_t *strbuff, char byte)
{
  char v3; // [sp+7h] [bp-5h] BYREF

  v3 = byte;
  return strbuffer_append_bytes(strbuff, &v3, 1u);
}
