int main()
{
	char *a = "hello";

	printf("[%10s]\n",a);
	printf("[%.3s]\n", a);
	printf("[%.10s]\n", a);
	printf("[%10.3s]\n", a);
	printf("[%-10.10s]\n", a);
	printf("[%10.s]\n", a);
	return (0);
}
