#include<stdio.h>
#include<string.h>
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
    int h=0,x=0;
    int res;
    printf("BITWISE DUPLICATES\n");
            //printf("Size of long int is : %d",sizeof(int));
    for(int i=0;a[i]!='\0';i++){
        x=1;
        x=x<<(a[i]-97);
        //printf("%c\t%d\t\n",a[i],a[i]-97);
            res=x&h;

        if(res>0){
            printf("%c is duplicate\n",a[i]);

        }
        else{
            h=h|x;
        }

    }
}


//anagram is a pair of strings formed by same set of elements
void anagram(char *a,char *b){
    int *p=(int *)calloc(26,sizeof(int));
    int res=1;
    int lengtha=strlen(a);
    int lengthb=strlen(b);

    if (lengtha==lengthb){
        for(int i=0;i<lengtha;i++){
            p[a[i]-97]++;
            p[b[i]-97]--;
        }
        for(int i=0;i<26;i++){
            if(p[i]>0){
                res=0;
                break;
            }
        }

    }
    else{
        printf("String length not equal. cannot be anagram. ");
    }

    if(res==1){
        printf("Yes it is a anagram");
    }
    else{
        printf("Not a anagram");
    }
}

void permutation(char *p,int k){
static int A[10];
static char res[10];
int i=0;
if(p[k]=='\0'){
    
    printf("%s\n",res);
}
else{
    for(i=0;p[i]!='\0';i++){
        if (A[i]==0){
            res[k]=p[i];
        A[i]=1;
        permutation(p,k+1);
        A[i]=0;
        }
    }
}
}


// void permswap(char s[],int l,int h){
// int i;
// if(l==h){
//     printf("%s\n",s);
// }
// else{
// for(i=l;i<=h;i++){
//     swap(s[l],s[i]);
//     permswap(s,l+1,h);
//     swap(s[l],s[i]);
// }
// }


// }
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
    
char ch8[]="administrator";
    duplicatebitwise(ch8);

    char ch9[]="medical";
    char ch10[]="decimal";
    anagram(ch9,ch10);

    char ch11[]="ABC";
    printf("\nPermutations of a string %s \n",ch11);
    permutation(ch11,0);

        return 0;
}

/*
Converting from upper case to lower case
A ascii value- 65
Z ascii value= 91

a ascii value - 97
a ascii value - 123

therefore ascii value of a - 32 = ascii value capital A

ascii value 0 - 48
ascii value 9 - 57

*/