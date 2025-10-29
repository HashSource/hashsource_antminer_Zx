void __fastcall add_opt(const opt_table *entry)
{
  opt_table *v2; // r4
  const char *names; // r0
  opt_type type; // r1
  char *(*cb)(void *); // r2
  char *(*cb_arg)(const char *, void *); // r3
  unsigned int v7; // r12
  opt_table *v8; // r4
  opt_type v9; // r1
  char *(*v10)(void *); // r2

  v2 = (opt_table *)realloc(opt_table_0, 28 * (opt_count + 1));
  names = entry->names;
  type = entry->type;
  cb = entry->cb;
  cb_arg = entry->cb_arg;
  entry = (const opt_table *)((char *)entry + 16);
  opt_table_0 = v2;
  v7 = opt_count++;
  v8 = &v2[v7];
  v8->names = names;
  v8->type = type;
  v8->cb = cb;
  v8->cb_arg = cb_arg;
  v8 = (opt_table *)((char *)v8 + 16);
  v9 = entry->type;
  v10 = entry->cb;
  v8->names = entry->names;
  v8->type = v9;
  v8->cb = v10;
}
