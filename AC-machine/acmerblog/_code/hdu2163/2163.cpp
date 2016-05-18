int is_palindrome(char *str)
{
	int i,len = strlen(str);
	for(i=0; i<len/2; i++)
	{
		if(str[i] != str[len-i-1])
			return 0;
	}
	return 1;
}