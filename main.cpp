#include <bits/stdc++.h>

struct Command_content
{
    std::string file1;
    std::string file2;
    std::string div_string;
    size_t sta=0;
    size_t end=std::string::npos;
    Command_content(int argc, char **argv)
    {
        for(int i=1; i<argc-1; ++i)
        {
            if(!strcmp(argv[i],"-file1"))
                file1=std::string(argv[i+1]);
            if(!strcmp(argv[i],"-file2"))
                file2=std::string(argv[i+1]);
            if(!strcmp(argv[i],"-div_strings"))
                div_string=std::string(argv[i+1]);
            if(!strcmp(argv[i],"-sta"))
                sta=stoi(std::string(argv[i+1]));
            if(!strcmp(argv[i],"-end"))
                end=stoi(std::string(argv[i+1]));
        }
        if(div_string=="space")
            div_string=" ";
    }
};


int main(int argc, char **argv) 
{
    Command_content cc(argc,argv);
    std::ofstream fout(cc.file2+".op");
    std::ifstream fin1(cc.file1);
    std::ifstream fin2(cc.file2);
    std::string address1, address2;
    getline(fin1,address1);
    getline(fin2,address2);
    while(fin1.good())
    {
        int tmp=address1.find_first_of(cc.div_string);
        std::string left_address=address1.substr(0,tmp);
        while(fin2.good())
        {
            tmp=address2.find_first_of(cc.div_string);
            if(address2.substr(0,tmp)==left_address)
            {
                for(int i=0; i<4; ++i)
                {
                    fout << address2 << '\n';
                    getline(fin2,address2);
                    if(i==0 || i==2)
                        address2=address2.substr(cc.sta,cc.end-cc.sta);
                }
                break;
            }
            else
                for(int i=0; i<4; ++i) getline(fin2,address2);
        }
        for(int i=0; i<4; ++i) getline(fin1,address1);
    }
    
    return 0;
}
