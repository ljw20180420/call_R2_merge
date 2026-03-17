#include <bits/stdc++.h>

class Truncate
{
private:
    size_t sta = 0;
    size_t end = std::string::npos;

    void help(int argc, char **argv)
    {
        if (!std::cin.eof())
        {
            return;
        }
        if (argc < 2 || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help") || !strcmp(argv[1], "-help"))
        {
            std::cout << "fqtools truncate -sta truncate_start[optional, default: 0] -end truncate_end[optional, default: end_of_read]\n";
            exit(0);
        }
    }

    void parse(int argc, char **argv)
    {
        for (int i = 1; i < argc - 1; ++i)
        {
            if (!strcmp(argv[i], "-sta"))
                sta = stoi(std::string(argv[i + 1]));
            if (!strcmp(argv[i], "-end"))
                end = stoi(std::string(argv[i + 1]));
        }
    }

public:
    Truncate(int argc, char **argv)
    {
        help(argc, argv);
        parse(argc, argv);
    }

    void run()
    {
        std::string line;
        getline(std::cin, line);
        while (std::cin.good())
        {
            for (int i = 0; i < 4; ++i)
            {
                std::cout << line << '\n';
                getline(std::cin, line);
                if (i == 0 || i == 2)
                    line = line.substr(sta, end - sta);
            }
        }
    }
};