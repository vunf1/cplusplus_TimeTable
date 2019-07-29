#include <iostream>
#include "libsqlite3/libsqlite.hpp" //DB Library SQLite3
#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input
#include <vector> 
#include <iomanip>
#include <typeinfo>

#include <sqlite3.h> 
//sqlite::sqlite db("dbStudent");
 
static int callback(void* data, int argc, char** argv, char** azColName) 
{ 
    int i; 
    fprintf(stderr, "%s: ", (const char*)data); 
  
    for (i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    } 
  
    printf("\n"); 
    return 0; 
} 
int checkConnection(auto& user){

        try{
	        
    sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("dbStudent.db", &DB); 
    std::string data("CALLBACK FUNCTION"); 
  
    std::string sql("SELECT * FROM users;"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else{
        std::cout << "Opened Database Successfully!" << std::endl; 
     }
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) {
        std::cout<<rc<<std::endl;
        std::cerr << "Error SELECT" << std::endl; }
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
  
    sqlite3_close(DB); 
    return (0); 
        }catch( sqlite::exception e ) {     // catch all sql issues
            std::cerr << e.what() << std::endl;
            return -1;
        }
    }
    
struct database_model
{
    
    /*
    Single student extraction Data DB */
    int single(std::string user){
        std::cout<<user<<std::endl;
        std::vector<std::string> detailInfo;
        



/*

        auto cur = db.get_statement();
        cur->set_sql( "SELECT * from users  where id=? ");
        cur->prepare();
        cur->bind(1,user);//? - prevencion 

        while(cur->step()){

            detailInfo.emplace_back(cur->get_text(0)) ;
            detailInfo.emplace_back(cur->get_text(1)) ;
            detailInfo.emplace_back(cur->get_text(2)) ;
            detailInfo.emplace_back(cur->get_text(3)) ;
            detailInfo.emplace_back(cur->get_text(4)) ;
            detailInfo.emplace_back(cur->get_text(5)) ;
            detailInfo.emplace_back(cur->get_text(6)) ;
        }
        for (int i = 0; i < 6; i++)
        {
           cout<<detailInfo[i]<<endl;
        }
        
        //return detailInfo;
    }
*/


};

};

int main(){

    std::string user;
    database_model ok;
    user="3";
    //ok.checkConnection(user);
    std::cout<<checkConnection(user)<<std::endl;

    return 0;

}

