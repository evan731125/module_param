unsigned int flag = 0;
int foo_set(const char *val, struct kernel_param *kp)
{
	int _val = simple_strtol(val,NULL,0);
	flag = _val;

	return 0;
}

int foo_get(char *buffer, struct kernel_param *kp)
{
	sprintf(buffer, "%d", flag);
	return *buffer;
}
module_param_call(foo, foo_set, foo_get, NULL, 0644);
