int res;
  for (int i=0;exp[i]!='\0';i++){
    if(exp[i]=='('){
        push(')');
    }
    if(exp[i]=='['){
        push(']');
    }
    if(exp[i]=='{'){
        push('}');
    }
       if(exp[i]==')'){
        res=pop('(');
    }
       if(exp[i]=='}'){
        res=pop('{');
    }
       if(exp[i]==']'){
        res=pop('[');
    }
    if(res==0){
  printf("It is not a valid expression");
        return 0;
    }
  }