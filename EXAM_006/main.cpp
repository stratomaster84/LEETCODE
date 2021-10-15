#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

class Queens{
private:
    WORD *lines;
    WORD *to_sub;
    int N;
//----------------------------------------
    WORD getLine(const WORD& line_to_sub, const int& line_no){
        WORD ret_line = 0x0001;
        int count = 0;
        for(int i = 0;i<N;i++){
            if(!(ret_line&line_to_sub)){
                if(count == line_no){
                    return ret_line;
                }
                count++;
            }
            ret_line <<= 1;
        }
        return 0x0000;
    }
//----------------------------------------
    int getLinearAddress(const int& line_no){
        int addr = 0;
        WORD tmp_line = lines[line_no];
        while(tmp_line != 1){
            tmp_line >>= 1;
            addr += 1;
        }
        addr += line_no*N;
        return addr;
    }
//----------------------------------------
    bool isLinearChecked(const int& linear_addr){
        WORD tmp_line = 0x0001 << (linear_addr%N);
        if(tmp_line & lines[linear_addr/N])
            return true;
        else
            return false;
    }
//----------------------------------------
    bool CheckDiagonals(){
        static int g = 0;
        g++;
        int _last_line = N-1;
        int _max_addr = N*N;
        for(int i =0;i<_last_line;i++){
            int l_addr = getLinearAddress(i);
            int l_addr_to_chk;
            int tmp_line;

            tmp_line = i;
            l_addr_to_chk = l_addr + N-1;
            while(l_addr_to_chk < _max_addr){
                if((l_addr_to_chk/N) == tmp_line)
                    break;
                if(isLinearChecked(l_addr_to_chk))
                    return false;
                l_addr_to_chk += N-1;
                tmp_line++;
            }
            tmp_line = i;
            l_addr_to_chk = l_addr + N+1;
            while(l_addr_to_chk < _max_addr){
                if((l_addr_to_chk/N) == tmp_line+2)
                    break;
                if(isLinearChecked(l_addr_to_chk))
                    return false;
                l_addr_to_chk += N+1;
                tmp_line++;
            }
        }
        return true;
    }
//----------------------------------------
    void print_line(const WORD& _line){
        WORD print_mask = 0x0001;
        for(int i=0;i<N;i++){
            if(print_mask & _line)
                cout << "Q ";
            else
                cout << ". ";
            print_mask <<= 1;
        }
        cout << '\n';
    }
//----------------------------------------
    void print_lines(const int& n){
        for(int i=N;i--;)
            print_line(result[n][i]);
        cout << '\n';
    }
//----------------------------------------
public:
    vector<WORD*> result;
    Queens(int _N) : N(_N){
        if(N<4)
            N = 4;
        if(N>16)
            N = 16;
        lines = new WORD [N];
        to_sub = new WORD [N];
        to_sub[0] = 0x0000;
    }
    ~Queens(){
        delete [] lines;
        delete [] to_sub;
        int _size = result.size();
        for(int i =0; i<_size ;i++)
            delete [] result[i];
        result.clear();
    }
//----------------------------------------
    void GetLines(const int& n = 0){
        int i = 0;
        WORD *lines_to_result;
        while(true){
            lines[n] = getLine(to_sub[n],i);
            if(!lines[n])
                break;
            i++;
            if(n == N-1){
                if(CheckDiagonals()){
                    lines_to_result = new WORD [N];
                    for(int j=0;j<N;j++)
                        lines_to_result[j] = lines[j];
                    result.push_back(lines_to_result);
                }
                break;
            }
            to_sub[n+1] = to_sub[n] | lines[n];
            GetLines(n+1);
        }
        return;
    }
    void Print(){
        int _size = result.size();
        for(int i =0; i<_size ;i++){
            cout << "Result #" << i+1 << '\n';
            print_lines(i);
        }
        cout.flush();
    }
};
//----------------------------------------
int main()
{
    int x;
    while(cin >> x){
        if(x<4){
            cout << "There are no solutions" << endl;
            continue;
        }
        if(x>16){
            cout << "More than 16 is too large" << endl;
            continue;
        }
        Queens *Q = new Queens(x);
        Q->GetLines();
        cout << "For " << x << " there are " << Q->result.size() << " solutions" << endl;
        delete Q;
    }
    return 0;
}
//----------------------------------------
