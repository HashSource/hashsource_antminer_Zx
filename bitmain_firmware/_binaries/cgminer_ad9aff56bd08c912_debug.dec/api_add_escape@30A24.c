api_data *__fastcall api_add_escape(api_data *root, char *name, char *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_ESCAPE, data, copy_data);
}
