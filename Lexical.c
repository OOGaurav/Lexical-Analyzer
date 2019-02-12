#include<stdio.h>
#include<string.h>
#include<ctype.h>

int Constant(char s)
{
	if ( isdigit(s) != 0 )
		return 1;
	else
		return 0;
}

int Operator(char s)
{
	if (s == '+' || s == '-' || s == '*' || s == '/' || s == '=')
		return 1;
	else
		return 0;
}

int Punct(char s)
{
	if (s == ',' || s == ';' || s == '.')
		return 1;
	else
		return 0;
}

int Identifier(char s[], int len)
{
	int iden=0, i=0;
	while(i <= len-2)
	{
		if ( isalpha(s[i])!=0 )
		{
			i++;
			while(i <= len-2){
				if(Operator(s[i]) || Punct(s[i])){
					iden++;
					break;
				}
				i++;
			}
			//goto f;
		}
		i++;
		//f:;
	}
	return iden;
}

int Keyword(char s[], int len)
{
	int key=0, i=0;
	while(i <= len-2)
	{
		if ( isalpha(s[i])!=0 )
		{
			if (s[i]=='i' && s[i+1]=='n' && s[i+2]=='t')
			{
				key++;
				i += 3;
				goto f;
			}
			else if (s[i]=='f' && s[i+1]=='l' && s[i+2]=='o' && s[i+3]=='a' && s[i+4]=='t')
			{
				key++;
				i += 5;
				goto f;
			}
			else if (s[i]=='c' && s[i+1]=='h' && s[i+2]=='a' && s[i+3]=='r')
			{
				key++;
				i += 4;
				goto f;
			}
			else if (s[i]=='d' && s[i+1]=='o' && s[i+2]=='u' && s[i+3]=='b' && s[i+4]=='l' && s[i+5]=='e')
			{
				key++;
				i += 6;
				goto f;
			}

		}
		i++;
		f:;
	}
	return key;
}

int main()
{
	char s[1000];
	fgets(s,1000,stdin);
	int len = strlen(s);
	int con=0, op=0, punc=0, iden, key;
	for (int i = 0; i <= len-2; ++i)
	{
		if (Constant(s[i]))
			con++;
		else if (Operator(s[i]))
			op++;
		else if (Punct(s[i]))
			punc++;
	}
	iden = Identifier(s, len);
	key = Keyword(s, len);
	printf("\nKeyword: %d\n",key);
	printf("Identifier: %d\n",iden);
	printf("Constant: %d\n",con);
	printf("Operator: %d\n",op);
	printf("Punctuator: %d\n",punc);

	return 0;
}

//int a=b+2; float c=d-3; sum=e*4; f=s+1,. char x;