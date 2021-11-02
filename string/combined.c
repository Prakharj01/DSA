#include<stdio.h>
#include<stdlib.h>
void uppercase(char *ch){

    for(int i=0;ch[i]!='\0';i++){
        ch[i] = ch[i] -32;
    }
    puts(ch);
}

void changingcase(char *ch){

    for(int i=0;ch[i]!='\0';i++){
        if(ch[i]>=65 && ch[i]<= 90){ 
        ch[i] = ch[i] +32;
        }
        else{
            ch[i]= ch[i] - 32;
        }
    }
    puts(ch);
}

void words(char *ch){
    int count=1;
    for(int i=0;ch[i]!='\0';i++){
       if(ch[i]==' ' && ch[i-1]!=' '){
           count++;
       }
    }
    
    puts(ch);
    printf("Number of words= %d \n", count);
}

void validstring(char *ch3){

}

void reversestring(char *ch){

}
void comparestring(char *a,char *b){
int i;
int res=0;
    for( i=0;a[i]!='\0' && b[i]!='\0';i++){
        if(a[i]!=b[i] && a[i]-b[i]!=32 && b[i]-a[i]!=32){
            res=5;
            break;
        }
    }
    if(res==5){
        printf("Strings not equal.");
        if(a[i] < b[i]){
            printf("%s is less than %s\n",a,b);
        }
        else{
            printf("%s is less than %s \n",b,a);
        }
    }
    else{
        printf("Equal\n");
    }
    
}
void palindrome(char *ch){
    int i;
    int res=0;
    for(i=0; ch[i]!='\0';i++){
        
    }
    i=i-1;
    for(int j=0;j<i;j++){

        if(ch[i]==ch[j]){
        i--;
        
        }
        else{
        res=1;
            break;
        }

    }
if(res==1){
    printf("Not a palindrome");

}
else{
    printf("Palindrome");
}
}

void duplicates(char *a){
    printf("\nDuplicate Elements\n");
int *array=(int *)calloc(26,sizeof(int));
for(int i=0; a[i]!='\0';i++){
    array[a[i]-97]++;
}
for(int i=0;i<26;i++){
    if (array[i] >1){
        printf("%c\t %d\n",i+97,array[i]);
    }
}
}

void duplicatebitwise(char *a){

}

int main()
{
    
    char ch[]="welcome";
    char ch2[]="WeLcOmE";
    uppercase(ch);

    changingcase(ch2);


    char ch3[]="Hello my   friend";
    words(ch3);
    char ch4[]="Painter";
    char ch5[]="painting";
    comparestring(ch4,ch5);

    char ch6[]="nitin";
    palindrome(ch6);
    
    char ch7[]="finding";
    duplicates(ch7);
    
char ch8="";
    duplicatebitwise(ch8);
    return 0;
}

/*
Converting from upper case to lower case
A ascii value- 65
a ascii value - 97

therefore ascii value of a - 32 = ascii value capital A

ascii value 0 - 48
ascii value 9 - 57

*/