api_data *__fastcall api_add_bool(api_data *root, char *name, bool *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_BOOL, data, copy_data);
}
