#include "../include/App.h"

int main(int argc, char* argv[])
{
    App aplicativo("diary.txt");
    return aplicativo.run(argc, argv);
}
