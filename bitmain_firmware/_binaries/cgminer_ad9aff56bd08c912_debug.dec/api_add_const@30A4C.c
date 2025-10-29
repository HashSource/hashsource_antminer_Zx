api_data *__fastcall api_add_const(api_data *root, char *name, const char *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_CONST, (void *)data, copy_data);
}
