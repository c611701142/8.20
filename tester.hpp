#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>

#include "practice.hpp"

namespace b3prac {

class Tester {
private:
    int num;
    std::unordered_map<std::string, bool> samples;
    b3prac::StringSet strset;
public://同じファイル内のみで使う変数
    Tester() = default;
    Tester(int num) : num(num) {
        std::string input_name = std::string("s")+char(num+'0')+".txt";
        std::ifstream ifs(input_name);
        if (!ifs) {
            std::cerr<<"File not found input file: "<<input_name<<std::endl;
            //exit(0);//プログラム通常終了
        }
        std::vector<std::string> str_list;
        for (std::string s; std::getline(ifs, s); ) {
            str_list.push_back(s);
        }
        //for (auto s:str_list)
        //strset = b3prac::StringSet(str_list);
        int word = 0;
        //str_listがテキストファイルから取り出された単語
        //strがダブル配列を用いて渡す単語
        if(num ==1 || num == 2 || num == 3 ){//t1,t2,t3.txtの時はO(n^2)のループに入る
            for(std::string str : str_list) {//ここ検索
                bool check = true;
                word++;
                //int n2;
                strset.insert(str);
                for(int i=0; i < word; i++) {//単語数繰り返し(1単語ずつtestする)
                    check &= test(str_list[i]);
                    if(!check) {
                        for(int j = i+1; j < word; j++) {//
                            test(str_list[j]);
                        }
                        break;
                    }
                }
                std::cout << word << std::endl;
                std::cout << str << std::endl;
                std::cout << (check ? "OK" : "Failed") << std::endl;
                //checkが0ならok 1ならFailed表示
                if(!check) {
                    exit(1);//プログラム異常終了
                }
            }
        }    
        else if(num == 4){//s4.txtの時
        //  挿入したキーで検索し、最後に全部のキーで再度検索
            for(std::string str : str_list) {//ここ検索
                bool check = true;
                word++;
                //int n2;
                strset.insert(str);
                for(int i=0; i < word; i++) {//単語数繰り返し(1単語ずつtestする)
                    check &= test2(str_list[i]);
                    if(!check) {
                        for(int j = i+1; j < word; j++) {//
                            test2(str_list[j]);
                        }
                        break;
                    }
                }
                //std::cout << "aaaaaaaaaaaa" << std::endl;
                //std::cout << str << std::endl;
                std::cout << (check ? "OK" : "Failed") << std::endl;
                //checkが0ならok 1ならFailed表示
                if(!check) {
                    exit(1);//プログラム異常終了
                }
            }
        
        }
        else{
        }
        }
        //strset.check();
    bool test(const std::string& str) {
        return(strset.contains(str));
    }

    //test4用
    bool test2(const std::string& str) {
        return(strset.contains2(str));
    }
};
    
}