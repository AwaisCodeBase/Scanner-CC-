#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> keywords = {
    "FUN", "MAIN", "INT", "FLT", "STR", "BOOL", "CONST",
    "IF", "EL", "ELIF", "FOR", "WHILE", "DO", "RETURN", "OUTPUT", "TRUE", "FALSE"};

bool isSymbol(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' ||
           ch == '<' || ch == '>' || ch == '=' || ch == '.' || ch == '(' || ch == ')' ||
           ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == '~' || ch == ':' || ch == ',';
}

void scan(string code)
{
    for (size_t i = 0; i < code.length();)
    {
        char ch = code[i];

        if (isspace(ch))
        {
            i++;
            continue;
        }

        if (ch == '@' && code[i + 1] != '@')
        {
            while (i < code.length() && code[i] != '\n')
                i++;
            continue;
        }

        if (ch == '@' && code[i + 1] == '@')
        {
            i += 2;
            while (i < code.length() - 1 && !(code[i] == '@' && code[i + 1] == '@'))
                i++;
            i += 2;
            continue;
        }

        if (isalpha(ch) || ch == '_')
        {
            string word;
            while (i < code.length() && (isalnum(code[i]) || code[i] == '_'))
            {
                word += code[i++];
            }
            if (keywords.count(word))
            {
                cout << "[KEYWORD] " << word << endl;
            }
            else
            {
                cout << "[IDENTIFIER] " << word << endl;
            }
            continue;
        }

        if (isdigit(ch))
        {
            string number;
            bool isFloat = false;

            while (i < code.length())
            {
                if (isdigit(code[i]))
                {
                    number += code[i++];
                }
                else if (code[i] == '.')
                {
                    if (i + 1 < code.length() && isdigit(code[i + 1]))
                    {
                        isFloat = true;
                        number += code[i++];
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }

            cout << (isFloat ? "[FLOAT] " : "[INT] ") << number << endl;

            if (i < code.length() && code[i] == '.')
            {
                cout << "[SYMBOL] ." << endl;
                i++;
            }

            continue;
        }

        if (ch == '"')
        {
            string str;
            str += code[i++]; // opening "
            while (i < code.length() && code[i] != '"')
            {
                str += code[i++];
            }
            if (i < code.length())
                str += code[i++];
            cout << "[STRING] " << str << endl;
            continue;
        }

        if (isSymbol(ch))
        {
            cout << "[SYMBOL] " << ch << endl;
            i++;
            continue;
        }

        cout << "[UNKNOWN] " << ch << endl;
        i++;
    }
}

string readFile(const string &filename)
{
    ifstream file(filename);
    string content, line;

    if (!file)
    {
        cout << "Could not open file: " << filename << endl;
        return "";
    }

    while (getline(file, line))
    {
        content += line + "\n";
    }

    return content;
}

int main()
{
    int choice;
    cout << "===========================" << endl;
    cout << "     AEX SCANNER TOOL      " << endl;
    cout << "===========================" << endl;
    cout << "1. Use dummy AEX program" << endl;
    cout << "2. Use default file (program.aex)" << endl;
    cout << "3. Input your own file name" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cin.ignore();

    string code;

    switch (choice)
    {
    case 1:
        code = R"(
                    @@_ab$c
                    /IF1.5+!=>@@=3.5.45=<
            )";
        cout << "\nScanning dummy AEX program...\n\n";
        scan(code);
        break;

    case 2:
        code = readFile("program.txt");
        if (!code.empty())
        {
            cout << "\nScanning 'program.aex'...\n\n";
            scan(code);
        }
        break;

    case 3:
    {
        string filename;
        cout << "Enter file name (with extension): ";
        getline(cin, filename);
        code = readFile(filename);
        if (!code.empty())
        {
            cout << "\nScanning '" << filename << "'...\n\n";
            scan(code);
        }
        break;
    }

    default:
        cout << "Invalid choice. Exiting...\n";
        break;
    }

    return 0;
}
