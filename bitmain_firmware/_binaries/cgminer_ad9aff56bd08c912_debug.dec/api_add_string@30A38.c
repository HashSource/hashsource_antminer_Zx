api_data *__fastcall api_add_string(api_data *root, char *name, char *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_STRING, data, copy_data);
}
