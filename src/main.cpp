#include "CallR2.hpp"
#include "Truncate.hpp"
#include "SplitIndex.hpp"
#include "ListSuffix.hpp"

void help(int argc, char **argv)
{
    if ((argc < 2) || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help") || !strcmp(argv[1], "-help"))
    {
        std::cout << "fqtools (call-R2|truncate|split-index|list-suffix) -h|--help|-help\n";
        exit(0);
    }
}

void cmd(int argc, char **argv)
{
    char **cmd_argv = &argv[1];
    int cmd_argc = argc - 1;
    if (!strcmp(cmd_argv[0], "call-R2"))
    {
        CallR2(cmd_argc, cmd_argv).run();
    }
    else if (!strcmp(cmd_argv[0], "truncate"))
    {
        Truncate(cmd_argc, cmd_argv).run();
    }
    else if (!strcmp(cmd_argv[0], "split-index"))
    {
        SplitIndex(cmd_argc, cmd_argv).run();
    }
    else if (!strcmp(cmd_argv[0], "list-suffix"))
    {
        ListSuffix(cmd_argc, cmd_argv).run();
    }
    else
    {
        std::cerr << "command not found\n";
    }
}

int main(int argc, char **argv)
{
    help(argc, argv);
    cmd(argc, argv);
    return 0;
}
