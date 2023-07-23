#ifndef _SCRIPTGENERATOR_H_
#define _SCRIPTGENERATOR_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <ctype.h>
#include <vector>

#define MAX_LEN 100

using namespace std;

class ScriptGenerator{
    public:
        ScriptGenerator();
        bool OpenTaskTempulate(void);
        void TaskTempulateRead(void);
        void ScriptOutput(void);
        void CloseALLFiles(void);
    protected:
        fstream fin, fout_h, fout_c;
        string filename;
        string varname;
        vector<string> stages;
        int stage_num;
        char str_buffer[MAX_LEN];
        string input_str;
        string& _deleteBlankSpace(string &s);
        string& _convertLowerToUpper(string &s);
        string& _scriptGeneratorGetLine(string& str, char *str_buffer);   
};      


#endif
