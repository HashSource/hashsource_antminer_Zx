api_data *__fastcall api_add_uint(api_data *root, char *name, unsigned int *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_UINT, data, copy_data);
}
