#include <bits/stdc++.h>

class CallR2
{
private:
    std::string R1;
    std::string R2;
    std::string source;
    std::string delimiter;
    size_t sta = 0;
    size_t end = std::string::npos;

    void help(int argc, char **argv)
    {
        for (int i = 1; i < argc; ++i)
        {
            if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help") || !strcmp(argv[i], "-help"))
            {
                std::cout << "fqtools call-R2 -R1 R1.fq[in] -R2 R2.fq[out] -source source.R2.fq[in] -delimiter \"str\" -sta truncate_start[optional, default: 0] -end truncate_end[optional, default: end_of_read]\n";
                exit(0);
            }
        }
    }

    void parse(int argc, char **argv)
    {
        for (int i = 1; i < argc - 1; ++i)
        {
            if (!strcmp(argv[i], "-R1"))
                R1 = std::string(argv[i + 1]);
            if (!strcmp(argv[i], "-R2"))
                R2 = std::string(argv[i + 1]);
            if (!strcmp(argv[i], "-source"))
                source = std::string(argv[i + 1]);
            if (!strcmp(argv[i], "-delimiter"))
                delimiter = std::string(argv[i + 1]);
            if (!strcmp(argv[i], "-sta"))
                sta = stoi(std::string(argv[i + 1]));
            if (!strcmp(argv[i], "-end"))
                end = stoi(std::string(argv[i + 1]));
        }
    }

    std::string cut_addr(std::string &addr, std::string &delimiter)
    {
        int pos = addr.find_first_of(delimiter);
        return addr.substr(0, pos);
    }

public:
    CallR2(int argc, char **argv)
    {
        help(argc, argv);
        parse(argc, argv);
    }

    void run()
    {
        std::ofstream fout(R2);
        std::ifstream fin1(R1);
        std::ifstream fin2(source);
        std::string addr1, addr2;
        getline(fin1, addr1);
        getline(fin2, addr2);
        while (fin1.good())
        {
            while (fin2.good())
            {
                if (cut_addr(addr2, delimiter) == cut_addr(addr1, delimiter))
                {
                    for (int i = 0; i < 4; ++i)
                    {
                        fout << addr2 << '\n';
                        getline(fin2, addr2);
                        if (i == 0 || i == 2)
                            addr2 = addr2.substr(sta, end - sta);
                    }
                    break;
                }
                else
                {
                    for (int i = 0; i < 4; ++i)
                    {
                        getline(fin2, addr2);
                    }
                }
            }
            for (int i = 0; i < 4; ++i)
            {
                getline(fin1, addr1);
            }
        }
    }
};