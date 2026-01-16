#include <bits/stdc++.h>

struct Command_content
{
    std::string R1;
    std::string R2;
    std::string source;
    std::string div_string;
    size_t sta=0;
    size_t end=std::string::npos;
    Command_content(int argc, char **argv)
    {
        for(int i=1; i<argc-1; ++i)
        {
            if(!strcmp(argv[i],"-R1"))
                R1=std::string(argv[i+1]);
            if(!strcmp(argv[i],"-R2"))
                R2=std::string(argv[i+1]);
            if(!strcmp(argv[i],"-source"))
                source=std::string(argv[i+1]);
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

std::string get_and_cut_addr(std::ifstream &fin, std::string &div_string) {
    std::string addr;
    getline(fin, addr);
    int pos=addr.find_first_of(div_string);
    return addr.substr(0, pos);
}

int main(int argc, char **argv) {
    for(int i=1; i<argc; ++i) {
        if(!strcmp(argv[i],"-h") || !strcmp(argv[i],"--help") || !strcmp(argv[i],"-help")) {
            std::cout << "./call_r2_merge -R1 R1.fq -R2 R2.fq -source 下机.R2.fq -sta 截取起始 -end 截取终止\n";
            return 0;
        }
    }

    Command_content cc(argc,argv);
    std::ofstream fout(cc.R2);
    std::ifstream fin1(cc.R1);
    std::ifstream fin2(cc.source);
    std::string addr1 = get_and_cut_addr(fin1, cc.div_string);
    std::string addr2 = get_and_cut_addr(fin2, cc.div_string);
    while(fin1.good()) {
        while(fin2.good()) {
            if(addr2 == addr1) {
                fout << addr2 << '\n';
                for(int i=0; i<3; ++i)
                {
                    getline(fin2, addr2);
                    if(i==0 || i==2)
                        addr2 = addr2.substr(cc.sta, cc.end - cc.sta);
                    fout << addr2 << '\n';
                }
                addr2 = get_and_cut_addr(fin2, cc.div_string);
                break;
            }
            else {
                for(int i=0; i<3; ++i) {
                    getline(fin2, addr2);
                }
                addr2 = get_and_cut_addr(fin2, cc.div_string);
            }
        }
        for(int i=0; i<3; ++i) {
            getline(fin1, addr1);
        }
        addr1 = get_and_cut_addr(fin1, cc.div_string);
    }
    
    return 0;
}
