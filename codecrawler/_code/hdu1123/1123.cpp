#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;
struct Expression
{
    char*  exp;
    int type;
    char op;
};
int main()
{
    int tc =0;
    int table[130][130];
    table['+']['+']= 1; table['+']['-']= 1; table['+']['*']=-1; table['+']['/']=-1; table['+']['(']=-1;     table['+'][')']=1;      table['+']['#']=1; 
    table['-']['+']= 1; table['-']['-']= 1; table['-']['*']=-1; table['-']['/']=-1; table['-']['(']=-1;     table['-'][')']=1;      table['-']['#']=1; 
    table['*']['+']= 1; table['*']['-']= 1; table['*']['*']= 1; table['*']['/']= 1; table['*']['(']=-1;     table['*'][')']=1;      table['*']['#']=1; 
    table['/']['+']= 1; table['/']['-']= 1; table['/']['*']= 1; table['/']['/']= 1; table['/']['(']=-1;     table['/'][')']=1;      table['/']['#']=1; 
    table['(']['+']=-1; table['(']['-']=-1; table['(']['*']=-1; table['(']['/']=-1; table['(']['(']=-1;     table['('][')']=0;      table['(']['#']=-10000; 
    table[')']['+']= 1; table[')']['-']= 1; table[')']['*']= 1; table[')']['/']= 1; table[')']['(']=-10000; table[')'][')']=1;      table[')']['#']=1; 
    table['#']['+']=-1; table['#']['-']=-1; table['#']['*']=-1; table['#']['/']=-1; table['#']['(']=-1;     table['#'][')']=-10000; table['#']['#']=0; 
    scanf("%d",&tc);
    while(tc>0)
    {
        char input[255];
        scanf("%s",input);
        stack<char> operators;
        operators.push('#');
        stack<Expression>  operands;
        ::strcat(input,"#");
        for(int i=0;i<::strlen(input);i++)
        {
            if(input[i] == '#'||input[i] == '+'||input[i] == '-'||input[i] == '*'||input[i] == '/'||input[i] == '('||input[i] == ')')
            {
                char topOp = operators.top();
                if(table[topOp][input[i]]<0)
                    operators.push(input[i]);
                else if(table[topOp][input[i]]==0)
                    operators.pop();
                else
                {
                    i--;
                    operators.pop();
                    Expression exp2 = operands.top();
                    operands.pop();
                    Expression exp1 = operands.top();
                    operands.pop();
                    char* expA = exp1.exp;
                    char* expB = exp2.exp;
                    Expression n_exp;
                    n_exp.op = topOp;
                    n_exp.exp=new char[300];
                    n_exp.exp[0]='\0';
                    if(topOp == '+'||topOp == '-')
                    {
                        ::strcat(n_exp.exp,expA);
                        ::strcat(n_exp.exp,topOp=='+'?"+":"-");
                        if(topOp == '-' && exp2.type==1)
                        {
                            ::strcat(n_exp.exp,"(");
                            ::strcat(n_exp.exp,expB);
                            ::strcat(n_exp.exp,")");
                        }
                        else
                            ::strcat(n_exp.exp,expB);
                        n_exp.type=1;
                        operands.push(n_exp);
                    }
                    if(topOp == '*'||topOp == '/')
                    {
                        if(exp1.type==1)
                        {
                            ::strcat(n_exp.exp,"(");
                            ::strcat(n_exp.exp,expA);
                            ::strcat(n_exp.exp,")");
                        }
                        else
                            ::strcat(n_exp.exp,expA);
                        ::strcat(n_exp.exp,topOp=='*'?"*":"/");
                        if(exp2.type==1 || (topOp=='/'&&exp2.type==2))
                        {
                            ::strcat(n_exp.exp,"(");
                            ::strcat(n_exp.exp,expB);
                            ::strcat(n_exp.exp,")");
                        }
                        else
                            ::strcat(n_exp.exp,expB);
                        n_exp.type=2;
                        operands.push(n_exp);
                    }
                    delete[] expA;
                    delete[] expB;
                }
            }
            else
            {
                int j=i;
                while(!(input[i] == '#'||input[i] == '+'||input[i] == '-'||input[i] == '*'||input[i] == '/'||input[i] == '('||input[i] == ')') && i<::strlen(input))
                    i++;
                Expression exp;
                exp.type=3;
                exp.op='?';
                exp.exp = new char[i-j+1];
                for(int k=0;k<i-j+0;k++)
                    exp.exp[k] = input[j+k];
                exp.exp[i-j+0]='\0';
                operands.push(exp);
                i--;
            }
        }
        cout<<operands.top().exp<<endl;
        tc--;
    }
    return 0;
}