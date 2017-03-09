#include<stdio.h>

int TryReplace(char STR[],char PAT[],char REP[],char ANS[])
{
	int a,b,c,d,flag,isPresent = 0;
	a = b = c = d = 0;
	
	while(STR[a+1] != '\0')
	{
		flag = 1;
		b = a;
		c = 0;
		
		while(PAT[c+1] != '\0')
		{
			if(PAT[c] != STR[b])
			{
				flag = 0;
				break;
			}
			b++;
			c++;
		}

		if(flag)
		{
			isPresent = 1;
			a = b;
			c = 0;
			
			while(REP[c+1] != '\0')
			{
				ANS[d] = REP[c];
				d++;
				c++;
			}
		}
		else
		{
			ANS[d] = STR[a];
			d++;
			a++;
		}
	}
	
	ANS[d] = '\0';
	
	return isPresent;
}

int main()
{
	char STR[100],PAT[15],REP[15],ANS[200];
	
	printf("Enter A Sentence : ");
	fgets(STR,100,stdin);
	printf("Enter A Pattern String : ");
	fgets(PAT,15,stdin);
	printf("Enter A Replace String : ");
	fgets(REP,15,stdin);

	if(TryReplace(STR,PAT,REP,ANS))
	{
		printf("The Answer is : ");
		puts(ANS);
	}
	else
	{
		printf("The Pattern Was Not Found. \n");
	}

}
