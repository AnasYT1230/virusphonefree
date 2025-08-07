#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Function to get Current User in Windows who is logged in.
void tunnel()
{
    system("echo %USERPROFILE%>user");
}

//Function to detect and remove chrome.bat in startup folder in windows.
void tscan()
{
    FILE *f;
    char s[300],tmp[350],tmp2[350],ch; int i=0;
    f=fopen("user","r");
    if(f==NULL)
    {
        exit(0);
    }
    while(feof(f)==0)
    {
        fscanf(f,"%c",&ch);
        if(ch=='\n')
            break;
        s[i]=ch;
        i++;
    }
    s[i]='\0';
    fclose(f);
    strcat(s,"\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\chrome.bat");
	strcpy(tmp,"del \"");
	strcat(tmp,s);
	strcat(tmp,"\"");
    f=fopen(s,"r");
    if(f!=NULL)
    {
        printf("\nCstorm Infection Detected!:%s",s);
        printf("\nAttempting Repairs!\n");
        fclose(f);
        system(tmp);
    }
    else
    fclose(f);
    f=fopen("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\chrome.bat","r");
    if(f!=NULL)
    {
       printf("\nCstorm Infection Detected!");
       printf("\nAttempting Repairs!\n");
	   strcpy(tmp2,"del \"");
	   strcat(tmp2,"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\chrome.bat");
	   strcat(tmp2,"\"");
	   fclose(f);
       system(tmp2);
    }
    else
    fclose(f);
}

//Perform cleaning of temporary files generated .
void ok()
{
    remove("user");
}

//Load all reqired functions.
void run()
{
    tunnel();
    tscan();
}

//Function to pause the program.
void pause()
{
    printf("\n");
    system("pause");
}

int main()
{
    system("title Cstorm Remover ");
    run();
    ok();
    printf("All operations completed...\n");
    pause();
}
