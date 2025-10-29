api_data *__fastcall api_add_int(api_data *root, char *name, int *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_INT, data, copy_data);
}
