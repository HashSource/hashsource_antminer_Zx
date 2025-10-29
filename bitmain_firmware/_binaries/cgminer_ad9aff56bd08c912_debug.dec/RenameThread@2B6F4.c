void __fastcall RenameThread(const char *name)
{
  char buf[20]; // [sp+8h] [bp-14h] BYREF

  snprintf(buf, 0x10u, "cg@%s", name);
  prctl(15, buf, 0);
}
