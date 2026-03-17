#include "CallR2.hpp"

void help(int argc, char **argv)
{
    if ((argc < 2) || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help") || !strcmp(argv[1], "-help"))
    {
        std::cout << "fqtools (call-r2) -h|--help|-help\n";
        exit(0);
    }
}

void cmd(int argc, char **argv)
{
    char **cmd_argv = &argv[1];
    int cmd_argc = argc - 1;
    if (!strcmp(cmd_argv[0], "call-r2"))
    {
        CallR2 call_r2 = CallR2(cmd_argc, cmd_argv);
        call_r2.run();
    }
}

int main(int argc, char **argv)
{
    cmd(argc, argv);
    return 0;
}
