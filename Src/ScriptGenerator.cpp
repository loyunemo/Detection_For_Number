#include "ScriptGenerator.h"

using namespace std;

const string tab = "    ";

ScriptGenerator::ScriptGenerator(){
    stage_num = 0;
}

bool ScriptGenerator::OpenTaskTempulate(void){
    fin.open("./TaskTemplate.txt");
    if(!fin.is_open()){
        fin.open("../TaskTemplate.txt");
        if(!fin.is_open()){
            cout << "Open \"TaskTemplate.txt\" fail! " << endl;
            return -1;
        }
        else cout << "Open \"TaskTemplate.txt\" Success! " << endl;
    }else cout << "Open \"TaskTemplate.txt\" Success! " << endl;
}

void ScriptGenerator::TaskTempulateRead(void){
    int index;
    do index = _scriptGeneratorGetLine(input_str, str_buffer).find("FileName:"); while(!fin.eof() && index == -1); 
    filename = input_str.substr(index + 9, strlen(str_buffer) - index - 9);
    cout << "File Name: " << filename << endl;
    do index = _scriptGeneratorGetLine(input_str, str_buffer).find("Variable:"); while(!fin.eof() && index == -1); 
    varname = input_str.substr(index + 9, strlen(str_buffer) - index - 9);
    cout << "Variable: " << varname << endl;
    do _scriptGeneratorGetLine(input_str, str_buffer).find("Stages:"); while(!fin.eof() && index == -1);
    cout << "Readin Stages: " << endl;
    while(!fin.eof()){
        _scriptGeneratorGetLine(input_str, str_buffer);
        if(input_str != ""){
            stages.push_back(input_str);
            stage_num ++;
            cout << "  " << to_string(stage_num) << ". " << input_str << endl;
        }
    }
}

void ScriptGenerator::ScriptOutput(void){
    const char* filename_h = (filename + ".h").data();
    fout_h.open(filename_h, ios::out);
    const char* filename_c = (filename + ".c").data();
    fout_c.open(filename_c, ios::out);

    string tmp_fname = filename;

    // filename.h 文件
    // 头文件宏定义
    fout_h << "#ifndef _" + _convertLowerToUpper(tmp_fname) + "_H_" << endl;
    fout_h << "#define _" + _convertLowerToUpper(tmp_fname) + "_H_" << endl;
    fout_h << endl;

    // 头文件包含提示
    fout_h << "// macro include" << endl << endl;

    // 定义stage枚举变量类型
    fout_h << "typedef enum{ " << endl;
    for(auto it = stages.begin(); it != stages.end(); it++){
        fout_h << tab << *it;
        if(it == stages.begin()) fout_h << " = 0";
        if(it != stages.end())fout_h << "," << endl;
    }
    fout_h << "} " << filename << "_t;" << endl << endl;

    // 声明执行函数
    fout_h << "void " << filename << "Handler(void);" << endl << endl;

    // 声明枚举变量实例
    fout_h << "extern " << filename << "_t " << varname << ", " << "last_" << varname << endl << endl;

    // #endif
    fout_h << "#endif" << endl;

    // 输出.h文件成功log
    cout << "Output \"" + tmp_fname + ".h" + "\" Success!" << endl;

    // filename.c 文件
    // 包含头文件
    fout_c << "#include \"" + filename + ".h\"" << endl << endl;
    
    // 定义stage变量
    fout_c << filename << "_t " << varname << ", " << "last_" << varname << endl << endl;
    
    // 定义执行函数
    fout_c << "void " << filename << "Handler(void) {" << endl;
    fout_c << tab << "switch(" << varname << ") {" << endl;
    for(auto it = stages.begin(); it != stages.end(); it++){
        fout_c << tab << tab << "case ";
        fout_c << *it << ":" << endl;
        fout_c << tab << tab << tab << "// stage initiate" << endl;
        fout_c << tab << tab << tab << "if(" << varname << " != last_" << varname << ") {" << endl;
        fout_c << tab << tab << tab << tab << "last_" << varname << " = " << varname << ";" << endl << endl;
        fout_c << tab << tab << tab << tab << "// initiate todo" << endl << endl;
        fout_c <<  tab << tab << tab << "}" << endl << endl;
        fout_c <<  tab << tab << tab << "// loop" << endl << endl;
        fout_c <<  tab << tab << tab << "// end condition" << endl;
        fout_c <<  tab << tab << tab << "if(1) {" << endl;
        fout_c << tab << tab << tab << tab << "// end todo" << endl << endl;
        fout_c << tab << tab << tab << tab << varname << " ++;" << endl;
        fout_c << tab << tab << tab << "}" << endl;
        fout_c << tab << tab << tab << "break;" << endl << endl;
    }
    fout_c << tab << "}" << endl;
    fout_c << "}" << endl;

    // 输出.c文件成功log
    cout << "Output \"" + tmp_fname + ".c" + "\" Success!" << endl;
}

void ScriptGenerator::CloseALLFiles(void){
    fin.close();
    fout_h.close();
    fout_c.close();
}

string& ScriptGenerator::_deleteBlankSpace(string &s){
    int i;
    while((i=s.find(' '))!=-1) s.erase(i,1);
    while((i=s.find('\t'))!=-1) s.erase(i,1);
    return s;
}

string& ScriptGenerator::_convertLowerToUpper(string &s){
    for(auto &c : s) c = toupper(c);
    return s;
}

string& ScriptGenerator::_scriptGeneratorGetLine(string& str, char *str_buffer){
    fin.getline(str_buffer, MAX_LEN);
    str = str_buffer;
    return _deleteBlankSpace(str);
}