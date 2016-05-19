/*字典树，翻译*/
 #include<iostream>
 #include<cstring>
 #include<cstdlib>
 using namespace std;
 struct node
 {
    node* child[26];
    char word[12];
 };
 node*root=new node();
 void init()//初始化 
 {
    for(int i=0;i<26;i++) root->child[i]=NULL;
    strcpy(root->word,"");
 }
 void insert(char* s1,char* s2)//有s2 推s1 
 {
    int len=strlen(s2);
    node* cur=root;
    int i,pos,j;
    for(i=0;i<len;i++)
    {
       pos=s2[i]-'a';
       if(cur->child[pos]!=NULL) cur=cur->child[pos];
       else
       {
           cur->child[pos]=new node();
           node*temp=cur->child[pos];
           for(j=0;j<26;j++) temp->child[j]=NULL,strcpy(cur->word,"");//单词置空 
           cur=temp;
       }
    }
    strcpy(cur->word,s1);//s1放到对应的节点里面 
 }
 void print(char* s)//找出s对应的英语单词 
 {
    int len=strlen(s),i,j,pos;
    node*cur=root;
    for(i=0;i<len;i++)
    {
       pos=s[i]-'a';
       if(cur->child[pos]!=NULL) cur=cur->child[pos];
       else  break;
    }
    if(i==len && strlen(cur->word))  printf("%s",cur->word);//find
    else printf("%s",s);//not found ， print itself
 } 
 int main()
 {
     
     init();
     char a[12],b[12],line[3008];
     scanf("%s",&a);//读取start 
     getchar();
     while(scanf("%s",&a)==1 && strcmp(a,"END"))//
     {
       scanf("%s",&b);
       insert(a,b);
     }
     scanf("%s",&a);//读取start
     getchar();//读回车 
     int i,len;
     string temp;
     while(gets(line) && strcmp(line,"END"))
     {
        //printf("line:%s\n",line);
        temp="";
        len=strlen(line);
        for(i=0;i<len;i++)
        {
           if(isalpha(line[i])) temp+=line[i];
           else 
           {
              //printf("temp:%s\n",&temp[0]);
               print(&temp[0]);//char* 
               temp="";
               printf("%c",line[i]);
           }
        }
        print(&temp[0]);
        strcpy(line,"");//
        
        print("\n");
        //printf("................................\n");
     }
     system("pause");
     return 0;
 }