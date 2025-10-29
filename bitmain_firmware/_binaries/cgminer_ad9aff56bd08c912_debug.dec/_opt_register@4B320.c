void __fastcall opt_register(
        const char *names,
        opt_type type,
        char *(*cb)(void *),
        char *(*cb_arg)(const char *, void *),
        void (*show)(char *, const void *),
        const void *arg,
        const char *desc)
{
  opt_table entry; // [sp+4h] [bp-20h] BYREF

  entry.type = type;
  entry.names = names;
  entry.cb = cb;
  entry.cb_arg = cb_arg;
  entry.desc = desc;
  entry.show = show;
  entry.u.tlen = (size_t)arg;
  check_opt(&entry);
  add_opt(&entry);
}
