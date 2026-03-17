#include <bits/stdc++.h>

class ListSuffix
{
private:
    std::string path;
    std::string suffix;

    void help(int argc, char **argv)
    {
        if (argc < 2 || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help") || !strcmp(argv[1], "-help"))
        {
            std::cout << "fqtools list-suffix --path str --suffix str\n";
            std::cout << "Description: list files with specified suffix in path.\n";
            exit(0);
        }
    }

    void parse(int argc, char **argv)
    {
        for (int i = 1; i < argc - 1; ++i)
        {
            if (!strcmp(argv[i], "--path"))
                path = std::string(argv[i + 1]);
            if (!strcmp(argv[i], "--suffix"))
                suffix = std::string(argv[i + 1]);
        }
    }

public:
    ListSuffix(int argc, char **argv)
    {
        help(argc, argv);
        parse(argc, argv);
    }

    void run()
    {
        const std::filesystem::path search_path = std::filesystem::path(path);
        for (std::filesystem::directory_iterator itr(search_path); itr != std::filesystem::directory_iterator(); ++itr)
            if (!std::filesystem::is_directory(itr->status()))
            {
                std::string file = itr->path().string();
                if (file.ends_with(suffix))
                {
                    std::cout << file << "\n";
                }
            }
    }
};