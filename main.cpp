#include "Inc/ScriptGenerator.h"

using namespace std;

int main(void)
{
    ScriptGenerator sg;
    sg.OpenTaskTempulate();
    sg.TaskTempulateRead();
    sg.ScriptOutput();
    sg.CloseALLFiles();
    return 0;
}

